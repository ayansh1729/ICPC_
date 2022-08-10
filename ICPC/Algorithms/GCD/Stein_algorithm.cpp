#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (a == b)
    {
        return a;
    }
    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }
    if (a % 2 == 0)
    { // a is even
        if (b & 1)
        {                          // b is odd
            return gcd(a >> 1, b); // i.e gcd(a/2,b)
        }
        else
        {
            return gcd(a >> 1, b >> 1) << 1; // i.e gcd(a/2,b/2)*2
        }
    }
    if (b % 2 == 0)
    { // i,e a is odd and b is even
        return gcd(a, b >> 1);
    }
    // for reducing Larger no
    if (a > b)
    {
        return gcd((a - b) >> 1, b);
    }
    return gcd((b - a) >> 1, a);
}

int main()
{
    int a = 13, b = 39;
    printf("The Gcd of given no. is: %d", gcd(a, b));
    return 0;
}