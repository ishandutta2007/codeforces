#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T;

int n,d[N];

vector<pair<int,int> >g[N];

int ans[N];

void dfs(int x,int f,int w)
{
    for(auto [v,id]:g[x])
    {
        if(v==f)
            continue;
        ans[id]=w;
        dfs(v,x,5-w);
    }
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            d[i]=0,g[i].clear();
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            d[u]++;
            d[v]++;
            g[u].push_back({v,i});
            g[v].push_back({u,i});
        }
        if(*max_element(d+1,d+n+1)>=3)
            puts("-1");
        else
        {
            for(int i=1;i<=n;i++)
                if(d[i]==1)
                {
                    dfs(i,0,2);
                    break;
                }
            for(int i=1;i<n;i++)
                printf("%d%c",ans[i]," \n"[i+1==n]);
        }
    }
}