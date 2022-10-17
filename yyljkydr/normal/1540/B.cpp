#include<bits/stdc++.h>
using namespace std;

const int N=2e2+1e1+7,P=1e9+7,iv2=(P+1)/2;

int n;

int dep[N],fa[N];

vector<int>sb[N],g[N];

int rem[N][N];

int dp(int x,int y)
{
    if(!x)
        return 1;
    if(!y)
        return 0;
    if(rem[x][y])
        return rem[x][y];
    return rem[x][y]=1ll*iv2*(dp(x-1,y)+dp(x,y-1))%P;
}

void dfs(int x,int f)
{
    dep[x]=dep[f]+1;
    fa[x]=f;
    sb[x].clear();
    sb[x].push_back(x);
    for(auto v:g[x])
    {
        if(v==f)
            continue;
        dfs(v,x);
        for(auto p:sb[v])
            sb[x].push_back(p);
    }
}

int solve(int x)
{
    dfs(x,0);
    int ret=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<g[i].size();j++)
            for(int k=j+1;k<g[i].size();k++)
            {
                if(g[i][j]==fa[i]||g[i][k]==fa[i])
                    continue;
                for(auto x:sb[g[i][j]])
                    for(auto y:sb[g[i][k]])
                    {
                        int dx=dep[x]-dep[i];
                        int dy=dep[y]-dep[i];
                        if(x<y)
                            swap(dx,dy);
                        ret=(ret+dp(dx,dy))%P;
                    }
            }
        for(auto x:sb[i])
            if(i>x)
                ret=(ret+1)%P;
    }
    return ret;
}

int qpow(int a,int b)
{
    int ret=1;
    while(b)
    {
        if(b&1)
            ret=1ll*ret*a%P;
        b>>=1;
        a=1ll*a*a%P;
    }
    return ret;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=(ans+solve(i))%P;
    ans=1ll*ans*qpow(n,P-2)%P;
    printf("%d\n",ans);
}