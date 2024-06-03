#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string.h>
#include <ctime>
#include <typeinfo>

using namespace std;

// Lop cha

class CItem {
protected:
    string m_Code;
    string m_Name;
    string m_Producer;
    int m_Price;
    int m_Quantity;
    int m_Discount;

public:
    CItem() {
        m_Code = "";
        m_Name = "";
        m_Producer = "";
        m_Price = 0;

    }
    CItem(string code, string name, string producer, float price) {
        m_Code = code;
        m_Name = name;
        m_Producer = producer;


    }
    string getCode() {
        return m_Code;
    }
    string getName() {
        return m_Name;
    }
    string getProducer() {
        return m_Producer;
    }
    int getPrice() {
        return m_Price;
    }
    virtual void Input(ifstream& in) {
        getline(in, m_Code, '(');
        getline(in, m_Name, ',');
        getline(in, m_Producer, ',');
        in >> m_Price;
    }
    virtual void Output(ofstream& out) {
        out << m_Name << "," << m_Producer << "," << m_Price ;
    }
    void setQuantity(int quantity) {
        m_Quantity = quantity;
    }
    int getQuantity() {
        return m_Quantity;
    }

    virtual int getDiscountType() { return 0; }

    void setDiscount(int discount) {
        m_Discount = discount;
    }

    int getDiscount() {
        return m_Discount;
    }
};

class CElectronic : public CItem {
private:
    string m_Warranty;
    string m_ElectricPower;

public:
    CElectronic() {
        m_Warranty = "";
        m_ElectricPower = "";
    }
    CElectronic(string code, string name, string producer, float price, string warranty, string electricPower) : CItem(code, name, producer, price) {
        m_Warranty = warranty;
        m_ElectricPower = electricPower;
    }
    void Input(ifstream& in) override {

        CItem::Input(in);
        in.ignore();
        getline(in, m_Warranty, ',');
        getline(in, m_ElectricPower, ',');
        string quantity;
        getline(in, quantity, ')');
        int quantityValue = stoi(quantity);
        setQuantity(quantityValue);
    }
    void Output(ofstream& out) override {
        CItem::Output(out);
        out << "," << m_Quantity;
    }

    virtual int getDiscountType() override { return 1; }
};

class CTerracotta : public CItem {
private:
    string m_Material;

public:
    CTerracotta() {
        m_Material = "";
    }
    CTerracotta(string code, string name, string producer, float price, string material) : CItem(code, name, producer, price) {
        m_Material = material;
    }
    string getMaterial() {
        return m_Material;
    }
    void Input(ifstream &in) override {
        CItem::Input(in);
        in.ignore();
        getline(in, m_Material, ',');
        string quantity;
        getline(in, quantity, ')');
        int quantityValue = stoi(quantity);
        setQuantity(quantityValue);
    }
    void Output(ofstream& out) override {
        CItem::Output(out);
        out << "," << m_Quantity;
    }

    virtual int getDiscountType() override { return 2; }
};

class CFood : public CItem {
private:
    string m_MfgDate;
    string m_ExpDate;
public:
    CFood() {
        m_MfgDate = "";
        m_ExpDate = "";
        m_Quantity = 0;
    }
    CFood(string code, string name, string producer, float price, string mfgDate, string expDate) : CItem(code, name, producer, price) {
        m_MfgDate = mfgDate;
        m_ExpDate = expDate;
    }
    string getMfgDate() {
        return m_MfgDate;
    }
    string getExpDate() {
        return m_ExpDate;
    }
    void Input(ifstream& in) override {
        CItem::Input(in);
        in.ignore();
        getline(in, m_MfgDate, ',');
        getline(in, m_ExpDate, ',');
        string quantity;
        getline(in, quantity, ')');
        int quantityValue = stoi(quantity);
        setQuantity(quantityValue);
    }
    void Output(ofstream &out) override {
        CItem::Output(out);
        out << "," << m_MfgDate << "," << m_ExpDate << "," << m_Quantity;
    }

    virtual int getDiscountType() override { return 3; }
};


// Lop tong quat chua lop con va lop cha

class CGoods {
private:
    vector<CItem*> m_List;

public:
    CGoods() {
        m_List.clear();
    }

    CItem* createItem(ifstream& in) {
        char check = in.peek();
        if (check == 'E') {
            return new CElectronic();
        } else if (check == 'T') {
            return new CTerracotta();
        } else if (check == 'F') {
            return new CFood();
        }
        return nullptr;
    }

    void addItems(CItem* item) {
        m_List.push_back(item);
    }

