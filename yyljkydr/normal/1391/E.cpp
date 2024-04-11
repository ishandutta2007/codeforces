#include<bits/stdc++.h>
using namespace std;

const int N=5e5+1e3+7;

int T,n,m,d[N];

vector<int>g[N],c[N];

int vis[N];

void dfs(int x,int f)
{
    if(vis[x])
        return;
    vis[x]=1;
    d[x]=d[f]+1;
    c[d[x]].push_back(x);
    for(auto v:g[x])
        dfs(v,x);
}

vector<pair<int,int> >ans;

vector<int>path;

void get_path(int x,int y)
{
    if(vis[x])
        return;
    vis[x]=1;
    path.push_back(x);
    if(x==y)
    {
        for(auto t:path)
            printf("%d ",t);
        puts("");
        return;
    }
    for(auto v:g[x])
        get_path(v,y);
    if(path.size()&&path.back()==x)
        path.pop_back();
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            g[i].clear();
        for(int i=1;i<=m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        fill(vis+1,vis+n+1,0);
        dfs(1,0);
        int p=max_element(d+1,d+n+1)-d;
        fill(vis+1,vis+n+1,0);
        d[p]=0;
        for(int i=1;i<=n;i++)
            c[i].clear();
        dfs(p,0);
        int q=max_element(d+1,d+n+1)-d;
        if(d[q]>=(n+1)/2)
        {
            puts("PATH");
            printf("%d\n",d[q]);
            fill(vis+1,vis+n+1,0);
            path.clear();
            get_path(p,q);
        }
        else
        {
            ans.clear();
            for(int i=1;i<=d[q];i++)
                for(int j=0;j+1<c[i].size();j+=2)
                    ans.push_back(make_pair(c[i][j],c[i][j+1]));
            puts("PAIRING");
            printf("%d\n",ans.size());
            for(auto [x,y]:ans)
                printf("%d %d\n",x,y);
        }
    }
}