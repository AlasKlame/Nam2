#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm> // Để sử dụng hàm min_element
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
public:
    Date(int d = 1, int m = 1, int y = 1) : day(d), month(m), year(y) {}

    friend istream& operator>>(istream& is, Date& date) {
        is >> date.day >> date.month >> date.year;
        return is;
    }

    friend ostream& operator<<(ostream& os, const Date& date) {
        os << date.day << "/" << date.month << "/" << date.year;
        return os;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }

    int getDay() const {
        return day;
    }
};

class FootballPlayer {
private:
    string name;
    Date dob;
    string gender;

public:
    FootballPlayer(string n = "", Date d = Date(), string g = "") : name(n), dob(d), gender(g) {}

    friend istream& operator>>(istream& is, FootballPlayer& player) {
        string temp; // Dùng để bỏ qua dấu chấm và dấu cách thừa
        is >> temp >> player.name >> player.dob >> temp >> player.gender;
        return is;
    }

    int Age() const {
        Date today(1, 1, 2024);
        int age = today.getYear() - dob.getYear();
        if (today.getMonth() < dob.getMonth() || (today.getMonth() == dob.getMonth() && today.getDay() < dob.getDay())) {
            age--;
        }
        return age;
    }

    string getName() const {
        return name;
    }

    string getGender() const {
        return gender;
    }

};

bool isMale(const FootballPlayer& player) {
    return player.getGender() == "M";
}

int main() {
    freopen("input.txt", "rt", stdin);

    vector<FootballPlayer> players;
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        FootballPlayer player;
        iss >> player;
        players.push_back(player);
    }

    freopen("output.txt", "wt", stdout);

    // Tìm cầu thủ nam có tuổi nhỏ nhất
    auto youngestMale = min_element(players.begin(), players.end(), [](const FootballPlayer& p1, const FootballPlayer& p2) {
        return isMale(p1) && isMale(p2) ? p1.Age() < p2.Age() : !isMale(p1);
    });

    if (youngestMale != players.end()) {
        cout << youngestMale->getName() << " " << youngestMale->Age() << endl;
    }

    return 0;
}
