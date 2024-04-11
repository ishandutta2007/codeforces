#include<stdio.h>
#include<algorithm>
#define N 100005
#define M 200005
#define lowbit(o) o&-o
#include<cstring>
using namespace std;
long long i,j,k,l,s,n,m,tot,f[N],val[M],to[M],next[M],last[N],si[N],Q[N],q[N],ma[N];
long long T[N],V[N],L,ans,r,R,b[M],fa[N],x,y,z,D,W;
struct node {
    long long v,x,w;
}G[N];
inline bool cmp(node x,node y) {
    return x.v<y.v;
}
inline void add(long long o,long long p,long long w) {
    next[++tot]=last[o]; last[o]=tot; to[tot]=p; val[tot]=z;
}
inline void dfs(long long o,long long p,long long w) {
    if (p>D) return ; if (w>W) return ;
    G[++R].x=o;
    G[R].v=w; G[R].w=p;
    for (long long i=last[o];i;i=next[i]) {
        if (b[i]||to[i]==fa[o]) continue;
        dfs(to[i],p+1,w+val[i]);
    }
}
inline long long build(long long o) {
    long long l=0,r=1; Q[1]=o; fa[o]=0;
    while (l<r) {
        long long k=Q[++l]; si[k]=ma[k]=0;
        for (long long i=last[k];i;i=next[i]) {
            if (b[i]||fa[k]==to[i]) continue;
            fa[Q[++r]=to[i]]=k;
        }
    }
    long long gt=r,gyz=0;
    for (i=r;i;i--) {
        si[Q[i]]++;
        si[fa[Q[i]]]+=si[Q[i]]; ma[fa[Q[i]]]=max(ma[fa[Q[i]]],si[Q[i]]);
        long long gtw=max(r-si[Q[i]],ma[Q[i]]);
        if (gtw<gt) gt=gtw,gyz=Q[i];
    }
    return gyz;
}
inline void add(long long o,long long p) {
//  o++;
    for (;o;o-=lowbit(o)) f[o]+=p;
}
inline long long ask(long long o) {
    long long s=0;
//    o++;
    for (;o<=D;o+=lowbit(o)) s+=f[o];
    return s;
}
inline long long work(long long o) {
    long long s=0; L=R;
    for (long long i=1;i<=R;i++) add(D-G[i].w,1),T[i]=0;
    for (long long i=1;i<=L;i++) {
        while (G[R].v+G[i].v>W) {
            if (!T[R])
            add(D-G[R].w,-1);
            T[R]=1,R--;
        }
        if (R>i) {
            if (!T[i])
            add(D-G[i].w,-1); T[i]=1;
            s+=ask(G[i].w);
            
        }
    }
    for (long long i=1;i<=L;i++) if (!T[i]) add(D-G[i].w,-1);
    return s;
}       
inline void getans(long long o) {
    long long ll=0,rr=0;
    R=0;
    for (long long i=last[o];i;i=next[i]) {
        if (b[i]) continue;
        long long gt=to[i];
        q[++r]=gt; b[i]=b[i^1]=1;
        Q[++rr]=gt; V[gt]=val[i];
        dfs(gt,1,val[i]);
    }
    sort(G+1,G+1+R,cmp);
    ans+=R;
    ans+=work(R);
    for (long long i=1;i<=rr;i++) {
        R=0;
        long long gt=Q[i];
        dfs(gt,1,V[gt]);
        sort(G+1,G+1+R,cmp);
        ans-=work(R);
    }
}
int main() {
    scanf("%I64d%I64d%I64d",&n,&D,&W);
    tot=1;
    for (i=1;i<n;i++) scanf("%I64d%I64d",&x,&z),add(x,i+1,z),add(i+1,x,z);
    l=0,r=1; q[1]=1;
    while (l<r) {
        long long k=q[++l];
        long long gt=build(k);
        build(gt);
        getans(gt);
    }
    printf("%I64d\n",ans);
}