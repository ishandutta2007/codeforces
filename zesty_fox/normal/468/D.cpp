#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
const int N=100010;
int n,head[N],tot;
struct Edge{int to,nxt,w;}e[N<<1];
void addedge(int x,int y,int w){
    e[++tot]=(Edge){y,head[x],w};
    head[x]=tot;
}

int siz[N],maxn[N],zx;
void dfs(int x,int fa){
    siz[x]=1;
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==fa) continue;
        dfs(y,x);
        siz[x]+=siz[y];
        maxn[x]=max(maxn[x],siz[y]);
    }
    maxn[x]=max(maxn[x],n-siz[x]);
    if(maxn[x]<maxn[zx]||!zx) zx=x;
}

ll ans,dis[N],sum[N];
void dfs1(int x,int fa){
    ans+=dis[x];
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==fa) continue;
        dis[y]=dis[x]+e[i].w;
        dfs1(y,x);
    }
}

set<int> vis[N],minx;
set<pair<int,int> > s;
int belong[N];
void connect(int x,int y){
    int x1=belong[x],y1=belong[y];
    minx.erase(y);
    if(x1) s.erase(mp(sum[x1],x1)),s.insert(mp(--sum[x1],x1));
    if(y1){
        vis[y1].erase(y);
        if(!vis[y1].empty()) minx.insert(*vis[y1].begin());
        s.erase(mp(sum[y1],y1)),s.insert(mp(--sum[y1],y1));
    }
}

void doit(int x,int fa,int rt){
    belong[x]=rt;
    vis[belong[x]].insert(x);
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==fa) continue;
        doit(y,x,rt);
    }
}

int solve(int x){
    int res;
    if((*(--s.end())).first==n-x+1&&(*(--s.end())).second!=belong[x]) res=*vis[(*(--s.end())).second].begin();
    else res=belong[*minx.begin()]!=belong[x]||x==zx?*minx.begin():*(++minx.begin());
    connect(x,res);return res;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y,w;scanf("%d%d%d",&x,&y,&w);
        addedge(x,y,w);addedge(y,x,w);
    }
    dfs(1,0);dfs1(zx,0);
    cout<<ans*2<<endl;
    if(n==1) return puts("1"),0;
    minx.insert(zx);
    for(int i=head[zx];i;i=e[i].nxt){
        int x=e[i].to;doit(x,zx,x);
        minx.insert(*vis[x].begin()),s.insert(mp(sum[x]=vis[x].size()*2,x));
    }
    for(int i=1;i<=n;i++) printf("%d ",solve(i));
    puts("");
    return 0;
}