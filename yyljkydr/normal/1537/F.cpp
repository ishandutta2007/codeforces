#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n,m;

vector<int>g[N];

int t[N];

int vis[N];

void dfs(int x,int f)
{
    for(auto v:g[x])
    {
        if(v==f||vis[v])
            return;
        dfs(v,x);
        t[x]-=t[v];
    }
}

vector<int>cir;

int fd;

void col(int x,int c)
{
    if(vis[x]!=-1)
    {
        if(c!=vis[x])
            fd=1;
        return;
    }
    vis[x]=c;
    for(auto v:g[x])
        col(v,c^1);
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&t[i]);
        long long sum=0;
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            t[i]=x-t[i];
            g[i].clear();
            sum+=t[i];
        }
        for(int i=1;i<=m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(sum&1)
        {
            puts("NO");
        }
        else
        {
            fill(vis+1,vis+n+1,-1);
            fd=0;
            col(1,0);
            if(fd)
            {
                puts("YES");
            }
            else
            {
                long long st=0;
                for(int i=1;i<=n;i++)
                    if(vis[i])
                        st+=t[i];
                    else
                        st-=t[i];
                puts(st==0?"YES":"NO");
            }
        }
    }
}