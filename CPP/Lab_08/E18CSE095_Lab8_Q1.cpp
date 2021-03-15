/*
Name: M.Vineeth
Roll: E18CSE095
Batch: EB03
*/
#include <iostream>
using namespace std;

double getTotal(double *rainfall, int n) {
    double total = 0;
    for(int i = 0; i < n; i++)
        total += rainfall[i];
    
    return total;
}

double getAverage(double *rainfall, int n) {
    double total = getTotal(rainfall, n);
    return total / 12.0;
}

double getLowest(double *rainfall, int n, int &lowestIndex) {
    double lowest = rainfall[0];
    for(int i = 1; i < n; i++) {
        if(rainfall[i] < lowest) {
            lowest = rainfall[i];
            lowestIndex = i;
        }
    }
    return lowest;
}

double getHighest(double *rainfall, int n, int &highestIndex) {
    double highest = rainfall[0];
    for(int i = 1; i < n; i++) {
        if(rainfall[i] > highest) {
            highest = rainfall[i];
            highestIndex = i;
        }
    }
    return highest;
}

int main() {

    string months[12] = {"Jan", "Feb", "March", "April", "May", "June",
                        "July", "Aug", "Sept", "Oct", "Nov", "Dec"};
    
    double rainfall[12];

    cout << "Enter the rainfall: " << endl;
    for(int i = 0; i < 12; i++) {
        cout << months[i] << " : ";
        cin >> rainfall[i];
    }

    int lowestMonth, highestMonth;
    
    cout << "total rainfall: " << getTotal(rainfall, 12) << endl;
    cout << "average rainfall: " << getAverage(rainfall, 12) << endl;

    double low = getLowest(rainfall, 12, lowestMonth);
    double high = getHighest(rainfall, 12, highestMonth);

    cout << months[lowestMonth] << " has the lowest rainfall: " << low << endl;
    cout << months[highestMonth] << " has the highest rainfall: " << high << endl;
    
    return 0;
}