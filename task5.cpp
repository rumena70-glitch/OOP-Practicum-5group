#include <iostream>
using namespace std;

struct Point {
    double x;
    double y;
    void print() const {
        cout << "x = " << x << ", y = " << y << endl;
    }
    double findDistanceFromCentre() const {
        return sqrt(x * x + y * y);
    }
    double findDistanceFromPoint(const Point& otherPoint) const {
        return sqrt((x - otherPoint.x) * (x - otherPoint.x) + (y - otherPoint.y) * (y - otherPoint.y));
    }
    int quadrant() const {
        if (x > 0) {
            if (y > 0) {
                return 1;
            }
            if (y < 0) {
                return 4;
            }
        }
        else if (x < 0) {
            if (y > 0) {
                return 2;
            }
            if (y < 0) {
                return 3;
            }
        }
        return 0;
    }
};
int main() {
    Point p{-3, -4};
    Point q{6, 8};
    cout << p.findDistanceFromCentre() << endl;
    cout << p.findDistanceFromPoint(q) << endl;
    cout << p.quadrant() << endl;
    cout << q.quadrant() << endl;
}