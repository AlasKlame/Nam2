#include <iostream>


using namespace std;

class Time{
    private:
        int hour;
        int minute;
        int second;
    public:
        Time(int h, int m, int s){
            hour = h;
            minute = m;
            second = s;
        }
        void print(){
            cout << hour << ":" << minute << ":" << second << endl;
        }
        bool operator>=(Time t){
            if(hour > t.hour){
                return true;
            }
            else if(hour == t.hour){
                if(minute > t.minute){
                    return true;
                }
                else if(minute == t.minute){
                    if(second >= t.second){
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

        bool operator!=(Time& t){
            if(hour != t.hour || minute != t.minute || second != t.second){
                return true;
            }
            else{
                return false;
            }
        }

        Time operator+(Time t){
            Time tmp(0, 0, 0);
            tmp.second = second + t.second;
            if(tmp.second >= 60){
                tmp.second -= 60;
                tmp.minute++;
            }
            tmp.minute += minute + t.minute;
            if(tmp.minute >= 60){
                tmp.minute -= 60;
                tmp.hour++;
            }
            tmp.hour += hour + t.hour;
            return tmp;
        }
        Time operator-(Time t){
            Time tmp(0, 0, 0);
            tmp.second = second - t.second;
            if(tmp.second < 0){
                tmp.second += 60;
                tmp.minute--;
            }
            tmp.minute += minute - t.minute;
            if(tmp.minute < 0){
                tmp.minute += 60;
                tmp.hour--;
            }
            tmp.hour += hour - t.hour;
            return tmp;
        }
        Time operator++(){
            second++;
            if(second >= 60){
                second -= 60;
                minute++;
            }
            if(minute >= 60){
                minute -= 60;
                hour++;
            }
            return *this;
        }
        Time operator--(){
            second--;
            if(second < 0){
                second += 60;
                minute--;
            }
            if(minute < 0){
                minute += 60;
                hour--;
            }
            return *this;
        }
};
