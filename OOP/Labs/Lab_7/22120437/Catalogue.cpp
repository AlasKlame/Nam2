#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;



class Catalogue{
    protected:
        string m_ID;
        string m_Title;
        string m_Author;
        int m_Count;
        bool isDeleted = false;
    public:
        Catalogue(){};
        Catalogue(string ID, string Title, string Author, int Count){
            m_ID = ID;
            m_Title = Title;
            m_Author = Author;
            m_Count = Count;
        }
        virtual void Input(){
            getline(cin, m_Title);
            getline(cin, m_Author);
            cin >> m_Count;
        }
        
        
        virtual void Output(ofstream &fileOutput){
            fileOutput <<m_ID << " " << m_Title << "," << m_Author << "," << m_Count << endl;
        }
        virtual void Delete(){
            isDeleted = true;
        }
        bool getIsDeleted() { 
            return isDeleted; 
        }   
        virtual string getYear() const {
            return m_ID.substr(1, 4);
        }
        virtual void sortYear(vector<Catalogue*>& documents) {
            sort(documents.begin(), documents.end(), [](const Catalogue* a, const Catalogue* b) {
                int yearA = stoi(a->getYear().substr(6, 4));
                int yearB = stoi(b->getYear().substr(6, 4));
                if (yearA != yearB) {
                    return yearA < yearB;
                }

                int monthA = stoi(a->getYear().substr(0, 2));
                int monthB = stoi(b->getYear().substr(0, 2));
                if (monthA != monthB) {
                    return monthA < monthB;
                }

                int dayA = stoi(a->getYear().substr(3, 2));
                int dayB = stoi(b->getYear().substr(3, 2));
                return dayA < dayB; 
            });
        }

        virtual void sortCount(vector<Catalogue*>& documents) {
            sort(documents.begin(), documents.end(), [](const Catalogue* a, const Catalogue* b) {
                return a->getCount() < b->getCount();
            });
        }

        virtual int getCount() const {
            return m_Count;
        }

        string getID(){ return m_ID; }
        string getTitle(){ return m_Title; }
        string getAuthor(){ return m_Author; }
        int getCount(){ return m_Count; }
};



class CPaper  : public Catalogue {
    private:
        string m_Journal;
        string m_Year;
    public:
        CPaper(){
            m_ID = "";
            m_Title = "";
            m_Author = "";
            m_Count = 0;
            m_Journal = "";
            m_Year = "";
        }
        CPaper(string ID, string Title, string Author, int Count, string Journal, string Year) : Catalogue(ID, Title, Author, Count){
            m_Journal = Journal;
            m_Year = Year;
        }
        void Input() override {
            getline(cin, m_ID);
            getline(cin, m_Title);
            getline(cin, m_Author);
            cin >> m_Count;
            cin.ignore();
            getline(cin, m_Journal);
            getline(cin, m_Year);
            cin.ignore();
        }
        void Output(ofstream &fileoutput) override {
            fileoutput << m_ID << " " << m_Title << "," << m_Author << "," << m_Count << "," << m_Journal << "," << m_Year << endl;
        }
        string getYear() const override {
            return m_Year;
        }
        int getCount() const override {
            return m_Count;
        }
        
};


class CBook : public Catalogue {
    private:
        string m_Publisher;
        string m_Version;
        string m_Year;
    public:
        CBook(){
            m_ID = "";
            m_Title = "";
            m_Author = "";
            m_Count = 0;
            m_Publisher = "";
            m_Version = "";
            m_Year = "";
        }
        CBook(string ID, string Title, string Author, int Count, string Publisher, string Version, string Year) : Catalogue(ID, Title, Author, Count){
            m_Publisher = Publisher;
            m_Version = Version;
            m_Year = Year;
        }
        void Input() override {
            getline(cin, m_ID);
            getline(cin, m_Title);
            getline(cin, m_Author);
            cin >> m_Count;
            cin.ignore();
            getline(cin, m_Publisher);
            getline(cin, m_Version);
            getline(cin, m_Year);

        }
        void Output(ofstream& fileoutput) override {
            fileoutput << m_ID << " " << m_Title << "," << m_Author << "," << m_Count << "," << m_Publisher << "," << m_Version << "," << m_Year << endl;
        }
        string getYear() const override {
            return m_Year;
        }
        int getCount() const override {
            return m_Count;
        }
};


class CThesis : public Catalogue {
    private:
        string m_School;
        string m_Falculty;
        string m_Year;
    public:
        CThesis(){
            m_ID = "";
            m_Title = "";
            m_Author = "";
            m_Count = 0;
            m_School = "";
            m_Falculty = "";
            m_Year = "";
        }
        CThesis(string ID, string Title, string Author, int Count, string School, string Falculty, string Year) : Catalogue(ID, Title, Author, Count){
            m_School = School;
            m_Falculty = Falculty;
            m_Year = Year;
        }
        void Input() override {
            getline(cin, m_ID);
            getline(cin, m_Title);
            getline(cin, m_Author);
            cin >> m_Count;
            cin.ignore();
            getline(cin, m_School);
            getline(cin, m_Falculty);
            getline(cin, m_Year);
        }
        void Output(ofstream& fileouput) override {
            fileouput <<m_ID << " " << m_Title << "," << m_Author << "," << m_Count << "," << m_School << "," << m_Falculty << "," << m_Year << endl;
        }
        string getYear() const override {
            return m_Year;
        }
        int getCount() const override {
            return m_Count;
        }
};



