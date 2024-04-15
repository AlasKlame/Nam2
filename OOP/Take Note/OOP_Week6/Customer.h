#include<iostream>
#define _Customer_h
#include<fstream>

using namespace std;

struct DATE{
    int day;
    int month;
    int year;
};


class Customer{
    protected:
        string ID;
        string name;
        DATE registration_date;
        float Accumulated_points;
        float purchase_amount;
    public:
        Customer(){};
        void input(ifstream &inputFile);
        void output(ofstream &outputFile);
};
