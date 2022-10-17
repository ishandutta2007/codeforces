#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

vector<int>g[N],h[N];

int n,m,q;

int vis[N],fa[N],dep[N];

int a[N],b[N],d[N],l[N];

void span(int x)
{
    vis[x]=1;
    for(auto v:h[x])
        if(!vis[v])
            dep[v]=dep[x]+1,fa[v]=x,g[x].push_back(v),span(v);
}

int cov(int x,int y)
{
    if(dep[x]<dep[y])
        swap(x,y);
    while(dep[x]>dep[y])
        d[x]^=1,x=fa[x];
    while(x!=y)
        d[x]^=1,d[y]^=1,x=fa[x],y=fa[y];
    return x;
}

vector<int>p;

int go(int x,int y,vector<int>&p)
{
    p.push_back(x);
    if(x==y)
        return 1;
    for(auto v:g[x])
        if(go(v,y,p))
            return 1;
    p.pop_back();
    return 0;
}

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

pii dp(int x)
{
    int ret=0,tf=0;
    for(auto v:g[x])
    {
        auto [s,f]=dp(v);
        ret+=s;
        if(tf&&f)
            ret++;
        tf^=f;
    }
    if(d[x]&&tf)
        return mp(ret,tf);
    else if(d[x])
        return mp(ret,1);
    else if(tf)
        return mp(ret+1,0);
    else
        return mp(ret,0);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        h[u].push_back(v);
        h[v].push_back(u);
    }
    span(1);
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        l[i]=cov(a[i],b[i]);
    }
    int ans=1;
    for(int i=1;i<=n;i++)
        ans&=!d[i];
    if(ans)
    {
        puts("YES");
        for(int i=1;i<=q;i++)
        {
            p.clear();
            go(l[i],a[i],p);
            reverse(p.begin(),p.end());
            p.pop_back();
            go(l[i],b[i],p);
            printf("%d\n",p.size());
            for(auto x:p)
                printf("%d ",x);
            puts("");
        }
    }
    else
    {
        puts("NO");
        printf("%d\n",dp(1).fs);
    }
}