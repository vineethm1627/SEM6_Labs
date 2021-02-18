/*
Name: M.Vineeth
Enrol: E18CSE095
Batch: EB03
*/

/*
    Q)
    Write	a	program	to	display	the	count	of	prime	numbers	upto	a	particular	
    number (N). Here	N	is	included.		
    Example:	 Input	(1):	100,	Output:	25
    Input	(2):	23,	Output:	9
*/
#include <iostream>
#include <cstring> // for memset function
using namespace std;

// using the efficient approach of Sieve of Eratosthenes.
int countPrimes(int n) {
    // intially we will mark all the numbers as true indicating they are prime.
    bool prime[n];
    memset(prime, true, sizeof(prime)); // setting all values as true in one line

    for(int p = 2; p * p <= n; p++) {
        if(prime[p]) {
            // update all the multiples of p >= p^2
            for(int i = p * p; i <= n; i += p) 
                prime[i] = false;
        }
    }

    int count = 0;
    for(int i = 2; i <= n; i++) {
        if(prime[i])
            count++;
    }

    return count;
}

int main() {

    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "count of primes: " << countPrimes(n) << endl;

    return 0; // 0 indicates the successful termination of the program
}