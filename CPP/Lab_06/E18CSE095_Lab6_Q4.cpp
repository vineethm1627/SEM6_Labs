/*
Name: M.Vineeth
Roll: E18CSE095
Batch: EB03
*/
/*
    One of Judge provides a number N1 to the Brain team and asks a smallest number N2 in return such that the multiplication
    of digits of N2 is equal to N1. For example, they provide a number 36 and expect 49 from
    any member of Brain team. Suppose, one of your friend is the member of Brain team then
    write a program in Python to help your friend using modules.
    Test Case 1:
    Input: 7
    Output: 17
    Test Case 2:
    Input:36
    Output: 49
    Test Case 3:
    Input: 13
    Output: Not Possible
*/
#include <iostream>
#include <vector>
using namespace std;
 
void smallest_product(int n1) {
    if(n1 < 10) {
        cout << n1 + 10;
        return;
    }
    else {
        vector<int> factors;
        for(int i = 9; i > 1; i--) {
            while(n1 % i == 0) {
                factors.push_back(i);
                n1 /= i;
            }
        }
        if(n1 > 10)
            cout << "Not Possible";
        else {
            for(auto it = factors.rbegin(); it != factors.rend(); it++)
                cout << *it;
        }
    }
}
 
int main() {
    
    char ans;
    do {
        cout << "Enter a number: "; 
        int n1;
        cin >> n1;
        cout << "Output: ";
        smallest_product(n1);

        cout << "\nDo you want to continue(y/n): ";
        cin >> ans;
    }while(ans == 'y' or ans == 'Y');
 
    return 0;
}