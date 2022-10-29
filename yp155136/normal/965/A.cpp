#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int k,n,s,p;
    cin >> k >>n >>s >> p;
    cout << (( k * ((n+s-1)/s) ) + p - 1)/p << endl;
}