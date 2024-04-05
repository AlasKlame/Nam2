#include <iostream>
#include<fstream>
using namespace std;


class CMyTime{
    private:
        int m_Hour;
        int m_Minute;
        int m_Second;
    public:
        CMyTime(){};
        CMyTime(int h, int m, int s){
            m_Hour = h;
            m_Minute = m;
            m_Second = s;
        };
        CMyTime(const CMyTime& other){
            m_Hour = other.m_Hour;
            m_Minute = other.m_Minute;
            m_Second = other.m_Second;
        }

        ~CMyTime(){};

        void input(){
            cin >> m_Hour;
            cin >> m_Minute;
            cin >> m_Second;
        }

        void output(){
            if(m_Hour < 10){
                cout << "0" << m_Hour << ":";
            } else {
                cout << m_Hour << ":";
            }
            if(m_Minute < 10){
                cout << "0" << m_Minute << ":";
            } else {
                cout << m_Minute << ":";
            }
            if(m_Second < 10){
                cout << "0" << m_Second;
            } else {
                cout << m_Second;
            }
        }

        void operator++(){
            m_Second++;
            if(m_Second == 60){
                m_Second = 0;
                m_Minute++;
                if(m_Minute == 60){
                    m_Minute = 0;
                    m_Hour++;
                    if(m_Hour == 24){
                        m_Hour = 0;
                    }
                }
            }
        }

        void operator--(){
            m_Minute--;
            if(m_Minute == -1){
                m_Minute = 59;
                m_Hour--;
                if(m_Hour == -1){
                    m_Hour = 23;
                }
            }
        }

        void operator+=(int n_hours){
            m_Hour += n_hours;
            if(m_Hour >= 24){
                m_Hour %= 24;
            }
        }

        void operator-=(int n_hours){
            m_Hour -= n_hours;
            if(m_Hour < 0){
                m_Hour += 24;
            }
        }

        void operator+(CMyTime& other){
            m_Hour += other.m_Hour;
            m_Minute += other.m_Minute;
            m_Second += other.m_Second;
            if(m_Second >= 60){
                m_Second -= 60;
                m_Minute++;
            }
            if(m_Minute >= 60){
                m_Minute -= 60;
                m_Hour++;
            }
            if(m_Hour >= 24){
                m_Hour -= 24;
            }
        }

        void operator-(CMyTime& other){
            m_Hour -= other.m_Hour;
            m_Minute -= other.m_Minute;
            m_Second -= other.m_Second;
            if(m_Second < 0){
                m_Second += 60;
                m_Minute--;
            }
            if(m_Minute < 0){
                m_Minute += 60;
                m_Hour--;
            }
            if(m_Hour < 0){
                m_Hour += 24;
            }
        }

        bool operator>(CMyTime& other){
            if(m_Hour > other.m_Hour){
                return true;
            } else if(m_Hour == other.m_Hour){
                if(m_Minute > other.m_Minute){
                    return true;
                } else if(m_Minute == other.m_Minute){
                    if(m_Second > other.m_Second){
                        return true;
                    }
                }
            }
            return false;
        }

        bool operator<(CMyTime& other){
            if(m_Hour < other.m_Hour){
                return true;
            } else if(m_Hour == other.m_Hour){
                if(m_Minute < other.m_Minute){
                    return true;
                } else if(m_Minute == other.m_Minute){
                    if(m_Second < other.m_Second){
                        return true;
                    }
                }
            }
            return false;
        }

        bool operator>=(CMyTime& other){
            if(m_Hour >= other.m_Hour){
                return true;
            } else if(m_Hour == other.m_Hour){
                if(m_Minute > other.m_Minute){
                    return true;
                } else if(m_Minute == other.m_Minute){
                    if(m_Second >= other.m_Second){
                        return true;
                    }
                }
            }
            return false;
        }

        bool operator<=(CMyTime& other){
            if(m_Hour <= other.m_Hour){
                return true;
            } else if(m_Hour == other.m_Hour){
                if(m_Minute < other.m_Minute){
                    return true;
                } else if(m_Minute == other.m_Minute){
                    if(m_Second <= other.m_Second){
                        return true;
                    }
                }
            }
            return false;
        }

        bool operator==(CMyTime& other){
            if(m_Hour == other.m_Hour && m_Minute == other.m_Minute && m_Second == other.m_Second){
                return true;
            }
            return false;
        } 
};



int main(){
    CMyTime myTime;
    int n;
    freopen("input.txt", "r", stdin);
    myTime.input();
    cout << endl;
    myTime.operator++();
    myTime.operator--();
    
}