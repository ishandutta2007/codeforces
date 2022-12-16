#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
#define pb push_back

const int N=600010;

struct {int x,y,w;}e1[N];

struct dsu{
    int f[N];
    void init(int n) {iota(f+1,f+n+1,1);}
    int find(int x) {return x==f[x]?f[x]:f[x]=find(f[x]);}
}d;

int n,q;

int w[N*2],cnt;
vi e[N];

void build_tree(){
    sort(e1+1,e1+n,[&](const auto &a,const auto &b){return a.w<b.w;});
    cnt=n,d.init(2*n);
    for(int i=1;i<n;i++){
        int x=d.find(e1[i].x),y=d.find(e1[i].y);
        e[++cnt]={x,y},w[cnt]=e1[i].w,d.f[x]=d.f[y]=cnt;
    }
    fill(w+1,w+n+1,-1);
}

int lg2(int x) {return !x?0:__lg(x);}

int f[N][21],dfn[N],ti,dep[N];
void dfs(int x,int fa){
    dfn[x]=++ti,f[x][0]=fa,dep[x]=dep[fa]+1;
    for(int i=1;i<=lg2(dep[x]);i++) f[x][i]=f[f[x][i-1]][i-1];
    for(auto y:e[x]) if(y!=fa) dfs(y,x);
}

int LCA(int x,int y){
    if(!x||!y||x==y) return x|y;
    if(dfn[x]<dfn[y]) swap(x,y);
    for(int i=lg2(dep[x]);i>=0;i--)
        if(dfn[f[x][i]]>dfn[y]) x=f[x][i];
    return f[x][0];
}

struct SGT{
#define lson (now<<1)
#define rson (now<<1|1)
#define mid ((l+r)>>1)
    int lc[N*4],tag[N*4],rlc[N*4];
    void pushup(int now) {lc[now]=LCA(lc[lson],lc[rson]);}
    void upd(int now,int val) {lc[now]=val*rlc[now],tag[now]=val;}
    void pushdown(int now) {if(tag[now]!=-1) upd(lson,tag[now]),upd(rson,tag[now]),tag[now]=-1;}
    void build(int now,int l,int r){
        tag[now]=-1,lc[now]=0;
        if(l==r) return (void)(rlc[now]=l);
        build(lson,l,mid),build(rson,mid+1,r);
        rlc[now]=LCA(rlc[lson],rlc[rson]);
    }
    void modify(int now,int l,int r,int x,int y,int val){
        if(x<=l&&r<=y) return upd(now,val);
        pushdown(now);
        if(x<=mid) modify(lson,l,mid,x,y,val);
        if(y>mid) modify(rson,mid+1,r,x,y,val);
        pushup(now);
    }
#undef lson
#undef rson
#undef mid
}t;

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),q=rdi();
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi(),w=rdi();
        e1[i]={x,y,w};
    }
    build_tree();dfs(cnt,0);t.build(1,1,n);
    while(q--){
        int typ=rdi(),x,y;
        if(typ==1) x=rdi(),y=rdi(),t.modify(1,1,n,x,y,1);
        if(typ==2) x=rdi(),y=rdi(),t.modify(1,1,n,x,y,0);
        if(typ==3) x=rdi(),cout<<w[LCA(x,t.lc[1])]<<'\n';
    }
    return 0;
}