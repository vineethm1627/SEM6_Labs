/*
Name: M.Vineeth
Enrol: E18CSE095
Batch: EB03
*/
/*
    (2) Write a program to find the area of Triangle, Rectangle and Sphere using function
    overloading. Call the corresponding function to find area of each shape and return the
    area to the main function and print the area of the shape in main function only. (You
    need to ask the user to input the choice i.e. which shape’s area the user wants to
    calculate, Use if – elseif – else to call the respective functions.
*/
#include <iostream>
using namespace std;

#define PI 3.14159

// area of triangle
float area(float c, float base, float height) {
    return c * base * height;
}

// area of rectangle
float area(float length, float breadth) {
    return length * breadth;
}

// area of sphere
float area(float radius) {
    return 4 * PI * radius * radius;
}

int main() {

    char ans;
    do {
        cout << "1. Triangle" << endl;
        cout << "2. Rectangle" << endl;
        cout << "3. Sphere" << endl;

        int choice;
        cout << "Enter the choice: ";
        cin >> choice;

        if(choice == 1) {
            float base, height;
            cin >> base >> height;
            cout << "area of triangle: " << area(0.5, base, height) << endl;
        }
        else if(choice == 2) {
            float length, breadth;
            cin >> length >> breadth;
            cout << "area of rectangle: " << area(length, breadth) << endl;
        }
        else {
            float radius;
            cin >> radius;
            cout << "area of sphere: " << area(radius) << endl;
        }

        cout << "Do you want to continue ? ";
        cin >> ans;

    }while(ans == 'y' || ans == 'Y');

    return 0;
}