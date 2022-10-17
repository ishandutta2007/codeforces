#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e7+1e3+7,L=720720,P=998244353;

int n,a[N],x,y,M,k;

int f[18][L],inv[N];

void inc(int &a,int b)
{
    a+=b;
    a>=P?a-=P:0;
}

signed main()
{
    scanf("%lld",&n);
    scanf("%lld%lld%lld%lld%lld",&a[1],&x,&y,&k,&M);
    for(int i=2;i<=n;i++)
        a[i]=(a[i-1]*x+y)%M;
    inv[1]=1;
    for(int i=2;i<=n;i++)
        inv[i]=inv[P%i]*(P-P/i)%P;
    int ans=0;
    int pw=1;
    for(int i=1;i<k;i++)
        pw=pw*n%P;
    for(int i=1;i<=n;i++)
    {
        int w=a[i]%L;
        inc(ans,(a[i]-w)*pw%P*k%P);
        f[0][w]++;
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<L;j++)
            inc(ans,pw*j%P*f[i-1][j]%P);
        for(int j=0;j<L;j++)
        {
            inc(f[i][j],f[i-1][j]*(n-1)%P);
            inc(f[i][j-j%i],f[i-1][j]);
        }
        pw=pw*inv[n]%P;
    }
    printf("%lld\n",ans);
}