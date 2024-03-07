<<<<<<< HEAD
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
=======
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class ToaDo{
    private:
        float x;
        float y;
    public:
        ToaDo(){
            
        }

        void input(){
            cin >> x >> y;
        }
        void output(){
            cout << x << " " << y << endl;
        }
        float distance( ToaDo& b){
            return sqrt((x - b.x)* (x - b.x) + (y - b.y)* (y - b.y));
        }
};

int main(){
    ToaDo a;
    ToaDo b;
    
    a.input();
    b.input();
    
    cout << a.distance(b) << endl;
}
>>>>>>> a249c73535dd2859a3332d6267e89b45284c1558
