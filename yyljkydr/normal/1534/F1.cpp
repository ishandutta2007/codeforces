#include<bits/stdc++.h>
using namespace std;

const int N=4e5+1e3+7;

int n,m;

vector<int>g[N];

int ind[N];

string s[N];

vector<int>ne[N];

int get(int x,int y)
{
    return (x-1)*m+y;
}

void add(int x,int y)
{
    g[x].push_back(y);
}

int dfn[N],low[N],dc,inst[N],a[N],ok[N];

int st[N],top,scc,bel[N];

void tarjan(int x)
{
    st[++top]=x;
    dfn[x]=low[x]=++dc;
    inst[x]=1;
    for(auto v:g[x])
    {
        if(!dfn[v])
        {
            tarjan(v);
            low[x]=min(low[x],low[v]);
        }
        else if(inst[v])
            low[x]=min(low[x],dfn[v]);
    }
    if(dfn[x]==low[x])
    {
        ++scc;
        int u;
        do
        {
            u=st[top--];
            inst[u]=0;
            bel[u]=scc;
        }while(u!=x);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>s[i];
    for(int i=1;i<=n;i++)
    {
        s[i].resize(m+1);
        for(int j=m;j>=1;j--)
            s[i][j]=s[i][j-1];
    }
    s[0].resize(m+1);
    s[n+1].resize(m+1);
    for(int i=1;i<=m;i++)
        cin>>a[i];
    ne[n+1].resize(m+2);
    for(int i=n;i>=0;i--)
    {
        ne[i].resize(m+2);
        for(int j=1;j<=m;j++)
            if(s[i+1][j]=='#')
                ne[i][j]=get(i+1,j);
            else 
                ne[i][j]=ne[i+1][j];
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            ok[get(i,j)]=(s[i][j]=='#');
            if(!ok[get(i,j)])
                continue;
            if(s[i-1][j]=='#')
                add(get(i,j),get(i-1,j));
            if(ne[i][j])
                add(get(i,j),ne[i][j]);
            if(ne[i-1][j-1])
                add(get(i,j),ne[i-1][j-1]);
            if(ne[i-1][j+1])
                add(get(i,j),ne[i-1][j+1]);
        }
    for(int i=1;i<=n*m;i++)
        if(!dfn[i]&&ok[i])
            tarjan(i);
    for(int i=1;i<=n*m;i++)
        for(auto v:g[i])
            if(bel[i]!=bel[v])
                ++ind[bel[v]];
    int ans=0;
    for(int i=1;i<=scc;i++)
        if(!ind[i])
            ans++;
    cout<<ans<<endl;
}