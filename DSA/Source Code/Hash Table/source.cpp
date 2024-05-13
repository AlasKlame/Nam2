#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<cmath>
#define CAPACITY 2000

using namespace std;


struct Company{
    string name;
    string tax_code;
    string address;
};


struct HashTable{
    Company **itemm;
    int size;
    int count;
};

Company Input(){
    Company company;
    getline(cin, company.name);
    getline(cin, company.tax_code);
    getline(cin, company.address);
    return company;
}

vector<Company> readCompanyList(string filename){
    vector<Company> companyList;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open the file." << endl;
        return companyList;
    }

    string line;
    while (getline(file, line)) {
        
        stringstream ss(line);
        string name, taxCode, address;
        getline(ss, name, '|');
        getline(ss, taxCode, '|');
        getline(ss, address, '|');
        
        Company company;
        company.name = name;
        company.tax_code = taxCode;
        company.address = address;
        companyList.push_back(company);
    }

    file.close();

    return companyList;

}

long long hashString(string companyName){
    long long hash = 0;
    long long m = pow(10,9) + 9;
    long long power_of_31 = 1;
    

    if(companyName.length() > 20){
        for(int i = companyName.length() - 20; i < companyName.length(); i++){
            hash = (hash + companyName[i] * power_of_31) % m;
            power_of_31 = (power_of_31 * 31) % m;
        }
    }
    else{
        for(int i = 0; i < companyName.length(); i++){
            hash = (hash + companyName[i] * power_of_31) % m;
            power_of_31 = (power_of_31 * 31) % m;
        }
    }
    return hash;
}



Company *createHashTable(vector<Company> listCompany){
    Company *hashTable = new Company[CAPACITY];
    for (int i = 0; i < listCompany.size(); i++) {
        long long hash = hashString(listCompany[i].name);
        int index = hash % CAPACITY ;
        int attempt = 0;
        while(hashTable[index].name != "" && attempt < 2000){
            index = (index + 1) % CAPACITY ;
            attempt++;
        }
        if(attempt <= CAPACITY) {
            hashTable[index] = listCompany[i];
        }
        else{
            cout << "Cannot insert " << listCompany[i].name << endl;
        }
    }   
    return hashTable;
}

void Insert(Company *hashTable, Company company){
    long long hash = hashString(company.name);
    int index = hash % CAPACITY;
    int attempt = 0;
    while(hashTable[index].name != "" && attempt < 2000){
        index = (index + 1) % 2000;
        attempt++;
    }
    if(attempt < 2000){
        hashTable[index] = company;
    }
    else{
        cout << "Cannot insert " << company.name << endl;
    }
}

Company *Search(Company* hashTable, string companyName){
    long long hash = hashString(companyName);
    int index = hash % CAPACITY;
    int attempt = 0;
    while(hashTable[index].name != companyName && attempt < 2000){
        index = (index + 1) % 2000;
        attempt++;
    }
    if(attempt < 2000){
        return &hashTable[index];
    }
    else{
        cout << "Cannot find " << companyName << endl;
        return NULL;
    }

}

void printListCompany(vector<Company> listCompany){
    for(int i = 0; i < listCompany.size(); i++){
        cout << listCompany[i].name << " " << listCompany[i].tax_code << " " << listCompany[i].address << endl;
    }
}

void freeHashTable(Company *hashTable){
    delete[] hashTable;
}




