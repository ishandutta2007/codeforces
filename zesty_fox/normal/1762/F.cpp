#include <bits/stdc++.h>

using namespace std;

using i64=long long;
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
#define rdi64 read<i64>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=5e5+10,M=1e5+10;

int n,k,a[N];

struct SGT{
#define lson (nw<<1)
#define rson (nw<<1|1)
#define mid ((l+r)>>1)
    int mx[M*4],sum[M*4];
    void pushup(int nw){
        mx[nw]=max(mx[lson],mx[rson]);
        sum[nw]=sum[lson]+sum[rson];
    }

    void ins(int nw,int l,int r,int x,int v,int ad){
        if(l==r) {mx[nw]=v,sum[nw]+=ad;return;}
        if(x<=mid) ins(lson,l,mid,x,v,ad);
        else ins(rson,mid+1,r,x,v,ad);
        pushup(nw);
    }
    int qmax(int nw,int l,int r,int x,int y){
        if(x<=l&&r<=y) return mx[nw];
        int ret=0;
        if(x<=mid) ret=max(ret,qmax(lson,l,mid,x,y));
        if(y>mid) ret=max(ret,qmax(rson,mid+1,r,x,y));
        return ret;
    }
    int qsum(int nw,int l,int r,int x,int y){
        if(x<=l&&r<=y) return sum[nw];
        int ret=0;
        if(x<=mid) ret+=qsum(lson,l,mid,x,y);
        if(y>mid) ret+=qsum(rson,mid+1,r,x,y);
        return ret;
    }
#undef lson
#undef rson
#undef mid
}t;

i64 calc(int a[]){
    static int cnt[N];cnt[0]=0;
    for(int i=1;i<=n;i++){
        cnt[i]=1;
        int nxt=t.qmax(1,1,M-1,a[i],a[i]+k);
        if(nxt){
            cnt[i]+=cnt[nxt];
            if(a[i]<a[nxt]) cnt[i]+=t.qsum(1,1,M-1,a[i],a[nxt]-1);
        }
        t.ins(1,1,M-1,a[i],i,1);
    }
    for(int i=1;i<=n;i++)
        t.ins(1,1,M-1,a[i],0,-1);
    return accumulate(cnt+1,cnt+n+1,0ll);
}

i64 calc1(){
    static int cnt[M];
    i64 sum=0;
    for(int i=1;i<=n;i++)
        sum+=(++cnt[a[i]]);
    for(int i=1;i<=n;i++) --cnt[a[i]];
    return sum;
}

void solve(){
    n=rdi(),k=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    i64 res=calc(a)-calc1();
    reverse(a+1,a+n+1),res+=calc(a);
    cout<<res<<'\n';
}

int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    int T=rdi();
    while(T--) solve();
    return 0;
}