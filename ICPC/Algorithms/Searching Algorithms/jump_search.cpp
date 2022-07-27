#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int jump_search(int *arr, int size, int key)
{
    int i;
    int step = int(sqrt(size));
    for (i = step; i < size; i = i + step)
    {
        if (key < arr[i])
        {
            for (int j = i - step; j < i; j++)
            {
                if (arr[j] == key)
                {
                    return j;
                }
            }
        }
        else if (key == arr[i])
        {
            return i;
        }
    }
    i = i - step;
    for (i; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    printf("The element is not present in array\n");
    return -1;
}

int main()
{
    int key;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(int);
    cout << "Enter the element you want to search: ";
    cin >> key;
    int result = jump_search(arr, size, key);
    cout << result << endl;

    return 0;
}