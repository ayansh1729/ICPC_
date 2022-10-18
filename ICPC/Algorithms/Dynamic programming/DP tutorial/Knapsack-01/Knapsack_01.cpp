// 1. Subset sum
// 2. Equal sum partition
// 3. count of subset sum
// 4. Minimum subset sum
// 5. Target sum
// 6. subset of given

// <-------------------------------------------------------------------------------->
// 1. Fractional - Greedy
// 2. 0-1 (Dp)
// 3. Unbounded (Dp)

//<--------------------------------------------------------------------------------->
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Recursive and memoization

// Memoization here ---  considering global matrix of dp[n][w]
int static dp[102][1002];

// Recursive Approach first
int knapsack(int *w, int *p, int n, int W)
{
    if (w == 0 or n == 0)                       // If weight or number of items is 0
    {
        return 0;
    }
    if (dp[n][W] != -1)                         // If the values are present then just return that
    {
        return dp[n][W];
    }
    if (w[n - 1] <= W)                          // If weight is less than capacity then two choices either to include or not
    {
        return dp[n][W] = max(knapsack(w, p, n - 1, W), p[n - 1] + knapsack(w, p, n - 1, W - w[n - 1]));
        // max(not including,including)
    }
    else                                        // If weight is greater than capacity
    {
        return dp[n][W] = knapsack(w, p, n - 1, W);
        // not including
    }
}

// Top-down approach --- Real dp -- No worries of stack overflow error

int knap_sack(int *w, int *p, int n, int W)
{
    int d[n + 1][W + 1];
    for (int i = 0; i < n + 1; i++)
    {
        d[i][0] = 0;
    }
    for (int i = 0; i < W + 1; i++)
    {
        d[0][i] = 0;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (w[i - 1] < j)                       //This is just same as recursion
            {
                d[i][j] = max(p[i - 1] + d[i - 1][j - w[i - 1]], d[i - 1][j]);
            }
            else
            {
                d[i][j] = d[i - 1][j];
            }
        }
    }
    return d[n][W];
}

int main()
{
    int w[] = {1, 3, 4, 5};
    int p[] = {3, 4, 5, 7};
    int W = 7;
    memset(dp, -1, sizeof(dp));
    cout << knap_sack(w, p, 4, W) << endl;
    cout << knapsack(w, p, 4, W);
    return 0;
}