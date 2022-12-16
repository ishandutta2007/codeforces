#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef double db;
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
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

inline int lg2(int x) {return !x?-1:__lg(x);}

const int N=1e6+10;

int n,rt;
vi e[N];

struct LCA_Solver{
    int seq[2*N],st[N],ti,dep[N];
    void dfs(int x,int fa){
        st[x]=++ti,seq[ti]=x;
        dep[x]=dep[fa]+1;
        for(auto y:e[x]){
            if(y==fa) continue;
            dfs(y,x);
            seq[++ti]=x;
        }
    }
    int mi[22][N*2];
    int _min(int x,int y) {return dep[x]<dep[y]?x:y;}
    void init(){
        dfs(rt,0);
        for(int i=1;i<=ti;i++) mi[0][i]=seq[i];
        for(int j=1;j<=lg2(ti);j++)
            for(int i=1;i<=ti-(1<<j)+1;i++)
                mi[j][i]=_min(mi[j-1][i],mi[j-1][i+(1<<(j-1))]);
    }
    inline int operator()(int x,int y){
        if(st[x]>st[y]) swap(x,y);
        int k=lg2(st[y]-st[x]+1);
        return _min(mi[k][st[x]],mi[k][st[y]-(1<<k)+1]);
    }
    inline int dist(int x,int y){
        return dep[x]+dep[y]-2*dep[(*this)(x,y)];
    }
}lca;

int d[N];
void bfs(){
    memset(d,0x3f,sizeof(d));
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(e[i].size()==1) q.push(i),d[i]=0;
    while(!q.empty()){
        int x=q.front();q.pop();
        for(auto y:e[x])
            if(d[y]>d[x]+1) d[y]=d[x]+1,q.push(y);
    }
}

struct Tri{
    int u,v,d;
    friend Tri operator+(const Tri &a,const Tri &b){
        if(!a.u) return b;
        if(!b.u) return a;
        Tri ret{0,0,-1};
        if(a.d>ret.d) ret=a;
        if(b.d>ret.d) ret=b;
        for(auto x:{a.u,a.v}){
            for(auto y:{b.u,b.v}){
                int dis=lca.dist(x,y);
                if(dis>ret.d) ret={x,y,dis};
            }
        }
        return ret;
    }
    int operator()(int x){
        if(!u) return 0;
        return max(lca.dist(x,u),lca.dist(x,v));
    }
}mx[N];

void prepare(){
    for(int i=1;i<=n;i++) if(e[i].size()>1) rt=i;
    bfs();lca.init();
    for(int x=1;x<=n;x++) mx[d[x]]=mx[d[x]]+(Tri){x,x,0};
    for(int i=n;i>=0;i--) mx[i]=mx[i]+mx[i+1];
}

int solve(int w){
    int res=0;
    for(int x=1;x<=n;x++){
        res=max(res,min(mx[0](x),d[x]+w));
        if(res>=d[x]+w)
            while(mx[res+1-w-d[x]](x)>=res+1) ++res;
    }
    return res;
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();
    for(int i=2;i<=n;i++){
        int x=rdi(),y=i;
        e[x].pb(y),e[y].pb(x);
    }
    prepare();
    int q=rdi();
    while(q--) cout<<solve(rdi())<<' ';
    return 0;
}