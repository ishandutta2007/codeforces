#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;

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
#define mp make_pair
#define pb push_back

const int N=200010;

int n,q,a[N];

#define lson (now<<1)
#define rson (now<<1|1)
#define mid ((l+r)>>1)

struct Node{
    int l,r,llen,rlen;
    ll sum;
}t[N<<2];

Node operator + (const Node &lhs,const Node &rhs){
    return {lhs.l,rhs.r,\
            lhs.llen+(lhs.llen==lhs.r-lhs.l+1&&a[lhs.r]<=a[rhs.l])*rhs.llen,\
            rhs.rlen+(rhs.rlen==rhs.r-rhs.l+1&&a[lhs.r]<=a[rhs.l])*lhs.rlen,\
            lhs.sum+rhs.sum+(a[lhs.r]<=a[rhs.l])*((ll)lhs.rlen*rhs.llen)};
}

void pushup(int now){
    t[now]=t[lson]+t[rson];    
}

void build(int now,int l,int r){
    if(l==r){
        t[now]={l,r,1,1,1};
        return;
    }
    build(lson,l,mid);
    build(rson,mid+1,r);
    pushup(now);
}

void modify(int now,int l,int r,int x,int val){
    if(l==r){
        t[now]={l,r,1,1,1};
        a[x]=val;
        return;
    }
    if(x<=mid) modify(lson,l,mid,x,val);
    else modify(rson,mid+1,r,x,val);
    pushup(now);
}

Node query(int now,int l,int r,int x,int y){
    if(x<=l&&r<=y) return t[now];
    if(y<=mid) return query(lson,l,mid,x,y);
    else if(x>mid) return query(rson,mid+1,r,x,y);
    return query(lson,l,mid,x,y)+query(rson,mid+1,r,x,y);
}

#undef lson
#undef rson
#undef mid

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),q=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    build(1,1,n);
    while(q--){
        int op=rdi(),x=rdi(),y=rdi();
        if(op==1) modify(1,1,n,x,y);
        else printf("%lld\n",query(1,1,n,x,y).sum);
    }
    return 0;
}