/*
Name: M.Vineeth
Roll: E18CSE095
Batch: EB03
*/
/*
    Given two integers, find the described solution of the integers(use reference variable).
    Write a function:
    double * ProblemSolution :: solution(int N1, int N2)
    that accepts two integers and return the reference to the variable holding:
    a*20+34/b
    Input:
    5
    10
    Where,
    • First line represents integer N1.
    • Second line represents integer N2.
    Output:
    103.40
*/
#include <iostream>
using namespace std;
 
double* solution(int n1, int n2) {
    double *result = new double;
    *result = n1 * 20 + 34.0 / n2;
    return result;
} 
 
int main() {

    char ans;
    do {
        cout << "Enter the 2 numbers: ";
        int n1, n2;
        cin >> n1 >> n2;

        double *result = solution(n1, n2);
        cout << "Output: " << *result << '\n';

        cout << "Do you want to continue?(y/n): ";
        cin >> ans;
    }while(ans == 'y' || ans =='Y');
 
    return 0;
}