    void input(ifstream& in) {
        CItem* goods;
        while (!feof(stdin)) {
            goods = createItem(in);
            if (goods != nullptr) {
                goods->Input(in);
                addItems(goods);
                in.ignore();
            }
            else {
                break;
            }

        }
    }

    void ouput(ofstream& out) {
        out << m_List.size() << endl;

        for (int i = 0; i < m_List.size(); i++) {
            out << i + 1 << ". ";
            m_List[i]->Output(out);
            out << endl;
        }
    }
    vector<CItem*>& getList() {
        return m_List;
    }

    void applyDiscount(CItem* item) {
        time_t now = time(0);
        tm* ltm = localtime(&now);

        switch (item->getDiscountType()) {
            case 1: 
                if (ltm->tm_wday == 2 || ltm->tm_wday == 3) {
                    item->setDiscount(15);
                }
                break;
            case 2: 
                if (ltm->tm_wday == 6 || ltm->tm_wday == 0) {
                    item->setDiscount(30);
                }
                break;
            case 3: 
                if (ltm->tm_wday == 5) {
                    item->setDiscount(20);
                }
                break;
        }
    }

    void ViewExpDate(ofstream &out) {
        time_t now = time(0);
        tm* ltm = localtime(&now);

        out << "Các mặt hàng thực phẩm đã hết hạn sử dụng:" << endl;
        for (int i = 0; i < m_List.size(); i++) {
            if (typeid(*m_List[i]) == typeid(CFood)) {
                CFood* foodItem = dynamic_cast<CFood*>(m_List[i]);
                if (foodItem != nullptr) {
                    tm expDate;
                    strptime(foodItem->getExpDate().c_str(), "%d/%m/%Y", &expDate);

                    if (mktime(&expDate) < now) { 
                        out << foodItem->getCode() << ", " << foodItem->getName() << ", "
                             << foodItem->getQuantity() << ", " << foodItem->getExpDate() << endl;
                    }
                }
            }
        }
    }

    
    void Delete() {
        string codeToDelete;
        cout << "Nhập mã số mặt hàng cần xóa: ";
        cin >> codeToDelete;
        codeToDelete = codeToDelete + " ";

        for (int i = 0; i < m_List.size(); i++) {
            if ((m_List[i]->getCode()) == codeToDelete) {
                delete m_List[i];
                m_List.erase(m_List.begin() + i);
                cout << "Xóa mặt hàng thành công!" << endl;
                return; 
            }
        }
        cout << "Không tìm thấy mặt hàng có mã số: " << codeToDelete << endl;
    }

    void Buy(ifstream& in, ofstream& out) {
        string customerCode;
        string line;
        getline(in, customerCode); 
        
        time_t now = time(0);
        tm *ltm = localtime(&now);
        char buffer[80];
        strftime(buffer, 80, "%H:%M:%S %A %d/%m/%Y", ltm);
        
        out << customerCode << endl; 
        out << buffer << endl; 

        int itemCount = 1;
        int totalPrice = 0;

        while (getline(in, line)) {
            stringstream ss(line);
            string code, name;
            int quantity;
            getline(ss, code, ',');
            getline(ss, name, ',');
            ss >> quantity;
            code = code + " ";

            for (int i = 0; i < m_List.size(); i++) {
                if (m_List[i]->getCode() == code) {
                    applyDiscount(m_List[i]); 
                    int itemPrice = m_List[i]->getPrice() * (100 - m_List[i]->getDiscount()) / 100;
                    totalPrice += itemPrice * quantity;
                    out << itemCount << ". " << name << ": " << quantity << " x " 
                         << m_List[i]->getPrice() << " = " << itemPrice * quantity << " VNĐ" << endl;
                    itemCount++;
                    break;
                }
            }
        }
        
        out << "Giảm giá: " << totalPrice * (m_List[0]->getDiscount()) / 100 << " VNĐ" << endl;
        out << "Số tiền thanh toán: " << totalPrice << " VNĐ" << endl;
    }

    void viewQuantity(ofstream& out) {
        for(int i = 0; i < m_List.size(); i++) {
            if(m_List[i]->getQuantity() == 0) {
                out << m_List[i]->getCode() << " " << m_List[i]->getName() << endl;
            }
        }
    }
};


int main() {
    CGoods goods;
    ifstream in("input.txt");
    ifstream in2("buy.txt");
    ofstream out("output.txt");
    ofstream out2("viewExpDate.txt");
    ofstream out3("invoice.txt");
    ofstream out4("Quantity.txt");

    goods.input(in);
    goods.ouput(out);   
    goods.ViewExpDate(out2);

    goods.Delete();
  

    goods.Buy(in2, out3);
    goods.viewQuantity(out4);
}   