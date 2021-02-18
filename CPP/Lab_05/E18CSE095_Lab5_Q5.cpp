/*
Name: M.Vineeth
Enrol: E18CSE095
Batch: EB03 
*/
/*
    Given the age details of all the members as integers, write a program so that all the
    members can be arranged in a queue based on their age, and in increasing order of their age.
    Also, calculate and display the average age of the passengers.

    sorting algorithm used: Heap Sort O(nlogn)
*/
#include <iostream>
#include <vector>
using namespace std;
 
// sorting the array using Heap Sort
void heapify(vector<int> &ages, int index, int size) {
    int left = 2 * index;
    int right = left + 1;

    int last = size - 1;
    int min_index = index;

    // condition for maxHeap
    if(left <= last and ages[left] > ages[index])
        min_index = left;
    if(right <= last and ages[right] > ages[min_index])
        min_index = right;
    
    if(min_index != index) {
        swap(ages[min_index], ages[index]);
        heapify(ages, min_index, size);
    }
}

void buildHeap(vector<int> &ages) {
    // for leaf nodes there wont be any changes as we are checking for the heap condition from bottom to top
    // (n-1) / 2 is the first non-leaf element
    for(int i = (ages.size() - 1) / 2; i > 0; i--)
        heapify(ages, i, ages.size());
}

void heapSort(vector<int> &ages) {
    buildHeap(ages);
    int n = ages.size();

    while(n > 1) {
        swap(ages[1], ages[n - 1]);
        n--;
        heapify(ages, 1, n);
    }
}

void print(vector<int> ages) {
    for(int i = 1; i < ages.size(); i++)
        cout << ages[i] << " ";
}

float average(vector<int> ages) {
    float sum = 0;
    for(int i = 1; i < ages.size(); i++)
        sum += ages[i];

    return sum / ages.size();
}
 
int main() {
    
    char ans;
    do {
        cout << "Enter the value of n: ";
        int n;
        cin >> n;
        vector<int> ages(n + 1);
        ages[0] = -1; // blocking index 0, facilitates heap sort
        cout << "Enter the age values: " << endl;
        for(int i = 1; i <= n; i++) 
            cin >> ages[i];

        heapSort(ages);
        cout << "sorted array: ";
        print(ages);
        cout << endl;
        cout << "average age: " << average(ages) << endl;

        cout << "Do you want to continue? (y/n): ";
        cin >> ans;

    }while(ans == 'y' or ans == 'Y');
 
    return 0;
}