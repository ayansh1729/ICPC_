#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int l, int m, int r) // l=0 m=1 r=3
{
    int *temp_arr = new int[r - l + 1];                                     // Creating an array of size 3-0+1 i.e size of array
    int index = 0;                                                          // setting index to be 0 of temp array
    int i, j;                                                               // indecies for two subarray
    for (i = l, j = m + 1; (i < m + 1) && (j <= r) && (index < r - l + 1);) // First index will go till 1,second till 3
    {
        if (arr[i] <= arr[j])
        {
            temp_arr[index] = arr[i];
            i++;
        }
        else
        {
            temp_arr[index] = arr[j];
            j++;
        }
        // cout << i << " " << j << " " << index << temp_arr[index] << endl;
        index++;
    }
    if (i == m + 1)
    {
        for (int k = j; k <= r; k++)
        {
            temp_arr[index] = arr[k];
            index++;
        }
    }
    else if (j == r + 1)
    {
        for (int k = i; k <= m; k++)
        {
            temp_arr[index] = arr[k];
            cout << temp_arr[index] << endl;
            index++;
        }
    }
    for (int i = 0; i < index; i++) // This is allocating it to array
    {
        arr[i] = temp_arr[i];
    }
}
// void merge(int array[], int const left, int const mid, int const right)
// {
//     auto const subArrayOne = mid - left + 1;
//     auto const subArrayTwo = right - mid;

//     // Create temp arrays
//     auto *leftArray = new int[subArrayOne],
//          *rightArray = new int[subArrayTwo];

//     // Copy data to temp arrays leftArray[] and rightArray[]
//     for (auto i = 0; i < subArrayOne; i++)
//         leftArray[i] = array[left + i];
//     for (auto j = 0; j < subArrayTwo; j++)
//         rightArray[j] = array[mid + 1 + j];

//     auto indexOfSubArrayOne = 0,   // Initial index of first sub-array
//         indexOfSubArrayTwo = 0;    // Initial index of second sub-array
//     int indexOfMergedArray = left; // Initial index of merged array

//     // Merge the temp arrays back into array[left..right]
//     while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
//     {
//         if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
//         {
//             array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
//             indexOfSubArrayOne++;
//         }
//         else
//         {
//             array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
//             indexOfSubArrayTwo++;
//         }
//         indexOfMergedArray++;
//     }
//     // Copy the remaining elements of
//     // left[], if there are any
//     while (indexOfSubArrayOne < subArrayOne)
//     {
//         array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
//         indexOfSubArrayOne++;
//         indexOfMergedArray++;
//     }
//     // Copy the remaining elements of
//     // right[], if there are any
//     while (indexOfSubArrayTwo < subArrayTwo)
//     {
//         array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
//         indexOfSubArrayTwo++;
//         indexOfMergedArray++;
//     }
//     delete[] leftArray;
//     delete[] rightArray;
// }

void merge_sort(int *arr, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int mid = l + (r - l) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);
    merge(arr, l, mid, r);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {1};
    // merge(arr, 0, 0, 0);
    merge_sort(arr, 0, 5);
    for (int i = 0; i < 1; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}