#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Recursive Approach
int Subset_Sum(int *arr, int n, int sum)
{
    if (sum == 0) // If sum is 0 then oviously it is true we have a subset
    {
        return 1;
    }
    if (n == 0) // If length of array is 0 then It is not possible.....
                // It is important to note that this statement is written after the sum as if sum=0 and n=0 should be true
    {
        return 0;
    }
    if (arr[n - 1] > sum) // If the element is greater than sum then oviously no
    {
        return Subset_Sum(arr, n - 1, sum);     //Look in remaining array
    }
    return Subset_Sum(arr, n - 1, sum) || Subset_Sum(arr, n - 1, sum - arr[n - 1]); // either not including the element or including the last element
}

// Given and array and a sum print 1 if a subset is present with sum and 0 if not
int subset_sum(int *arr, int n, int sum)
{
    bool dp[n + 1][sum + 1];
    // Initalization
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = true;
    }
    for (int i = 1; i < sum + 1; i++)
    {
        dp[0][i] = false;
    }
    // Similarity with knapsack
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j) // it is i-1 beacuse the first element in array is 0th element....if that is less than corresponding sum then two possibility either to include it or not
            {
                dp[i][j] = (dp[i - 1][j - arr[i - 1]]) || (dp[i - 1][j]); // if included then look for the part where one element is less and sum is (sum looking for-element)
            }
            else
            {
                dp[i][j] = dp[i - 1][j]; // Just look for sum with 1 element less
            }
        }
    }
    // for (int i = 0; i < n + 1; i++)                      //For printing the array
    // {
    //     for (int j = 0; j < sum + 1; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return dp[n][sum];
}

int main()
{
    int arr[] = {5, 8};
    int sum = 8;
    int n = sizeof(arr) / sizeof(int);
    cout << subset_sum(arr, n, sum) << endl;
    cout << Subset_Sum(arr, n, sum) << endl;
    return 0;
}