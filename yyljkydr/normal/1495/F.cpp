#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+1e3+7;

int n,q,p[N],a[N],b[N],f[N],d[N];

int dep[N],anc[N][21],vis[N],cnt[N];

vector<int>g[N];

void dfs(int x)
{
    f[x]=a[x]-b[x];
    for(auto v:g[x])
    {
        dfs(v);
        f[x]+=b[v];
        if(f[v]<0)
            f[x]+=f[v],f[v]=0;
    }
}

int lca(int x,int y)
{
    if(dep[x]<dep[y])
        swap(x,y);
    for(int i=20;i>=0;i--)
        if(dep[x]-(1<<i)>=dep[y])
            x=anc[x][i];
    if(x==y)
        return x;
    for(int i=20;i>=0;i--)
        if(anc[x][i]!=anc[y][i])
            x=anc[x][i],y=anc[y][i];
    return anc[x][0];
}

int dis(int x,int y)
{
    return d[x]+d[y]-2*d[lca(x,y)];
}

set<int>s;

int ans;

void ins(int x)
{
    s.insert(x);
    auto it=s.find(x);
    int u=it==s.begin()?*--s.end():*prev(it);
    int v=it==--s.end()?*s.begin():*next(it);
    ans+=dis(u,x)+dis(x,v)-dis(u,v);
}

void del(int x)
{
    auto it=s.find(x);
    int u=it==s.begin()?*--s.end():*prev(it);
    int v=it==--s.end()?*s.begin():*next(it);
    ans-=dis(u,x)+dis(x,v)-dis(u,v);
    s.erase(it);
}

signed main()
{
    scanf("%lld%lld",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%lld",&p[i]);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%lld",&b[i]);
    stack<int>st;
    p[0]=n+1;
    st.push(0);
    for(int i=1;i<=n;i++)
    {
        while(p[st.top()]<p[i])
            st.pop();
        g[st.top()].push_back(i);
        anc[i][0]=st.top();
        st.push(i);
    }
    dfs(0);
    for(int i=0;i<=n;i++)
        d[i]=d[anc[i][0]]+f[i],dep[i]=dep[anc[i][0]]+1;
    for(int j=1;j<=20;j++)
        for(int i=1;i<=n;i++)
            anc[i][j]=anc[anc[i][j-1]][j-1];
    ins(0);
    cnt[0]++;
    while(q--)
    {
        int x;
        scanf("%lld",&x);
        int y=anc[x][0];
        if(vis[x])
        {
            cnt[y]--;
            if(!cnt[y])
                del(y);
            vis[x]=0;
        }
        else
        {
            if(!cnt[y])
                ins(y);
            cnt[y]++;
            vis[x]=1;
        }
        printf("%lld\n",ans/2+f[0]);
    }
}