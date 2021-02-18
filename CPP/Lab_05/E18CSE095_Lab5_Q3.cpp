/*
Name: M.Vineeth
Enrol: E18CSE095
Batch: EB03 
*/
/*
    Here, your task is to create an overloaded function called "compare" using function
    overloading which accepts two values of same type (either integer, character or String).

    In input, first line of input represents the type of function to call on the basis of
    arguments passed as 1 for integer, 2 for character and 3 for the string. Second and Third
    lines represent N1 and N2 respectively.
    Sample Input:
    1
    215
    215
    Sample Output:
    0
    Sample Input:
    3
    Hello
    Good
    Sample Output:
    -1
*/
#include <iostream>
using namespace std;

template<class T>
int compare(T a, T b) {
    if(a > b)
        return 1;
    else if(a < b)
        return -1;
    return 0;
}

// template specialization to compare strings based on length
template<>
int compare<string>(string a, string b) {
    if(a.size() > b.size())
        return 1;
    else if(a.size() < b.size())
        return -1;
    return 0;
}

 
int main() {
    
    char ans;
    do {
        cout << "Overloaded Compare Function" << endl;
        cout << "1. Integers" << endl;
        cout << "2. Characters" << endl;
        cout << "3. Strings" << endl;
        cout << "Select one option: ";
        int choice;
        cin >> choice;

        switch(choice) {
            case 1: {
                cout << "Enter the 2 numbers: ";
                int n1, n2;
                cin >> n1 >> n2;
                cout << "result: " << compare<int>(n1, n2) << endl;
                break;
            }
            
            case 2: {
                cout << "Enter the 2 characters: ";
                char a, b;
                cin >> a >> b;
                cout << "result: " << compare<char>(a, b) << endl;
                break;
            }
            
            case 3: {
                cout << "Enter 2 strings: ";
                string s1, s2;
                cin >> s1 >> s2;
                cout << "result: " << compare<string>(s1, s2) << endl;
                break;
            }
            default: {
                cout << "Enter a valid option!" << endl;
                break;
            }
        }
        cout << "Do you want to continue? (y/n): ";
        cin >> ans;

    }while(ans == 'y' or ans =='Y');

    return 0;
}
