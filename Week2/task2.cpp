#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

namespace passCheck {
    bool hasUppercase(const string& password) {
        const size_t n = password.length();
        for (size_t i = 0; i < n; i++) {
            if (password[i] >= 'A' && password[i] <= 'Z') {
                return true;
            }
        }
        return false;
    }
    bool hasLowercase(const string& password) {
        const size_t n = password.length();
        for (size_t i = 0; i < n; i++) {
            if (password[i] >= 'a' && password[i] <= 'z') {
                return true;
            }
        }
        return false;
    }
    bool hasNumbers(const string& password) {
        const size_t n = password.length();
        for (size_t i = 0; i < n; i++) {
            if (password[i] >= '0' && password[i] <= '9') {
                return true;
            }
        }
        return false;
    }
    bool isValidLength(const string& password) {
        return password.length() >= 8;
    }
}
class Student {
    string name;
    string facultyNumber;
    string password;
    bool validPasswordCheck(const string& password) const {
        using namespace passCheck;
        return hasUppercase(password) && hasLowercase(password) && hasNumbers(password) && isValidLength(password);
    }
    public:
    string getName() const {
        return this -> name;
    }
    string getFacultyNumber() const {
        return this -> facultyNumber;
    }
    string getPassword() const {
        return this -> password;
    }
    bool setName(const string& name) {
        if (!name.empty() && this -> name.empty()) {
            this -> name = name;
            return true;
        }
        return false;
    }
    bool setFacultyNumber(const string& facultyNumber) {
        if (!facultyNumber.empty() && this -> facultyNumber.empty()) {
            this -> facultyNumber = facultyNumber;
            return true;
        }
        return false;
    }
    bool setPassword(const string& password) {
        if ((this -> password).empty() && validPasswordCheck(password)) {
            this -> password = password;
            return true;
        }
        return false;
    }
    bool changePassword(const string& oldPassword, const string& newPassword) {
        if (oldPassword != this -> password) {
            return false;
        }
        if (validPasswordCheck(newPassword)) {
            this -> password = newPassword;
            return true;
        }
        return false;
    }
    void printInfo() const {
        println("{};{};{}", this -> name, this -> facultyNumber, this -> password);
    }
};
class StudentSerializer {
    string inputFileName;
    string outputFileName;
    Student student;
    public:
    void setInputFileName(const string& inputFileName) {
        this -> inputFileName = inputFileName;
    }
    void setOutputFileName(const string& outputFileName) {
        this -> outputFileName = outputFileName;
    }
    void setStudent(const Student& student) {
        this -> student = student;
    }
    void read() const{
        ifstream inFile(inputFileName);
        if (!inFile.is_open()) {
            return;
        }
        while (!inFile.eof()) {
            Student s;
            string line;
            getline(inFile, line);
            stringstream ss(line);
            string name, facultyNumber, password;
            getline(ss, name, ';');
            getline(ss, facultyNumber, ';');
            getline(ss, password);
            s.setName(name);
            s.setFacultyNumber(facultyNumber);
            s.setPassword(password);
            s.printInfo();
        }
        inFile.close();
    }

    void write() const {
        ofstream ofs(outputFileName, ofstream::app);
        if (!ofs.is_open()) {
            return;
        }
        println(ofs, "{};{};{}", student.getName(), student.getFacultyNumber(), student.getPassword());
    }
};;
int main() {
    StudentSerializer serializer;
    serializer.setInputFileName("studentInput.txt");
    serializer.read();
    Student student;
    student.setName("Ivana Ivanova");
    student.setFacultyNumber("9Mi0600120");
    student.setPassword("Ivanan67");
    serializer.setOutputFileName("studentOutput.txt");
    serializer.setStudent(student);
    serializer.write();
}