/*
Name: M.Vineeth
Roll: E18CSE095
Batch: EB03
*/
/*
    Write a C++ program to store the customer details such as name and numbers as members and allocates the memory for the noofcustomers of the structure variable dynamically using new operator.
*/
#include <iostream>
#include <string>
using namespace std;

struct customers {
    string name;
    long int number;
};

int main() {

    int num_customers;
    cin >> num_customers;
    cin.get();
    customers *cs = new customers[num_customers];
    
    for(int i = 0; i < num_customers; i++) {
        string name;
        getline(cin, (cs + i)->name);
        cin >> (cs + i)->number;
        cin.get(); // to tacke '\n'
    }
    
    cout << "Displaying output: \n";
    customers *end = cs + num_customers;
    for(customers *ptr = cs; ptr != end; ptr++)
        cout << ptr->name << " " << ptr->number << endl;

    return 0;
}