#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e6+1e3+7,INF=1e18;

int T,n;

int f[N][2],t[N],h[N];

vector<int>g[N];

vector<int>c[3];

int id[2];

bool cmp(int a,int b)
{
    return f[a][id[0]]-f[a][id[1]]>f[b][id[0]]-f[b][id[1]];
}

void dfs(int x,int F)
{
    for(auto v:g[x])
    {
        if(v==F)
            continue;
        dfs(v,x);
    }
    for(int i=0;i<3;i++)
        c[i].clear();
    for(auto v:g[x])
    {
        if(v==F)
            continue;
        c[(int)(h[v]>=h[x])+(int)(h[v]==h[x])].push_back(v);
    }
    int bs=0;
    for(int j=0;j<2;j++)
        for(auto v:c[j])
            bs+=f[v][j];
    id[0]=0,id[1]=1;
    if(c[0].size()>c[1].size())
        swap(id[0],id[1]);
    assert(c[id[0]].size()<=c[id[1]].size());
    bs+=c[id[0]].size()*t[x];
    int rem=c[id[1]].size()-c[id[0]].size();
    sort(c[2].begin(),c[2].end(),cmp);
    int sf=0;
    for(auto x:c[2])
        sf+=f[x][id[1]];
    for(int i=0;i<=c[2].size();i++)//how many zeros
    {
        int sz[2]={0,0};
        sz[id[0]]=i;
        sz[id[1]]=c[2].size()-i+rem;
        int tot=min(sz[0],sz[1]);
        sz[0]-=tot,sz[1]-=tot;
        f[x][0]=max(f[x][0],bs+sf+t[x]*(F&&sz[0])+t[x]*tot);
        f[x][1]=max(f[x][1],bs+sf+t[x]*(F&&sz[1])+t[x]*tot);
        if(i!=c[2].size())
        {
            int v=c[2][i];
            sf+=f[v][id[0]]-f[v][id[1]];
        }
    }
    // if(h[x]!=h[F])
    //     f[x][h[x]<h[F]]=-INF;
}

signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&t[i]);
    for(int i=1;i<=n;i++)
        scanf("%lld",&h[i]);
    h[0]=h[1];
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%lld%lld",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans+=g[i].size()*t[i];
    dfs(1,0);
    ans-=f[1][0];
    printf("%lld\n",ans);
}