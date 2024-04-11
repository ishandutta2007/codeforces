#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long x, y, z;
    long long n;
    cin>>n;
    x=n;
    x/=1;
    x*=(n-1);
    x/=2;
    x*=(n-2);
    x/=3;
    x*=(n-3);
    x/=4;
    x*=(n-4);
    x/=5;
    x*=(n-5);
    x/=6;
    x*=(n-6);
    x/=7;
    y=n;
    y/=1;
    y*=(n-1);
    y/=2;
    y*=(n-2);
    y/=3;
    y*=(n-3);
    y/=4;
    y*=(n-4);
    y/=5;
    y*=(n-5);
    y/=6;
    z=n;
    z/=1;
    z*=(n-1);
    z/=2;
    z*=(n-2);
    z/=3;
    z*=(n-3);
    z/=4;
    z*=(n-4);
    z/=5;
    cout<<x+y+z;

    return 0;
}