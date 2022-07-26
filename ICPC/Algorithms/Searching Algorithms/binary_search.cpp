#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int binary_search(int key, int *arr, int size) // Method - 1
{
    // When high and low are indecies
    int low = 0;
    int high = size - 1;
    while (high > low)
    {
        int mid = (high + low) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (key > arr[mid])
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    printf("Element not present in array\n");
}

int main()
{
    int key;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(int);
    cout << "Enter the element you want to search: ";
    cin >> key;
    int result = binary_search(key, arr, size);
    cout << result << endl;

    return 0;
}
