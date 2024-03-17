#include <iostream>

using namespace std;

class Day{
    private:
        int day;
        int month;
        int year;
    public:
        Day(int d, int m, int y){
            day = d;
            month = m;
            year = y;
        }
        void print(){
            cout << day << "/" << month << "/" << year << endl;
        }
        bool operator==(Day &d){
            if(day == d.day && month == d.month && year == d.year){
                return true;
            }
            else{
                return false;
            }
        }

        bool operator<(Day &d){
            if(year < d.year){
                return true;
            }
            else if(year == d.year){
                if(month < d.month){
                    return true;
                }
                else if(month == d.month){
                    if(day < d.day){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }

        Day operator++(){
            day++;
            if(day > 30){
                day = 1;
                month++;
                if(month > 12){
                    month = 1;
                    year++;
                }
            }
            return *this;
        }

        Day operator--(){
            day--;
            if(day < 1){
                day = 30;
                month--;
                if(month < 1){
                    month = 12;
                    year--;
                }
            }
            return *this;
        }

        istream& operator>>(istream& s, const Day& d){
            s << d.day << "/" << d.month << "/" << d.year;
            return s;
        }
        ostream& operator<<(ostream& s, const Day& d{
            s >> d.day >> d.month >> d.year;
            return s;
        }
};
