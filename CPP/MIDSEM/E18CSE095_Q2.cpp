/*
Name: M.Vineeth
Roll: E18CSE095
Batch: EB03
*/
#include <iostream>
#include <string>
using namespace std;

// function to print the matrix block
void printBlock(int **arr, int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) 
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

// function for z traversal
void zTraversal(int **arr, int r, int c) {
    cout << "Z traversal\n";
    // print the first row
    for(int i = 0; i < c; i++)
        cout << arr[0][i] << " ";
    
    // print the diagonal
    int i = 1, j = c - 2;
    while(i < r and j >= 0) {
        cout << arr[i][j] << " ";
        i++;
        j--;
    }

    // finally, print the last row
    for(int i = 1; i < c; i++) 
        cout << arr[r - 1][i] << " ";
}

// function for zig-zag traversal
void zigTraversal(int **arr, int r, int c) {
    for(int i = 0; i < r; i++) {
        // for even indexed rows, print from left to right
        if(i % 2 == 0) {
            for(int j = 0; j < c; j++)
                cout << arr[i][j] << " ";
        }
        else {
            // for odd indexed rows, print from right to left
            for(int j = c - 1; j >= 0; j--)
                cout << arr[i][j] << " ";
        }
    }
}

int main() {

    int r, c;
    cin >> r >> c;

    cin.get(); // to tackle '\n'
    string traversal;
    getline(cin, traversal);

    int **arr = new int*[r];
    for(int i = 0; i < r; i++)
        arr[i] = new int[c];
    // take the user input to fill the matrix
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) 
            cin >> arr[i][j];
    }

    // print the matrix block
    printBlock(arr, r, c);

    // conditions based on traversal type:
    if(traversal == "z" || traversal == "Z") 
        zTraversal(arr, r, c);
    else if(traversal == "zig" || traversal == "ZIG")
        zigTraversal(arr, r, c);
    else 
        cout << "Invalid choice" << endl;


    return 0;
}