/*
Name: M.Vineeth
Roll: E18CSE095
Batch: EB03
*/
/*
Define a class Employee with 
• data members as 
    o int employee_id – To store employee ID. 
    o String employee_name – To store the name of the employee. 
    o String designation – To store employee designation. 
    o double monthly_salary – To store salary of the employee. 
• Methods
    o void display() – To display details of employees whose earning is more than 20,000.
*/
#include <iostream>
#include <iomanip>
using namespace std;
 
class Employee {
        int employee_id;
        string employee_name;
        string designation;
        double monthly_salary;
    public:
        Employee(int id, string name, string designation, double salary) {
            employee_id = id;
            employee_name = name;
            this->designation = designation;
            monthly_salary = salary;
        }

        void display() {
            if(monthly_salary > 20000) {
                cout << employee_id << " " << employee_name << " " << designation << " "; 
                cout << fixed << setprecision(1) << monthly_salary << endl;
            }
        }
}; 
 
int main() {
    
    int T;
    cin >> T;

    string name, designation;
    int id;
    double salary;
    Employee *emp[T];
    for(int i = 0; i < T; i++) {
        cin >> id;
        cin.get(); // to tackle '\n'
        getline(cin, name);
        getline(cin, designation);
        cin >> salary;
        emp[i] = new Employee(id, name, designation, salary);
    }

    cout << "Output: \n";
    for(int i = 0; i < T; i++) 
        emp[i]->display();
 
    return 0;
}