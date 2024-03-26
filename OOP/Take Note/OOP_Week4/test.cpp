#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}

    int sumOfSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }
    friend std::istream& operator>>(std::istream& is, Time& time) {
        char colon;
        is >> time.hours >> colon >> time.minutes >> colon >> time.seconds;
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Time& time) {
        os << time.hours << ":" << time.minutes << ":" << time.seconds;
        return os;
    }
};

int main() {
    Time T;
    cin>>T;
    cout<<T;
    // freopen("input.txt", "rt", stdin);

    // std::string line;
    // while (std::getline(std::cin, line)) {
    //     std::istringstream iss(line);
    //     std::string name;
    //     Time time;
        
    // }

 
    

    // freopen("output.txt", "wt", stdout);

    //std::cout << fastestRunner << " " << fastestTime << std::endl;

    //fclose(stdout);
}
