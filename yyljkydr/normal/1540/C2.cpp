#include<bits/stdc++.h>
using namespace std;

const int N=105,P=1e9+7;

int n,c[N],b[N],sb[N],ssb[N];

int f[N][N*N],g[N][N*N];

int q,x[100001];

int solve(int x)
{
    f[0][0]=1;
    g[0][0]=1;
    for(int i=1;i<=n*100;i++)
        g[0][i]=1;
    for(int i=1;i<=n;i++)
    {
        for(int k=0;k<=n*100;k++)
        {
            if(k-ssb[i-1]<x*i)
            {
                f[i][k]=0;
                continue;
            }
            f[i][k]=g[i-1][k];
            if(k-c[i]-1>=0)
                f[i][k]=(f[i][k]-g[i-1][k-c[i]-1]+P)%P;
        }
        // for(int j=0;j<=c[i];j++)
        //     for(int k=j;k<=sc;k++)
        //     {
        //         if(k-ssb[i-1]<x*i)
        //             continue;
        //         f[i][k]=(f[i][k]+f[i-1][k-j])%P;
        //     }
        g[i][0]=f[i][0];
        for(int j=1;j<=n*100;j++)
            g[i][j]=(g[i][j-1]+f[i][j])%P;
    }
    int ret=0;
    for(int j=0;j<=10000;j++)
        ret=(ret+f[n][j])%P;
    return ret;
}

int ans[N*10],L,R;

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
    int sc=0;
    L=R=1e9;
    for(int i=1;i<=n;i++)
    {
        L=min(L,(0-ssb[i-1])/i);
        sc+=c[i];
        R=min(R,(sc-ssb[i-1])/i);
    }
    L-=10,R+=10;
    for(int i=L;i<=R;i++)
        ans[i-L]=solve(i);
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        int x;
        scanf("%d",&x);
        if(x<L)
            printf("%d\n",ans[0]);
        else if(x>R)
            puts("0");
        else
            printf("%d\n",ans[x-L]);
    }
}