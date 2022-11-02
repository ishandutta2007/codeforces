#include <bits/stdc++.h>
using namespace std;
long long n;
int main()
{
    cin>>n;
    long long x;
    x=n*(n-1)*(n-2)*(n-3)*(n-4);
    x/=120;
    x*=n*(n-1)*(n-2)*(n-3)*(n-4);
    cout<<x;

    return 0;
}