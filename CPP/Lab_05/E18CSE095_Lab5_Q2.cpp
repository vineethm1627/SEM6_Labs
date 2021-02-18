/*
Name: M.Vineeth
Enrol: E18CSE095
Batch: EB03 
*/
/*
    Write a program to implement following encryption-decryption algorithm.
    a. Alice wants to share some secret numeric data with Bob which is in the form of a
    2D array. But to save its data from attacker Alice adopts the following encryption
    algorithm to encrypt the 2D numerical data array.
    • The outer elements of the 2D array should be incremented by i+1.
    • The inner elements of array should be decrement by j.
    Here, i and j are the row and column numbers of the 2D array.
    Your task is to Print the encrypted matrix.
    b. Similarly, when Bob will receive the encrypted matrix, he should be able to
    decrypt the encrypted matrix to get back the original numeric data represented in
    matrix format. Your task is to find the equivalent decryption algorithm.

    Sample Input for (a):
    1 1 1 1
    1 1 1 1
    1 1 1 1
    Sample Output for (a):
    2 2 2 2
    3 0 -1 3
    4 4 4 4

*/
#include <iostream>
using namespace std;

void printMatrix(int **arr, int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

void encrypt(int **arr, int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            // outer elements
            if(i == 0 or i == r - 1 or j == 0 or j == c - 1)
                arr[i][j] += i + 1;
            // inner elements
            else   
                arr[i][j] -= j;
        }
    }
}
 
void decrypt(int **arr, int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            // outer elements
            if(i == 0 or i == r - 1 or j == 0 or j == c - 1)
                arr[i][j] -= (i + 1);
            // inner elements
            else   
                arr[i][j] += j;
        }
    }
}

int main() {
    
    char ans;
    int r,c;
    cout << "Enter rows and columns: ";
    cin >> r >> c;

    int **arr = new int*[r];
    for(int i = 0; i < r; i++)
        arr[i] = new int[c];
    
    cout << "Enter the matrix elements: " << endl;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++)
            cin >> arr[i][j];
    }

    do {

        cout << "1. Encrypt" << endl;
        cout << "2. Decrypt" << endl;
        cout << "3. Print Matrix" << endl;

        cout << "Select one option: ";
        int choice;
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Matrix Encrypted successfully" << endl;
                encrypt(arr, r, c);
                break;
            
            case 2:
                cout << "Matrix Decrypted successfully" << endl;
                decrypt(arr, r, c);
                break;
            
            case 3: 
                printMatrix(arr, r, c);
                break;
            default:
                cout << "Enter a valid option!" << endl;
        }


        cout << "Do you want to continue? (y/n): ";
        cin >> ans;

    }while(ans == 'y' or ans == 'Y');
 
    return 0;
}