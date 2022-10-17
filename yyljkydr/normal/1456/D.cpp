#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=5e3+1e2+7;

int n,t[N],x[N],a[N],r[N];

int f[N][N],g[N];

bool cmp(int x,int y)
{
    return t[x]<t[y];
}

signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&t[i],&x[i]),r[i]=i;
    sort(r+1,r+n+1,cmp);
    for(int i=1;i<=n;i++)
        a[i]=t[r[i]];
    for(int i=1;i<=n;i++)
        t[i]=a[i];
    for(int i=1;i<=n;i++)
        a[i]=x[r[i]];
    for(int i=1;i<=n;i++)
        x[i]=a[i];
    for(int i=1;i<=n;i++)
        g[i]=1e18;
    for(int i=0;i<n;i++)
    {
        if(g[i]<=t[i])
        {
            g[i+1]=min(g[i+1],max(abs(x[i+1]-x[i])+g[i],t[i]));
            for(int j=i+1;j<=n;j++)
                if(abs(x[j]-x[i])*2+g[i]<=t[i])
                    f[i][j]=1;
            for(int j=i+2;j<=n;j++)
                if(max(abs(x[j]-x[i])+g[i],t[i])+abs(x[i+1]-x[j])<=t[i+1])
                    f[i+1][j]=1;
        }
        if(f[i][i+1])
        {
            g[i+2]=min(g[i+2],max(t[i]+abs(x[i]-x[i+2]),t[i+1]));
            for(int j=i+3;j<=n;j++)
                if(max(abs(x[j]-x[i])+t[i],t[i+1])+abs(x[j]-x[i+2])<=t[i+2])
                    f[i+2][j]=1;
        }
        for(int j=i+2;j<=n;j++)
            if(f[i][j])
            {
                if(abs(x[i+1]-x[i])+t[i]<=t[i+1])
                    f[i+1][j]=1;
            }
    }
    if(g[n]<=t[n]||f[n-1][n]==1)
        puts("YES");
    else
        puts("NO");
}