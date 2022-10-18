#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Normal Approach

int check_ugly(int n)
{
    while (n % 2 == 0)
    {
        n = n / 2;
    }
    while (n % 3 == 0)
    {
        n = n / 3;
    }
    while (n % 5 == 0)
    {
        n = n / 5;
    }
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n, count = 0;
    cin >> n;
    for (int i = 0; count <= n; i++)
    {
        if (check_ugly(i + 1))
        {
            count++;
        }
        if (count == n)
        {
            cout << i + 1 << endl;
        }
    }
    return 0;
}