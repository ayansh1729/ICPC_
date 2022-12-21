// Divide an array into two subsets of equal sum - return true if possible false if not possible
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Recursive Approach
int Equal_sum_partition(int *arr, int n, int sum)
{
    if (sum < 0) // If sum goes less than 0...then oviously invalid
    {
        return 0;
    }
    if (sum == 0) // If sum is 0 then we reached
    {
        return 1;
    }
    if (n == 0) // If n is 0 then no element in array and so return 0
    {
        return 0;
    }
    if (arr[n - 1] > sum) // If element is greater than sum then choose the remaining array
    {
        return Equal_sum_partition(arr, n - 1, sum);
    }
    // Either we include an element...so we subtract twice of that...since it is equal partition...subtracting twice will result the end sum to be 0
    // Rest of the logic is same as finding the sum
    // First is including and other one is not including
    return Equal_sum_partition(arr, n - 1, sum - 2 * arr[n - 1]) || Equal_sum_partition(arr, n - 1, sum);
    // We can also check if sum is even or odd in first place
}

int equal_sum_partition(int *arr, int n, int sum)
{
    if (sum & 1)
    {
        return 0;
    }
    else
    {
        sum = sum / 2;                              //just half the sum and then find if a subarray is there with that sum
        int dp[n + 1][sum + 1];
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            dp[0][i] = 0;
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (arr[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][sum];
    }
}

int main()
{
    int arr[] = {1, 5, 9, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    cout << Equal_sum_partition(arr, n, sum) << endl;
    cout << equal_sum_partition(arr, n, sum) << endl;
    return 0;
}