#include<bits/stdc++.h>
using namespace std;

const int N=3e3+1e2+7;

int n,m;

set<int>g[N],og[N],ng[N];

vector<int>ans;

set<int>g2;

void dfs(int x)
{
    while(!g[x].empty())
    {
        int y=*g[x].begin();
        g[x].erase(y);
        g[y].erase(x);
        dfs(y);
    }
    ans.push_back(x);
}

bool chk(int x)
{
    for(int i=1;i<=n;i++)
        g[i]=ng[i];
    ans.clear();
    int cntm=0,cnt=0;
    for(int i=1;i<=n;i++)
        cntm+=g[i].size(),cnt+=g[i].size()&1;
    if(cnt>2)
        return 0;
    if(cnt&&(!(g[x].size()&1)))
        return 0;
    dfs(x);
    return (ans.size()-1)*2==cntm;
}

void out(int x)
{
    printf("%d\n",ans.size()+g2.size()*2+1);
    for(int i=0;i<ans.size();i++)
        printf("%d ",ans[i]);
    printf("-1 ");
    for(auto u:g2)
        printf("%d %d ",u,x);
    puts("");
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        og[u].insert(v);
        og[v].insert(u);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            ng[j]=og[j];
        g2.clear();
        for(auto x:ng[i])
            if(ng[x].size()&1)
                g2.insert(x);
        for(auto x:g2)
            ng[i].erase(x),ng[x].erase(i);
        if(chk(i))
        {
            out(i);
            return 0;
        }
        for(auto it=og[i].begin();it!=og[i].end();it++)
        {
            int x=*it;
            if(ng[i].find(x)!=ng[i].end())
            {
                ng[i].erase(x);
                ng[x].erase(i);
                g2.insert(x);
            }
            else
            {
                ng[i].insert(x);
                ng[x].insert(i);
                g2.erase(x);
            }
            if(chk(i))
            {
                out(i);
                return 0;
            }
            if(ng[i].find(x)==ng[i].end())
            {
                ng[i].insert(x);
                ng[x].insert(i);
                g2.erase(x);
            }
            else
            {
                ng[i].erase(x);
                ng[x].erase(i);
                g2.insert(x);
            }
        }
    }
    puts("0");
}