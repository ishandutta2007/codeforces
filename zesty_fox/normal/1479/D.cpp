#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef unsigned long long u64;
typedef double db;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=3e5+10;

mt19937_64 rng(102391);

int n,q,a[N];
u64 p[N];
vi e[N];

struct SGT{
#define lson (t[now].ls)
#define rson (t[now].rs)
#define mid ((l+r)>>1)
    struct Node{int ls,rs;u64 v;}t[N*20];
    int tot;
    int new_n() {return ++tot;}
    void add(int &now,int pre,int l,int r,int x,u64 v){
        t[now=new_n()]=t[pre],t[now].v^=v;
        if(l==r) return;
        if(x<=mid) add(lson,t[pre].ls,l,mid,x,v);
        else add(rson,t[pre].rs,mid+1,r,x,v);
    }
    int query(int nw1,int nw2,int nw3,int nw4,int l,int r,int x,int y){
#define lsons t[nw1].ls,t[nw2].ls,t[nw3].ls,t[nw4].ls
#define rsons t[nw1].rs,t[nw2].rs,t[nw3].rs,t[nw4].rs
        if(x<=l&&r<=y){
            u64 v=t[nw1].v^t[nw2].v^t[nw3].v^t[nw4].v;
            if(!v) return -1;
            if(l==r) return l;
            v=t[t[nw1].ls].v^t[t[nw2].ls].v^t[t[nw3].ls].v^t[t[nw4].ls].v;
            if(v) return query(lsons,l,mid,x,y);
            else return query(rsons,mid+1,r,x,y);
        }
        if(x<=mid){
            int ret=query(lsons,l,mid,x,y);
            if(ret!=-1) return ret;
        }
        if(y>mid) return query(rsons,mid+1,r,x,y);
#undef lsons
#undef rsons
        return -1;
    }
#undef lson
#undef rson
#undef mid
}t;

inline int lg2(int x) {return !x?-1:__lg(x);}

int rt[N],f[N][21],dep[N];

void dfs(int x,int fa){
    t.add(rt[x],rt[fa],1,n,a[x],p[a[x]]);
    f[x][0]=fa,dep[x]=dep[fa]+1;
    for(int i=1;i<=lg2(dep[x]);i++) f[x][i]=f[f[x][i-1]][i-1];
    for(auto y:e[x]) if(y!=fa) dfs(y,x);
}

int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=lg2(dep[x]-dep[y]);i>=0;i--)
        if(dep[f[x][i]]>=dep[y]) x=f[x][i];
    if(x==y) return x;
    for(int i=lg2(dep[x]);i>=0;i--)
        if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    return f[x][0];
}

int query(int x,int y,int l,int r){
    int lc=lca(x,y);
    return t.query(rt[x],rt[y],rt[lc],rt[f[lc][0]],1,n,l,r);
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),q=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi();
        e[x].pb(y),e[y].pb(x);
    }

    for(int i=1;i<=n;i++) p[i]=rng();
    dfs(1,0);
    
    while(q--){
        int x=rdi(),y=rdi(),l=rdi(),r=rdi();
        cout<<query(x,y,l,r)<<'\n';
    }
    return 0;
}