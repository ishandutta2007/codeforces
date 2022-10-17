#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T,n;

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

vector<pii>g[N];

int ans[N];

int dfn;

void dfs(int x,int f,int c)
{
    for(auto [v,id]:g[x])
    {
        if(v==f)
            continue;
        ++dfn;
        if(!c)
            ans[id]=dfn^n,ans[v]=dfn;
        else
            ans[id]=dfn,ans[v]=dfn^n;
        dfs(v,x,c^1);
    }
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        int p;
        scanf("%d",&p);
        n=1<<p;
        for(int i=1;i<=n;i++)
            g[i].clear();
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            g[u].push_back({v,i+n});
            g[v].push_back({u,i+n});
        }
        printf("%d\n",1);
        dfn=0;
        dfs(1,0,0);
        ans[1]=n;
        for(int i=1;i<n*2;i++)
            printf("%d%c",ans[i]," \n"[i==n||i+1==n*2]);
    }
}