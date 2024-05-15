#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;



class Catalogue{
    protected:
        string m_ID;
        string m_Title;
        string m_Author;
        int m_Count;
        bool isDeleted = false;
    public:
        Catalogue(){
            m_ID = "";
            m_Title = "";
            m_Author = "";
            m_Count = 0;
        }
        Catalogue(string ID, string Title, string Author, int Count){
            m_ID = ID;
            m_Title = Title;
            m_Author = Author;
            m_Count = Count;
        }
        virtual void Input(){
            getline(cin, m_ID);
            getline(cin, m_Title);
            getline(cin, m_Author);
            cin >> m_Count;
        }
        
        
        virtual void Output(){
            cout << m_ID << " " << m_Title << "," << m_Author << "," << m_Count << endl;
        }
        virtual void Delete(){
            isDeleted = true;
        }
        bool getIsDeleted() { // Loại bỏ const
            return isDeleted; 
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
        CPaper(string ID, string Title, string Author, int Count, string Journal, int Year) : Catalogue(ID, Title, Author, Count){
            m_Journal = Journal;
            m_Year = Year;
        }
        void Input() override {
            string date;
            getline(cin, m_ID);
            getline(cin, m_Title);
            getline(cin, m_Author);
            cin >> m_Count;
            cin.ignore();
            getline(cin, m_Journal);
            getline(cin, m_Year);
        }
        void Output() override {
            cout << m_ID << " " << m_Title << "," << m_Author << "," << m_Count << "," << m_Journal << "," << m_Year << endl;
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
        CBook(string ID, string Title, string Author, int Count, string Publisher, string Version, int Year) : Catalogue(ID, Title, Author, Count){
            m_Publisher = Publisher;
            m_Version = Version;
            m_Year = Year;
        }
        void Input() override {
            string date;
            getline(cin, m_ID);
            getline(cin, m_Title);
            getline(cin, m_Author);
            cin >> m_Count;
            cin.ignore();
            getline(cin, m_Publisher);
            getline(cin, m_Version);
            getline(cin, m_Year);

        }
        void Output() override {
            cout << m_ID << " " << m_Title << "," << m_Author << "," << m_Count << "," << m_Publisher << "," << m_Version << "," << m_Year << endl;
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
        CThesis(string ID, string Title, string Author, int Count, string School, string Falculty, int Year) : Catalogue(ID, Title, Author, Count){
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
        void Output() override {
            cout << m_ID << " " << m_Title << "," << m_Author << "," << m_Count << "," << m_School << "," << m_Falculty << "," << m_Year << endl;
        }
};



int main() {

    freopen("input.txt", "r", stdin); 
    int n;
    cin >> n; 
    freopen("output.txt", "w", stdout);

    vector<Catalogue*> documents(n); 

    for (int i = 0; i < n; i++) {
        string ID;
        cin >> ID;
        cout << i + 1 << ".";
        if (ID[0] == 'P') {
            documents[i] = new CPaper();
            documents[i]->Input();
            documents[i]->Output();
        } else if (ID[0] == 'B') {
            documents[i] = new CBook();
            documents[i]->Input();
            documents[i]->Output();
        } else if (ID[0] == 'T') {
            documents[i] = new CThesis();
            documents[i]->Input();
            documents[i]->Output();
        }
    }
    fclose(stdout); 

    // Xóa dữ liệu từ delete.txt
    ifstream file("delete.txt");
    vector<string> bookIDsToDelete; 

    string d_ID;
    while (getline(file, d_ID)) {
        if (file.is_open() == false){
            cout << "Lỗi khi đọc dữ liệu." << endl;
            break;
        }
        bookIDsToDelete.push_back(d_ID);
    }
    file.close();
    // Đọc dữ liệu từ input.txt
    // Xóa các quyển sách trong vector
    for (int i = 0; i < documents.size(); i++) {
        for (int j = 0; j < bookIDsToDelete.size(); j++) {
            if (documents[i]->getID() == bookIDsToDelete[j]) {
                documents[i]->Delete(); 
                break; 
            }
        }
    }
    
    freopen("output.txt", "w", stdout);
    cout << "After delete:" << endl;
    for (int i = 0; i < documents.size(); i++) {
        if (!documents[i]->getIsDeleted()) { 
            cout << i + 1 << ".";
            documents[i]->Output(); 
        }
        delete documents[i]; // Giải phóng bộ nhớ
    }
    fclose(stdout);

    for(int i = 0; i < documents.size(); i++){
        cout << documents[i];
    }
    
    return 0;
}