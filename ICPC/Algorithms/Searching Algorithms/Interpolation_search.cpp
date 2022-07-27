#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Here the idea is same as Binary search expect we want to modify it...we don't want our guess to be middle element...we want a better guess and we are calling that pos
// Assuming that the data in sorted form is almost linear(or like in A.P)....we can use this formula to find the position....
// similarly ther are quadratic probing..

// Try writing the same code recursively

int Interpolation_search(int *arr, int size, int key)
{
    int low = 0;
    int high = size - 1;
    while (low <= high && key <= arr[high] && key >= arr[low])
    {
        if (low == high)
        {
            if (arr[high] == key)
            {
                return high;
            }
            else
            {
                cout << "The element is not present in array: " << endl;
                return -1;
            }
        }
        int pos = low + (key - arr[low]) * (high - low) / (arr[high] - arr[low]);
        if (arr[pos] == key)
        {
            return pos;
        }
        else if (arr[pos] < key)
        {
            low = pos;
        }
        else
        {
            high = pos;
        }
    }
    cout << "The element is not present in array: " << endl;
    return -1;
}

int main()
{
    int key;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(int);
    cout << "Enter the element you want to search: ";
    cin >> key;
    int result = Interpolation_search(arr, size, key);
    cout << result << endl;

    return 0;
}