/*
Name: M.Vineeth
Enrol: E18CSE095
Batch: EB03
*/
/*
    Any given number (N) can be written in the form like P1E1 * P2E2 * P3E3 *… *PnEn where Pi
    is the prime factor of N and Ei is it’s exponent. Here, Pi, Ei >= 1. The task is to take input
    any number and display it in the specified format as above.
    Sample Input: 36
    Sample Output: 2^2 * 3^2

    Sample Input: 91
    Sample Output: 7^1 * 13^1
*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// arr[i] = smallest prime factor of i.
void sieve(int n, int arr[]) {
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    // for all even numbers 2 will be the smallest prime factor.
    for(int i = 2; i<= n; i += 2) 
        arr[i] = 2;
    // for the remaining odd numbers
    for(int p = 3; p <= n; p += 2) {
        if(prime[p]) {
            arr[p] = p;

            // update all the multiples of this prime number as non-primes
            for(int i = p * p; i <= n; i += p) {
                if(prime[i] == true) {
                    prime[i] = false;
                    arr[i] = p;
                }
            }
        }
    }
}

void printPrimeFactors(int n) {
    int arr[n + 1]; // arr[i] stores the smallest prime factor of i
    sieve(n, arr);

    // for printing the (factor, power) in a suitable format
    vector<pair<int, int>> fp;

    int factor = arr[n];
    int power = 1;

    while(n > 1) {
        n = n / arr[n];
        if(factor == arr[n]) {
            power++;
            continue;
        }
        fp.push_back(make_pair(factor, power));
        // update the factor to the next value
        factor = arr[n];
        power = 1;
    }

    // print the factors and powers in the required format
    int i;
    for(i = 0; i < fp.size() - 1; i++)
        cout << fp[i].first << "^" << fp[i].second << " * ";

    cout << fp[i].first << "^" << fp[i].second;
}

int main() {

    char ans;
    do {
        
        int n;
        cout << "Enter a number: ";
        cin >> n;

        printPrimeFactors(n);

        cout << "\nDo you want to continue? : ";
        cin >> ans;

    }while(ans == 'y' || ans == 'Y');

    return 0;
}