int main() {
    vector<Catalogue*> documents; 

    int choice;
    do {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Đọc dữ liệu từ input.txt" << endl;
        cout << "2. Xóa dữ liệu từ delete.txt" << endl;
        cout << "3. Xuất dữ liệu vào output.txt" << endl;
        cout << "4. Sắp xếp theo năm và xuất ra file SortYear.txt" << endl;
        cout << "5. Sắp xếp theo số lượng và xuất ra file SortCount.txt" << endl;
        cout << "0. Thoát" << endl;
        cout << "Chọn chức năng: ";
        cin >> choice;

        switch (choice) {
            case 1:
            {
                ifstream fileInput("input.txt");
                if (!fileInput.is_open()) {;
                    cout << "Lỗi khi mở file input.txt" << endl;
                    break;
                }
                int n;
                fileInput >> n; 
                fileInput.ignore();

                documents.resize(n);

                for (int i = 0; i < n; i++) {
                    string ID;
                    getline(fileInput, ID); 
                    if (ID[0] == 'P') {cout << i + 1 << ".";
                        string Title, Author, Journal, Year;
                        int Count;
                        getline(fileInput, Title);
                        getline(fileInput, Author);
                        fileInput >> Count;
                        fileInput.ignore();
                        getline(fileInput, Journal);
                        getline(fileInput, Year);
                        documents[i] = new CPaper(ID, Title, Author, Count, Journal, Year); 
                    } else if (ID[0] == 'B') {
                        string Title, Author, Publisher, Version, Year;
                        int Count;
                        getline(fileInput, Title);
                        getline(fileInput, Author);
                        fileInput >> Count;
                        fileInput.ignore();
                        getline(fileInput, Publisher);
                        getline(fileInput, Version);
                        getline(fileInput, Year);
                        documents[i] = new CBook(ID, Title, Author, Count, Publisher, Version, Year);
                    } else if (ID[0] == 'T') {
                        string Title, Author, School, Falculty, Year;
                        int Count;
                        getline(fileInput, Title);
                        getline(fileInput, Author);
                        fileInput >> Count;
                        fileInput.ignore();
                        getline(fileInput, School);
                        getline(fileInput, Falculty);
                        getline(fileInput, Year);
                        documents[i] = new CThesis(ID, Title, Author, Count, School, Falculty, Year);
                    }
                }
                fileInput.close();
            }
            break;

            case 2:
            {
                ifstream fileDelete("delete.txt");
                if (!fileDelete.is_open()) {
                    cout << "Lỗi khi mở file delete.txt" << endl;
                    break;
                }
                vector<string> bookIDsToDelete; 

                string d_ID;
                while (getline(fileDelete, d_ID)) {
                    bookIDsToDelete.push_back(d_ID);
                }
                fileDelete.close();

                for (int i = 0; i < documents.size(); i++) {
                    for (int j = 0; j < bookIDsToDelete.size(); j++) {
                        if (documents[i]->getID() == bookIDsToDelete[j]) {
                            documents[i]->Delete(); 
                            break; 
                        }
                    }
                }
                ofstream fileOutput("output.txt");
                if (!fileOutput.is_open()) {
                    cout << "Lỗi khi mở file output.txt" << endl;
                    break;
                }
                cout << "After delete:" << endl;
                for (int i = 0; i < documents.size(); i++) {
                    if (!documents[i]->getIsDeleted()) { 
                        cout << i + 1 << ".";
                        fileOutput << i + 1 << ".";
                        fileOutput << documents[i]->getID() << " " << documents[i]->getTitle() << "," << documents[i]->getAuthor() << "," << documents[i]->getCount() << endl; 
                    }
                }
                fileOutput.close();
            
            }
            break;

            case 3:
            {
                ofstream fileOutput("output.txt");
                if (!fileOutput.is_open()) {
                    cout << "Lỗi khi mở file output.txt" << endl;
                    break;
                }
                for(int i = 0; i < documents.size(); i++) {
                    fileOutput << i + 1 << ".";
                    documents[i]->Output(fileOutput);
                    
                }
            }
            case 4:{
                ofstream fileOutput("SortYear.txt");
                if (!fileOutput.is_open()) {
                    cout << "Lỗi khi mở file output.txt" << endl;
                    break;
                }
                for(int i = 0; i < documents.size(); i++) {
                    fileOutput << i + 1 << ".";
                    documents[i]->sortYear(documents);
                    documents[i]->Output(fileOutput);
                    
                }
                fileOutput.close();
            }
            break;
            case 5:{
                ofstream fileOutput("SortCount.txt");
                if (!fileOutput.is_open()) {
                    cout << "Lỗi khi mở file output.txt" << endl;
                    break;
                }
                for(int i = 0; i < documents.size(); i++) {
                    fileOutput << i + 1 << ".";
                    documents[i]->sortCount(documents);
                    documents[i]->Output(fileOutput);
                    
                }
                fileOutput.close();
            }
            case 0:
                cout << "Thoát chương trình." << endl;
                break;

            default:
                cout << "Lựa chọn không hợp lệ. Vui lòng thử lại." << endl;
        }

    } while (choice != 0);

    // Giải phóng bộ nhớ
    for (int i = 0; i < documents.size(); i++) {
        delete documents[i];
    }
    documents.clear();

    return 0;
}