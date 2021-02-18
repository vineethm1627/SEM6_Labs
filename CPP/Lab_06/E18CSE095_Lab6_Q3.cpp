/*
Name: M.Vineeth
Roll: E18CSE095
Batch: EB03
*/
/*
    In a class, ‘N’ students are asked to bring number of dishes as per their roll numbers, for
    instance roll number 1 will bring 1 item, roll number 2 will bring 2 items, roll number 3 will
    get 3 items and so on. Write the function to get the total number of items brought by “N”
    students.
    Testcase 1
    Input:
    7
    Output:
    28
*/
#include <iostream>
using namespace std;
 
int main() {
    
    int n;
    cin >> n;

    cout << "Total items brought: " << n*(n + 1) / 2 << '\n';
 
    return 0;
}