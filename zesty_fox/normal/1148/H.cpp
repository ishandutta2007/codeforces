// LUOGU_RID: 94485351
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
const int INF=0x3f3f3f3f;

int n;

using Data=pair<i64,i64>;
Data operator + (const Data &a,const Data &b) {return {a.fi+b.fi,a.se+b.se};}
Data operator * (const Data &a,i64 b) {return {a.fi*b,a.se*b};}

struct DS{
    struct SGT{
#define lson (t[now].ls)
#define rson (t[now].rs)
#define mid ((l+r)>>1)
        struct Node{int ls,rs;Data sum,tg;}t[N*60];
        int tot;
        void pushup(int now,int l,int r){
            t[now].sum=t[lson].sum+t[rson].sum+t[now].tg*(r-l+1);
        }
        void apply(int now,int l,int r,Data v){
            t[now].sum=t[now].sum+v*(r-l+1),t[now].tg=t[now].tg+v;
        }
        void add(int &now,int pre,int l,int r,int x,int y,Data v){
            t[now=++tot]=t[pre];
            if(x<=l&&r<=y) {apply(now,l,r,v);return;}
            if(x<=mid) add(lson,t[pre].ls,l,mid,x,y,v);
            if(y>mid) add(rson,t[pre].rs,mid+1,r,x,y,v);
            pushup(now,l,r);
        }
        Data query(int now,int l,int r,int x,int y,Data tg={0,0}){
            if(x<=l&&r<=y) return t[now].sum+tg*(r-l+1);
            Data ret{0,0};tg=tg+t[now].tg;
            if(x<=mid) ret=ret+query(lson,l,mid,x,y,tg);
            if(y>mid) ret=ret+query(rson,mid+1,r,x,y,tg);
            return ret;
        }
#undef lson
#undef rson
#undef mid
    }t;
    map<int,int> rt[N];
    int lim;i64 ti;

    void init(int n,int m){
        lim=m,ti=0,t.tot=0;
        for(int i=0;i<=n;i++) rt[i][0]=0;
    }
    void expand() {++ti;}
    void enable(int id,int l,int r){
        int pre=rt[id].rbegin()->se;
        t.add(rt[id][ti],pre,1,lim,l,r,{-(ti-1),1});
    }
    void disable(int id,int l,int r){
        int pre=rt[id].rbegin()->se;
        t.add(rt[id][ti],pre,1,lim,l,r,{ti-1,-1});
    }
    i64 query(int id,int tl,int tr,int l,int r){
        auto sum = [&](int ti){
            if(!ti) return 0ll;
            int rt1=prev(rt[id].upper_bound(ti))->se;
            auto res=t.query(rt1,1,lim,l,r);
            return res.fi+(i64)ti*res.se;
        };
        return sum(tr)-sum(tl-1);
    }
}ds;

set<int> p[N];
int lst[N];
struct SGT{
#define lson (now<<1)
#define rson (now<<1|1)
#define mid ((l+r)>>1)
    int mi[N*4];
    SGT() {memset(mi,0x3f,sizeof(mi));}
    void upd(int now,int l,int r,int x){
        if(l==r) {mi[now]=p[x].empty()?INF:*p[x].begin();return;}
        if(x<=mid) upd(lson,l,mid,x);
        else upd(rson,mid+1,r,x);
        mi[now]=min(mi[lson],mi[rson]);
    }
    int query(int now,int l,int r,int x,int y){
        if(x<=l&&r<=y) return mi[now];
        int ret=INF;
        if(x<=mid) ret=min(ret,query(lson,l,mid,x,y));
        if(y>mid) ret=min(ret,query(rson,mid+1,r,x,y));
        return ret;
    }
#undef lson
#undef rson
#undef mid
}t;

void init(){
    ds.init(n,n);
    for(int i=0;i<=n;i++)
        p[lst[i]=0].insert(i);
    t.upd(1,0,n,0);
}

int pos;
map<int,pii> seg;
void append(int val){
    ++pos,ds.expand();
    p[lst[val]].erase(val),t.upd(1,0,n,lst[val]);
    p[lst[val]=pos].insert(val),t.upd(1,0,n,lst[val]);

    auto insert = [&](int v,int l,int r){
        auto it=seg.find(v);
        if(it==seg.end()) 
            seg[v]={l,r},ds.enable(v,l,r);
        else{
            int &l1=it->se.fi,&r1=it->se.se;
            if(l<l1) ds.enable(v,l,l1-1),l1=l;
            if(r>r1) ds.enable(v,r1+1,r),r1=r;
        }
    };
    auto it=seg.find(val);
    if(it!=seg.end()){
        int l=it->se.fi,r=it->se.se;
        seg.erase(it),ds.disable(val,l,r);
        while(l<=r){
            int v=t.query(1,0,n,0,r-1);
            int nx=max(lst[v]+1,l);
            insert(v,nx,r),r=nx-1;
        }
    }
    insert(!val,pos,pos);
}

i64 query(int l,int r,int v){
    return ds.query(v,l,r,l,r);
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();init();
    i64 lst_ans=0;
    for(int i=1;i<=n;i++){
        int v=(rdi()+lst_ans)%(n+1);
        int l=(rdi()+lst_ans)%i+1;
        int r=(rdi()+lst_ans)%i+1;
        int k=(rdi()+lst_ans)%(n+1);
        if(l>r) swap(l,r);
        append(v);
        cout<<(lst_ans=query(l,r,k))<<'\n';
    }
    return 0;
}