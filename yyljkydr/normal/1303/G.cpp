#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+1e3+7;

int n,a[N];

vector<int>g[N];

struct Line{
    int k,b;

    void init()
    {
        k=b=0;
    }

    int eval(int x)
    {
        return k*x+b;
    }
};

int cnt;

struct T{
    int l,r,ls,rs;
    Line L;
}t[N*2+1];

vector<int>X;

int build(int l,int r)
{
    int x=++cnt;
    t[x].l=l,t[x].r=r;
    t[x].L.init();
    if(l==r)
        return x;
    int mid=(l+r)>>1;
    t[x].ls=build(l,mid);
    t[x].rs=build(mid+1,r);
    return x;
}

bool goL(Line a,Line b,int x)
{
    //if intersection of a and b is less than or equal to x
    return abs(b.b-a.b)<=x*abs(a.k-b.k);
}

void upd(int x,Line vL)
{
    int mid=(t[x].l+t[x].r)>>1;
    if(t[x].L.eval(X[mid])<vL.eval(X[mid]))
        swap(t[x].L,vL);
    if(t[x].l==t[x].r)
        return;
    int fa=t[x].L.eval(X[t[x].l])<vL.eval(X[t[x].l]);
    int fb=t[x].L.eval(X[t[x].r])>vL.eval(X[t[x].r]);
    if(!(fa^fb))
        return;
    if(goL(t[x].L,vL,X[mid]))
        upd(t[x].ls,vL);
    else
        upd(t[x].rs,vL);
}

int qry(int x,int p)
{
    int ret=t[x].L.eval(X[p]);
    if(t[x].l==t[x].r)
        return ret;
    int mid=(t[x].l+t[x].r)>>1;
    if(p<=mid)
        ret=max(ret,qry(t[x].ls,p));
    else
        ret=max(ret,qry(t[x].rs,p));
    return ret;
}

int vis[N];

int sz[N],nsz,mx[N];

void grs(int x,int f)
{
    nsz++;
    for(auto v:g[x])
    {
        if(vis[v]||v==f)
            continue;
        grs(v,x);
    }
}

int rt;

void getsz(int x,int f)
{
    sz[x]=1;
    mx[x]=0;
    for(auto v:g[x])
    {
        if(vis[v]||v==f)
            continue;
        getsz(v,x);
        sz[x]+=sz[v];
        mx[x]=max(mx[x],sz[v]);
    }
    mx[x]=max(mx[x],nsz-sz[x]);
    if(mx[x]<mx[rt])
        rt=x;
}

int ans;

struct Data{
    int ps,s,l;
};

vector<Data>d[N];

void gpath(int x,int f,vector<Data>&d,int ps,int s,int l)
{
    bool isleaf=1;
    ps+=a[x]+s,s+=a[x],l++;
    for(auto v:g[x])
    {
        if(vis[v]||v==f)
            continue;
        isleaf=0;
        gpath(v,x,d,ps,s,l);
    }
    if(isleaf)
        d.push_back(Data{ps,s,l}),ans=max(ans,ps);
}

void initSeg(int n,vector<int>&nX)
{
    cnt=0;
    build(0,n-1);
    X=nX;
}

vector<int>vs,vl;

void solve(int x)
{
    nsz=0;
    grs(x,0);
    rt=0;
    getsz(x,0);
    int tot=0;
    vs.clear(),vl.clear();
    for(auto v:g[rt])
    {
        if(vis[v])
            continue;
        d[v].clear();
        gpath(v,rt,d[v],a[rt],a[rt],1);
        for(auto [ps,s,l]:d[v])
            vs.push_back(s),vl.push_back(l);
        tot+=d[v].size();
    }
    sort(vs.begin(),vs.end());
    sort(vl.begin(),vl.end());
    if(!tot)
        return;
    initSeg(tot,vs);
    //as front
    for(int i=0;i<g[rt].size();i++)
    {
        int v=g[rt][i];
        if(vis[v])
            continue;
        for(auto [ps,s,l]:d[v])
        {
            int pos=lower_bound(X.begin(),X.end(),s)-X.begin();
            ans=max(ans,qry(1,pos)+s*(l+1)-ps);
        }
        for(auto [ps,s,l]:d[v])
            upd(1,Line{l-1,ps-a[rt]*l});
    }

    initSeg(tot,vs);

    for(int i=(int)g[rt].size()-1;i>=0;i--)
    {
        int v=g[rt][i];
        if(vis[v])
            continue;
        for(auto [ps,s,l]:d[v])
        {
            int pos=lower_bound(X.begin(),X.end(),s)-X.begin();
            ans=max(ans,qry(1,pos)+s*(l+1)-ps);
        }
        for(auto [ps,s,l]:d[v])
            upd(1,Line{l-1,ps-a[rt]*l});
    }
    //as after
    initSeg(tot,vl);

    for(int i=0;i<g[rt].size();i++)
    {
        int v=g[rt][i];
        if(vis[v])
            continue;
        for(auto [ps,s,l]:d[v])
        {
            int pos=lower_bound(X.begin(),X.end(),l)-X.begin();
            ans=max(ans,qry(1,pos)+ps);
        }
        for(auto [ps,s,l]:d[v])
            upd(1,Line{s-a[rt],s*(l+1)-ps-s});
    }

    initSeg(tot,vl);

    for(int i=(int)g[rt].size()-1;i>=0;i--)
    {
        int v=g[rt][i];
        if(vis[v])
            continue;
        for(auto [ps,s,l]:d[v])
        {
            int pos=lower_bound(X.begin(),X.end(),l)-X.begin();
            ans=max(ans,qry(1,pos)+ps);
        }
        for(auto [ps,s,l]:d[v])
            upd(1,Line{s-a[rt],s*(l+1)-ps-s});
    }

    vis[rt]=1;
    for(auto v:g[rt])
    {
        if(vis[v])
            continue;
        solve(v);
    }
}

signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%lld%lld",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    mx[0]=n+1;
    solve(1);
    printf("%lld\n",ans);
}