#include <iostream>
#include <string>
#include <vector>

class Student {
public:
    Student(const std::string& name, int age, const std::string& id)
        : name(name), age(age), id(id) {}

    void displayInfo() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "ID: " << id << std::endl;
    }

    

private:
    std::string name;
    int age;
    std::string id;
};

int main() {
    std::vector<Student> students;


    // Create some students with 

    Student student1("John Doe", 18, "123456");
    Student student2("Jane Smith", 17, "789012");

    // Add students to the vector
    students.push_back(student1);
    students.push_back(student2);

    // Display information of all students
    for (const auto& student : students) {
        student.displayInfo();
        std::cout << std::endl;
    }

    return 0;
}