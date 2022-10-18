#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Task 1: To create all the substrings of a given string:
string substring(string s1)
{
    cout << s1 << endl;
    if (s1.length() == 1)
    {
        cout << s1 << endl;
        return s1;
    }
    else
    {
        for (int i = 0; i < s1.length(); i++)
        {
            string temp = substring(s1.substr(i, s1.length()));
            cout << temp << endl;
        }
    }
}

int main()
{
    string test = "sanjeet";
    string temp = substring(test);
    return 0;
}