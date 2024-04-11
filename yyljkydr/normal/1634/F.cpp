#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=3e5+1e3+7;

int n,Q,P;

int a[N],cnt,f[N];

void inc(int &a,int b)
{
    a+=b;
    a%=P;
    a+=P;
    a%=P;
}

void add(int &val,int d)
{
    cnt-=val==0;
    inc(val,(d+P)%P);
    cnt+=val==0;
}

void add(int v,int l,int r)
{
    add(a[l],v);
    if(r+1<=n)
        add(a[r+1],-v*(f[r-l+1]+f[r-l])%P);
    if(r+2<=n)
        add(a[r+2],-v*f[r-l+1]);
}

signed main()
{
    scanf("%lld%lld%lld",&n,&Q,&P);
    f[1]=1%P,f[2]=1%P;
    for(int i=3;i<=n;i++)
        f[i]=(f[i-1]+f[i-2])%P;
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%lld",&x);
        inc(a[i],P-x);
    }
    for(int i=n;i>=2;i--)
        inc(a[i],P-(a[i-1]+a[i-2])%P),cnt+=!a[i];
    cnt+=!a[1];
    while(Q--)
    {
        char op[2];
        int l,r;
        scanf("%s%lld%lld",op,&l,&r);
        add(op[0]=='A'?1:-1,l,r);
        puts(cnt==n?"YES":"NO");
    }
}