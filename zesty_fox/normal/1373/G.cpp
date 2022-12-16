#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=600010;

struct sgt{
#define lson (now<<1)
#define rson (now<<1|1)
#define mid ((l+r)>>1)

    int maxn[N<<2],tag[N<<2];
    void pushup(int now){
        maxn[now]=max(maxn[lson],maxn[rson]);
    }
    void upd(int now,int val){
        maxn[now]+=val;
        tag[now]+=val;
    }
    void pushdown(int now){
        if(tag[now]){
            upd(lson,tag[now]),upd(rson,tag[now]);
            tag[now]=0;
        }
    }
    void build(int now,int l,int r){
        if(l==r){
            maxn[now]=l-1;
            return;
        }
        build(lson,l,mid);
        build(rson,mid+1,r);
        pushup(now);
    }
    void modify(int now,int l,int r,int x,int y,int val){
        if(x<=l&&r<=y){
            upd(now,val);
            return;
        }
        pushdown(now);
        if(x<=mid) modify(lson,l,mid,x,y,val);
        if(y>mid) modify(rson,mid+1,r,x,y,val);
        pushup(now);
    }
    int query(int now,int l,int r,int x,int y){
        if(x>y) return 0;
        if(x<=l&&r<=y) return maxn[now];
        pushdown(now);
        int ret=0;
        if(x<=mid) ret=max(ret,query(lson,l,mid,x,y));
        if(y>mid) ret=max(ret,query(rson,mid+1,r,x,y));
        return ret;
    }

#undef lson
#undef rson
#undef mid
}t;

int n,m,k,maxpos,lim;

struct Position{
    int x,y;
    int dest(int row) const{return y+abs(x-row);}
    bool operator < (const Position &rhs) const{
        if(dest(k)!=rhs.dest(k)) return dest(k)<rhs.dest(k);
        else return mp(x,y)<mp(rhs.x,rhs.y);
    }
};
set<Position> pts;
int ans;

void insert(Position val){
    pts.insert(val);
    maxpos=(*pts.rbegin()).dest(k);
    t.modify(1,1,lim,1,val.dest(k),1);
    ans=max(t.query(1,1,lim,1,maxpos)-n,0);
}

void erase(Position val){
    pts.erase(val);
    t.modify(1,1,lim,1,val.dest(k),-1);
    if(pts.empty()){
        maxpos=ans=0;
        return;
    }
    maxpos=(*pts.rbegin()).dest(k);
    ans=max(t.query(1,1,lim,1,maxpos)-n,0);
}

void modify(Position val){
    if(pts.find(val)==pts.end()) insert(val);
    else erase(val);
}

int main(){
    n=rdi(),k=rdi(),m=rdi();
    lim=2*n+m;
    t.build(1,1,lim);
    while(m--){
        //cerr<<m<<endl;
        int x=rdi(),y=rdi();
        modify({x,y});
        printf("%d\n",ans);
    }
    return 0;
}