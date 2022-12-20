// RMJ

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

const int N=2e5+10;

int n,q,a[N];

struct SGT{
#define lson (now<<1)
#define rson (now<<1|1)
#define mid ((l+r)>>1)
    struct Node{
        int mx,lmx,rmx,sum,bmi;
    }t[N*4];
    Node merge(Node a,Node b){
        if(a.bmi>b.bmi) return {max(a.mx,b.mx),max(a.mx,b.lmx),b.rmx,b.sum,min(a.bmi,b.bmi)};
        if(b.bmi>a.bmi) return {max(a.mx,b.mx),a.lmx,max(a.rmx,b.mx),a.sum,min(a.bmi,b.bmi)};
        return {max(a.mx,b.mx),a.lmx,b.rmx,a.sum+b.sum+max(a.rmx,b.lmx),min(a.bmi,b.bmi)};
    }
    int tg[N*4];
    void pushup(int now){
        t[now]=merge(t[lson],t[rson]);
    }
    void apply(int now,int v){
        t[now].bmi+=v,tg[now]+=v;
    }
    void pushdown(int now){
        if(tg[now]){
            apply(lson,tg[now]),apply(rson,tg[now]);
            tg[now]=0;
        }
    }
    void modify(int now,int l,int r,int x,int v){
        if(l==r) {t[now].mx=t[now].lmx=v;return;}
        pushdown(now);
        if(x<=mid) modify(lson,l,mid,x,v);
        else modify(rson,mid+1,r,x,v);
        pushup(now);
    }
    void add(int now,int l,int r,int x,int y,int v){
        if(x<=l&&r<=y) {apply(now,v);return;}
        pushdown(now);
        if(x<=mid) add(lson,l,mid,x,y,v);
        if(y>mid) add(rson,mid+1,r,x,y,v);
        pushup(now);
    }
#undef lson
#undef rson
#undef mid
}t;

set<int> pos[N];

void init(){
    for(int i=1;i<=n;i++)
        pos[a[i]].insert(i);
    for(int i=1;i<N;i++){
        if(pos[i].empty()) continue;
        int mi=*pos[i].begin(),mx=*pos[i].rbegin();
        if(mi<mx) t.add(1,1,n,mi,mx-1,1);
        t.modify(1,1,n,mi,pos[i].size());
    }
}

int query(){
    return n-(t.t[1].sum+t.t[1].lmx+t.t[1].rmx);
}

void modify(int x,int v){
    if(a[x]==v) return;
    int mi=*pos[a[x]].begin(),mx=*pos[a[x]].rbegin();
    if(mi<mx) t.add(1,1,n,mi,mx-1,-1);
    t.modify(1,1,n,mi,0);
    pos[a[x]].erase(x);
    if(pos[a[x]].size()){
        mi=*pos[a[x]].begin(),mx=*pos[a[x]].rbegin();
        if(mi<mx) t.add(1,1,n,mi,mx-1,1);
        t.modify(1,1,n,mi,pos[a[x]].size());
    }

    a[x]=v;
    if(pos[a[x]].size()){
        mi=*pos[a[x]].begin(),mx=*pos[a[x]].rbegin();
        if(mi<mx) t.add(1,1,n,mi,mx-1,-1);
        t.modify(1,1,n,mi,0);
    }
    pos[a[x]].insert(x);
    mi=*pos[a[x]].begin(),mx=*pos[a[x]].rbegin();
    if(mi<mx) t.add(1,1,n,mi,mx-1,1);
    t.modify(1,1,n,mi,pos[a[x]].size());
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),q=rdi();
    for(int i=1;i<=n;i++)
        a[i]=rdi();
    init();
    cout<<query()<<'\n';
    while(q--){
        int x=rdi(),v=rdi();
        modify(x,v);
        cout<<query()<<'\n';
    }
    return 0;
}