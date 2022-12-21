#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct item
{
    int profit;
    int weight;
};

int binary_knapsack(struct item *arr, int n, int w)
{
    if (w <= 0 or n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return 0;
    }
    return max(binary_knapsack(arr, n - 1, w - arr[n - 1].weight) + arr[n - 1].profit, binary_knapsack(arr, n - 1, w));
}

int main()
{
    struct item arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i].weight = (i + 1) * 10;
        arr[i].profit = (i + 2) * 5;
    }
    cout << binary_knapsack(arr, 10, 70) << endl;

    return 0;
}