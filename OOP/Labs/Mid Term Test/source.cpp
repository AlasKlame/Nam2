#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class CDate {
protected:
    int day;
    int month;
    int year;

public:
    CDate() {}
    CDate(int d, int m, int y) : day(d), month(m), year(y) {}

    int getDay() const {
        return day;
    }  
    int getMonth() const {
        return month;
    }
    int getYear() const {
        return year;
    }

    friend istream& operator>>(istream& input, CDate& date) {
        char delimiter;
        input >> date.day >> delimiter >> date.month >> delimiter >> date.year;
        return input;
    }

    friend ostream& operator<<(ostream& output, const CDate& date) {
        output << date.day << "/" << date.month << "/" << date.year;
        return output;
    }

    bool operator>(const CDate& other) const {
        if (year != other.year) return year > other.year;
        if (month != other.month) return month > other.month;
        return day > other.day;
    }
};

class Cauthu {
protected:
    string name;
    string pos;
    CDate date;
    int num;

public:
    Cauthu() {}
    Cauthu(const string& name, const string& pos, const CDate& date, int num) : name(name), pos(pos), date(date), num(num) {}
    Cauthu(const Cauthu& authu) : name(authu.name), pos(authu.pos), date(authu.date), num(authu.num) {}

    CDate getDate() const {
        return date;
    }

    friend istream& operator>>(istream& input, Cauthu& authu) {
        string line;
        getline(input, line);

        stringstream ss(line);
        getline(ss, authu.name, '-');
        getline(ss, authu.pos, '-');
        ss >> authu.date; 
        ss.ignore(3, '-'); 
        ss >> authu.num; 

        return input;
    }



    friend ostream& operator<<(ostream& output, const Cauthu& authu) {
        output << authu.name << " - " << authu.pos << " - " << authu.date << " - " << authu.num;
        return output;
    }

    bool operator>(const Cauthu& other) const {
        return date > other.date;
    }

    bool operator<(const Cauthu& other) const {
        return num < other.num;
    }
};

void printPlayerWithMaxDOB(const vector<Cauthu>& players) {
    if (players.empty()) {
        cout << "Danh sách cầu thủ trống." << endl;
        return;
    }

    const auto maxDOBPlayer = max_element(players.begin(), players.end(), [](const Cauthu& a, const Cauthu& b) {
        return a > b;
    });

    cout << "Cầu thủ có ngày sinh lớn nhất: " << *maxDOBPlayer << endl;
}
void sortPlayersByJerseyNumber(vector<Cauthu>& players) {
    sort(players.begin(), players.end(), [](const Cauthu& a, const Cauthu& b) {
        return a < b;
    });
}


int main() {
    vector<Cauthu> cauthu;
    ifstream infile("input.txt");

    if (!infile.is_open()) {
        cerr << "Không thể mở file input.txt" << endl;
        return 1;
    }

    string line;
    while (getline(infile, line)) {
        Cauthu authu;
        stringstream ss(line);
        ss >> authu;
        if (!ss.fail()) {
            cauthu.push_back(authu);
        }
    }

    infile.close();

    for (const auto& player : cauthu) {
        cout << player << endl;
    }

    printPlayerWithMaxDOB(cauthu);

    cout << "Danh sách cầu thủ sau khi sắp xếp theo số áo: " << endl;
    sortPlayersByJerseyNumber(cauthu);
    for (const auto& player : cauthu) {
        cout << player << endl;
    }

    return 0;
}
