#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=5e2+1e1+7;

int n,m,P;

int f[N][N],g[N][N],C[N][N];

void inc(int &a,int b)
{
    a+=b;
    a>=P?a-=P:0;
}

signed main()
{
    scanf("%lld%lld%lld",&n,&m,&P);
    C[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%P;
    }
    f[0][0]=1;
    g[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            for(int k=0;k<=j;k++)
            {
                inc(f[i][j],f[k][k]*f[i-k-1][j-k]%P*C[j][k]%P);
                inc(g[i][j],(g[k][k]*f[i-k-1][j-k]%P*C[j][k]%P+g[i-k-1][j-k]*f[k][k]%P*C[j][k]%P)%P);
            }
        }
        for(int j=1;j<=i;j++)
        {
            inc(f[i][i],f[j-1][j-1]*f[i-j][i-j]%P*(i+1)%P*C[i-1][j-1]%P);
            inc(g[i][i],(i+1)*C[i-1][j-1]%P*(f[j-1][j-1]*g[i-j][i-j]%P+g[j-1][j-1]*f[i-j][i-j]%P)%P);
            inc(g[i][i],(j*(j-1)/2+(i-j+1)*(i-j)/2)*f[j-1][j-1]%P*f[i-j][i-j]%P*C[i-1][j-1]%P);
        }
    }
    printf("%lld\n",g[n][m]);
}