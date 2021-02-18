/*
Name: M.Vineeth
Enrol: E18CSE095
Batch: EB03 
*/
/*
    Given a string S, character C1 and C2 as input, replace all the occurrences of the given
    character C1 with C2 in the given string S. Do not use any system library function to
    solve the problem and ignore the case.
    Sample Input:
    Bennett University
    n
    x
    Sample Output:
    Bexxett Uxiversity
    Sample Input:
    Times of India
    i
    j
    Sample Output:
    Times of Jndja
*/
#include <iostream>
#include <cstring>
using namespace std;

string replace(string str, char c1, char c2) {
    for(int i = 0; str[i]; i++) {
        if(tolower(str[i]) == c1)
            str[i] = c2;
    }
    return str;
} 
 
int main() {
 
    char ans;
    do {
        string str;
        char c1, c2;
        cout << "Enter the string: ";
        getline(cin, str);
        cout << "Enter char1 and char2: ";
        cin >> c1 >> c2;

        cout << replace(str, c1, c2) << endl;

        cout << "Do you want to continue ? (y/n): ";
        cin >> ans;
        cin.get(); // to take "\n"

    } while(ans == 'y' or ans == 'Y');
    
 
    return 0;
}