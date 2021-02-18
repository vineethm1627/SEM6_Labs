/*
Name: M.Vineeth
Enrol: E18CSE095
Batch: EB03
*/

/*
    Q)
    An integer N is	given. Write a program to find the square and cube of the integer	
    N.	(Range of N lies between -100 and +100,	both the numbers are included)
    Example:	 
    Input	(1):	5,	Output	(1):	25,	125
    Input	(2):	-5,	Output	(2):	25,	-125
    Input	(3):	1,	Output	(3):	1,	1
*/
#include <iostream>
using namespace std;

int main() {

    cout << "Enter the number: ";
    int n;
    cin >> n;

    int square = n * n;
    int cube = square * n;

    cout << "square: " << square << endl;
    cout << "cube: " << cube << endl;

    return 0; // 0 indicates the successful termination of the program
}