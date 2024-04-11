#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e3+1e2+7;

int T,n;

int hc,dc,hm,dm;

int k,w,a;

bool chk(int a,int b,int c,int d)
{
    return (a+d-1)/d>=(c+b-1)/b;
}

signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld%lld%lld%lld%lld%lld",&hc,&dc,&hm,&dm,&k,&w,&a);
        bool ok=0;
        for(int i=0;i<=k;i++)
            ok|=chk(hc+i*a,dc+(k-i)*w,hm,dm);
        puts(ok?"YES":"NO");
    }
}