/*
Name: M.Vineeth
Enrol: E18CSE095
Batch: EB03
*/
/*  
    3) Write a program to find all the possible clustering arrangements from a given number of
    records.
    Sample Input/Output:
    Input: Enter the number of records n: 3
    Output: Total number of possible clustering arrangements is 5

    Clustering arrangements with 1 cluster:
    No. of clustering arrangements: 1
    The clusters are: {{r1,r2,r3}}
    Clustering arrangements with 2 clusters:
    No. of clustering arrangements: 3
    The clusters are: {{r1,r2},{r3}}, {{r1,r3},{r2}}, {{r2,r3},{r1}}
    Clustering arrangements with 3 clusters:
    No. of clustering arrangements: 1
    The clusters are: {{r1},{r2},{r3}}
*/
#include <iostream>
using namespace std;

int countPartitions(int n) {
    int bell[n + 1][n + 1];
    bell[0][0] = 1;

    for(int i = 1; i <= n; i++) {
        bell[i][0] = bell[i - 1][i - 1];

        for(int j = 1; j <= i; j++)
            bell[i][j] = bell[i - 1][j - 1] + bell[i][j - 1];
    }
    return bell[n][0];
}

int main() {

    //Bell numbers : Number of ways to partition a set.

    char ans;
    do {
        int n;
        cout << "Enter the number of records: ";
        cin >> n;
        cout << "Total number of clustering arrangements: " << countPartitions(n) << endl;

        cout << "Do you want to continue?: ";
        cin >> ans;

    }while(ans == 'y' || ans == 'Y');

    return 0;
}
