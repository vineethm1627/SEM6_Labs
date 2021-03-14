/*
Name: M.Vineeth
Roll: E18CSE095
Batch: EB03
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// function to calculate, the minions will make it or not
bool isPossible(vector<int> &arr, int n, int handshakes) {
    // we will first sort the array
    sort(arr.begin(), arr.end());

    int min_val;
    // the loop will run for handshakes number of times
    for(int i = 0; i < handshakes; i++) {
        int index = 0;
        while(index < n && arr[index] <= 0)
            index++;
        
        // minion having the smallest value
        min_val = arr[index];
        while(index < n) {
            arr[index] -= min_val;
            index++;
        }
    }
    if(arr[n - 1] == 0)
        return true;
    else    
        return false;
}

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);
    // input array elements
    for(int i = 0; i < n; i++) 
        cin >> arr[i];
    
    int handshakes;
    cin >> handshakes;

    bool result = isPossible(arr, n, handshakes);
    if(result)
        cout << "Yes" << endl;
    else    
        cout << "No" << endl;

    return 0;
}