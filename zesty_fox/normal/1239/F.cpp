#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef double db;
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
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=500010,INF=0x3f3f3f3f;

vi e[N],ans;
int n,m,deg[N];

bool upd_ans(const vi &res){
    if(res.size()&&res.size()<n){
        static int vis[N];ans.clear();
        for(int i=1;i<=n;i++) vis[i]=1;
        for(auto x:res) vis[x]=0;
        for(int i=1;i<=n;i++) 
            if(vis[i]) ans.pb(i),vis[i]=0;
        return true;
    }
    else return false;
}

bool solve1(){
    for(int i=1;i<=n;i++)
        if(!deg[i]) return upd_ans({i});
    return false;
}

int dis[N],pre[N];
bool solve2(){
    fill(dis+1,dis+n+1,INF);
    queue<int> q;int st=0;
    for(int i=1;i<=n;i++)
        if(deg[i]==1) {st=i;break;}
    if(!st) return false;
    dis[st]=0,q.push(st);
    while(!q.empty()){
        int x=q.front();q.pop();
        for(auto y:e[x]){
            if(dis[y]>dis[x]+1)
                dis[y]=dis[x]+1,pre[y]=x,q.push(y);
        }
    }
    int ed=0;
    for(int i=1;i<=n;i++)
        if(deg[i]==1&&i!=st)
            if(!ed||dis[i]<dis[ed]) ed=i;
    if(!ed) return false;
    int nw=ed;vi p;
    while(nw!=st) p.pb(nw),nw=pre[nw];
    p.pb(st);return upd_ans(p);
}

int vis[N],dep[N],fa[N];
void dfs1(int x){
    vis[x]=1;
    for(auto y:e[x])
        if(!vis[y]&&deg[y]==2)
            dep[y]=dep[x]+1,fa[y]=x,dfs1(y);
}

bool solve3(){
    fill(vis+1,vis+n+1,0);
    for(int i=1;i<=n;i++)
        if(deg[i]==2) dfs1(i);
    int mi=INF;
    for(int x=1;x<=n;x++){
        if(deg[x]!=2) continue;
        for(auto y:e[x])
            if(deg[y]==2&&dep[y]-dep[x]>1) mi=min(mi,dep[y]-dep[x]);
    }
    for(int x=1;x<=n;x++){
        if(deg[x]!=2) continue;
        for(auto y:e[x])
            if(deg[y]==2&&dep[y]-dep[x]==mi){
                vi p;
                while(y!=x) p.pb(y),y=fa[y];
                p.pb(x);return upd_ans(p);
            }
    }
    return false;
}

int lf[N],lcnt;
void dfs2(int x,int rt){
    vis[x]=1;
    for(auto y:e[x])
        if(deg[y]==1) lf[++lcnt]=x;
    for(auto y:e[x])
        if(!vis[y]&&deg[y]==2) dfs2(y,rt);
}

int st[N],tp;
bool dfs3(int x,int fa,int to){
    st[++tp]=x;
    if(x==to) return true;
    for(auto y:e[x]){
        if(y==fa||deg[y]!=2) continue;
        if(dfs3(y,x,to)) return true;
    }
    --tp;return false;
}

void find_path(int x,int y) {tp=0;dfs3(x,0,y);}

bool solve4(){
    fill(vis+1,vis+n+1,0);

    int rt=0;
    for(int i=1;i<=n;i++) if(deg[i]==1) rt=i;
    if(!rt) return false;
    pii p[2];int c=0;
    for(auto y:e[rt]){
        if(!vis[y]){
            lcnt=0,dfs2(y,y);
            if(lcnt>=2) p[c++]={lf[1],lf[2]};
            if(c==2){
                vi tmp({rt});
                find_path(p[0].fi,p[0].se);tmp.insert(tmp.end(),st+1,st+tp+1);
                find_path(p[1].fi,p[1].se);tmp.insert(tmp.end(),st+1,st+tp+1);
                return upd_ans(tmp);
            }
        }
    }
    return false;
}

void clear(){
    ans.clear();
    for(int i=1;i<=n;i++){
        e[i].clear(),deg[i]=0;
        dis[i]=pre[i]=0;
        fa[i]=dep[i]=vis[i]=0;
    }
}

void solve(){
    n=rdi(),m=rdi();
    for(int i=1;i<=m;i++){
        int x=rdi(),y=rdi();
        e[x].pb(y),e[y].pb(x);
    }
    for(int i=1;i<=n;i++) deg[i]=e[i].size()%3;
    if(!solve1()&&!solve2()&&!solve3()&&!solve4()) cout<<"No\n";
    else{
        cout<<"Yes\n"<<ans.size()<<'\n';
        for(auto x:ans) cout<<x<<' ';
        cout<<'\n';
    }
    clear();
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    int T=rdi();
    while(T--) solve();
    return 0;
}