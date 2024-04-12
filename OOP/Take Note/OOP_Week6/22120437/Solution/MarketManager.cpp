#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

class Customer {
protected:
    string ID;
    string IDNumber;
    Date registrationDate;
    float accumulatedPoints;
    float purchaseAmount;

public:
    virtual void input(istringstream &iss) {
        char delim; // để bỏ qua '/'
        iss >> IDNumber >> registrationDate.day >> delim >> registrationDate.month >> delim >> registrationDate.year >> accumulatedPoints;
    }

    virtual void output(ofstream &outputFile) {
        outputFile << ID << " " << IDNumber << " " 
                   << registrationDate.day << "/" << registrationDate.month << "/" << registrationDate.year << " "
                   << fixed << setprecision(1) << accumulatedPoints << endl;
    }
    string getID() {
        return ID;
    }
    void setID(string id) {
        ID = id;
    }
    virtual double calculateDiscount() const {
        return 0.0;
    }
    double getFinalAmount() {
        return purchaseAmount - calculateDiscount();
    }
    void setPurchaseAmount(double amount) {
        purchaseAmount = amount;
    }
    void input(){
        cout <<"Enter Purchase Amount: ";
        cin >> purchaseAmount;
    }
    virtual void output(){
    cout << fixed << setprecision(0); 
    cout << "Final Amount: " << getFinalAmount() << endl;
    }
};

class RegularCustomer : public Customer {
public:
    void input(istringstream &iss) override {
        Customer::input(iss);
    }

    void output(ofstream &outputFile) override {
        outputFile << "Regular Customer: ";
        Customer::output(outputFile);
    }

    double calculateDiscount() const override {
        if (accumulatedPoints > 1000 && purchaseAmount > 5000000) {
            return purchaseAmount * 0.02; 
        }
        return 0.0; 
    }

};

class VIPCustomer : public Customer {
private:
    int loyaltyLevel;

public:
    void input(istringstream &iss) override {
        Customer::input(iss);
        iss >> loyaltyLevel;
    }

    void output(ofstream &outputFile) override {
        outputFile << "VIP Customer (Level " << loyaltyLevel << "): ";
        Customer::output(outputFile);
    }
    double calculateDiscount() const override {
        float discount = 0; 
        if (accumulatedPoints > 1000 && purchaseAmount > 5000000) {
            if(loyaltyLevel == 1) {
                discount += purchaseAmount * 0.05;
            } else if(loyaltyLevel == 2) {
                discount += purchaseAmount * 0.07;
            } else if(loyaltyLevel == 3) {
                discount += purchaseAmount * 0.10;
            }
        }
        return discount;
    }

    void output() override {
        Customer::output(); 
    }
};

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cout << "Failed to open file!" << endl;
        return 1;
    }

    vector<Customer*> customers;

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string customerType;
        iss >> customerType; 

        Customer* customer;
        if (customerType[0] == 'N') {
            customer = new RegularCustomer();
        } else if (customerType[0] == 'V') {
            customer = new VIPCustomer();
        } else {
            cout << "Invalid customer type!" << endl;
            continue;
        }

        customer->setID(customerType); 
        customer->input(iss); 
        customers.push_back(customer);
    }

    inputFile.close();

    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        cout << "Failed to create output file!" << endl;
        return 1;
    }

    for (auto& customer : customers) {
        customer->output(outputFile);
    }

    

    outputFile.close();
    for (auto& customer : customers) {
        cout << "\nCustomer " << customer->getID() << ":" << endl;
        customer->input(); 
    }

    cout << "\nFinal amounts after discount:" << endl;
    for (auto& customer : customers) {
        customer->output(); 
    }

    for (auto& customer : customers) {
        delete customer;
    }

    cin.get();
    cin.get();
    return 0;
}
