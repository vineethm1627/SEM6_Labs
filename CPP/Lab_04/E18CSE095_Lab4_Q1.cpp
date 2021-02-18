/*
Name: M.Vineeth
Enrol: E18CSE095
Batch: EB03
*/
/*
    (1) Given two positive integer arrays A[] and B[].
        a. First task is to find all possible pair wise sum and store in an array C[].
        b. Second is to find the bitwise xor of all pairs of elements present in array C[] and
        print the maximum among them (MAXPair).

    Sample Input: A[] = {1,2}, B[] = {3,4}
    Sample Output: (a) C[] = {4, 5, 5, 6}, (b) MAXPair = 3
*/
#include <iostream>
#include <climits>
using namespace std;

// find pair wise sum of array elements
int* pair_sum(int *A, int m, int *B, int n) {
    int *C = new int[m * n]; 
    int index = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            C[index++] = A[i] + B[j];
    }
    return C;
}

int max_xor(int *arr, int n) {
    // 0 ^ a = a
    // 1 ^ a = ~a
    int result = INT_MIN;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            result = max(result, arr[i] ^ arr[j]);
        }
    }
    return result;
}

int main() {

    int n, m;
    cin >> m;

    int A[m];
    for(int i = 0; i < m; i++)
        cin >> A[i];
    
    cin >> n;

    int B[n];
    for(int i = 0; i < n; i++)
        cin >> B[i];
    
    // part: a find the pair wise sum of array elements
    int *C = pair_sum(A, m, B, n);
    cout << "pair sum: ";
    for(int i = 0; i < m * n; i++)
        cout << C[i] << " ";
    
    cout << endl << "max xor value: ";
    cout << max_xor(C, m * n) << endl;

    return 0;
}