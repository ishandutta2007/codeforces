#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e6+1e3+7;

int n,h[N];

long long s;

signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&h[i]),s+=h[i];
    int l=-1,r=1e12;
    while(r-l>1)
    {
        int mid=(l+r)>>1;
        if((mid+mid+n-1)*n/2>=s)
            r=mid;
        else
            l=mid;
    }
    int b=r;
    int d=(b+b+n-1)*n/2-s;
    for(int i=1;i<=n;i++)
        printf("%lld%c",b+i-1-(i>=(n-d+1))," \n"[i==n]);
    //(x+x+n-1)*n/2==s
}