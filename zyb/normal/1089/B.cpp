#include<bits/stdc++.h>
using namespace std;
#define N 1005
struct edge {
    int Next,to;
}e[N*N];
int bel[N],mark[N],match[N],vis[N],Next[N],n,m,M,g[N],T,ans;
queue<int>q;
inline void addedge(int x,int y) {
    e[++M]=(edge){g[x],y};
    g[x]=M;
}
inline void adde(int x,int y) {
    addedge(x,y),addedge(y,x);
}
inline int getf(int x) {
    return bel[x]==x?x:bel[x]=getf(bel[x]);
}
inline void unite(int x,int y) {
    bel[getf(x)]=getf(y);
}
inline int lca(int x,int y) {
    static int t=0;t++;
    for (;;) {
        if (x) {
            x=getf(x);
            if (vis[x]==t) return x;
            vis[x]=t;
            if (match[x]) x=Next[match[x]];
            else x=0;
        }
        swap(x,y);
    }
}
inline void flower(int a,int p) {
    for (;a!=p;) {
        int b=match[a],c=Next[b];
        if (getf(c)!=p) Next[c]=b;
        if (mark[b]==2) q.push(b);mark[b]=1;
        if (mark[c]==2) q.push(c),mark[c]=1;
        unite(a,b); unite(b,c);
        a=c;
    }
}
inline void work(int S) {
    for (int i=1;i<=n;i++) Next[i]=mark[i]=vis[i]=0,bel[i]=i;
    while (!q.empty()) q.pop();
    mark[S]=1; q.push(S);
    while (!q.empty()) {
        if (match[S]) return ;
        int x=q.front(); q.pop();
        for (int i=g[x],y;i;i=e[i].Next) {
            y=e[i].to;
            if (match[x]==y) continue;
            if (getf(x)==getf(y)) continue;
            if (mark[y]==2) continue;
            if (mark[y]==1) {
                int r=lca(x,y);
                if (getf(x)!=r) Next[x]=y;
                if (getf(y)!=r) Next[y]=x;
                flower(x,r); flower(y,r);
            }
            else if (!match[y]) {
                Next[y]=x;
                for (int u=y,v,w;u;) {
                    v=Next[u];
                    w=match[v];
                    match[v]=u; match[u]=v; u=w;
                }
                break;
            }
            else {
                Next[y]=x;
                mark[match[y]]=1;
                q.push(match[y]);
                mark[y]=2;
            }
        }
    }
}
int a[N],b[N];
int main() {
    //freopen("b.in","r",stdin);
    int test;
    scanf("%d",&test);
    while (test--) {
        memset(match,0,sizeof(match));
        memset(g,0,sizeof(g));
        scanf("%d%d",&n,&m);
        int ans=-n;
        for (int i=1;i<=n;i++) a[i]=m+i,b[i]=m+n+i,adde(a[i],b[i]);
        for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) {
            char c=getchar();
            while (c!='0'&&c!='1') c=getchar();
            if (c=='1') adde(j,a[i]),adde(j,b[i]);
        }
        n=n*2+m;
        for (int i=1;i<=n;i++) if (!match[i]) work(i);
        for (int i=1;i<=n;i++) if (match[i]>i) ans++;
        printf("%d\n",ans);
    }

}