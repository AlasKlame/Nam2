#include<iostream>

using namespace std;

class Student {
    private:    
        int id;
        string name;
        int age;
        string address;
        int score;
    public:
        Student(){

        }
        Student(int id, string name, int age, string address, int score){
            this->id = id;
            this->name = name;
            this->age = age;
            this->address = address;
            this->setScore(score);
        }
        void setId(int id){
            this->id = id;
        }
        int getId(){
            return id;
        }

        void setName(string name){
            this->name = name;
        }
        string getName(){
            return name;
        }

        void setAge(int age){
            this->age = age;
        }
        int getAge(){
            return age;
        }

        void setAddress(string address){
            this->address = address;
        }

        string getAddress(){
            return address;
        }

        void setScore(int score) {
		if (score < 0) {
			this->score = 0;
		} else if (score > 10) {
			this->score = 10;
		} else {
			this->score = score;
		}
	}

        int getScore(){
            return score;
        }

        
};


int main(){
    Student student1;
    student1.setId(1);
    student1.setName("Nguyen Van A");
    student1.setAge(20);
    student1.setAddress("Ha Noi");
    student1.setScore(9);
    cout << "ID: " << student1.getId() << endl;
    cout << "Name: " << student1.getName() << endl;
    cout << "Age: " << student1.getAge() << endl;
    cout << "Address: " << student1.getAddress() << endl;
    cout << "Score: " << student1.getScore() << endl;
    return 0;}