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

const int N=200010,INF=0x3f3f3f3f;
vi e[N];
int n,Q;

int f[N][21],lg2[N],dep[N],siz[N],dfn[N],ti;
void init_lg(){
    for(int i=2;i<=n;i++) lg2[i]=lg2[i>>1]+1;
}
void dfs(int x,int fa){
    dfn[x]=++ti;f[x][0]=fa;siz[x]=1;
    for(int i=1;i<=lg2[dep[x]];i++){
        f[x][i]=f[f[x][i-1]][i-1];
    }
    for(auto y:e[x]){
        if(y==fa) continue;
        dep[y]=dep[x]+1;
        dfs(y,x);
        siz[x]+=siz[y];
    }
}

int LCA(int x,int y){
    if(dfn[x]<dfn[y]) swap(x,y);
    for(int i=lg2[dep[x]];i>=0;i--){
        if(dfn[f[x][i]]>dfn[y]) x=f[x][i];
    }
    return f[x][0];
}

vi nodes;
vector<pii> v[N];
int k,m,qs[N],sd[N],key[N];

int st[N],tp;
void init(){
    k=rdi(),m=rdi();
    for(int i=1;i<=k;i++) qs[i]=rdi(),sd[i]=rdi(),nodes.pb(qs[i]);
    for(int i=1;i<=m;i++) key[i]=rdi(),nodes.pb(key[i]);
    sort(nodes.begin(),nodes.end(),[&](int x,int y){return dfn[x]<dfn[y];});
    for(int i=nodes.size()-2;i>=0;i--) nodes.pb(LCA(nodes[i],nodes[i+1]));
    sort(nodes.begin(),nodes.end(),[&](int x,int y){return dfn[x]<dfn[y];});
    nodes.resize(unique(nodes.begin(),nodes.end())-nodes.begin());
    for(auto x:nodes){
        while(tp&&dfn[st[tp]]+siz[st[tp]]-1<dfn[x]) --tp;
        if(tp){
            int y=st[tp],w=dep[x]-dep[st[tp]];
            v[x].pb(mp(y,w));v[y].pb(mp(x,w));
        }
        st[++tp]=x;
    }
}

struct Node{
    int x,vid,ti;
    bool operator < (const Node &b) const{
        return ti==b.ti?vid>b.vid:ti>b.ti;
    }
};
priority_queue<Node> q;
int col[N],dis[N],tim[N],vis[N];
void solve(){
    while(!q.empty()) q.pop();
    for(int i=1;i<=k;i++) dis[qs[i]]=tim[qs[i]]=0,col[qs[i]]=i,q.push({qs[i],i,0});
    while(!q.empty()){
        auto tmp=q.top();q.pop();
        int x=tmp.x,vir=tmp.vid;
        if(vis[x]) continue;
        vis[x]=1;
        for(auto tmp1:v[x]){
            int y=tmp1.fi,w=tmp1.se;
            int ti1=(w+dis[x]+sd[vir]-1)/sd[vir];
            if(ti1<tim[y]||(ti1==tim[y]&&col[y]>vir)){
                dis[y]=dis[x]+w;tim[y]=ti1;col[y]=vir;
                q.push({y,vir,ti1});
            }
        }
    }
    for(int i=1;i<=m;i++) printf("%d ",col[key[i]]);
    puts("");
}

void clear(){
    for(auto x:nodes) v[x].clear(),col[x]=0,vis[x]=0,dis[x]=tim[x]=INF;
    nodes.clear();tp=0;
}

int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    n=rdi();
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi();
        e[x].pb(y);e[y].pb(x);
    }
    init_lg();
    dfs(1,0);
    Q=rdi();
    memset(tim,0x3f,sizeof(tim));
    memset(dis,0x3f,sizeof(dis));
    while(Q--) init(),solve(),clear();
    return 0;
}