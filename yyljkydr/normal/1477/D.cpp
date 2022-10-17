#include<bits/stdc++.h>
using namespace std;

const int N=5e5+1e3+7;

int T,n,m;

vector<int>g[N],s[N],r[N],t[N];

int p[N],q[N],vis[N],dep[N],deg[N],fa[N],cen[N],lef[N];

unordered_set<int>tmpr[N];

void dfs(int x,int f)
{
    vis[x]=1;
    fa[x]=f;
    for(auto v:s[x])
    {
        if(vis[v])
            continue;
        t[x].push_back(v);
        t[v].push_back(x);
        dfs(v,x);
    }
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        fill(deg+1,deg+n+1,0);
        fill(dep+1,dep+n+1,0);
        fill(p+1,p+n+1,0);
        fill(q+1,q+n+1,0);
        for(int i=1;i<=n;i++)
            s[i].clear(),g[i].clear(),r[i].clear(),t[i].clear(),tmpr[i].clear();
        for(int i=1;i<=m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        fill(vis+1,vis+n+1,0);
        for(int i=1;i<=n;i++)
            if(deg[i]!=n-1)
            {
                for(auto v:g[i])
                    vis[v]=i;
                int x=1;
                while(x==i||vis[x]==i)
                    x++;
                s[i].push_back(x);
                s[x].push_back(i);
            }
        fill(vis+1,vis+n+1,0);
        for(int i=1;i<=n;i++)
            if(deg[i]!=n-1&&!vis[i])
                dfs(i,0);
        fill(cen+1,cen+n+1,0);
        fill(lef+1,lef+n+1,0);
        for(int i=1;i<=n;i++)
            if(deg[i]!=n-1)
            {
                if(cen[i]||lef[i])
                    continue;
                for(auto v:t[i])
                    if(cen[v])
                        lef[i]=v,tmpr[v].insert(i);
                if(!lef[i])
                {
                    cen[i]=1;
                    for(auto v:t[i])
                        if(tmpr[lef[v]].size()>1)
                        {
                            tmpr[lef[v]].erase(tmpr[lef[v]].find(v));
                            lef[v]=i;
                            tmpr[i].insert(v);
                            break;
                        }
                        else if(!lef[v]&&!cen[v])
                        {
                            tmpr[i].insert(v);
                            lef[v]=i;
                            break;
                        }
                    if(!tmpr[i].size())
                    {
                        int y=t[i][0];
                        lef[i]=y;
                        cen[lef[y]]=0;
                        lef[lef[y]]=y;
                        tmpr[y].insert(i);
                        tmpr[y].insert(lef[y]);
                        tmpr[lef[y]].clear();
                        cen[y]=1;
                        lef[y]=0;
                    }
                }
            }
        for(int i=1;i<=n;i++)
            if(tmpr[i].size())
                for(auto x:tmpr[i])
                    r[i].push_back(x);
        int cnt=1;
        for(int i=1;i<=n;i++)
            if(r[i].size())
            {
                int k=(int)r[i].size()+1;
                assert(k!=1);
                p[i]=cnt;
                q[i]=cnt+k-1;
                for(int j=0;j<r[i].size();j++)
                    p[r[i][j]]=cnt+j+1,q[r[i][j]]=cnt+j;
                cnt+=k;
            }
        for(int i=1;i<=n;i++)
            if(deg[i]==n-1)
                p[i]=q[i]=cnt++;
        for(int i=1;i<=n;i++)
            printf("%d%c",p[i]," \n"[i==n]);
        for(int i=1;i<=n;i++)
            printf("%d%c",q[i]," \n"[i==n]);
    }   
}