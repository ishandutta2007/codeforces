// LUOGU_RID: 97055331
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

const int N=5e5+10,INF=0x3f3f3f3f;

int n,p[N];
int L[N],R[N];

int pre[N],suf[N];

void init(){
    n=rdi();
    for(int i=1;i<=n;i++) p[i]=rdi();

    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+(p[i]==0);
    for(int i=n;i>=1;i--) suf[i]=suf[i+1]+(p[i]==0);

    int c0=pre[n];
    fill(L+1,L+n+1,0),fill(R+1,R+n+1,0);
    for(int i=n;i>=1;i--)
        if(p[i]&&suf[i]>=(c0+1)/2&&!L[p[i]]) L[p[i]]=i;
    for(int i=1;i<=n;i++)
        if(p[i]&&pre[i]>=(c0+2)/2&&!R[p[i]]) R[p[i]]=i; 
}

struct SGT{
#define lson (nw<<1)
#define rson (nw<<1|1)
#define mid ((l+r)>>1)
    int mn[N*4],tg[N*4];
    void apply(int nw,int v){
        mn[nw]+=v,tg[nw]+=v;
    }
    void pushdown(int nw){
        if(tg[nw]){
            apply(lson,tg[nw]),apply(rson,tg[nw]);
            tg[nw]=0;
        }
    }
    void pushup(int nw){
        mn[nw]=min(mn[lson],mn[rson]);
    }

    void build(int nw,int l,int r){
        tg[nw]=0;
        if(l==r) {mn[nw]=suf[l];return;}
        build(lson,l,mid),build(rson,mid+1,r);
        pushup(nw);
    }
    void add(int nw,int l,int r,int x,int y,int v){
        if(x<=l&&r<=y) {apply(nw,v);return;}
        pushdown(nw);
        if(x<=mid) add(lson,l,mid,x,y,v);
        if(y>mid) add(rson,mid+1,r,x,y,v);
        pushup(nw);
    }
    int query(int nw,int l,int r,int x,int y){
        if(x<=l&&r<=y) return mn[nw];
        pushdown(nw);int ret=INF;
        if(x<=mid) ret=min(ret,query(lson,l,mid,x,y));
        if(y>mid) ret=min(ret,query(rson,mid+1,r,x,y));
        return ret;
    }
#undef lson
#undef rson
#undef mid
}t;

int cnt[N];
vi v[N];

void clear(){
    for(int i=0;i<=n+1;i++){
        cnt[i]=0,v[i].clear();
        pre[i]=suf[i]=L[i]=R[i]=0;
    }
}

void solve(){
    init();
    for(int i=1;i<=n;i++){
        if(!L[i]&&!R[i]) continue;
        int l=L[i],r=R[i];
        if(!l||!r) l=r=(l|r);
        cnt[r]++,v[l].pb(r);
    }
    
    int ans=INF;t.build(1,1,n+1);
    for(int l=n;l>=0;l--){
        ans=min(ans,pre[l]+t.query(1,1,n+1,l+1,n+1));
        t.add(1,1,n+1,l+1,n+1,cnt[l]);
        for(auto r:v[l]) 
            if(l!=r) t.add(1,1,n+1,l+1,r,1);
    }
    ans=min(ans,pre[n]/2);
    cout<<ans<<'\n';
    clear();
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