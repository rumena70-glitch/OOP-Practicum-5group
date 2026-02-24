#include <iostream>
using namespace std;

struct imaginaryNumber {
    int real;
    int imaginary;
    void print() const {
        cout << real << " + " << imaginary << "i";
    }
};
namespace complexNumOperations {
    void sum(imaginaryNumber n1, imaginaryNumber n2) {
        int secondCollectable = n1.imaginary + n2.imaginary;
        if (secondCollectable > 0) {
            cout << n1.real + n2.real << " + " << n1.imaginary + n2.imaginary << "i" << endl;
        }
        else if (secondCollectable < 0) {
            cout << n1.real + n2.real << " - " << n1.imaginary + n2.imaginary << "i" << endl;
        }
        else {
            cout << n1.real + n2.real;
        }
    }
    void product(imaginaryNumber n1, imaginaryNumber n2) {
        int secondCollectable = n1.real * n2.imaginary - n1.imaginary * n2.real;
        if (secondCollectable > 0) {
            cout << n1.real * n2.real - n1.imaginary * n2.imaginary << " + " << n2.real << "i";
        }
        else if (secondCollectable < 0) {
            cout << n1.real * n2.real - n1.imaginary * n2.imaginary << " - " << n2.real << "i";
        }
        else {
            cout << n1.real * n2.real - n1.imaginary * n2.imaginary;
        }
    }
    void quotient(imaginaryNumber n1, imaginaryNumber n2) {
        int complexConjugate = n2.real - n2.imaginary;
        cout << (n1.real + n1.imaginary) * complexConjugate << " / " << n2.real * n2.real + n2.imaginary * n2.imaginary;

    }
}
int main() {
    //задачата не работи, не разбрах как да я направя, ако може да я обсъдим на следващия практикум
}