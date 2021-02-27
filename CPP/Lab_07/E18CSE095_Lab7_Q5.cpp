/*
Name: M.Vineeth
Roll: E18CSE095
Batch: EB03
*/
/*
    Given an array of N numbers, partition the arrays into two subarrays such that none of the
    elements of the left subarray are in the right subarray. If there are multiple partitions possible,
    then partition the array in such a way that the absolute difference between the sum of left
    subarray and sum of the right subarray is minimum. Display the absolute difference between
    the sum of both subarrays.
    Display -1 if no such partition is possible.
    Input:
    5
    4 2 4 8 9

    where:
    First line represents the number of elements in the array.
    Second line represents the elements in the array.
    Output:
    7
    Explanation: Possible partitions are:{ 4, 2, 4 },{ 8, 9 } and { 4, 2, 4, 8 },{ 9 }
    Out of the possible partitions { 4 ,2, 4 },{ 8, 9 } has least absolute difference i.e.
    |( 4 + 2 + 4 ) - ( 8 + 9 )| = 7, hence the output is 7.  
*/
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
 
int minDiffPartition(int *arr, int n) {
    int total_sum = 0;
    for(int i = 0; i < n; i++)
        total_sum += arr[i];
    
    int prefix_sum = 0, min_diff = INT_MAX;
    for(int i = 0; i < n - 1; i++) {
        prefix_sum += arr[i];
        // partition is not possible.
        if(arr[i] == arr[i + 1])
            continue;
        min_diff = min(min_diff, abs((total_sum - prefix_sum) - prefix_sum));
    } 
    return min_diff;
}
 
int main() {

    char ans;
    do {
        cout << "Enter the size of the array: ";
        int n;
        cin >> n;
        cout << "Enter the array elements: ";
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        
        sort(arr, arr + n);
        cout << minDiffPartition(arr, n) << endl;

        cout << "Do you want to continue?(y/n): ";
        cin >> ans;
    }while(ans == 'y' || ans == 'Y');

    return 0;
}