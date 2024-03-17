#include<iostream>

using namespace std;


class CDate{
    private:
        int year;
        int month;
        int day;
    public:
        void InputDate(){
            cin >> day >> month >> year;
        }
        void OutputDate(){
            if(month < 10 && day < 10)
                cout << "0" << day << "/0" << month << "/" << year << endl;
            else if(month < 10)
                cout << day << "/0" << month << "/" << year << endl;
            else if(day < 10)
                cout << "0" << day << "/" << month << "/" << year << endl;
            else
                cout << day << "/" << month << "/" << year << endl;
        }

        bool CheckDate(){
            if(year < 0 || month < 1 || month > 12 || day < 1 || day > 31){
                return false;
            }
            return true;
        }

        bool InspectLeapYear(){
            if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
                return true;
            }
            return false;
        }

        CDate IncreaseYear(){
            year++;
            return *this;
        }

        CDate IncreaseMonth(){
            if(month == 12){
                month = 1;
                year++;
            }else{
                month++;
            }
            return *this;
        }

        CDate IncreaseDay(){
            if(day == 31){
                if(month == 12){
                    year++;
                    month = 1;
                    day = 1;
                }else{
                    month++;
                    day = 1;
                }
            }else{
                day++;
            }
            return *this;
        }

        CDate DecreaseYear(){
            year--;
            return *this;
        }

        CDate DecreaseMonth(){
            if(month == 1){
                month = 12;
                year--;
            }else{
                month--;
            }
            return *this;    
        }

        CDate DecreaseDay(){
            if(day == 1){
                if(month == 1){
                    year--;
                    month = 12;
                    day = 31;
                }else{
                    month--;
                    if(month == 4 || month == 6 || month == 9 || month == 11){
                        day = 30;
                    }else if(month == 2){
                        if(InspectLeapYear()){
                            day = 29;
                        }else{
                            day = 28;
                        }
                    }else{
                        day = 31;
                    }
                }
            }else{
                day--;
            }
            return *this;
        }


        CDate IncreaseYear(int n){
            year += n;
            return *this;
        }

        CDate IncreaseMonth(int n){
            month += n;
            if(month > 12){
                year += month / 12;
                month = month % 12;
            }
            return *this;
        }

        CDate IncreaseDay(int n){
            day += n;
            if(day > 31){
                month += day / 31;
                day = day % 31;
                if(month > 12){
                    year += month / 12;
                    month = month % 12;
                }
            }
            return *this;
        }


        CDate DecreaseYear(int n){
            year -= n;
            return *this;
        }

        CDate DecreaseMonth(int n){
            month -= n;
            if(month < 1){
                year -= month / 12;
                month = month % 12;
            }
            return *this;
        }

        CDate DecreaseDay(int n){
            day -= n;
            if(day < 1){
                month -= day / 31;
                day = day % 31;
                if(month < 1){
                    year -= month / 12;
                    month = month % 12;
                }
            }
            return *this;
        }

        int DayOrderInYear(){
            int dayOrder = 0;
            for(int i = 1; i < month; i++){
                if(i == 4 || i == 6 || i == 9 || i == 11){
                    dayOrder += 30;
                }else if(i == 2){
                    if(InspectLeapYear()){
                        dayOrder += 29;
                    }else{
                        dayOrder += 28;
                    }
                }else{
                    dayOrder += 31;
                }
            }
            dayOrder += day;
            return dayOrder;
        }

        int WeekOrderInYear(){
            int weekOrder = 0;
            for(int i = 1; i < month; i++){
                if(i == 4 || i == 6 || i == 9 || i == 11){
                    weekOrder += 4;
                }else if(i == 2){
                    if(InspectLeapYear()){
                        weekOrder += 4;
                    }else{
                        weekOrder += 4;
                    }
                }else{
                    weekOrder += 5;
                }
            }
            weekOrder += day / 7;
            return weekOrder;
        }
        
        void TransferMonthToString(){
            switch (month) {
                case 1:
                    cout << "January";
                    break;
                case 2:
                    cout << "February";
                    break;
                case 3:
                    cout << "March";
                    break;
                case 4:
                    cout << "April";
                    break;
                case 5:
                    cout << "May";
                    break;
                case 6:
                    cout << "June";
                    break;
                case 7:
                    cout << "July";
                    break;
                case 8:
                    cout << "August";
                    break;
                case 9:
                    cout << "September";
                    break;
                case 10:
                    cout << "October";
                    break;
                case 11:
                    cout << "November";
                    break;
                case 12:
                    cout << "December";
                    break;
                default:
                    cout << "Invalid month";
                    break;
            }
            
        }
        void ConvertDate(){
            TransferMonthToString();
            cout << " " << day << ", " << year << endl;
        }
        int DeductDate(CDate& date) {
            int yearsDiff = year - date.year;
            int monthsDiff = month - date.month;
            int daysDiff = day - date.day;

            int totalDays = yearsDiff * 365 + monthsDiff * 30 + daysDiff;
            return totalDays;
        }
};


int DeductDateToDate(CDate& date1, CDate& date2) {
    return date1.DeductDate(date2);
}


int main(){
    CDate date1, date2;
    int choice;
    
    do {
        cout << "Menu:" << endl;
        cout << "1. Input date" << endl;
        cout << "2. Output date" << endl;
        cout << "3. Check date validity" << endl;
        cout << "4. Increase year" << endl;
        cout << "5. Increase month" << endl;
        cout << "6. Increase day" << endl;
        cout << "7. Decrease year" << endl;
        cout << "8. Decrease month" << endl;
        cout << "9. Decrease day" << endl;
        cout << "10. Calculate day order in year" << endl;
        cout << "11. Calculate week order in year" << endl;
        cout << "12. Convert date to string" << endl;
        cout << "13. Deduct date" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter date 1: ";
                date1.InputDate();
                cout << "Enter date 2: ";
                date2.InputDate();
                break;
            case 2:
                cout << "Date 1: ";
                date1.OutputDate();
                cout << "Date 2: ";
                date2.OutputDate();
                break;
            case 3:
                cout << "Date 1 is " << (date1.CheckDate() ? "valid" : "invalid") << endl;
                cout << "Date 2 is " << (date2.CheckDate() ? "valid" : "invalid") << endl;
                break;
            case 4:
                date1.IncreaseYear();
                date2.IncreaseYear();
                break;
            case 5:
                date1.IncreaseMonth();
                date2.IncreaseMonth();
                break;
            case 6:
                date1.IncreaseDay();
                date2.IncreaseDay();
                break;
            case 7:
                date1.DecreaseYear();
                date2.DecreaseYear();
                break;
            case 8:
                date1.DecreaseMonth();
                date2.DecreaseMonth();
                break;
            case 9:
                date1.DecreaseDay();
                date2.DecreaseDay();
                break;
            case 10:
                cout << "Day order in year for date 1: " << date1.DayOrderInYear() << endl;
                cout << "Day order in year for date 2: " << date2.DayOrderInYear() << endl;
                break;
            case 11:
                cout << "Week order in year for date 1: " << date1.WeekOrderInYear() << endl;
                cout << "Week order in year for date 2: " << date2.WeekOrderInYear() << endl;
                break;
            case 12:
                cout << "Date 1: ";
                date1.ConvertDate();
                cout << "Date 2: ";
                date2.ConvertDate();
                break;
            case 13:
                cout << "Difference in days between date 1 and date 2: " << DeductDateToDate(date1, date2) << endl;
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
        
        cout << endl;
    } while (choice != 0);
    
    return 0;
}


