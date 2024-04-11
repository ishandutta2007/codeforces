#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int n,a[N],d[N];

vector<int>g[N];

set<int>s[N];

int ans;

void dfs(int x,int f)
{
    d[x]=a[x]^d[f];
    s[x].insert(d[x]);
    bool vis=0;
    for(auto v:g[x])
    {
        if(v==f)
            continue;
        dfs(v,x);
        if(s[v].size()>s[x].size())
            s[x].swap(s[v]);
        for(auto p:s[v])
            vis|=s[x].count(p^a[x]);
        for(auto p:s[v])
            s[x].insert(p);
    }
    if(vis)
        s[x].clear(),ans++;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    printf("%d\n",ans);
}