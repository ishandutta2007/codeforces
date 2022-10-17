#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int n;

vector<int>g[N];

int ans;

struct DP{
    int a,b;
}f[N][2];

bool operator <(const DP &a,const DP &b)
{
    if(a.a!=b.a)
        return a.a>b.a;
    return a.b<b.b;
}

void operator +=(DP &a,DP b)
{
    a.a+=b.a;
    a.b+=b.b;
}

void dfs(int x,int F)
{
    f[x][0]={0,1};
    f[x][1]={1,g[x].size()};
    for(auto v:g[x])
    {
        if(v==F)
            continue;
        dfs(v,x);
        f[x][0]+=min(f[v][0],f[v][1]);
        f[x][1]+=f[v][0];
    }   
}

int w[N];

void gans(int x,int F,int y)
{
    if(!y)
        w[x]=1;
    else
        w[x]=g[x].size();
    for(auto v:g[x])
    {
        if(v==F)
            continue;
        if(!y)
            gans(v,x,f[v][0]<f[v][1]?0:1);
        else
            gans(v,x,0);
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    DP ans=min(f[1][0],f[1][1]);
    printf("%d %d\n",ans.a+(n==2),ans.b);
    gans(1,0,f[1][1]<f[1][0]);
    for(int i=1;i<=n;i++)
        printf("%d%c",w[i]," \n"[i==n]);
}