#include<bits/stdc++.h>
using namespace std;

const int N=5e3+1e3+7,P=998244353;

int n,k,dep[N];

int f[N][N],h[N];

vector<int>g[N];

void inc(int &a,int b)
{
    a+=b;
    a>=P?a-=P:0;
}

void dfs(int x,int fa)
{
    f[x][0]=1;
    for(auto v:g[x])
    {
        if(v==fa)
            continue;
        dfs(v,x);
    }
    for(auto v:g[x])
    {
        if(v==fa)
            continue;
        for(int j=0;j<=min(k,max(dep[x],dep[v]+1));j++)
            h[j]=0;
        for(int j=0;j<=min(k,dep[x]);j++)
            for(int t=0;t<=min(k,dep[v]);t++)
            {
                if(j+t+1<=k)
                    inc(h[max(j,t+1)],1ll*f[x][j]*f[v][t]%P);
                inc(h[j],1ll*f[x][j]*f[v][t]%P);
            }
        dep[x]=max(dep[x],dep[v]+1);
        for(int j=0;j<=min(k,dep[x]);j++)
            f[x][j]=h[j];
    }
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    int ans=0;
    for(int i=0;i<=k;i++)
        inc(ans,f[1][i]);
    printf("%d\n",ans);
}