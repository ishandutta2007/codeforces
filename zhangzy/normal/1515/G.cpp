#include <bits/stdc++.h>
#define ll long long
using namespace std;
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, q;

#define pii pair<int,int>
#define fi first
#define se second
vector<pii>G[202000];

int dfn[202000], dft, low[202000], st[202000], tp, bel[202000], blt;
int dep[202000], fa[202000][22];
ll dis[202000];

// int lca(int x,int y){
//     if (dep[x]<dep[y]) swap(x,y);
//     for (int i=20;i>=0;--i)
//         if (dep[fa[x][i]]>=dep[y])
//             x=fa[x][i];
//     if (x==y) return x;
//     for (int i=20;i>=0;--i)
//         if (fa[x][i]!=fa[y][i]){
//             x=fa[x][i];
//             y=fa[y][i];
//         }
//     return fa[x][0];
// }

void dfs(int x,int fff){
    st[++tp]=x;
    dfn[x]=low[x]=++dft;
    dep[x]=dep[fff]+1; fa[x][0]=fff;
    for (int i=1;i<=20;++i) fa[x][i]=fa[fa[x][i-1]][i-1];
    for (auto o:G[x]){
        int y=o.fi, w=o.se;
        if (!dfn[y]){
            dis[y]=dis[x]+w;
            dfs(y,x);
            low[x]=min(low[x],low[y]);
        }else{
            if (!bel[y]){
                low[x]=min(low[x],dfn[y]);
            }
        }
    }
    if (low[x]>=dfn[x]){
        ++blt;
        while (st[tp]!=x){
            bel[st[tp]]=blt;
            --tp;
        }
        {
            bel[st[tp]]=blt;
            --tp;
        }
    }
}


int vis[202000]; ll d[202000];
ll gcd(ll x,ll y){
    if (x==0||y==0) return x+y;
    return __gcd(x,y);
}
void dfs2(int x,int fff){
    vis[x]=1;
    for (auto o:G[x]){
        int y=o.fi, w=o.se;
        if (!vis[y]){
            dfs2(y,x);
        }else{
            if (bel[x]==bel[y]){
                // int l=lca(x,y);
                ll tmp=abs(dis[x]-dis[y]+w);
                d[bel[x]]=gcd(d[bel[x]],tmp);
            }
        }
    }
}


int main(){
    cin>>n>>m;
    for (int i=1;i<=m;++i){
        int u, v, w; scanf("%d%d%d",&u,&v,&w);
        G[u].push_back({v,w});
        // G[v].push_back({u,w});
    }
    for (int i=1;i<=n;++i)
        if (!dfn[i]) dfs(i,0);
    for (int i=1;i<=n;++i)
        if (!vis[i]) dfs2(i,0);
    // for (int i=1;i<=n;++i) printf("%d ",bel[i]); puts("");
    // for (int i=1;i<=n;++i) printf("%lld ",d[bel[i]]); puts("");
    int q, u; ll s, t;
    cin>>q;
    for (;q--;){
        scanf("%d%lld%lld",&u,&s,&t);
        int b=bel[u];
        ll g=gcd(d[b],t);
        if (s%g==0){
            puts("YES");
        }else{
            puts("NO");
        }
    }
}