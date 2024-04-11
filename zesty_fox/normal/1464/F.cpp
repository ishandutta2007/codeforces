#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using u64=unsigned long long;
using db=double;
using pii=pair<int,int>;
using vi=vector<int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch-'0'),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back

inline int lg2(int x){
    return !x?-1:__lg(x);
}

const int N=3e5+10;

int n,m;
vi e[N];

int f[N][20],dep[N];
int dfn[N],low[N],ti;
void dfs(int x,int fa){
    dfn[x]=++ti;
    f[x][0]=fa,dep[x]=dep[fa]+1;
    for(int i=1;i<=lg2(dep[x]);i++)
        f[x][i]=f[f[x][i-1]][i-1];
    for(auto y:e[x]){
        if(y==fa) 
            continue;
        dfs(y,x);
    }
    low[x]=ti;
}

inline int kth_anc(int x,int k){
    if(k>=dep[x])
        return 0;
    for(int i=lg2(k);i>=0;i--)
        if(k>>i&1) 
            x=f[x][i];
    return x;
}

inline int lca(int x,int y){
    if(dep[x]<dep[y])
        swap(x,y);
    for(int i=lg2(dep[x]-dep[y]);i>=0;i--)
        if(dep[f[x][i]]>=dep[y])
            x=f[x][i];
    if(x==y)
        return x;
    for(int i=lg2(dep[x]);i>=0;i--)
        if(f[x][i]!=f[y][i])
            x=f[x][i],y=f[y][i];
    return f[x][0];
}

inline int dist(int x,int y){
    return dep[x]+dep[y]-2*dep[lca(x,y)];
}

struct Set{
    int x,y,mxd;
    friend Set operator + (Set a,Set b){
        if(!a.x) return b;
        if(!b.x) return a;
        Set ret(a);
        if(b.mxd>ret.mxd)
            ret=b;
        for(auto x:{a.x,a.y}){
            for(auto y:{b.x,b.y}){
                int d=dist(x,y);
                if(d>ret.mxd)
                    ret={x,y,d};
            }
        }
        return ret;
    }
    int operator()(int p) const{
        return max(dist(p,x),dist(p,y));
    }
};

struct SGT{
#define lson (now<<1)
#define rson (now<<1|1)
#define mid ((l+r)>>1)
    Set t[N*4];
    void pushup(int now){
        t[now]=t[lson]+t[rson];
    }
    void modify(int now,int l,int r,int x,const Set &v){
        if(l==r){
            t[now]=v;
            return;
        }
        if(x<=mid)
            modify(lson,l,mid,x,v);
        else
            modify(rson,mid+1,r,x,v);
        pushup(now);
    }
    Set query(int now,int l,int r,int x,int y){
        if(x<=l&&r<=y)
            return t[now];
        Set ret{0,0,0};
        if(x<=mid)
            ret=ret+query(lson,l,mid,x,y);
        if(y>mid)
            ret=ret+query(rson,mid+1,r,x,y);
        return ret;
    }
#undef lson
#undef rson
#undef mid
}st;

struct BIT{
    int sum[N],n;
    void add(int x,int v){
        for(;x<=n;x+=(x&(-x)))
            sum[x]+=v;
    }
    int query(int x){
        int ret=0;
        for(;x;x-=(x&(-x)))
            ret+=sum[x];
        return ret;
    }
}t;

struct cmp_by_dep{
    bool operator()(int x,int y) const{
        return dep[x]!=dep[y]?dep[x]<dep[y]:x<y;
    }
};
multiset<int,cmp_by_dep> s;

int cnt[N];
void insert(int x,int y){
    int lc=lca(x,y);
    t.add(dfn[x],1),t.add(dfn[y],1),t.add(dfn[lc],-1);

    s.insert(lc),++cnt[lc];
    if(cnt[lc]==1)
        st.modify(1,1,n,dfn[lc],{lc,lc,0});
}

void erase(int x,int y){
    int lc=lca(x,y);
    t.add(dfn[x],-1),t.add(dfn[y],-1),t.add(dfn[lc],1);

    s.erase(s.find(lc)),--cnt[lc];
    if(!cnt[lc])
        st.modify(1,1,n,dfn[lc],{0,0,0});
}

bool query(int d){
    if(s.empty())
        return true;
    int x=max(kth_anc(*s.rbegin(),d),1);
    int u=max(kth_anc(x,d),1);
    if(t.query(dfn[u]-1)+t.query(n)-t.query(low[u]))
        return false;
    if(st.query(1,1,n,dfn[u],low[u])(x)>d)
        return false;
    return true;
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),m=rdi();
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi();
        e[x].pb(y),e[y].pb(x);
    }
    dfs(1,0);
    t.n=n;
    while(m--){
        int op=rdi();
        if(op==1){
            int x=rdi(),y=rdi();
            insert(x,y);
        }
        else if(op==2){
            int x=rdi(),y=rdi();
            erase(x,y);
        }
        else{
            int d=rdi();
            cout<<(query(d)?"Yes":"No")<<'\n';
        }
    }
    return 0;
}