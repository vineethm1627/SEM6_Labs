/*
Name: M.Vineeth
Roll: E18CSE095
Batch: EB03
*/
/*
Given a matrix M of R rows and C columns, find the maximum sum of an hourglass in a matrix.
An hour-glass is made of 7 cells in the following form.
A B C
 D
E F G
It is evident from above that to find hour-glass the number of rows and number of columns in
a matrix must be greater than or equal to 3.
In a matrix total number of hour-glasses is (R-2)*(C-2).

Input:
 5
 5
 1 1 1 0 0
 0 1 0 0 0
 1 1 1 0 0
 0 0 0 0 0
 0 0 0 0 0

Output:
 7
*/
#include <iostream>
#include <climits>
using namespace std;

// returns sum of the hour glass matrix with m[i][j] as the top left element
int matrixSum(int **m, int i, int j) {
    int sum = m[i][j] + m[i][j+1] + m[i][j+2] + m[i+1][j+1];
    sum += m[i+2][j] + m[i+2][j+1] + m[i+2][j+2];
    return sum;
}
 
int maxHourGlassSum(int **matrix, int r, int c) {
    // base case
    if(r < 3 or c < 3)
        return -1;
    
    int max_sum = INT_MIN;
    for(int i = 0; i < r - 2; i++) {
        for(int j = 0; j < c - 2; j++)
            max_sum = max(max_sum, matrixSum(matrix, i, j));
    }
    return max_sum;
}
 
int main() {

    char ans;
    do {
        cout << "Enter rows and columns: ";
        int r, c;
        cin >> r >> c;
        cout << "Enter the matrix elements: \n";
        int **matrix = new int*[r];
        for(int i = 0; i < r; i++)
            matrix[i] = new int[c];
        
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++)
                cin >> matrix[i][j];
        }

        int sum = maxHourGlassSum(matrix, r, c);
        if(sum != -1) 
            cout << "max hour glass sum: " << sum << '\n';
        else 
            cout << "Not Possible \n";

        cout << "Do you want to continue(y/n): ";
        cin >> ans;
    }while(ans == 'y' or ans == 'Y');

    return 0;
}