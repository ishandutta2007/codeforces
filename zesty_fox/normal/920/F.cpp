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

const int N=300010,M=1000010;

int d[M];
void init(int lim=M-10){
    for(int i=1;i<=lim;i++){
        for(int j=i;j<=lim;j+=i) d[j]++;
    }
}

namespace Tree{
    #define lson (now<<1)
    #define rson (now<<1|1)
    #define mid ((l+r)>>1)
    ll sum[N<<2],maxn[N<<2];
    void pushup(int now){
        sum[now]=sum[lson]+sum[rson];
        maxn[now]=max(maxn[lson],maxn[rson]);
    }
    void build(int now,int l,int r,int *a){
        if(l==r){
            sum[now]=maxn[now]=a[l];
            return;
        }
        build(lson,l,mid,a);build(rson,mid+1,r,a);
        pushup(now);
    }
    void modify(int now,int l,int r,int x,int y){
        if(maxn[now]<=2) return;
        if(l==r){
            sum[now]=maxn[now]=d[sum[now]];
            return;
        }
        if(x<=mid) modify(lson,l,mid,x,y);
        if(y>mid) modify(rson,mid+1,r,x,y);
        pushup(now);
    }
    ll query(int now,int l,int r,int x,int y){
        if(x<=l&&r<=y) return sum[now];
        ll res=0;
        if(x<=mid) res+=query(lson,l,mid,x,y);
        if(y>mid) res+=query(rson,mid+1,r,x,y);
        return res;
    }
}
using namespace Tree;

int n,m,a[N];
int main(){
    n=rdi(),m=rdi();init();
    for(int i=1;i<=n;i++) a[i]=rdi();
    build(1,1,n,a);
    while(m--){
        int op=rdi(),x=rdi(),y=rdi();
        if(op==1) modify(1,1,n,x,y);
        else printf("%lld\n",query(1,1,n,x,y));
    }
    return 0;
}