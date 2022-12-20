#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>

#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

#define rdi read<int>
#define rdl read<ll>
#define fi first
#define sec second
#define pb push_back
#define mp make_pair

const int N=600010,INF=0x3f3f3f3f;
struct Edge{int to,nxt;}e[N];
int n,q,rt=1,head[N],tot;
ll w[N];
void addedge(int x,int y){
    e[++tot]=(Edge){y,head[x]};
    head[x]=tot;
}

int f[N][21],dep[N],a[N],lg2[N],dfn[N],id[N],ti,siz[N];
/*
struct ST{
    int f[N][21];
}
*/

void init_lg(int lim){
    for(int i=2;i<=lim;i++) lg2[i]=lg2[i>>1]+1;
}

void dfs(int x,int fa){
    dep[x]=dep[fa]+1;f[x][0]=fa;dfn[x]=++ti;id[ti]=x;siz[x]=1;
    for(int i=1;i<=lg2[dep[x]];i++) f[x][i]=f[f[x][i-1]][i-1];
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==fa) continue;
        dfs(y,x);siz[x]+=siz[y];
    }
}

inline int LCA(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=lg2[dep[x]-dep[y]];i>=0;i--){
        if(dep[f[x][i]]>=dep[y]) x=f[x][i];
    }
    if(x==y) return x;
    for(int i=lg2[dep[x]];i>=0;i--){
        if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    }
    return f[x][0];
}

//yx
inline int getson(int x,int y){
    for(int i=lg2[dep[x]-dep[y]];i>=0;i--){
        if(dep[f[x][i]]>dep[y]) x=f[x][i];
    }
    return x;
}

inline int dist(int x,int y){
    return dep[x]+dep[y]-2*dep[LCA(x,y)];
}

inline int get_lca(int x,int y){
    int lc[4]={LCA(x,rt),LCA(y,rt),LCA(x,y)};
    if(LCA(rt,lc[2])!=lc[2]) return lc[2];
    else if(dist(lc[0],rt)>dist(lc[1],rt)) return lc[1];
    else return lc[0];
}

struct SegmentTree{
#define lson (now<<1)
#define rson (now<<1|1)
#define mid ((l+r)>>1)
    ll sum[N<<2],add[N<<2];
    void pushup(int now){
        sum[now]=sum[lson]+sum[rson];
    }
    void pushdown(int now,int l,int r){
        if(add[now]){
            add[lson]+=add[now];
            add[rson]+=add[now];
            sum[lson]+=add[now]*(mid-l+1);
            sum[rson]+=add[now]*(r-mid);
            add[now]=0;
        }
    }
    void build(int now,int l,int r){
        if(l==r){
            sum[now]=w[id[l]];
            return;
        }
        build(lson,l,mid);build(rson,mid+1,r);
        pushup(now);
    }
    void modify(int now,int l,int r,int x,int y,ll val){
        if(x<=l&&r<=y){
            sum[now]+=(r-l+1)*val;
            add[now]+=val;
            return;
        }
        pushdown(now,l,r);
        if(x<=mid) modify(lson,l,mid,x,y,val);
        if(y>mid) modify(rson,mid+1,r,x,y,val);
        pushup(now);
    }
    ll query(int now,int l,int r,int x,int y){
        if(x<=l&&r<=y) return sum[now];
        pushdown(now,l,r);
        ll tmp=0;
        if(x<=mid) tmp+=query(lson,l,mid,x,y);
        if(y>mid) tmp+=query(rson,mid+1,r,x,y);
        pushup(now);return tmp;
    }
#undef lson
#undef rson
#undef mid
}st;

void modify(int x,int y,int val){
    int lca=get_lca(x,y),lc=LCA(lca,rt);
    if(lca==rt) {st.modify(1,1,n,1,n,val);return;}
    if(lc!=lca) st.modify(1,1,n,dfn[lca],dfn[lca]+siz[lca]-1,val);
    else{
        int tmp=getson(rt,lca);
        st.modify(1,1,n,1,n,val);
        st.modify(1,1,n,dfn[tmp],dfn[tmp]+siz[tmp]-1,-val);
    }
}

ll query(int x){
    if(x==rt) return st.query(1,1,n,1,n);
    int lc=LCA(x,rt);
    if(lc!=x) return st.query(1,1,n,dfn[x],dfn[x]+siz[x]-1);
    else{
        int tmp=getson(rt,x);
        return st.query(1,1,n,1,n)-st.query(1,1,n,dfn[tmp],dfn[tmp]+siz[tmp]-1);
    }
}

int main(){
    n=rdi(),q=rdi();
    for(int i=1;i<=n;i++) w[i]=rdi();
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi();
        addedge(x,y);addedge(y,x);
    }
    init_lg(n+5);dfs(1,0);
    st.build(1,1,n);
    while(q--){
        int typ=rdi(),x=rdi(),y,val;
        if(typ==1) {rt=x;continue;}
        else if(typ==2){
            y=rdi(),val=rdi();
            modify(x,y,val);
        }
        else printf("%lld\n",query(x));
    }
    return 0;
}