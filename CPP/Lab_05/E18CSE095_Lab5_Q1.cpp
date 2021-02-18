/*
Name: M.Vineeth
Enrol: E18CSE095
Batch: EB03 
*/
/*
    Given a two dimensional matrix, you have to traverse the matrix in a hypothetical
    traversal way and display the numbers present in the corresponding location (see
    example below for better clarity). The matrix need not be a square matrix.
    Sample Input (1):
    1 2 3 4
    5 6 7 8
    9 10 11 12
    13 14 15 16
    Sample Output (1): 1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10
*/
#include <iostream>
using namespace std;
 
void spiralPrint(int **matrix, int r, int c) {
    int sr = 0, sc = 0;
    int er = r - 1, ec = c - 1;

    while(sr <= er and sc <= ec) {
        // start row
        for(int j = sc; j <= ec; j++)
            cout << matrix[sr][j] << " ";
        sr++;

        // end column
        for(int i = sr; i <= er; i++)
            cout << matrix[i][ec] << " ";
        ec--;

        // end row
        if(sr < er) {
            for(int j = ec; j >= sc; j--) 
                cout << matrix[er][j] << " ";
            er--;
        }

        // start column
        if(sc < ec) {
            for(int i = er; i >= sr; i--)
                cout << matrix[i][sc] << " ";
            sc++;
        }
    }
}
 
int main() {
    
    char ans;
    do {
        int r, c;
        cout << "Enter rows and columns: ";
        cin >> r >> c;

        int **matrix = new int*[r];
        for(int i = 0; i < r; i++)
            matrix[i] = new int[c];
        
        cout << "Enter the matrix elements: " << endl;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++)
                cin >> matrix[i][j];
        }

        cout << "spiral order print: " << endl;
        spiralPrint(matrix, r, c);
        cout << endl;
        cout << "Do you want to continue ? (y/n): ";
        cin >> ans;

    }while(ans == 'y' or ans == 'Y');

    return 0;
}