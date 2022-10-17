#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e3+1e2+7;

int T,n,m;

vector<int>g[N];

int a[N],b[N];

int ok[N],vis[N];

int tag[N];

bool dfs(int x,int f,int en,int nd)
{
    vis[x]=1;
    for(auto v:g[x])
    {
        if(v==f)
            continue;
        if(vis[v])
        {
            if(nd)
            {
                tag[x]=1;
                return 1;
            }
        }
        else if(en>a[v])
        {
            int ret=dfs(v,x,en+b[v]*(!ok[v]),nd|(!ok[v]));
            if(ret)
            {
                tag[x]=1;
                return ret;
            }
        }
    }
    // vis[x]=0;
    return 0;
}

bool chk(int beg)
{
    fill(ok+1,ok+n+1,0);
    int vs=1;
    int now=beg;
    while(vs!=n)
    {
        fill(vis+1,vis+n+1,0);
        fill(tag+1,tag+n+1,0);
        int go=dfs(1,0,now,0);
        if(!go)
            return 0;
        for(int i=2;i<=n;i++)
            if(tag[i]&&!ok[i])
                now+=b[i],ok[i]=1,vs++;
    }
    return 1;
}

signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld",&n,&m);
        for(int i=1;i<=n;i++)
            g[i].clear();
        for(int i=2;i<=n;i++)
            scanf("%lld",&a[i]);
        for(int i=2;i<=n;i++)
            scanf("%lld",&b[i]);
        for(int i=1;i<=m;i++)
        {
            int u,v;
            scanf("%lld%lld",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int l=0,r=*max_element(a+1,a+n+1)+1;
        while(r-l>1)
        {
            int mid=(l+r)>>1;
            if(chk(mid))
                r=mid;
            else
                l=mid;
        }
        printf("%lld\n",r);
    }
}