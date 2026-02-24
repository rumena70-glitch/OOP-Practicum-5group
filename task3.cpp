#include <iostream>
using namespace std;

struct Triangle {
    double a;
    double b;
    double c;
    double getFace() const {
        double p = (a + b + c) / 2;
        double s = sqrt(p * (p - a) * (p - b) * (p - c));
        return s;
    }
};
void bubbleSort(double* arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    int n;
    cin >> n;
    Triangle* t = new Triangle[n];
    for (int i = 0; i < n; i++) {
        cin >> t[i].a;
        cin >> t[i].b;
        cin >> t[i].c;
    }
    double* faces = new double[n];
    for (int i = 0; i < n; i++) {
        faces[i] = t[i].getFace();
    }
    bubbleSort(faces, n);
    for (int i = 0; i < n; i++) {
        cout << "Triangle " << i + 1 << ": " << faces[i] << endl;
    }
    delete[] t;
    delete[] faces;
}