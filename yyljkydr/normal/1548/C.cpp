#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=3e6+1e3+7,P=1e9+7,iv3=(P+1)/3;

int fac[N],inv[N];

int n,q;

int qpow(int a,int b)
{
    int ret=1;
    while(b)
    {
        if(b&1)
            ret=ret*a%P;
        b>>=1;
        a=a*a%P;
    }
    return ret;
}

void pre(int n)
{
    fac[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=fac[i-1]*i%P;
    inv[n]=qpow(fac[n],P-2);
    for(int i=n-1;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%P;
}

int C(int n,int m)
{
    if(n<0||m<0||n<m)
        return 0;
    return fac[n]*inv[m]%P*inv[n-m]%P;
}

int ans[N];

signed main()
{
    scanf("%lld%lld",&n,&q);
    pre(n*3+10);
    ans[0]=C(3*n+3,1)*iv3%P;
    for(int i=1;i<=n*3;i++)
        ans[i]=(C(3*n+3,i+1)-3*ans[i-1]-(i==1?0:ans[i-2])+P*6)*iv3%P;
    while(q--)
    {
        int x;
        scanf("%lld",&x);
        printf("%lld\n",ans[x]);
    }
}