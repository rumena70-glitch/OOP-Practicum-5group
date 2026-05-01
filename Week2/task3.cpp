#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

struct Employee {
    string name;
    string position;
    float salary;
    int skillGrade;
    void print() const {
        println("{};{};{};{}", this -> name, this -> position, this -> salary, this -> skillGrade);
    }
    void changeSalary(const float salary) {
        this -> salary = salary;
    }
    void changeSkillGrade(const int skillGrade) {
        this -> skillGrade = skillGrade;
    }
    void changePosition(const string& position) {
        this -> position = position;
    }
};
struct Firm {
    Employee employee[3];
    float averageSalary{};
    void setAverageSalary() {
        float averageSalary = 0;
        for (auto & i : employee) {
            averageSalary += i.salary;
        }
        averageSalary /= 3;
        this -> averageSalary = averageSalary;
    }
    void print() const {
        for (const auto & i : employee) {
            println("{} is {}, earns {}, with a skill grade of {}", i.name, i.position, i.salary, i.skillGrade);
        }
    }
};
class ITCompanySerializer {
    string inputFileName;
    string outputFileName;
    Firm firm;
    public:
    void setInputFileName(const string& inputFileName) {
        this -> inputFileName = inputFileName;
    }
    void setOutputFileName(const string& outputFileName) {
        this -> outputFileName = outputFileName;
    }
    void setFirm(const Firm& firm) {
        this -> firm = firm;
    }
    void read() const{
        ifstream inFile(inputFileName);
        if (!inFile.is_open()) {
            return;
        }
        Firm f;
        for (auto & i : f.employee) {
            string line;
            getline(inFile, line);
            stringstream ss(line);
            string name, position, salaryStr, skillGradeStr;
            getline(ss, name, ';');
            getline(ss, position, ';');
            getline(ss, salaryStr, ';');
            getline(ss, skillGradeStr);
            i = {name, position, stof(salaryStr), stoi(skillGradeStr)};
        }
        f.setAverageSalary();
        f.print();
        inFile.close();
    }

    void write() const {
        ofstream ofs(outputFileName, ofstream::app);
        if (!ofs.is_open()) {
            return;
        }
        for (const auto & i : firm.employee) {
            println(ofs, "{};{};{};{}", i.name, i.position, i.salary, i.skillGrade);
        }
        ofs.close();
    }
};
int main() {
    ITCompanySerializer serializer;
    serializer.setInputFileName("input.txt");
    serializer.read();
    serializer.setOutputFileName("output.txt");
    const Employee employees2[] {
        {"Angel", "Lead Software Engineer", 5000, 5},
        {"Vasil", "Software Engineer", 6000, 6},
        {"Anton", "Senior Software Engineer", 7000, 7}
    };;
    const Firm firm2{employees2[0], employees2[1], employees2[2]};
    serializer.setFirm(firm2);
    serializer.write();
}