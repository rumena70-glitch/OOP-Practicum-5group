#include <iostream>
using namespace std;

namespace passCheck {
    bool hasUppercase(const string& password) {
        size_t n = password.length();
        for (size_t i = 0; i < n; i++) {
            if (password[i] >= 'A' && password[i] <= 'Z') {
                return true;
            }
        }
        return false;
    }
    bool hasLowercase(const string& password) {
        size_t n = password.length();
        for (size_t i = 0; i < n; i++) {
            if (password[i] >= 'a' && password[i] <= 'z') {
                return true;
            }
        }
        return false;
    }
    bool hasNumbers(const string& password) {
        size_t n = password.length();
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
    public:
        string name;
        string facultyNumber;
    bool validPasswordCheck() const {
        using namespace passCheck;
        return hasUppercase(password) && hasLowercase(password) && hasNumbers(password) && isValidLength(password);
    }
    void printInfo() const {
        cout << "Student name: " << name << ", Faculty number: " << facultyNumber << endl;
    }
    void setPassword() {
        if (password.empty()) {
            cout << "Enter password: " ;
            cin >> password;
            if (validPasswordCheck()) {
                cout << "Successfully set password!" << endl;
            }
            else {
                cout << "Unsuccessful password set, password didn't meet requirements!" << endl;
            }
        }
        else {
            cout << "Password is already set!" << endl;
        }
    }
    void changePassword() {
        string oldPassword;
        cout << "Enter old password: ";
        cin >> oldPassword;
        if (oldPassword != password) {
            cout << "Incorrect old password!" << endl;
            return;
        }
        cout << "Enter new password: ";
        cin >> password;
        if (validPasswordCheck()) {
            cout << "Successfully changed password!" << endl;
        }
        else {
            cout << "Unsuccessful password change, new password didn't meet requirements!" << endl;
            password = oldPassword;
        }
    }
    private:
        string password;
};
int main() {
    Student student;
    cin >> student.name;
    cin >> student.facultyNumber;
    student.setPassword();
    student.changePassword();
    student.printInfo();
}