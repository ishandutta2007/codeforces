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

const int N=200010,INF=0x3f3f3f3f;

struct {int to,nxt;}e[N*2];
int head[N],tot=1;
void addedge(int x,int y){
    e[++tot]={y,head[x]};
    head[x]=tot;
}

int n,w[N],m,Q;

int dfn[N],low[N],ti;
int v_c;
vi v[N];

void tarjan(int x){
    static int st[N],tp;
    dfn[x]=low[x]=++ti,st[++tp]=x;
    if(!head[x]) {v[++v_c].pb(x);return;}
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(!dfn[y]){
            tarjan(y),low[x]=min(low[x],low[y]);
            if(dfn[x]<=low[y]){
                ++v_c;
                do v[v_c].pb(st[tp]);
                while(st[tp--]!=y);
                v[v_c].pb(x);
            }
        }
        else low[x]=min(low[x],dfn[y]);
    }
}

vi t[N*2];
int rt;

int f[N],siz[N],son[N],dep[N];
void dfs(int x,int fa){
    siz[x]=1,f[x]=fa,dep[x]=dep[fa]+1;
    for(auto y:t[x]){
        if(y==fa) continue;
        dfs(y,x);
        siz[x]+=siz[y];
        if(siz[y]>siz[son[x]]) son[x]=y;
    }
}

int tp[N];
void dfs1(int x,int ntp){
    tp[x]=ntp,dfn[x]=++ti;
    if(son[x]) dfs1(son[x],ntp);
    for(auto y:t[x]){
        if(y==f[x]||y==son[x]) continue;
        dfs1(y,y);
    }
}

inline int getmin(const multiset<int> &a){
    return a.empty()?INF:*a.begin();
}

struct SGT{
#define lson (now<<1)
#define rson (now<<1|1)
#define mid ((l+r)>>1)
    multiset<int> s[N];
    int t[N*4];
    void pushup(int now) {t[now]=min(t[lson],t[rson]);}
    void build(int now,int l,int r){
        if(l==r) {t[now]=getmin(s[l]);return;}
        build(lson,l,mid);build(rson,mid+1,r);
        pushup(now);
    }
    void modify(int now,int l,int r,int x,int fr,int to){
        if(l==r){
            s[l].erase(s[l].find(fr));
            s[l].insert(to);
            t[now]=getmin(s[l]);
            return;
        }
        x<=mid?modify(lson,l,mid,x,fr,to):modify(rson,mid+1,r,x,fr,to);
        pushup(now);
    }
    int query(int now,int l,int r,int x,int y){
        if(x<=l&&r<=y) return t[now];
        int ret=INF;
        if(x<=mid) ret=min(ret,query(lson,l,mid,x,y));
        if(y>mid) ret=min(ret,query(rson,mid+1,r,x,y));
        return ret;
    }
#undef lson
#undef rson
#undef mid
}t1;

void init(){
    for(int i=1;i<=n;i++) 
        if(!dfn[i]) tarjan(i);
    for(int i=1;i<=v_c;i++){
        int x=i+n;
        for(auto y:v[i]) t[x].pb(y),t[y].pb(x);
    }
    rt=n+v_c;
    ti=0;dfs(rt,0);dfs1(rt,rt);
    for(int x=n+1;x<=n+v_c;x++){
        for(auto y:t[x]){
            if(y==f[x]) continue;
            t1.s[dfn[x]].insert(w[y]);
        }
    }
    t1.build(1,1,n+v_c);
}

void modify(int x,int val){
    if(f[x]) t1.modify(1,1,n+v_c,dfn[f[x]],w[x],val);
    w[x]=val;
}

int query(int x,int y){
    int ret=INF;
    while(tp[x]!=tp[y]){
        if(dep[tp[x]]<dep[tp[y]]) swap(x,y);
        ret=min(ret,t1.query(1,1,n+v_c,dfn[tp[x]],dfn[x]));
        x=f[tp[x]];
    }
    if(dep[x]<dep[y]) swap(x,y);
    ret=min(ret,t1.query(1,1,n+v_c,dfn[y],dfn[x]));
    if(y>n&&f[y]) ret=min(ret,w[f[y]]);
    else if(y<=n) ret=min(ret,w[y]);
    return ret;
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),m=rdi(),Q=rdi();
    for(int i=1;i<=n;i++) w[i]=rdi();
    for(int i=1;i<=m;i++){
        int x=rdi(),y=rdi();
        addedge(x,y),addedge(y,x);
    }
    init();
    while(Q--){
        char typ[2];int x,y;
        scanf("%s%d%d",typ,&x,&y);
        if(typ[0]=='C') modify(x,y);
        else cout<<query(x,y)<<'\n';
    }
    return 0;
}