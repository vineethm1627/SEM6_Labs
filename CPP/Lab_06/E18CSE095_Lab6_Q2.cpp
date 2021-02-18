/*
Name: M.Vineeth
Roll: E18CSE095
Batch: EB03
*/
/*
    Given an array of N distinct elements, find the minimum number of swaps required to sort the array in non-descreasing order.
    Testcase1
    Input:
    4
    4 3 2 1
    where:
    • First line represents the number of elements in the array.
    • Second line represents the elements in the array.
    Output:
    2
    Explanation: Swap elements at index 0 with 3 and 1 with 2 to form the sorted array {1, 2, 3,
    4}.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minSwaps(int *arr, int n) {
    int count = 0;
    vector<pair<int, int>> v(n); // {element, index}
    for(int i = 0; i < n; i++) 
        v[i] = make_pair(arr[i], i);
    
    sort(v.begin(), v.end()); // sort on the basis of array element
    for(int i = 0; i < n; i++) {
        if(v[i].second == i)
            continue;
        else {
            swap(v[i].first, v[v[i].second].first);
            swap(v[i].second, v[v[i].second].second);
        }

        // swap unless the correct index matches
        if(v[i].second != i)
            --i;
        count++;
    }
    return count;
}
 
int main() {
    
    char ans;
    do {
        cout << "Enter the array size: ";
        int n;
        cin >> n;
        int arr[n];
        cout << "Enter the array elements: \n";
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        cout << "min swaps: " << minSwaps(arr, n) << '\n'; 
        cout << "Do you want to continue(y/n): ";
        cin >> ans;
    }while(ans == 'y' or ans == 'Y');

    return 0;
}