#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=3e2+1e1+7,P=998244353;

int n;

vector<int>G[N];

int r;

int f[2][N][N],dep[N];

int g[2][N];

void inc(int &a,int b)
{
    a+=b;
    a>=P?a-=P:0;
}

void dfs(int x,int fa)
{
    dep[x]=0;
    for(int i=1;i<=n;i++)
        f[0][x][i]=f[1][x][i]=0;
    f[0][x][0]=f[1][x][0]=1;
    for(auto v:G[x])
    {
        if(v==fa)
            continue;
        dfs(v,x);
    }
    for(auto v:G[x])
    {
        if(v==fa)
            continue;
        for(int i=0;i<=max(dep[x],dep[v]+1);i++)
            g[0][i]=g[1][i]=0;
        for(int i=0;i<=min(dep[x],r);i++)
            for(int j=0;j<=min(dep[v],r);j++)
            {
                if(i+j+1<=r)
                {
                    inc(g[1][i],f[1][x][i]*f[0][v][j]%P);
                    inc(g[1][j+1],f[0][x][i]*f[1][v][j]%P);
                }
                else
                {
                    inc(g[0][j+1],f[1][x][i]*f[0][v][j]%P);
                    inc(g[0][i],f[0][x][i]*f[1][v][j]%P);
                }
                if(j+1<r&&i<r)
                    inc(g[0][max(i,j+1)],f[0][x][i]*f[0][v][j]%P);
                inc(g[1][min(i,j+1)],f[1][x][i]*f[1][v][j]%P);
            }
        dep[x]=max(dep[x],dep[v]+1);
        for(int i=0;i<=dep[x];i++)
            f[0][x][i]=g[0][i],f[1][x][i]=g[1][i];
    }
}

int cnt[N];

signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%lld%lld",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=0;i<=n;i++)
    {
        r=i;
        dfs(1,0);
        for(int j=0;j<=n;j++)
            inc(cnt[i],f[1][1][j]);
    }
    for(int i=n;i>=1;i--)
        inc(cnt[i],P-cnt[i-1]);
    int ans=0;
    for(int i=0;i<=n;i++)
        inc(ans,cnt[i]*(i-1)%P);
    ans=(ans+n)%P;
    for(int i=1;i<=n;i++)
        ans=(ans*(P+1)/2)%P;
    printf("%lld\n",ans);
}