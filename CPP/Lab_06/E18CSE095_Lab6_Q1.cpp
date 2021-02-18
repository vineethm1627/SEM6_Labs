/*
Name: M.Vineeth
Roll: E18CSE095
Batch: EB03
*/
/*
    Names Of soldiers are stored dynamically in a list as soon
    as name=’end’ or ‘End’ is encountered, the list is done. The list is then splitted into two
    halves (Left List and Right List) till all the final list contains single element.
    Test Case 1:
    Input:
    Anil
    Mukesh
    Raj
    suresh
    ramesh
    end
    Output:
    Splitting['Anil', 'Mukesh', 'Raj', 'suresh', 'ramesh']
    Left List=['Anil', 'Mukesh'] Right List=['Raj', 'suresh', 'ramesh']
    Splitting['Anil', 'Mukesh']
    Left List=['Anil'] Right List=['Mukesh']
    Splitting['Anil']
    Splitting['Mukesh']
    Splitting['Raj', 'suresh', 'ramesh']
    Left List=['Raj'] Right List=['suresh', 'ramesh']
    Splitting['Raj']
    Splitting['suresh', 'ramesh']
    Left List=['suresh'] Right List=['ramesh']
    Splitting['suresh']
    Splitting['ramesh']
*/
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
 
void printArray(vector<string> &names, int start, int end) {
    for(int i = start; i <= end; i++)
        cout << names[i] << " ";
}

void recursiveSplit(vector<string> &names, int start, int end) {
    // base conditions
    if(end - start == 1) {
        cout << "Splitting: ";
        printArray(names, start, end);
        cout << '\n';
        cout << "Left List: " << names[start] << " ; ";
        cout << "Right List: " << names[end] << '\n';
        cout << "Splitting: " << names[start] << '\n';
        cout << "Splitting: " << names[end] << '\n';
        return;
    }
    else if(start == end) {
        cout << "Splitting: " << names[start] << '\n';
        return;
    }

    // printing the list
    cout << "Splitting: ";
    printArray(names, start, end);
    cout << '\n';
    int mid = ceil(start + (end - start) / 2.0);
    cout << "Left List: ";
    printArray(names, start, mid - 1);
    cout << "; ";
    cout << "Right List: ";
    printArray(names, mid, end);
    cout << '\n';

    // recursive calls
    recursiveSplit(names, start, mid - 1);
    recursiveSplit(names, mid, end);
    return;
}

vector<string> inputList() {
    vector<string> names;
    string name;
    cin >> name;

    while(name != "end") {
        names.push_back(name);
        cin >> name;
    }
    return names;
}
 
int main() {
 
    vector<string> names = inputList();
    cout << "-----Output-----\n";
    recursiveSplit(names, 0, names.size() - 1);

    return 0;
}