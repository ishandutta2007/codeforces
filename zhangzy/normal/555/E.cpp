#include<bits/stdc++.h>
using namespace std;

int n, m, q;

vector<int>G[202000], G2[202000];

stack<int>st;
int dfn[202000], low[202000], dft, bel[202000], blt;

int f[202000], g[202000], vis[202000];

void sfd(int x,int fff){
    vis[x]=1;
    for (auto y:G2[x])
        if (y!=fff){
            sfd(y,x);
            f[x]+=f[y];
            g[x]+=g[y];
        }
    if (f[x]&&g[x]){
        puts("No");
        exit(0);
    }
}

int dep[202000], fa[202000][20];
int lca(int x,int y){
    if (dep[x]<dep[y]) swap(x,y);
    for (int i=19;i>=0;--i)
        if (dep[fa[x][i]]>=dep[y])
            x=fa[x][i];
    if (x==y) return x;
    for (int i=19;i>=0;--i)
        if (fa[x][i]!=fa[y][i]){
            x=fa[x][i];
            y=fa[y][i];
        }
    return fa[x][0];
}
void dfs(int x,int fff){
    dep[x]=dep[fff]+1;
    fa[x][0]=fff;
    for (int i=1;i<=19;++i)
        fa[x][i]=fa[fa[x][i-1]][i-1];
    for (auto y:G2[x])
        if (y!=fff)
            dfs(y,x);
}

void tarj(int x,int fff){
    dfn[x]=low[x]=++dft; st.push(x);
    int cnf=0;
    for (auto y:G[x]){
        if (!dfn[y]){
            tarj(y,x);
            low[x]=min(low[x],low[y]);
        }else{
            if (y==fff&&!cnf++) continue;
            low[x]=min(low[x],dfn[y]);
        }
    }
    if (low[x]==dfn[x]){
        ++blt;
        while (1){
            int i=st.top(); st.pop();
            bel[i]=blt;
            if (i==x) break;
        }
    }
}

int main(){
    cin>>n>>m>>q;
    for (int x,y;m--;){
        scanf("%d%d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for (int i=1;i<=n;++i)
        if (!dfn[i])
            tarj(i,0);
    for (int i=1;i<=n;++i)
        for (auto j:G[i])
            if (j>=i&&bel[i]!=bel[j]){
                G2[bel[i]].push_back(bel[j]);
                G2[bel[j]].push_back(bel[i]);
            }
    // for (int i=1;i<=blt;++i){
    //     sort(G2[i].begin(),G2[i].end());
    //     G2[i].resize(unique(G2[i].begin(),G2[i].end())-G2[i].begin());
    // }
    for (int i=1;i<=blt;++i)
        if (!dep[i])
            dfs(i,0);  
    for (int x,y;q--;){
        scanf("%d%d",&x,&y); x=bel[x]; y=bel[y];
        int l=lca(x,y);
        if (l==0){
            puts("No");
            exit(0);
        }
        ++f[x]; --f[l];
        ++g[y]; --g[l];
    }
    for (int i=1;i<=blt;++i)
        if (!vis[i])
            sfd(i,0);
    puts("Yes");
}