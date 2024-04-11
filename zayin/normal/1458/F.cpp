#include<bits/stdc++.h>
#define maxn 200050
using namespace std;
typedef long long LL;

int n;
vector<int> G[maxn];

int sz[maxn],dep[maxn];
int fa[maxn],son[maxn],tp[maxn];

int dfs1(int i)    {
    dep[i]=dep[fa[i]]+1;
    for (int j:G[i])    {
        if (fa[i]==j) continue;
        fa[j]=i;
        sz[i]+=dfs1(j);
        if (sz[son[i]]<sz[j])
            son[i]=j;
    }
    return ++sz[i];
}

int N,pos[maxn],id[maxn];

void dfs2(int i,int t)    {
    id[i]=++N;
    pos[N]=i;
    tp[i]=t;
    if (son[i])
        dfs2(son[i],t);
    for (int j:G[i])    {
        if (fa[i]==j||son[i]==j) continue;
        dfs2(j,j);
    }
}

LL C,D;
struct node {
    LL sum,tag;
} T[maxn<<2];
#define sum(k) T[k].sum
#define tag(k) T[k].tag

inline void renew(int k,int l,int r,LL d)  {
    tag(k)+=d;
    sum(k)+=(r-l+1)*d;
}

inline void godown(int k,int l,int r)  {
    int mid=(l+r)>>1;
    renew(k<<1,l,mid,tag(k));
    renew(k<<1|1,mid+1,r,tag(k));
    tag(k)=0;
}

inline void update(int k)  {
    sum(k)=sum(k<<1)+sum(k<<1|1);
}

void change(int k,int l,int r,int a,int b,int d)    {
    // cout<<"change:"<<k<<" "<<l<<" "<<r<<" "<<a<<" "<<b<<" "<<d<<endl;
    if (a<=l&&r<=b) 
        renew(k,l,r,d);
    else    {
        godown(k,l,r);
        int mid=(l+r)>>1;
        if (a<=mid)
            change(k<<1,l,mid,a,b,d);
        if (b>mid)
            change(k<<1|1,mid+1,r,a,b,d);
        update(k);
    }
}

LL query(int k,int l,int r,int a,int b) {
    if (a>r||b<l) return 0;
    // cout<<"query:"<<k<<" "<<l<<" "<<r<<" "<<a<<" "<<b<<" "<<endl;
    if (a<=l&&r<=b) return sum(k);
    godown(k,l,r);
    int mid=(l+r)>>1;
    return query(k<<1,l,mid,a,b)+query(k<<1|1,mid+1,r,a,b);
}

void change(int u,int d)    {
    // cout<<"change:"<<u<<" "<<d<<endl;
    C+=d,D+=d*dep[u];
    for (;u;u=fa[tp[u]])
        // cout<<"change ["<<tp[u]<<","<<u<<"] "<<d<<endl,
        change(1,1,N,id[tp[u]],id[u],d);
}

LL query(int u)    {
    LL ans=C*dep[u]+D;
    // cout<<"C D:"<<C<<" "<<D<<endl;
    for (;u;u=fa[tp[u]])
        // cout<<"query ["<<tp[u]<<","<<u<<"]="<<query(1,1,N,id[tp[u]],id[u])<<endl,
        ans-=2*query(1,1,N,id[tp[u]],id[u]);
    return ans;
}

inline int lca(int u,int v)    {
    while (tp[u]!=tp[v])    {
        if (dep[tp[u]]<dep[tp[v]])
            swap(u,v);
        u=fa[tp[u]];
    }
    return dep[u]<dep[v]?u:v;
}

inline int dis(int u,int v)    {
    return dep[u]+dep[v]-2*dep[lca(u,v)];
}

inline int jump(int u,int d)   {
    assert(dep[u]>d);
    for (;d>=dep[u]-dep[fa[tp[u]]];u=fa[tp[u]])
        d-=dep[u]-dep[fa[tp[u]]];
    return pos[id[u]-d];
}

inline int lieon(int u,int v,int d)    {
    // cout<<"lieon:"<<u<<" "<<v<<" "<<d<<endl;
    int k=lca(u,v);
    if (dep[u]-dep[k]>=d)
        return jump(u,d);
    else
        return jump(v,dis(u,v)-d);
}

