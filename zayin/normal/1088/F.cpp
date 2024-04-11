#include<bits/stdc++.h>
#define maxh 20
#define maxn 500050
using namespace std;
typedef long long LL;

int n,rt=1;
int a[maxn];
vector<int> G[maxn];

void init()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        if (a[rt]>a[i])
            rt=i;
    }
    for (int k=1;k<n;++k)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

LL ans;

int fa[maxn][maxh];

void dfs(int i)
{
    LL d,mn=1LL<<60;
    for (d=1;fa[i][d-1];++d)
        fa[i][d]=fa[fa[i][d-1]][d-1];
    for (d=0;fa[i][d];++d)
        mn=min(mn,(d+1)*a[fa[i][d]]+a[i]);
    mn=min(mn,(d+1)*a[rt]+a[i]);
    if (fa[i][0])
        ans+=mn;

    for (auto j:G[i])
    {
        if (fa[i][0]==j)  continue;
        fa[j][0]=i;
        dfs(j);
    }
}

void solve()
{
    dfs(rt);
    printf("%lld\n",ans);
}

int main()
{
    init();
    solve();
    return 0;
}