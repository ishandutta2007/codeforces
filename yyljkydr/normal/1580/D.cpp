#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=4e3+1e2+7;

int n,m,st[N],top,a[N];

int f[N][N],tot,g[N];

int dfs(int l,int r)
{
    int p=min_element(a+l,a+r+1)-a;
    int x=++tot;
    //[l,p-1] [p+1,r]
    for(int j=0;j<=r-l+1;j++)
        f[x][j]=-1e18;
    f[x][0]=0;
    f[x][1]=a[p]*(m-1);
    int ls=-1,rs=-1;
    if(l<=p-1)
        ls=dfs(l,p-1);
    if(p+1<=r)
        rs=dfs(p+1,r);
    int sz=1;
    if(ls!=-1)
    {
        int szl=p-l;
        for(int j=0;j<=szl+sz;j++)
            g[j]=-1e18;
        for(int j=0;j<=szl;j++)
            for(int k=0;k<=sz;k++)
                g[j+k]=max(g[j+k],f[ls][j]+f[x][k]-2*j*k*a[p]);
        sz+=szl;
        for(int j=0;j<=sz;j++)
            f[x][j]=max(f[x][j],g[j]);
    }
    if(rs!=-1)
    {
        int szr=r-p;
        for(int j=0;j<=szr+sz;j++)
            g[j]=-1e18;
        for(int j=0;j<=szr;j++)
            for(int k=0;k<=sz;k++)
                g[j+k]=max(g[j+k],f[rs][j]+f[x][k]-2*j*k*a[p]);
        sz+=szr;
        for(int j=0;j<=sz;j++)
            f[x][j]=max(f[x][j],g[j]);
    }
    return x;
}

signed main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    dfs(1,n);
    printf("%lld\n",f[1][m]);   
}