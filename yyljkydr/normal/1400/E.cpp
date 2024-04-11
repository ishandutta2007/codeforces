#include<bits/stdc++.h>
using namespace std;

const int N=5e3+1e2+7,INF=1e9;

int n,f[N][N],a[N],g[N],h[N];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            f[i][j]=1e9;
    f[0][0]=0;
    for(int i=0;i<=n+1;i++)
        h[i]=INF;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=min(a[i],n);j++)
        {
            f[i][j]=min(g[j]+j+(j!=a[i]),h[j+1]+(j!=a[i]));
            g[j]=min(j?g[j-1]:INF,f[i][j]-j);
        }
        for(int j=min(a[i],n)+1;j<=n;j++)
            g[j]=g[j-1],h[j]=INF;
        h[min(a[i],n)]=f[i][min(a[i],n)];
        for(int j=min(a[i],n)-1;j>=0;j--)
            h[j]=min(f[i][j],h[j+1]);
    }
    int ans=1e9;
    for(int i=0;i<=n;i++)
        ans=min(ans,f[n][i]);
    printf("%d\n",ans);
}