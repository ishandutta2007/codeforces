#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

typedef long long ll;

int T,n;

vector<int>g[N],v[N];

int a[N],dep[N],fa[N],d;

ll f[N];

void dfs(int x,int f)
{
    dep[x]=dep[f]+1;
    fa[x]=f;
    v[dep[x]].push_back(x);
    d=max(d,dep[x]);
    for(auto v:g[x])
    {
        if(v==f)
            continue;
        dfs(v,x);
    }
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            g[i].clear(),v[i].clear();
        for(int i=2;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            g[x].push_back(i);
            g[i].push_back(x);
        }
        for(int i=2;i<=n;i++)
            scanf("%d",&a[i]);
        dfs(1,0);
        //f[i] = max( f[p[i]] + |a[x] - a[i]| );
        //f[i] = max( f[p[v]] + |a[i] - a[v]| );
        f[1]=0;
        for(int i=2;i<=d;i++)
        {
            int mx=0,mn=1e9;
            ll ma=-1e15,mb=-1e15;
            for(auto x:v[i])
                mx=max(mx,a[x]),mn=min(mn,a[x]),ma=max(ma,f[fa[x]]+a[x]),mb=max(mb,f[fa[x]]-a[x]);
            for(auto x:v[i])
            {
                f[x]=f[fa[x]]+max(mx-a[x],a[x]-mn);
                f[x]=max(f[x],ma-a[x]);
                f[x]=max(f[x],mb+a[x]);
            }
        }
        ll ans=0;
        for(int i=1;i<=n;i++)
            ans=max(ans,f[i]);
        printf("%lld\n",ans);
    }
}