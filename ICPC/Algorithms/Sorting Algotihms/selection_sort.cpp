#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// The idea for selection sort is to iterate over an array...find the minimum value from array except that element then swap it with first

int *selection_sort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int min_index = i; // Declearing minimum index to be i
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[min_index]) // finding the index of minimum element in rest of the array
            {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]); // swapping the element
    }
    return arr;
}
int main()
{
    int arr[] = {3, 8, 1, 5, 7, 6, 9, -1};
    int size = sizeof(arr) / sizeof(int);
    int *sorted_array = selection_sort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << sorted_array[i] << " ";
    }
    return 0;
}