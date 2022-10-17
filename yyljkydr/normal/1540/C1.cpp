#include<bits/stdc++.h>
using namespace std;

const int N=105,P=1e9+7;

int n,c[N],b[N],sb[N],ssb[N];

int f[N][N*N],g[N][N*N];

int q,x[100001];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<n;i++)
        scanf("%d",&b[i]),sb[i]=sb[i-1]+b[i],ssb[i]=ssb[i-1]+sb[i];
    // f[0][0]=1;
    // for(int i=1,sc=c[1];i<=n;i++,sc+=c[i])
    //     for(int j=0;j<=c[i];j++)
    //         for(int k=j;k<=sc;k++)
    //             f[i][k]=(f[i][k]+f[i-1][k-j])%P;
    // g[n+1][0]=1;
    // for(int i=n,sc=c[n];i>=1;i--,sc+=c[i])
    //     for(int j=0;j<=c[i];j++)
    //         for(int k=j;k<=sc;k++)
    //             g[i][k]=(g[i][k]+g[i+1][k-j])%P;
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
        scanf("%d",&x[i]);
    f[0][0]=1;
    for(int i=1,sc=c[1];i<=n;i++,sc+=c[i])
    {
        for(int j=0;j<=c[i];j++)
            for(int k=j;k<=sc;k++)
            {
                //a * i + ssb[i - 1] = k
                //a = (k - ssb[i - 1]) / i
                //a >= x
                //k - ssb[i - 1] >= x * i
                if(k-ssb[i-1]<x[1]*i)
                    continue;
                f[i][k]=(f[i][k]+f[i-1][k-j])%P;
            }
    }
    int ans=0;
    for(int j=0;j<=10000;j++)
        ans=(ans+f[n][j])%P;
    printf("%d\n",ans);
}