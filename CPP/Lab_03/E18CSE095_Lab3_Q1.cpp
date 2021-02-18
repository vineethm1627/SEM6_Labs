/*
Name: M.Vineeth
Enrol: E18CSE095
Batch: EB03
*/
/*
    (1) Given two integers r1 and r2, representing the radius of two circles (C1 & C2),
    a. First task is to find the area of both the circles (AC1, AC2).
    b. Second is to find the radius of a new circle (C3) whose area is = AC1 + AC2.

    Sample Input: r1 = 4, r2 = 6
    Sample Output: 
    (a) AC1 = 50.265482457437, AC2 = 113.09733552923
    (b) r3 = 7.2111025509353
*/
#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14159

float area(float r) {
    return PI * r * r;
}

float findRadius(float area) {
    return sqrt(area / PI);
}

int main() {

    float r1, r2;
    cout << "enter the 2 radii: ";
    cin >> r1 >> r2;

    cout << "area of circle 1: " << area(r1) << endl;
    cout << "area of circle 2: " << area(r2) << endl;
    cout << "radius of new circle: " << findRadius(area(r1) + area(r2)) << endl;

    return 0;
}