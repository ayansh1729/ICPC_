// Count no. of subsets with given sum
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Recursive: Approach is same we try to include or exlude a number
int static cnt = 0; // We can declear a global varibale
int count_subset_with_sum(int *arr, int n, int sum)
{
    if (sum == 0)
    {
        cnt++;    // and increment the count when we find any suitable subset
        return 1; // or just return 1
    }
    if (n == 0)
    {
        return 0;
    }
    if (arr[n - 1] > sum)
    {
        return count_subset_with_sum(arr, n - 1, sum);
    }
    return count_subset_with_sum(arr, n - 1, sum) + count_subset_with_sum(arr, n - 1, sum - arr[n - 1]);
    // Subset comes either form not including or including....add the results of both
}

int Count_subset_with_sum(int *arr, int n, int sum)
{

    int dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i < sum + 1; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}

int main()
{
    int arr[] = {1, 5, 9, 13, 7, 6, 8, 7, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 14;
    cout << count_subset_with_sum(arr, n, sum) << endl; // Both prints the same thing
    cout << cnt << endl;                                
    cout << Count_subset_with_sum(arr, n, sum) << endl; // This also prints the same 

    return 0;
}