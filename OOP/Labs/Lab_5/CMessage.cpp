#include<iostream>
#include<string>
#include<fstream>


using namespace std;

class CMyDate{
    private:
        string day;
        string month;
        string year;
    public:
        CMyDate(){};
        void input(ifstream &inputFile){
            inputFile >> day >> month >> year;
        }
        void output(ofstream &outputFile){
            outputFile << day << "/" << month << "/" << year;
            outputFile << endl;
        }
        bool isValid(){
            if(stoi(day) > 31 || stoi(day) < 1){
                return false;
            }
            if(stoi(month) > 12 || stoi(month) < 1){
                return false;
            }
            if(stoi(year) < 0){
                return false;
            }
            return true;
        }    
};


class CMyTime{
    private:
        int hour;
        int minute;
        int second;
    public: 
        CMyTime(){};
        void input(ifstream &inputFile){
            inputFile >> hour >> minute >> second;
        }
        void output(ofstream &outputFile){
            outputFile << hour << ":" << minute << ":" << second;
            outputFile << endl;
        }
        
};




class CMessage{
    private:
        string m_Number;
        int m_Vote;
        CMyDate m_Date;
        CMyTime m_Time;
    public:
        void input(ifstream &inputFile){
            inputFile >> m_Number >> m_Vote;
            m_Date.input(inputFile);
            m_Time.input(inputFile);
        }
        void output(ofstream &outputFile){
            outputFile << m_Number << " " << m_Vote << " ";
            m_Date.output(outputFile);
            m_Time.output(outputFile);
        }
};


class CListMessenge{
    private:
        CMessage *m_Message;
        int m_Amount;
    public:
        CListMessenge(){
            m_Amount = 0;
            m_Message = NULL;
        }
        void input(ifstream &inputFile){
            inputFile >> m_Amount;
            m_Message = new CMessage[m_Amount];
            for(int i = 0; i < m_Amount; i++){
                m_Message[i].input(inputFile);
            }
        }
        void output(ofstream &outputFile){
            for(int i = 0; i < m_Amount; i++){
                m_Message[i].output(outputFile);
                outputFile << endl;
            }
        }

        void free(){
            delete[] m_Message;
        }

};


int main(){
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    CListMessenge listMessage;
    listMessage.input(inputFile);
    listMessage.output(outputFile);
    listMessage.free();
    inputFile.close();
    outputFile.close();
    return 0;
}