/*
Name: M.Vineeth
Roll: E18CSE095
Batch: EB03
*/
/*
    Write a program to input an array of n integers (n<=100) and arrange them in ascending
    order. The subscripts of the elements vary from 0-(n-1).Make use of functions given below:
    Functions/methords:
    void read_array(int arr[],int l) //input array elements from the user
    void arrange_array(int arr[],int l) //arrange the elements in ascending order
    void display_array(int arr[],int l) //displays n integers using pointers
    int binarysearch(int arr[],int l,int value) //searches for the value in the array using the
    binary search technique.
    It returns the subscript of the array element if the value is found otherwise it returns -999.
    Testcase
    Input:
    5
    12 3 6 7 8
    15

    where:
    First line represents the number of elements in the array.
    Second line represents the elements in the array.
    Third line represents the value of element to be searched.
    Output:
    -999
*/
#include <iostream>
#include <algorithm>
using namespace std;
 
void display(int *arr, int n) {
    int *end = arr + n;
    for(int *ptr = arr; ptr != end; ptr++) 
        cout << *ptr << " ";
}

int binarySearch(int *arr, int n, int key) {
    int start = 0, end = n - 1;
    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(arr[mid] == key)
            return mid;
        else if(key < arr[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}
 
int main() {
    
    char ans;
    do {
        cout << "MENU DRIVEN PROGRAM \n";
        cout << "1. read array \n";
        cout << "2. arrange_array \n";
        cout << "3. display_array \n";
        cout << "4. binary search \n";
        int choice;
        cout << "Select one choice: ";
        cin >> choice; 

        int arr[1000], n;

        switch(choice) {
            case 1: 
                cout << "Enter the size of the array: ";
                cin >> n;
                cout << "Enter the array elements: ";
                for(int i = 0; i < n; i++)
                    cin >> arr[i];
                break;

            case 2: 
                cout << "sorted the array ! \n";
                sort(arr, arr + n);
                break;
            
            case 3:
                display(arr, n);
                cout << '\n';
                break;
            
            case 4: {
                int key;
                cout << "Enter key to be searched: ";
                cin >> key;

                int index = binarySearch(arr, n, key);
                if(index != -1)
                    cout << "Key found at index: " << index << '\n';
                else 
                    cout << "Not found: -999 \n";
                break;
            }
            
            default:
                cout << "Select a suitable choice! \n";
        }
        cout << "Do you want to continue?(y/n): ";
        cin >> ans;
    }while(ans == 'y' || ans == 'Y');
 
    return 0;
}