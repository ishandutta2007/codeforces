#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

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
#define pb push_back
#define mp make_pair

const int N=500010,INF=0x3f3f3f3f;

int n,k,h[N],s[N],ans=INF;
vi e[N];

int mn[N],mn2[N],cur[N];
void dfs(int x,int fa){
    mn[x]=mn[fa],mn2[x]=mn2[fa];
    if(h[x]<=h[mn[fa]]) mn2[x]=mn[fa],mn[x]=x;
    else if(h[x]<=h[mn2[fa]]) mn2[x]=x;
    cur[x]=h[mn[x]];
    for(auto y:e[x]){
        if(y==fa) continue;
        dfs(y,x);
    }
}

vi dom[N];

struct SGT{
#define lson (now<<1)
#define rson (now<<1|1)
#define mid ((l+r)>>1)
    int mn[N*4],tag[N*4];
    void pushup(int now) {mn[now]=min(mn[lson],mn[rson]);}
    void upd(int now,int val) {mn[now]+=val,tag[now]+=val;}
    void pushdown(int now) {if(tag[now]) upd(lson,tag[now]),upd(rson,tag[now]),tag[now]=0;}
    void add(int now,int l,int r,int x,int y,int val){
        if(x>y) return;
        if(x<=l&&r<=y) return upd(now,val);
        pushdown(now);
        if(x<=mid) add(lson,l,mid,x,y,val);
        if(y>mid) add(rson,mid+1,r,x,y,val);
        pushup(now);
    }
    int query() {return mn[1];}
#undef lson
#undef rson
#undef mid
}t;

int rk[N];
bool check(int x,int delta){
    static int rk1[N];
    for(auto y:dom[x]){
        int nw=min(h[mn2[y]],cur[y]+delta);
        int org=rk[y],now=upper_bound(s+1,s+k+1,nw)-s-1;
        rk1[y]=now,t.add(1,1,k,org+1,now,1);
    }
    bool ret=t.query()>=0;
    for(auto y:dom[x]) t.add(1,1,k,rk[y]+1,rk1[y],-1);
    return ret;
}

int solve(int x){
    int lim=min(h[mn2[x]],ans-1),l=0,r=lim+1;
    if(!check(x,lim)) return INF;
    while(l<r){
        int mid=(l+r)/2;
        if(check(x,mid)) r=mid;
        else l=mid+1;
    }
    return l>lim?INF:l;
}

void init(){
    for(int i=1;i<=k;i++) t.add(1,1,k,i,i,-(k-i+1));
    for(int i=1;i<=n;i++){
        rk[i]=upper_bound(s+1,s+k+1,h[mn[i]])-s-1;
        t.add(1,1,k,1,rk[i],1);
    }
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();
    for(int i=1;i<=n;i++) h[i]=rdi();
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi();
        e[x].pb(y),e[y].pb(x);
    }
    h[0]=INF,dfs(1,0);
    for(int i=1;i<=n;i++) dom[mn[i]].pb(i);
    k=rdi();
    for(int i=1;i<=k;i++) s[i]=rdi();
    sort(s+1,s+k+1);init();
    for(int i=1;i<=n;i++) ans=min(ans,solve(i));
    cout<<(ans>=INF?-1:ans)<<endl;
    return 0;
}