#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n,m,d[N],f[N],mxd;

vector<int>g[N],s[N];

queue<int>q;

void bfs()
{
    fill(d+1,d+n+1,-1);
    q.push(1);
    d[1]=0;
    while(!q.empty())
    {
        int x=q.front();
        s[d[x]].push_back(x);
        mxd=max(mxd,d[x]);
        q.pop();
        for(auto v:g[x])
        {
            if(d[v]!=-1)
                continue;
            q.push(v);
            d[v]=d[x]+1;
        }
    }
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            g[i].clear(),s[i].clear();
        for(int i=1;i<=m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
        }
        bfs();
        for(int i=1;i<=n;i++)
            f[i]=d[i];
        for(int i=mxd;i>=0;i--)
            for(auto x:s[i])
                for(auto y:g[x])
                    if(d[x]<d[y])
                        f[x]=min(f[x],f[y]);
                    else
                        f[x]=min(f[x],d[y]);
        for(int i=1;i<=n;i++)
            printf("%d%c",f[i]," \n"[i==n]);
    }
}