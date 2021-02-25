/*
Name: M.Vineeth
Roll: E18CSE095
Batch: EB03
*/
/*
    We have three arrays:
        a. Difficulty[i] is the difficulty of the ith problem
        b. Marks[i] is the Marks of the ith problem.
        c. Student[i] is the ability of the ith student.
    The task is to figure out the maximum marks based on student’s ability. Make use of
    pointers for traversing the values in array.
    Note:
    The student can only complete a problem with difficulty at most [i].
    Every student can be assigned at most one problem, but one problem can be completed
    multiple times.
    For example, if 5 students attempt the same question of 10 mark, then the total marks will
    be 30. If a student can not attempt any problem, his/her mark is 0.
    Testcase 1
    Input:
    difficulty = [2,4,6,8,10], marks = [10,20,30,40,50], student = [4,5,6,7]
    Output:
    100
    Explanation: Students are assigned problems of difficulty [4,4,6,6] and they get marks of
    [20,20,30,30] separately.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int totalMarks(int *difficult, int *marks, int *students, int n, int m) {
    int sum = 0;
    int *dptr = difficult, *mptr = marks, *sptr = students;
    for(int i = 0; i < m; i++) {
        int index = upper_bound(difficult, difficult + n, *(sptr + i)) - difficult - 1;
        sum += *(mptr + index);
    }
    return sum;
} 
 
int main() {
   
    char ans;
    do {
        int n, m;
        cout << "Enter size of difficult array: ";
        cin >> n;
        int difficult[n], marks[n];
        cout << "Enter the difficult array elements: ";
        for(int i = 0; i < n; i++) 
            cin >> difficult[i];
        cout << "Enter the marks array elements: ";
        for(int i = 0; i < n; i++)
            cin >> marks[i];
        cout << "Enter the number of students: ";
        cin >> m;
        int students[m];
        cout << "Enter the student array elements: ";
        for(int i = 0; i < m; i++)
            cin >> students[i];
        
        cout << "total Marks: " << totalMarks(difficult, marks, students, n, m) << '\n';

        cout << "Do you want to continue?(y/n): ";
        cin >> ans; 
    }while(ans == 'y' || ans == 'Y');

    return 0;
}