// Codechef contest---- contest code-- PERMGCD
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        if (x < n)
        {
            cout << -1 << endl;
        }
        else
        {
            int s = x - n + 1;
            cout << s << " ";
            for (int i = 1; i < n + 1; i++)
            {
                if (s != i)
                {
                    cout << i << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}