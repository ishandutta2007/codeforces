#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int n,a[N],b[N];

vector<int>g[N],v[N];

int st[N],ed[N],dc,fa[N];

void dfs(int x,int f)
{
    st[x]=ed[x]=++dc;
    fa[x]=f;
    for(int i=0;i<g[x].size();i++)
    {
        int v=g[x][i];
        if(v==f)
            continue;
        dfs(v,x);
    }
    ed[x]=dc;
}

int c[N];

void add(int l,int r)
{
    c[l]++;
    c[r+1]--;
}

bool cmp(int x,int y)
{
    return st[x]<st[y];
}

bool isanc(int x,int y)
{
    return st[y]>=st[x]&&st[y]<=ed[x];
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),b[i]=a[i];
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(b+1,b+n+1,a[i])-b,v[a[i]].push_back(i);
    dfs(1,0);
    for(int i=1;i<=n;i++)
        for(int j=0;j<g[i].size();j++)
            if(g[i][j]==fa[i])
                g[i].erase(g[i].begin()+j);
    for(int i=1;i<=n;i++)
    {
        sort(v[i].begin(),v[i].end(),cmp);
        if(v[i].size()<=1)
            continue;
        for(int j=2;j<v[i].size();j++)
        {
            int x=v[i][j-1],y=v[i][j];
            if(isanc(x,y))
            {
                puts("0");
                return 0;
            }
        }
        if(isanc(v[i][0],v[i][1]))
        {
            int x=v[i][0],y=v[i][1];
            int son=-1;
            for(int j=0;j<g[x].size();j++)
            {
                if(isanc(g[x][j],y))
                    son=g[x][j];
            }
            for(int j=2;j<v[i].size();j++)
            {
                int z=v[i][j];
                if(!isanc(son,z))
                {
                    puts("0");
                    return 0;
                }
            }
            for(int j=1;j<v[i].size();j++)
                add(st[v[i][j]],ed[v[i][j]]);
            add(1,st[son]-1);
            add(ed[son]+1,n);
        }
        else
        {
            for(int j=0;j<v[i].size();j++)
                add(st[v[i][j]],ed[v[i][j]]);
        }
    }
    for(int i=1;i<=n;i++)
        c[i]+=c[i-1];
    int ans=n;
    for(int i=1;i<=n;i++)
        ans-=(c[i]>0);
    printf("%d\n",ans);
}