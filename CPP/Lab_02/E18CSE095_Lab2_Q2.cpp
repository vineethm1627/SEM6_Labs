/*
Name: M.Vineeth
Enrol: E18CSE095
Batch: EB03
*/

/*
    Q)
    The	BASIC Salary	of	an	employee	is	provided.	Write	a	program	to	find	the	Gross	
    Salary	(BASIC	+	DA%	of	BASIC	+	HRA%	of	BASIC)	of	the	employee.
    Example:
    Input	(1):	BASIC	=	20000,	DA	=	17%,	HRA	=	20%	
    Output	(1):	Gross	Salary	=	27400
*/
#include <iostream>
using namespace std;

int main() {

    float BASIC, DA, HRA;
    cout << "Enter the BASIC: ";
    cin >> BASIC;

    cout << "Enter the DA %: ";
    cin >> DA;

    cout << "Enter the HRA %: ";
    cin >> HRA;

    float grossSalary = BASIC * (1 + (DA + HRA) / 100);
    cout << "Gross Salary: " << grossSalary << endl;

    return 0; // 0 indicates the successful termination of the program
}