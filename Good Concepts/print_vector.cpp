#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// This template can be used to print a vector just using cout
template <typename S>
ostream &operator<<(ostream &os,
                    const vector<S> &vector)
{

    for (auto element : vector)
    {
        os << element << " ";
    }
    return os;
}

int main()
{
    vector<int> v;
    v = {1, 2, 3, 4, 5, 6};
    cout << v << endl;
    return 0;
}
