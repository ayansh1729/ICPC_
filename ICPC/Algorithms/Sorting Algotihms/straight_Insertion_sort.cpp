#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Iterative way: The idea is to find appropriate position for each element and shift everything accordingly
void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// int *Insertion_sort(int *arr, int size)
// {
//     if (arr[1] < arr[0])
//     {
//         swap(arr[1], arr[0]);
//     }
//     for (int i = 2; i < size; i++)
//     {
//         int j = i - 1;
//         while (arr[i] < arr[j] && j > 0)
//         {
//             j--;
//         }
//         if (j != 0)
//         {
//             j++;
//         }
//         int temp = arr[i];
//         for (int k = i; k > j; k--)
//         {
//             arr[k] = arr[k - 1];
//         }
//         arr[j] = temp;
//     }
//     return arr;
// }

int *Insertion_sort(int *arr, int size)
{
    
    return arr;
}

int main()
{
    int arr[] = {3, 8, 1, 5, 7, 6, 9, -1, 10, -26};
    int size = sizeof(arr) / sizeof(int);
    int *sorted_array = Insertion_sort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << sorted_array[i] << " ";
    }

    return 0;
}