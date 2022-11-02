#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long ans;
int main()
{
    cin>>n>>m;
    long long cn=1;
    while(1)
    {
        long long x2=cn/2;
        long long x3=cn/3;
        long long koz=cn/6;
        x2-=koz;
        x3-=koz;
        if(x2>=n)
        {
            if(x3+koz>=m)
            {
                ans=cn;
                break;
            }
        }
        else if(x3>=m)
        {
            if(x2+koz>=n)
            {
                ans=cn;
                break;
            }
        }
        else
        {
            if(x2+x3+koz>=n+m)
            {
                ans=cn;
                break;
            }
        }
        cn++;
    }
    cout<<cn;
    return 0;
}