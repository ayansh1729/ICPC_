#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Question 1: Addition,subtraction,multiplication and division using recursion
int Add(int x, int y)
{
    if (x == 0)
    {
        return y;
    }
    else
    {
        return Add(x - 1, 1 + y);
    }
}

int Sub(int x,int y){           //subtracts y-x
    if(x==0){
        return y;
    }
    else{
        return Sub(x-1,y-1);
    }
}

int main()
{
    cout << Add(5, 6) << endl;
    return 0;
}