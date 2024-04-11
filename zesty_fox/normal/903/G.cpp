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

const int N=200010;
const ll INFl=0x3f3f3f3f3f3f3f3f;

int n,m,Q,a[N],b[N];
vector<pii> e[N];

struct SGT{
#define lson (now<<1)
#define rson (now<<1|1)
#define mid ((l+r)>>1)
    ll t[N<<2],tag[N<<2];
    void pushup(int now) {t[now]=min(t[lson],t[rson]);}
    void upd(int now,ll val) {tag[now]+=val;t[now]+=val;}
    void pushdown(int now) {if(tag[now]) upd(lson,tag[now]),upd(rson,tag[now]),tag[now]=0;}
    void modify(int now,int l,int r,int x,int y,int val){
        if(x>y) return;
        if(x<=l&&r<=y) {upd(now,val);return;}
        pushdown(now);
        if(x<=mid) modify(lson,l,mid,x,y,val);
        if(y>mid) modify(rson,mid+1,r,x,y,val);
        pushup(now);
    }
    ll query(int now,int l,int r,int x,int y){
        if(x<=l&&r<=y) return t[now];
        ll tmp=INFl;pushdown(now);
        if(x<=mid) tmp=min(tmp,query(lson,l,mid,x,y));
        if(y>mid) tmp=min(tmp,query(rson,mid+1,r,x,y));
        return tmp;
    }
#undef lson
#undef rson
#undef mid
}t;

priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
ll sum[N];
void init(){
    for(int i=0;i<n;i++) t.modify(1,0,n-1,i,i,b[i]);
    for(int i=1;i<=n;i++){
        for(auto tmp:e[i]) t.modify(1,0,n-1,0,tmp.fi-1,tmp.se);
        sum[i]=a[i]+t.query(1,0,n-1,0,n-1);
        q.push(mp(sum[i],i));
    }
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),m=rdi(),Q=rdi();
    for(int i=1;i<n;i++) a[i]=rdi(),b[i]=rdi();
    for(int i=1;i<=m;i++){
        int x=rdi(),y=rdi(),z=rdi();
        e[x].pb(mp(y,z));
    }
    init();
    cout<<q.top().fi<<'\n';
    while(Q--){
        int x=rdi(),w=rdi();
        sum[x]=sum[x]-a[x]+w,a[x]=w;
        q.push(mp(sum[x],x));
        while(sum[q.top().se]!=q.top().fi) q.pop();
        cout<<q.top().fi<<'\n';
    }
    return 0;
}