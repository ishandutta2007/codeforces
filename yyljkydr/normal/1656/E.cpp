#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n;

int ans[N];

vector<int>g[N];

void dfs(int x,int f)
{
    ans[x]=ans[f]>0?-g[x].size():g[x].size();
    for(auto v:g[x])
    {
        if(v==f)
            continue;
        dfs(v,x);
    }
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,0);
        for(int i=1;i<=n;i++)
            printf("%d%c",ans[i]," \n"[i==n]),g[i].clear();
    }
}