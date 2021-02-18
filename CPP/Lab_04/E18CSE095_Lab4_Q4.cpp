/*
Name: M.Vineeth
Enrol: E18CSE095
Batch: EB03
*/
/*
    We can store a 2D 10 x 10 square matrix in a 1D array of size 100 by sequentially writing
    each row one after another. Now, it is also given that the (i, j)-th element is equal to the
    (j, i)-th element of the 2D matrix for all i and j. This means that the given matrix is a
    symmetrical matrix around its diagonal.
    Now, you write a program to perform the above operation and based on the user’s
    choice do the first solution or the second solution. And subsequently, take the 2D matrix
    as input. And finally display the corresponding 1D matrix. 
*/
#include <iostream>
using namespace std;

void printArray(int *arr, int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int* lower_triangle(int **arr, int n) {
    int *result = new int[n*(n+1) / 2];
    int index = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i + 1; j++) 
            result[index++] = arr[i][j];
    }
    return result;
}

int *upper_triangle(int **arr, int n) {
    int *result = new int[n*(n+1) / 2];
    int index = 0;
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < j + 1; i++) 
            result[index++] = arr[i][j];
    }
    return result;
}

int main() {

    char ans;
    do {
        cout << "Symmetric Matrix Print Operations" << endl;
        cout << "1. Lower Triangle" << endl;
        cout << "2. Upper Triangle" << endl;

        int choice;
        cout << "Enter the choice: ";
        cin >> choice;

        int n; // number of rows and columns in the symmetric matrix
        cout << "enter the value of n: ";
        cin >> n;
        int **matrix = new int*[n];

        for(int i = 0; i < n; i++)
            matrix[i] = new int[n];

        cout << "Enter the matrix elements: " << endl;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
                cin >> matrix[i][j];
        }

        if(choice == 1) {
            cout << "lower triangle: " << endl;
            int *result = lower_triangle(matrix, n);
            printArray(result, n*(n+1) / 2);
        }
        else if(choice == 2){
            cout << "upper triangle: " << endl;
            int *result = upper_triangle(matrix, n);
            printArray(result, n*(n+1) / 2);
        }
        else {
            cout << "Enter a valid choice!" << endl;
        }

        cout << "Do you want to continue? : ";
        cin >> ans;

    }while(ans == 'y' || ans == 'Y');


    return 0;
}