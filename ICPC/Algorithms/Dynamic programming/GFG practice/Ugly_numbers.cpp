#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//Ugly no. are no. whose only prime factors are 2 3 and 5

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

//Approach to get nth Ugly number
int Ugly_number(int n){
    vector <int> v;
    v.push_back(1);
    int i2=0,i3=0,i5=0;
    for(int i=0;i<n;i++){
        v.push_back(min(v[i2],v[i3],v[i5]));
        if(v[i2]<=min(v[i3],v[i5])){
            i2++;
        }
        else if(v[i3]<=v[i5]){
            i3++;
        }
        else{
            i5++;
        }
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