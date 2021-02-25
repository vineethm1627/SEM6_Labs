/*
Name: M.Vineeth
Roll: E18CSE095
Batch: EB03
*/
/*
    You need a picture frame of Amitabh Bacchan, so you walk down to the local photo store
    to examine their collection. They have all of their frames lined up against the wall. Apply
    the linear search algorithm to this problem, and describe how you would find the frame
    you wanted. Starting at the first frame, examine each frame along the wall (without
    skipping any) until you find the frame you want. Use the pointer for traversing the
    elements in char array.
    Test Case 1:
    Input:
    Anil
    Dev
    Raj
    Sanjeev
    Amitabh
    Dharmendra
    Output:
    Present at number 5
*/
#include <iostream>
#include <cstring>
using namespace std;
 
// pointer traversal of the array.
void presence(char arr[][1000], int n) {
    char (*ptr)[1000] = arr;
    bool flag = false;
    for(int i = 0; i < n; i++) {
        if(strcmp(*(ptr + i), "Amitabh") == 0) {
            cout << "Present at number: " << (i+1) << '\n';
            flag = true;
        }
    }
    if(!flag)
        cout << "Not present";
}
 
int main() {
    
    int n;
    cin >> n;
    cin.get();
    char arr[n][1000];

    for(int i = 0; i < n; i++) 
        cin.getline(arr[i], 1000);
    
    presence(arr, n);
    
    return 0;
}