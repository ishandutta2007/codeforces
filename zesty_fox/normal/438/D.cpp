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
#define mp make_pair
#define pb push_back

const int N=100010;

#define lson (now<<1)
#define rson (now<<1|1)
#define mid ((l+r)>>1)

ll sum[N<<2];
int maxn[N<<2];

void pushup(int now){
    sum[now]=sum[lson]+sum[rson];
    maxn[now]=max(maxn[lson],maxn[rson]);
}

void build(int now,int l,int r,int *a){
    if(l==r){
        sum[now]=maxn[now]=a[l];
        return;
    }
    build(lson,l,mid,a);
    build(rson,mid+1,r,a);
    pushup(now);
}

void modify(int now,int l,int r,int x,int val){
    if(l==x&&r==x){
        maxn[now]=sum[now]=val;
        return;
    }
    if(x<=mid) modify(lson,l,mid,x,val);
    else modify(rson,mid+1,r,x,val);
    pushup(now);
}

ll query(int now,int l,int r,int x,int y){
    if(x<=l&&r<=y) return sum[now];
    ll res=0;
    if(x<=mid) res+=query(lson,l,mid,x,y);
    if(y>mid) res+=query(rson,mid+1,r,x,y);
    return res;
}

void mod(int now,int l,int r,int x,int y,int m){
    if(l==r) {sum[now]%=m,maxn[now]%=m;return;}
    if(x<=l&&r<=y){
        if(maxn[now]>=m){
            mod(lson,l,mid,x,y,m);
            mod(rson,mid+1,r,x,y,m);
            pushup(now);
        }
        return;
    }
    if(x<=mid) mod(lson,l,mid,x,y,m);
    if(y>mid) mod(rson,mid+1,r,x,y,m);
    pushup(now);
}

#undef lson
#undef rson
#undef mid

int n,m,a[N];
int main(){
    n=rdi(),m=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    build(1,1,n,a);
    while(m--){
        int typ=rdi(),l,r,x;
        if(typ==1){
            l=rdi(),r=rdi();
            printf("%lld\n",query(1,1,n,l,r));
        }
        if(typ==2){
            l=rdi(),r=rdi(),x=rdi();
            mod(1,1,n,l,r,x);
        }
        if(typ==3){
            l=rdi(),x=rdi();
            modify(1,1,n,l,x);
        }
    }
    return 0;
}