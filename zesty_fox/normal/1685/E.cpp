#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
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

const int N=200010;

int n,m,p[N];

struct SGT{
#define lson (now<<1)
#define rson (now<<1|1)
#define mid ((l+r)>>1)
    int mi[N*4],tg[N*4];
    void pushup(int now) {mi[now]=min(mi[lson],mi[rson]);}
    void upd(int now,int t) {mi[now]+=t,tg[now]+=t;}
    void pushdown(int now) {if(tg[now]) upd(lson,tg[now]),upd(rson,tg[now]),tg[now]=0;}
    void build(int now,int l,int r,int *a){
        if(l==r) {mi[now]=a[l];return;}
        build(lson,l,mid,a),build(rson,mid+1,r,a);
        pushup(now);
    }
    void add(int now,int l,int r,int x,int y,int v){
        if(x<=l&&r<=y) {upd(now,v);return;}
        pushdown(now);
        if(x<=mid) add(lson,l,mid,x,y,v);
        if(y>mid) add(rson,mid+1,r,x,y,v);
        pushup(now);
    }
    int query_pos(int now,int l,int r){
        if(l==r) return l;
        pushdown(now);
        if(mi[lson]==mi[now]) return query_pos(lson,l,mid);
        else return query_pos(rson,mid+1,r);
    }
    int query_mi(int now,int l,int r,int x){
        if(l==r) return mi[now];
        pushdown(now);
        return x<=mid?query_mi(lson,l,mid,x):query_mi(rson,mid+1,r,x);
    }
#undef lson
#undef rson
#undef mid
}t;

int pos[N];
i64 d1,d2;

inline int dist(int x,int y) {return (pos[y]+2*n+1-pos[x])%(2*n+1);}
inline int w(int x) {return x<n+1?-1:(x>n+1?1:0);}

void init(){
    static int sum[N];
    for(int i=1;i<=2*n+1;i++)
        sum[i]=sum[i-1]+w(p[i]),pos[p[i]]=i;
    t.build(1,0,2*n+1,sum);

    for(int i=1;i<n+1;i++) d1+=dist(i+n,i+n+1),d2+=dist(i,i+1);
    d1+=dist(2*n+1,n+1),d2+=dist(n+1,1);
}

void _mod(int x,int v){
    t.add(1,0,2*n+1,x,2*n+1,-w(p[x]));
    t.add(1,0,2*n+1,x,2*n+1,w(v));
}

void _upd(int x,int op){
    if(x>=n+1){
        if(x>n+1) d1+=op*dist(x-1,x);
        else d1+=op*dist(2*n+1,x);
        if(x<2*n+1) d1+=op*dist(x,x+1);
        else d1+=op*dist(x,n+1);
    }
    if(x<=n+1){
        if(x>1) d2+=op*dist(x-1,x);
        else d2+=op*dist(n+1,x);
        if(x<n+1) d2+=op*dist(x,x+1);
        else d2+=op*dist(x,1);
    }
}

void modify(int x,int y){
    _mod(x,p[y]),_mod(y,p[x]),_upd(p[x],-1),_upd(p[y],-1);
    swap(pos[p[x]],pos[p[y]]),swap(p[x],p[y]);
    _upd(p[x],1),_upd(p[y],1);
}

int solve(){
    if(t.mi[1]!=t.query_mi(1,0,2*n+1,pos[n+1])) 
        return t.query_pos(1,0,2*n+1)%(2*n+1);
    else if(d1!=2*n+1) return pos[n+1]-1;
    else if(d2!=2*n+1) return pos[n+1]%(2*n+1);
    else return -1;
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),m=rdi();
    for(int i=1;i<=2*n+1;i++) p[i]=rdi();
    init();
    while(m--){
        int x=rdi(),y=rdi();
        modify(x,y);
        cout<<solve()<<'\n';
    }
    return 0;
}