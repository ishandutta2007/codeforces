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

struct Edge{int to,nxt,w;}e[N<<1];
int head[N],tot=1,onp[N<<1];
void addedge(int x,int y,int w){
    e[++tot]={y,head[x],w};
    head[x]=tot;
}

int n,m,q;

void dij(int st,ll *dis,int *pre){
    memset(dis,0x3f,sizeof(ll)*(n+2));
    memset(pre,0,sizeof(int)*(n+2));
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
    q.push(mp(dis[st]=0,st));
    while(!q.empty()){
        auto tmp=q.top();q.pop();
        int x=tmp.se;
        if(tmp.fi!=dis[x]) continue;
        for(int i=head[x];i;i=e[i].nxt){
            int y=e[i].to;
            if(dis[y]>dis[x]+e[i].w){
                dis[y]=dis[x]+e[i].w,pre[y]=i;
                q.push(mp(dis[y],y));
            }
        }
    }
}

ll dis[2][N];
int id[N],pcnt,pre[N],p[N];

vi tr[N];
int L[N],R[N];
void dfs(int x,int rt,int *bl){
    if(id[x]) rt=x;
    bl[x]=id[rt];
    for(auto y:tr[x]) dfs(y,rt,bl);
}

struct SGT{
#define lson (now<<1)
#define rson (now<<1|1)
#define mid ((l+r)>>1)
    vector<ll> t,tag;
    void init(int n=0){
        t.resize((n<<2)+1),tag.resize((n<<2)+1);
        fill(t.begin(),t.end(),INFl),fill(tag.begin(),tag.end(),INFl);
    }
    void pushup(int now) {t[now]=min(t[lson],t[rson]);}
    void upd(int now,ll val){
        t[now]=min(t[now],val);
        tag[now]=min(tag[now],val);
    }
    void pushdown(int now){
        if(tag[now]<INFl){
            upd(lson,tag[now]),upd(rson,tag[now]);
            tag[now]=INFl;
        }
    }
    void modify(int now,int l,int r,int x,int y,ll val){
        if(x>y) return;
        if(x<=l&&r<=y){
            upd(now,val);
            return;
        }
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
}t;

void init(){
    dij(1,dis[0],pre);
    int now=n;
    while(now) p[++pcnt]=now,onp[pre[now]]=onp[pre[now]^1]=1,now=e[pre[now]^1].to;
    reverse(p+1,p+pcnt+1);
    for(int i=1;i<=pcnt;++i) id[p[i]]=i;

    dij(1,dis[0],pre);
    for(int i=1;i<=n;i++) tr[i].clear();
    for(int i=2;i<=n;i++) tr[e[pre[i]^1].to].pb(i);
    dfs(1,0,L);

    dij(n,dis[1],pre);
    for(int i=1;i<=n;i++) tr[i].clear();
    for(int i=1;i<n;i++) tr[e[pre[i]^1].to].pb(i);
    dfs(n,0,R);

    t.init(pcnt);
    for(int x=1;x<=n;x++){
        for(int i=head[x];i;i=e[i].nxt){
            if(onp[i]) continue;
            int y=e[i].to;
            t.modify(1,1,pcnt-1,L[x],R[y]-1,dis[0][x]+dis[1][y]+e[i].w);
        }
    }
}

ll query(int i,int val){
    int x=e[(i<<1)^1].to,y=e[i<<1].to,w=e[i<<1].w;
    if(!onp[i<<1]){
        if(w>val) return min(dis[0][n],min(dis[0][x]+val+dis[1][y],dis[0][y]+val+dis[1][x]));
        else return dis[0][n];
    }
    else{
        if(w>val) return dis[0][n]-w+val;
        else return min(dis[0][n]-w+val,t.query(1,1,pcnt-1,min(id[x],id[y]),max(id[x],id[y])-1));
    }
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),m=rdi(),q=rdi();
    for(int i=1;i<=m;i++){
        int x=rdi(),y=rdi(),w=rdi();
        addedge(x,y,w),addedge(y,x,w);
    }
    init();
    while(q--){
        int id=rdi(),w=rdi();
        printf("%lld\n",query(id,w));
    }
    return 0;
}