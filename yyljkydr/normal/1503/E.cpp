#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e3+1e2+7,P=998244353;

int f[N][N],n,m;

void inc(int &a,int b)
{
    a+=b;
    a>=P?a-=P:0;
}

signed main()
{
    scanf("%lld%lld",&n,&m);
    f[1][1]=1;
    for(int i=1;i<=max(n,m)+1;i++)
        for(int j=1;j<=max(n,m)+1;j++)
            inc(f[i+1][j],f[i][j]),inc(f[i][j+1],f[i][j]);
    int ans=0;
    for(int i=1;i<m;i++)
    {
        int s=0;
        for(int j=2;j<=n;j++)
        {
            inc(s,f[m+1-(i+1)+1][j-1]*f[m+1-(i+2)+1][n-(j-1)+1]%P);
            inc(ans,f[i][j]*f[i+1][n-j+1]%P*s%P);
        }
    }
    for(int i=1;i<n;i++)
    {
        int s=0;//s denotes the sum from 2 to j
        for(int j=2;j<=m;j++)
        {
            inc(ans,f[i][j]*f[i+1][m-j+1]%P*s%P);
            inc(s,f[n+1-(i+1)+1][j-1]*f[n+1-(i+2)+1][m-(j-1)+1]%P);
        }
    }
    printf("%lld\n",ans*2%P);
}