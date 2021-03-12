/*
Name: M.Vineeth
Roll: E18CSE095
Batch: EB03
*/
/*
    Given a Student class, create a class with following characteristics 
    • The class name should be ClassRoom. 
    • Private variable students to maintain the list of Student objects. 
    • Function addStudent with input parameter name (string) and rollNo(int) adds a new student in “students” list. 
    • Method getAllStudents should return all the students in ClassRoom.
*/
#include <iostream>
#include <vector>
using namespace std;

class Student {
    int roll_num;
    string name;
    public:
        Student() { 

        }

        Student(int roll_num, string name) {
            this->roll_num = roll_num;
            this->name = name;
        }

        // this function can access the private members of the class
        friend class ClassRoom;
};

class ClassRoom {
        vector<Student> students;
    public:
        void addStudent(int roll_num, string name) {
            Student s(roll_num, name);
            students.push_back(s);
        }

        void getAllStudents() {
            if(students.empty())
                cout << "No students in the Classroom !" << endl;
            else {
                for(auto p : students)
                    cout << p.roll_num << " - " << p.name << endl;
            }
        }
};
 
int main() {
    ClassRoom cr;
    string name;
    int roll_num;
    while(cin) {
        getline(cin, name);
        cin >> roll_num;
        cr.addStudent(roll_num, name);
        cin.get(); // to tackle '\n'
    }

    cr.getAllStudents();
 
    return 0;
}