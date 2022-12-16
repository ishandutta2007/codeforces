#include<stdio.h>
#include<algorithm>
#define P 1000000007
#define N 100005
#define M 200005
using namespace std;
int i,j,k,l,s,n,m,x[N],y[N],z[N],tot,last[N],to[M],val[M],v[N],next[M],q[N],dis[N],si[N];
int b[N],st[N],F[N],f[N],fa[N],ans,T[N],a[N*10],FF[N*10],id[M];
inline void add(int o,int p,int w) {
    next[++tot]=last[o]; last[o]=tot; to[tot]=p; val[tot]=w,id[tot]=i;
}
inline int in() {
    char c=getchar();
    int s=0;
    while (c<'0') c=getchar();
    while (c>='0') s=s*10+c-48,c=getchar();
    return s;
}
inline void build(int o) {
    int l=0,r=1; dis[q[1]=o]=1;
    while (l<r) {
        int k=q[++l]; si[k]=0;
        for (int i=last[k];i;i=next[i]) {
            if (fa[k]==to[i]) continue;
            fa[q[++r]=to[i]]=k; dis[to[i]]=dis[k]+1;
            v[to[i]]=val[i]; T[to[i]]=id[i];
        }
    }
    for (int i=r;i;i--) si[q[i]]++,si[fa[q[i]]]+=si[q[i]];
}
inline void dfs(int o,int p) {
    if (!p) p=o;
    f[o]=p; st[o]=++tot; b[tot]=o;
    int gt=0,gtw=0;
    for (int i=last[o];i;i=next[i]) {
        if (to[i]==fa[o]) continue;
        if (si[to[i]]>gt) gt=si[to[i]],gtw=to[i];
    }
    if (gtw) dfs(gtw,p);
    for (int i=last[o];i;i=next[i]) {
        if (to[i]==fa[o]||to[i]==gtw) continue;
        dfs(to[i],0);
    }
}
inline int get(int o) {
    F[st[f[o]]]++; F[st[o]+1]--;
    return fa[f[o]];
}
inline void work(int x,int y) {
    while (f[x]!=f[y]) {
        if (dis[f[x]]>dis[f[y]]) x=get(x);
        else y=get(y);
    }
    if (dis[x]>dis[y]) F[st[y]+1]++,F[st[x]+1]--;
    else if (dis[y]>dis[x]) F[st[x]+1]++,F[st[y]+1]--;
}
inline int quick(int o,int p) {
    int s=1;
    while (p) {
        if (p&1) s=1ll*s*o%P;
        o=1ll*o*o%P;
        p>>=1;
    }
    return s;
}
int main() {
    n=in();
    for (i=1;i<n;i++) x[i]=in(),y[i]=in(),z[i]=in(),add(x[i],y[i],z[i]),add(y[i],x[i],z[i]);
    build(1); tot=0;
    dfs(1,0); m=in();
    for (i=1;i<=m;i++) a[i]=in(); a[0]=1;
    for (i=1;i<=m;i++) work(a[i],a[i-1]);
    for (i=1;i<=n;i++) {
        s+=F[i];
        if (v[b[i]]) {
            int pp=s/2;
            if (s%2) {
                if (dis[x[T[b[i]]]]>dis[y[T[b[i]]]]) pp++;
                //pp++;
            }
            if (!FF[pp]) FF[pp]=quick(2,pp);
            (ans+=FF[pp]-1)%=P;
        }
    }
    printf("%d\n",ans);
}