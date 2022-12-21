// Given an array divide into two subsets such that their difference is minimum:
// Approach:
// We don't want to deal with two variables s1 and s2...which are subsets....so we will try to reduce them to 1
// if the total sum of array is l then s1+s2=l....thus s2-s1=2*s1-l
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int mini = INT_MAX;
int Equal_sum_partition(int *arr, int n, int sum)
{
    if (sum < 0)
    {
        return mini;
    }
    if (sum < mini)
    {
        mini = sum;
    }
    if (n == 0)
    {
        return mini;
    }
    return min(Equal_sum_partition(arr, n - 1, sum - 2 * arr[n - 1]), Equal_sum_partition(arr, n - 1, sum));
}

int main()
{
    int arr[] = {5, 8, 1,6};
    int sum = 20;
    int n = sizeof(arr) / sizeof(int);
    cout << Equal_sum_partition(arr, n, sum) << endl;
    return 0;
}