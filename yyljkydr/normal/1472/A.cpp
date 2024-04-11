#include<bits/stdc++.h>
using namespace std;

int T,w,h,n;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&w,&h,&n);
        int ans=1;
        while(w%2==0)
            w/=2,ans*=2;
        while(h%2==0)
            h/=2,ans*=2;
        puts(ans>=n?"YES":"NO");
    }
}