struct ball {
    int c,r;
    ball(int _c=0,int _r=0)  {
        c=_c,r=_r;
    }
    bool cover(const ball& B,int strict=0) const {
        int d=dis(B.c,c);
        return r>=B.r+d+strict;
    }
    ball operator + (const ball& B) const   {
        if (!c) return B;
        if (!B.c) return *this;
        int d=dis(B.c,c);
        if (r+d<=B.r) return B;
        if (B.r+d<=r) return *this;
        return ball(lieon(c,B.c,(d+B.r-r)>>1),(r+B.r+d)>>1);
    }
} B[maxn];
ostream& operator << (ostream& os,const ball& B)    {
    os<<"("<<B.c<<","<<B.r<<")";
    return os;
}

LL suf[maxn];

LL ans=0;

LL tmp[maxn];

void solve(int l,int r) {
    if (l==r) return ;
    int mid=(l+r)>>1;
    solve(l,mid);
    solve(mid+1,r);

    // cout<<"to do:["<<l<<","<<r<<"]"<<endl;

    B[mid]=ball();
    for (int i=mid+1;i<=r;++i) B[i]=B[i-1]+ball(i);
    suf[r+1]=0;
    for (int i=r;i>mid;--i) suf[i]=suf[i+1]+B[i].r;

    // tmp[mid]=0;
    // for (int i=mid+1;i<=r;++i)  {
    //     tmp[i]=tmp[i-1];
    //     for (int j=mid+1;j<i;++j)
    //         tmp[i]=max(tmp[i],(LL)dis(i,j));
    // }
    
    // for (int i=mid+1;i<=r;++i)  
    //     cout<<"B["<<i<<"]="<<B[i]<<endl;

    LL res=0,pl=mid+1,pr=mid+1;
    ball b;
    for (int i=mid;i>=l;--i)    {//[mid+1,pl),[pl,pr),[pr,r]
        // cout<<"i:"<<i<<endl;
        b=b+ball(i);
        while (pl<=r&&b.cover(B[pl],1)) change(B[pl++].c,-1);
        while (pr<=r&&!B[pr].cover(b)) change(B[pr++].c,1);
        // cout<<i<<":"<<b<<" ~ "<<pl<<" "<<pr<<endl;
        assert(pl<=pr);
        // cout<<"q:"<<query(b.c)<<endl;
        // cout<<(LL)b.r*(pl-mid-1)<<" "<<\
        //     ((LL)b.r*(pr-pl)+query(b.c)+suf[pl]-suf[pr])/2<<" "<<\
        //     suf[pr]<<endl;
        LL t=(LL)b.r*(pl-mid-1)+\
            ((LL)b.r*(pr-pl)+query(b.c)+suf[pl]-suf[pr])/2+\
            suf[pr];
        res+=t;

        // LL t2=0,mx=0;
        // for (int j=i+1;j<=mid;++j)
        //     mx=max(mx,(LL)dis(i,j));
        // for (int j=mid+1;j<=r;++j)  {
        //     mx=max(mx,(LL)dis(i,j));
        //     tmp[j]=max(tmp[j],mx);
        //     t2+=tmp[j];
        // }
        // cout<<"tmp:"; for (int j=mid+1;j<=r;++j) cout<<tmp[j]<<" "; cout<<endl;
        // cout<<"t t2:"<<t<<" "<<t2<<endl;
        // assert(t*2==t2);
    }

    for (int i=pl;i<pr;++i) change(B[i].c,-1);

    ans+=res;
    // cout<<"["<<l<<","<<r<<"]="<<res<<endl;
    // cout<<endl;
}

int main()  {
    // freopen("c.in","r",stdin);
    scanf("%d",&n);
    for (int i=n+1;i<n+n;++i)   {
        int u,v;
        scanf("%d%d",&u,&v);
        G[i].push_back(v),G[v].push_back(i);
        G[i].push_back(u),G[u].push_back(i);
    }
    dfs1(1);
    dfs2(1,1);

    // cout<<ball(12,3).cover(ball(2,4))<<endl;
    solve(1,n);
    printf("%lld\n",ans);
    return 0;
}