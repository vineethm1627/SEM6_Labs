/*
Name: M.Vineeth
Enrol: E18CSE095
Batch: EB03
*/
/*
    (2) One array is provided to you where each location has one pair of elements. Let us
    suppose that (w,x) and (y,z) are two such pairs. You have to write a C++ program to find
    total number of such pairs of the form
    a. w<y and x>z
    b. w>y and x<z
    Also, find display the pair of elements.
    NOTE: If such pair of elements are not available display ”NOT FOUND”.

    Sample Input: A[] = {(1,4), (3,2), (5,6), (7,8), (9,10), (13, 12), (11, 14)}
    Sample Output: (a) 1 : (1,4), (3,2)
    (b) 1: (13, 12), (11, 14)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, a, b;
    cout << "enter the number of pairs: ";
    cin >> n;
    vector<pair<int, int>> p(n), result1, result2;
    
    cout << "enter the pair elements: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        p[i] = make_pair(a, b);
    }
    cout << endl;

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            // condition: (w, x) (y, z) ==> w < y and x > z
            if(p[i].first < p[j].first and p[i].second > p[j].second) {
                result1.push_back(p[i]);
                result1.push_back(p[j]);
            }
            // condition: (w, x) (y, z) ==> w >y and x < z
            else if(p[i].first > p[j].first and p[i].second < p[j].second) {
                result2.push_back(p[i]);
                result2.push_back(p[j]);
            }
        }
    }    

    // printing the final result
    cout << "condition 1: " << endl;
    if(!result1.empty()) {
        for(int i = 0; i < result1.size(); i += 2) {
            cout << "(" << result1[i].first << "," << result1[i].second << ") , ";
            cout << "(" << result1[i + 1].first << "," << result1[i + 1].second << ")" << endl; 
        }
    }
    else 
        cout << "NOT FOUND" << endl;

    cout << "condition 2: " << endl;
    if(!result2.empty()) {
        for(int i = 0; i < result2.size(); i += 2) {
            cout << "(" << result2[i].first << "," << result2[i].second << ") , ";
            cout << "(" << result2[i + 1].first << "," << result2[i + 1].second << ")" << endl; 
        }
    }
    else 
        cout << "NOT FOUND" << endl;

    return 0;
}