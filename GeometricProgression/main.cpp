#include <iostream>

#include "GeometricProgression.h"
using namespace std;

int main() {
    const GeometricProgression p1(1, 2);
    const GeometricProgression p2(1, 3);
    const GeometricProgression p3 = p1 + p2;
    const GeometricProgression p4 = p1 * p2;
    for (int i = 0; i < 5; i++) {
        println("{}", p3[i]);
    }
    println();
    for (int i = 0; i < 5; i++) {
        println("{}", p4[i]);
    }
    println();
    for (int i = 0; i < 5; i++) {
        println("{}", p1(i));
    }
}