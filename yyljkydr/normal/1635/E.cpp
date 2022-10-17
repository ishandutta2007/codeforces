#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

int n,m;

int t[N],u[N],v[N],c[N];

vector<int>g[N];

bool dfs(int x,int col)
{
    c[x]=col;
    bool ret=1;
    for(auto v:g[x])
        if(c[v]==-1)
            dfs(v,col^1);
        else
            ret&=c[x]^c[v];
    return ret;
}

int ans[N],ind[N];

queue<int>q;

bool topo()
{
    for(int i=1;i<=n;i++)
        if(!ind[i])
            q.push(i);
    int cnt=0;
    while(!q.empty())
    {
        auto x=q.front();
        q.pop();
        ans[x]=++cnt;
        for(auto v:g[x])
            if(!--ind[v])
                q.push(v);
    }
    return cnt==n;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&t[i],&u[i],&v[i]);
        if(t[i]==2)
            t[i]=0;
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
    }
    fill(c+1,c+n+1,-1);
    for(int i=1;i<=n;i++)
        if(c[i]==-1)
        {
            if(!dfs(i,0))
            {
                puts("NO");
                return 0;
            }
        }
    for(int i=1;i<=n;i++)
        g[i].clear();
    //c[i] = 0 -> L
    //t[i] = 1 -> L < R
    for(int i=1;i<=m;i++)
        if(t[i]^c[u[i]])
            g[u[i]].push_back(v[i]),++ind[v[i]];
        else
            g[v[i]].push_back(u[i]),++ind[u[i]];
    if(!topo())
    {
        puts("NO");
        return 0;
    }
    puts("YES");
    for(int i=1;i<=n;i++)
        printf("%c %d\n","LR"[c[i]],ans[i]);
}