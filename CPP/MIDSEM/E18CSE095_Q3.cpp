/*
Name: M.Vineeth
Roll: E18CSE095
Batch: EB03
*/
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// function to find max number of thieves caught
int catchMax(char *arr, int n, int k) {
    int count = 0;
    vector<int> thief, spy;

    // we need to store the indices in the vector
    for(int i = 0; i < n; i++) {
        if(arr[i] == 'S')
            spy.push_back(i);
        else if(arr[i] == 'T')
            thief.push_back(i);
    }

    // we now apply two pointer approach
    int left = 0, right = 0;
    while(left < thief.size() && right < spy.size()) {
        // if the thief can be caught
        if(abs(spy[right] - thief[left]) <= k) {
            count++;
            right++;
            left++;
        }
        else if(thief[left] < spy[right])
            left++;
        else    
            right++;
    }
    return count;
}

int main() {

    int players, search_range;
    cin >> players >> search_range;
    cin.get(); // to tackle '\n'

    char arr[players];
    for(int i = 0; i < players; i++)
        cin >> arr[i];
    
    int result = catchMax(arr, players, search_range);
    cout << result << endl;

    return 0;
}