#include<bits/stdc++.h>
using namespace std;


int n, m;

#define pii pair<int,int>
#define fi first
#define se second

int fa[101000];
int GF(int x){
    return x==fa[x]? x: fa[x]=GF(fa[x]);
}
vector<pii>els;
vector<int>G[101000];

int FA[101000][20], dep[101000];
void dfs(int x,int fff){
    dep[x]=dep[fff]+1;
    FA[x][0]=fff;
    for (int i=1;i<=19;++i) FA[x][i]=FA[FA[x][i-1]][i-1];
    for (auto y:G[x]){
        if (y==fff) continue;
        dfs(y,x);
    }
}

int f[101000];

int gogogo(int x,int y){
    for (int i=19;i>=0;--i)
        if (dep[FA[x][i]]>dep[y])
            x=FA[x][i];
    return x;
}

int lca(int x,int y){
    if (dep[x]<dep[y]) swap(x,y);
    for (int i=19;i>=0;--i)
        if (dep[FA[x][i]]>=dep[y])
            x=FA[x][i];
    if (x==y) return x;
    for (int i=19;i>=0;--i)
        if (FA[x][i]!=FA[y][i]){
            x=FA[x][i]; y=FA[y][i];
        }
    return FA[x][0];
}

void dfssum(int x,int fff){
    f[x]+=f[fff];
    for (auto y:G[x]){
        if (y==fff) continue;
        dfssum(y,x);
    }
}

int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i) fa[i]=i;
    for (;m--;){
        int x, y;
        scanf("%d%d",&x,&y);
        if (GF(x)==GF(y)){
            els.push_back({x,y});
        }else{
            G[x].push_back(y);
            G[y].push_back(x);
            fa[GF(x)]=GF(y);
        }
    }
    dfs(1,0);
    for (auto o:els){
        int x=o.fi, y=o.se, l=lca(x,y);
        // printf("%d %d %d\n",x,y,l);
        if (l==x||l==y){
            if (l==x) swap(x,y);
            // l==y
            int tx = gogogo(x,l);
            f[tx]+=1; f[x]+=-1;
        }else{
            f[1]+=1; f[x]+=-1; f[y]+=-1;
        }
    }
    dfssum(1,0);
    // for (int i=1;i<=n;++i) printf(" %d",f[i]);
    for (int i=1;i<=n;++i) printf("%d",(f[i]? 0: 1));
    puts("");
}