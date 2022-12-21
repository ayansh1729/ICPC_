#include <iostream>
using namespace std;

void merge(int *arr, int n, int l, int mid, int r)
{
    int k = 0, arr_x[n], i, j;
    if (n == 1)
    {
        return;
    }
    for (i = l, j = mid + 1; (i <= mid) && (j <= r) && k < (r - l + 1);)
    {
        if (arr[i] <= arr[j])
        {
            arr_x[k] = arr[i];
            i++;
            k++;
        }
        if (arr[i] > arr[j])
        {
            arr_x[k] = arr[j];
            j++;
            k++;
        }
    }
    if (i == mid + 1)
    {
        while (j <= r)
        {
            arr_x[k] = arr[j];
            k++;
            j++;
        }
    }
    if (j == r + 1)
    {
        while (i <= mid)
        {
            arr_x[k] = arr[j];
            k++;
            i++;
        }
    }
    cout << "k is" << k << endl;
    for (int p = l; p <= r; p++)
    {
        arr[p] = arr_x[p];
    }
}

void merge_sort(int *arr, int n, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int mid = l + (r - l) / 2;
    merge_sort(arr, n, l, mid);
    merge_sort(arr, n, mid + 1, r);
    merge(arr, n, l, mid, r);
}

int main()
{
    int arr[] = {2, 3, 6, 7, 9};
    int n = sizeof(arr) / sizeof(int);
    merge_sort(arr, n, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}