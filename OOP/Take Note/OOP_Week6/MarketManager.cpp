#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

struct DATE{
    int day;
    int month;
    int year;
};

class client{
protected:
    string ID;
    string name;
    DATE registration_date;
    float Accumulated_points;
    float purchase_amount;

public:
    client() {}
    client(string ID, string name, DATE registration_date, float Accumulated_points, float purchase_amount) {
        this->ID = ID;
        this->name = name;
        this->registration_date = registration_date;
        this->Accumulated_points = Accumulated_points;
        this->purchase_amount = purchase_amount;
    }

    void input(ifstream &inputFile) {
        char slash;
        inputFile >> ID;
        inputFile >> name;
        inputFile >> registration_date.day >> slash >> registration_date.month >> slash >> registration_date.year;
        inputFile >> Accumulated_points;
    }

    void output(ofstream &outputFile) {
        outputFile << ID << " " << name << " " << registration_date.day << "/" << registration_date.month << "/" << registration_date.year << " " << Accumulated_points << endl;
    }

    string getID() {
        return ID;
    }
};

class loyal_customer : public client {
private:
    int level;

public:
    loyal_customer() {}
    loyal_customer(string ID, string name, DATE registration_date, float Accumulated_points, float purchase_amount, int level) {
        this->ID = ID;
        this->name = name;
        this->registration_date = registration_date;
        this->Accumulated_points = Accumulated_points;
        this->purchase_amount = purchase_amount;
        this->level = level;
    }

    void input(ifstream &inputFile) {
        client::input(inputFile);
        inputFile >> level;
    }
};

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    int n;
    inputFile >> n;
    client *clients = new client[n];
    loyal_customer *loyal_customers = new loyal_customer[n];

    for(int i = 0; i < n; i++) {
        clients[i].input(inputFile);
    }

   

    for(int i = 0; i < n; i++) {
        clients[i].output(outputFile);
    }

    delete[] clients;
    delete[] loyal_customers;

    return 0;
}
