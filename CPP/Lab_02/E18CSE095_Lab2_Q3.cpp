/*
Name: M.Vineeth
Enrol: E18CSE095
Batch: EB03
*/

/*
    Q)
    Write	a	program	to	find	the	factorial	of	a	number.	It	should	display	an	error	
    message	if	the	number	is	negative.	
    Example:	 
    Input	(1):	6,	Output	(1):	720
    Input	(2):	- 3,	Output	(2):	Error
    Input	(3):	1,	Output	(3):	1
*/
#include <iostream>
using namespace std;

long long int factorial(int n) {
    // factorial is not possible for negative numbers.
    if(n < 0)
        return -1;
    long long int result = 1;
    for(int i = n; i > 1; i--) {
        result *= i;
    }
    return result;
}

int main() {

    int n;
    cout << "Enter a number: ";
    cin >> n;

    if(factorial(n) != -1) {
        cout << "factorial: " << factorial(n) << endl; 
    }
    else 
        cout << "Error" << endl;

    return 0; // 0 indicates the successful termination of the program
}