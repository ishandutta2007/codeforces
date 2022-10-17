#include<bits/stdc++.h>
using namespace std;

const int P=1e9+7;

int T;

int s(int x)
{
    return 1ll*x*(x+1)/2%P;
}

int ss(int x)
{
    return 1ll*x*(x+1)*(2*x+1)/6%P;
}

int qpow(int a,int b)
{
    int ret=1;
    while(b)
    {
        if(b&1)
            ret=1ll*ret*a%P;
        b>>=1;
        a=1ll*a*a%P;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>d;
    for(int i=1;i<=n;i++)
        if(n%i==0)
            d.push_back(i);
    reverse(d.begin(),d.end());
    vector<int>f(n+1),g(n+1);
    int ans=0;
    for(auto x:d)
    {
        for(int y=x;y<=n;y+=x)
        {
            int t=n/y;
            f[y]=((1ll*n*s(t)%P-1ll*n*t%P-1ll*ss(t)*y%P+1ll*s(t)*y%P+P*2)%P)%P;
        }
        for(int y=n/x*x;y>=x;y-=x)
        {
            for(int t=y*2;t<=n;t+=y)
                f[y]=(f[y]-f[t]+P)%P;
            g[x]=(g[x]+1ll*f[y]*y%P)%P;
        }
        for(int y=x*2;y<=n;y+=x)
            g[x]=(g[x]-g[y]+P)%P;
        ans=(ans+1ll*g[x]*qpow(x,P-2))%P;
    }
    printf("%d\n",ans);
}