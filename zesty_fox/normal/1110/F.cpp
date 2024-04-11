#include <bits/stdc++.h>
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
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=500010;
const ll INF=0x3f3f3f3f3f3f3f3f;
int n,Q,head[N],tot;
vector<pair<int,ll> > e[N];
void addedge(int x,int y,ll w){
    e[x].pb(mp(y,w));e[y].pb(mp(x,w));
}

namespace SegmentTree{
#define lson (now<<1)
#define rson (now<<1|1)
#define mid ((l+r)>>1)
    ll t[N<<2],tag[N<<2];
    inline void pushdown(int now){
        if(tag[now]){
            tag[lson]+=tag[now],tag[rson]+=tag[now];
            t[lson]+=tag[now],t[rson]+=tag[now];
            tag[now]=0;
        }
    }
    inline void pushup(int now){
        t[now]=min(t[lson],t[rson]);
    }
    void modify(int now,int l,int r,int x,int y,ll val){
        if(x>y) return;
        if(x<=l&&r<=y){
            tag[now]+=val,t[now]+=val;
            return;
        }
        pushdown(now);
        if(x<=mid) modify(lson,l,mid,x,y,val);
        if(y>mid) modify(rson,mid+1,r,x,y,val);
        pushup(now);
    }
    ll query(int now,int l,int r,int x,int y){
        if(x<=l&&r<=y) return t[now];
        pushdown(now);
        ll tmp=INF;
        if(x<=mid) tmp=min(tmp,query(lson,l,mid,x,y));
        if(y>mid) tmp=min(tmp,query(rson,mid+1,r,x,y));
        pushup(now);
        return tmp;
    }
}
using namespace SegmentTree;

struct Query{int l,r,id;};
vector<Query> q[N];
ll res[N];

int leafid[N],isleaf[N],cnt[N],ti,id[N];
ll dep[N];
void dfs(int x,int fa){
    isleaf[x]=1,leafid[x]=n+1;
    for(auto tmp:e[x]){
        int y=tmp.fi;
        if(y==fa) continue;
        isleaf[x]=0,dep[y]=dep[x]+tmp.se;
        dfs(y,x);
        leafid[x]=min(leafid[x],leafid[y]);
        cnt[x]+=cnt[y];
    }
    if(isleaf[x]){
        cnt[x]=1,leafid[x]=++ti,id[ti]=x;
    }
}

void solve(int x,int fa){
    for(auto tmp:q[x]) res[tmp.id]=query(1,1,ti,tmp.l,tmp.r);
    for(auto tmp:e[x]){
        int y=tmp.fi;
        if(y==fa) continue;
        modify(1,1,ti,leafid[y],leafid[y]+cnt[y]-1,-tmp.se);
        modify(1,1,ti,1,leafid[y]-1,tmp.se);
        modify(1,1,ti,leafid[y]+cnt[y],ti,tmp.se);
        solve(y,x);
        modify(1,1,ti,leafid[y],leafid[y]+cnt[y]-1,tmp.se);
        modify(1,1,ti,1,leafid[y]-1,-tmp.se);
        modify(1,1,ti,leafid[y]+cnt[y],ti,-tmp.se);
    }
}

int main(){
    n=rdi(),Q=rdi();
    for(int i=2;i<=n;i++){
        int x=rdi();ll w=rdll();
        addedge(i,x,w);
    }
    for(int i=1;i<=n;i++) sort(e[i].begin(),e[i].end());
    dfs(1,0);
    for(int x=1;x<=n;x++){
        if(isleaf[x]) modify(1,1,ti,leafid[x],leafid[x],dep[x]);
    }
    for(int i=1;i<=Q;i++){
        int x=rdi(),l=rdi(),r=rdi();
        int l1=lower_bound(id+1,id+ti+1,l)-id,r1=upper_bound(id+1,id+ti+1,r)-id-1;
        q[x].pb({l1,r1,i});
    }
    solve(1,0);
    for(int i=1;i<=Q;i++) printf("%lld\n",res[i]);
    return 0;
}