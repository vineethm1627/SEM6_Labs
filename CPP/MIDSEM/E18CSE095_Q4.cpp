/*
Name: M.Vineeth
Roll: E18CSE095
Batch: EB03
*/
#include <iostream>
using namespace std;

// function to calculate final tokens won
int winTokens(string s, int n) {
    int balance = 100, bet = 10, count = 0;
    bool flag = false;

    while(balance >= 0 and count < n) {
        if(s[count] == '1') {
            balance += bet;
            bet = 10;
        }
        else {
            balance -= bet;
            bet *= 2;
            if(bet > balance) {
                flag = true;
                break;
            }
        }
        count++;
    }
    
    // final condition checks
    if(balance <= 0 or flag)
        return -1;

    return balance;
}

int main() {

    int n;
    cin >> n;
    cin.get(); // to tackle '\n'
    string s;
    cin >> s;

    int result = winTokens(s, n);
    cout << result << endl;

    return 0;
}