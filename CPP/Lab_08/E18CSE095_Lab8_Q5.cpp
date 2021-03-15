/*
Name: M.Vineeth
Roll: E18CSE095
Batch: EB03
*/
/*
    Wildcard Pattern Matching
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isMatch(string s, string p) {
    int s_len = s.size(), p_len = p.size();
    vector<vector<bool>> dp(s_len + 1, vector<bool>(p_len + 1, false));

    // base case
    dp[0][0] = true;

    // fill the first row
    for(int i = 1; i <= p_len; i++) {
        if(p[i - 1] == '*')
            dp[0][i] = dp[0][i - 1];
    }

    // fill the remaining rows
    for(int i = 1; i <= s_len; i++) {
        for(int j = 1; j <= p_len; j++) {
            if(s[i - 1] == p[j - 1] || p[j - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if(p[j - 1] == '*')
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
        }
    }
    return dp[s_len][p_len];
}

int main() {
    char ans;
    string s, p;
    do {
        cout << "Enter string: ";
        cin >> s;
        cout << "Enter pattern: ";
        cin >> p;

        if(isMatch(s, p))
            cout << "Match found" << endl;
        else    
            cout << "No match found" << endl;

        cout << "Do you want to continue ?(y/n): ";
        cin >> ans;
    }while(ans == 'y' || ans == 'Y');
    return 0;
}