#include<bits/stdc++.h>
#define maxn 300050
#define inf (1LL<<30)
using namespace std;
typedef long long LL;

int n;
LL val[maxn]={-1};

vector<int> G[maxn];

void init()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%lld",&val[i]);
    for (int k=1;k<n;++k)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

LL S=-inf,cnt,T[maxn];

LL dfs1(int i,int fa=0)
{
    T[i]=val[i];
    for (auto j:G[i])
    {
        if (fa==j)  continue;
        T[i]+=max(0LL,dfs1(j,i));
    }
    S=max(S,T[i]);
    return T[i];
}

LL dfs2(int i,int fa=0)
{
    T[i]=val[i];
    for (auto j:G[i])
    {
        if (fa==j)  continue;
        T[i]+=max(0LL,dfs2(j,i));
    }
    if (T[i]>=S)
        ++cnt,T[i]=0;
    return T[i];
}

void solve()
{
    dfs1(1);
    dfs2(1);
    printf("%lld %lld\n",S*cnt,cnt);
}

int main()
{
    init();
    solve();
    return 0;
}