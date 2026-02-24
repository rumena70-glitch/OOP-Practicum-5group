#include <iostream>
using namespace std;

struct Employee {
    string name;
    int position;
    float salary;
    int age;
    int skillGrade;
    string positionArray[4] {
        "Software_Engineer",
        "Senior_Software_Engineer",
        "Engineer_Manager",
        "Lead_Software_Engineer"
    };
    void print() const {
        cout << "Employee: " << name << ", position: " << positionArray[position] << ", salary: " << salary << ", age: "
                << age << ", skill grade: " << skillGrade << endl;
    }
    void changeSalary(const float newSalary) {
        salary = newSalary;
    }
    void changeSkillGrade(const int newGrade) {
        skillGrade = newGrade;
    }
    void changePosition(const int newPosition) {
        position = newPosition;
    }
};
struct Firm {
    Employee* employee;
    float averageSalary;
    //не знам как фирмата да пази информация за n на брой служители
};
int main() {

}
