#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int m;

map<int,int>vis;

int n,c[N];

vector<int>a[N],ans[N],pos[N];

map<int,int> pov[N];

map<int,set<int> >in;

void dfs(int i,int v,int f)
{
    int j=pov[i][v];
    pov[i].erase(v);
    in[v].erase(i);
    ans[i][j]=0;
    if(!in[v].size())
        in.erase(v);
    int x=*in[v].begin();
    in[v].erase(x);
    if(!in[v].size())
        in.erase(v);
    j=pov[x][v];
    ans[x][j]=1;
    pov[x].erase(v);
    if(pov[x].size())
        dfs(x,pov[x].begin()->first,f);
}

int main()
{
    scanf("%d",&m);
    bool ok=1;
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&n);
        c[i]=n;
        ok&=(n%2==0);
        a[i].resize(n+1);
        ans[i].resize(n+1);
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]),vis[a[i][j]]^=1;
    }
    for(auto [x,y]:vis)
        ok&=!y;
    if(!ok)
    {
        puts("NO");
        return 0;
    }
    for(int i=1;i<=m;i++)
    {
        vis.clear();
        for(int j=1;j<=c[i];j++)
        {
            if(vis[a[i][j]])
            {
                ans[i][j]=1;
                vis[a[i][j]]=0;
            }
            else
                vis[a[i][j]]=j;
        }
        for(auto [x,y]:vis)
            if(y)
                pov[i][x]=y,in[x].insert(i);
    }
    while(in.size())
    {
        auto it=in.begin();
        dfs(*(it->second.begin()),it->first,0);
    }
    puts("YES");
    for(int i=1;i<=m;i++,puts(""))
        for(int j=1;j<=c[i];j++)
            putchar(ans[i][j]?'R':'L');
}