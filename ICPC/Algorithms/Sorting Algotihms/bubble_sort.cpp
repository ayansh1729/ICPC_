#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int *bubble_sort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        { // just swapping the adjacent element on condition to send the max element at last
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return arr;
}

int main()
{
    int arr[] = {3, 8, 1, 5, 7, 6, 9, -1};
    int size = sizeof(arr) / sizeof(int);
    int *sorted_array = bubble_sort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << sorted_array[i] << " ";
    }
    return 0;
}