#include <bits/stdc++.h>
using namespace std;
long long h, o;
long long n;
int main()
{
    h=0;
    o=0;
    cin>>n;
    if(n>=1)
    {
        h+=n;
        o+=n;
    }
    if(n>=2)
    {
        h+=(n*(n-1));
        o+=(n*(n-1)*2);
    }
    if(n>=3)
    {
        h+=(n*(n-1)*(n-2)/(6));
        o+=(n*(n-1)*(n-2));
    }
    if(n>=4)
    {
        o+=(n*(n-1)*(n-2)*(n-3)/6);
    }
    if(n>=5)
    {
        o+=(n*(n-1)*(n-2)*(n-3)*(n-4)/120);
    }
    cout<<h*o;
    return 0;
}