#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;
const int N=200010;
int n,m,q;
struct Edge{int to,nxt;};

int ecc[N],col[N];
namespace Graph{
    int head[N],tot=1,dfn[N],low[N],ti,color;
    Edge e[N<<1];
    bool br[N<<1];
    void addedge(int x,int y){
        e[++tot]=(Edge){y,head[x]};
        head[x]=tot;
    }
    void tarjan(int x,int in_edge){
        low[x]=dfn[x]=++ti;
        for(int i=head[x];i;i=e[i].nxt){
            int y=e[i].to;
            if(!dfn[y]){
                tarjan(y,i);
                low[x]=min(low[x],low[y]);
                if(low[y]>dfn[x]) br[i]=br[i^1]=1;
            }
            else if(i!=(in_edge^1)) low[x]=min(low[x],dfn[y]);
        }
    }
    void dfs(int x,int colo){
        ecc[x]=colo;
        for(int i=head[x];i;i=e[i].nxt){
            int y=e[i].to;
            if(br[i]||ecc[y]) continue;
            dfs(y,colo);
        }
    }
    void doit(){
        for(int i=1;i<=n;i++){
            if(!dfn[i]) tarjan(i,0);
        }
        for(int i=1;i<=n;i++){
            if(!ecc[i]) ++color,dfs(i,color);
        }
    }
}

int S[N],T[N],col_id,cnt;
namespace Tree{
    Edge e[N<<1];
    int head[N],tot=1,f[N][21],dep[N],lg2[N],up[N],down[N];
    void addedge(int x,int y){
        e[++tot]=(Edge){y,head[x]};
        head[x]=tot;
    }
    void init(){
        for(int i=2;i<=n;i++) lg2[i]=lg2[i>>1]+1;
    }
    void dfs(int x,int fa){
        f[x][0]=fa;dep[x]=dep[fa]+1;col[x]=col_id;
        for(int i=1;i<=lg2[dep[x]];i++) f[x][i]=f[f[x][i-1]][i-1];
        for(int i=head[x];i;i=e[i].nxt){
            int y=e[i].to;
            if(y==fa) continue;
            dfs(y,x);
        }
    }
    int lca(int x,int y){
        if(dep[x]<dep[y]) swap(x,y);
        for(int i=lg2[dep[x]-dep[y]];i>=0;i--){
            if(dep[f[x][i]]>=dep[y]) x=f[x][i];
        }
        if(x==y) return x;
        for(int i=lg2[dep[x]];i>=0;i--){
            if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
        }
        return f[x][0];
    }
    void dfs1(int x,int fa){
        for(int i=head[x];i;i=e[i].nxt){
            int y=e[i].to;
            if(y==fa) continue;
            dfs1(y,x);
            up[x]+=up[y],down[x]+=down[y];
        }
    }
    void solve(){
        cnt=Graph::color;init();
        for(int i=1;i<=cnt;i++){
            if(!col[i]) ++col_id,dfs(i,0);
        }
        for(int i=1;i<=q;i++){
            int x=ecc[S[i]],y=ecc[T[i]];
            if(col[x]!=col[y]){
                puts("No");
                exit(0);
            }
            int xy=lca(x,y);
            up[x]++,down[y]++,up[xy]--,down[xy]--;
        }
        for(int i=1;i<=cnt;i++) 
            if(dep[i]==1) dfs1(i,0);
        for(int i=1;i<=cnt;i++){
            if(up[i]&&down[i]){
                puts("No");
                exit(0);
            }
        }
        puts("Yes");
    }
}

void build_tree(){
    for(int i=1;i<=n;i++){
        for(int j=Graph::head[i];j;j=Graph::e[j].nxt){
            int y=Graph::e[j].to;
            if(ecc[i]!=ecc[y]) Tree::addedge(ecc[i],ecc[y]);
        }
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;i++){
        int x,y;scanf("%d%d",&x,&y);
        Graph::addedge(x,y);
        Graph::addedge(y,x);
    }
    Graph::doit();
    for(int i=1;i<=q;i++) 
        scanf("%d%d",&S[i],&T[i]);
    build_tree();
    Tree::solve();
    return 0;
}