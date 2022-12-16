#include <bits/stdc++.h>

using namespace std;

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x*10)+(ch^48),ch=getchar();
    return !f?x:-x;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=300010,MAXD=31,MAXN=1e9,INFi=0x3f3f3f3f;
const ll INFl=0x3f3f3f3f3f3f3f3f;

struct Line{
    int k,b;
    Line(int _k=0,int _b=-INFi){k=_k,b=_b;}
    bool isnoval(){return b==-INFi;}
    ll val(int x) {return (ll)x*k+b;}
};

struct SGT1{
#define lson t[now].ls
#define rson t[now].rs
#define mid ((l+r)>>1)

    struct{Line l;int ls,rs;}t[N*MAXD];
    int tot;
    int newnode(){
        t[++tot]={Line(),0,0};
        return tot;
    }
    void insert(int &now,int l,int r,Line cur){
        if(cur.isnoval()) return;
        if(!now) now=newnode();
        if(l==r) {t[now].l=cur;return;}
        if(t[now].l.isnoval()||t[now].l.val(mid)<cur.val(mid)) swap(t[now].l,cur);
        if(t[now].l.isnoval()||t[now].l.val(l)<cur.val(l)) insert(lson,l,mid,cur);
        if(t[now].l.isnoval()||t[now].l.val(r)<cur.val(r)) insert(rson,mid+1,r,cur);
    }
    Line query(int now,int l,int r,int x){
        if(!now) return Line();
        Line ret=t[now].l;
        if(l==r) return ret;
        Line tmp=(x<=mid?query(lson,l,mid,x):query(rson,mid+1,r,x));
        return ret.val(x)>tmp.val(x)||tmp.isnoval()?ret:tmp;
    }

#undef lson
#undef rson
#undef mid
}t1;

int q[N],hasq[N];
ll res[N];

struct SGT2{
#define lson (now<<1)
#define rson (now<<1|1)
#define mid ((l+r)>>1)

    int rt[MAXD];
    vector<Line> t[N<<2];
    void insert(int now,int l,int r,int x,int y,Line val){
        if(x<=l&&r<=y){
            t[now].pb(val);
            return;
        }
        if(x<=mid) insert(lson,l,mid,x,y,val);
        if(y>mid) insert(rson,mid+1,r,x,y,val);
    }
    void solve(int now,int l,int r,int dep,SGT1 &tr){
        int lasttot=tr.tot;
        for(auto tmp:t[now]) tr.insert(rt[dep],-MAXN,MAXN,tmp);
        if(l==r){
            if(hasq[l]){
                res[l]=-INFl;
                for(int i=0;i<=dep;i++){
                    Line tmp=tr.query(rt[i],-MAXN,MAXN,q[l]);
                    if(!tmp.isnoval()) res[l]=max(res[l],tmp.val(q[l]));
                }
            }
        }
        else solve(lson,l,mid,dep+1,tr),solve(rson,mid+1,r,dep+1,tr);
        tr.tot=lasttot,rt[dep]=0;
    }

#undef lson
#undef rson
#undef mid
}t2;

Line op[N];
int n,R[N];

int main(){
    n=rdi();
    for(int i=1;i<=n;i++){
        int typ=rdi(),x,y;
        if(typ==1) x=rdi(),y=rdi(),op[i]=Line(x,y);
        else if(typ==2) x=rdi(),R[x]=i;
        else x=rdi(),q[i]=x,hasq[i]=1;
    }
    for(int i=1;i<=n;i++)
        if(!op[i].isnoval()){
            R[i]=R[i]?R[i]:n;
            t2.insert(1,1,n,i,R[i],op[i]);
        }
    t2.solve(1,1,n,0,t1);
    for(int i=1;i<=n;i++)
        if(hasq[i]){
            if(res[i]==-INFl) puts("EMPTY SET");
            else printf("%lld\n",res[i]);
        }
    return 0;
}