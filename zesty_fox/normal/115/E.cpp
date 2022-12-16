#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=200010;
struct SegmentTree{
#define lson (now<<1)
#define rson (now<<1|1)
#define mid ((l+r)>>1)
    ll maxn[N<<2],add[N<<2];
    void pushdown(int now){
        if(add[now]){
            maxn[lson]+=add[now];
            maxn[rson]+=add[now];
            add[lson]+=add[now];
            add[rson]+=add[now];
            add[now]=0;
        }
    }
    void pushup(int now) {maxn[now]=max(maxn[lson],maxn[rson]);}
    void modify(int now,int l,int r,int x,int y,ll val){
        if(x>y) return;
        if(x<=l&&r<=y){
            maxn[now]+=val;add[now]+=val;
            return;
        }
        pushdown(now);
        if(x<=mid) modify(lson,l,mid,x,y,val);
        if(y>mid) modify(rson,mid+1,r,x,y,val);
        pushup(now);
    }
    ll query(int now,int l,int r,int x,int y){
        if(x<=l&&r<=y) return maxn[now];
        pushdown(now);ll res=0;
        if(x<=mid) res=max(res,query(lson,l,mid,x,y));
        if(y>mid) res=max(res,query(rson,mid+1,r,x,y));
        pushup(now);return res;
    }
}s;

ll f[N],ans;
int n,m,c[N];
struct Competition{
    int l,r;ll x;
    bool operator<(const Competition& a)const{
        return (r!=a.r?r<a.r:l<a.l);
    }
}t[N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=m;i++) scanf("%d%d%lld",&t[i].l,&t[i].r,&t[i].x);
    sort(t+1,t+m+1);int pos=1;
    for(int i=1;i<=n;i++){
        for(;t[pos].r<=i&&pos<=m;pos++){
            s.modify(1,0,n,0,t[pos].l-1,t[pos].x);
        }
        s.modify(1,0,n,0,i-1,-c[i]);
        f[i]=max(f[i-1],s.query(1,0,n,0,i));
        s.modify(1,0,n,i,i,f[i]);
        ans=max(ans,f[i]);
    }
    cout<<ans<<endl;
    return 0;
}