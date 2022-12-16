#include<stdio.h>
#include<algorithm>
#define N 200005
#define M 400005
using namespace std;
int i,j,k,l,s,n,m,tot,next[M],last[N],to[M],val[M],v[N];
int si[N],fa[N],q[N],t[N*4],dis[N],f[N],st[N];
long long ans,A[N];
struct node {
    int id,x,y,z,b;
}a[N];
inline bool cmp(const node &x,const node &y) {
    return x.z<y.z;
}
inline int get(int o) {
    if (fa[o]==o) return o;
    return fa[o]=get(fa[o]);
}
inline void add(int o,int p,int w) {
    next[++tot]=last[o]; last[o]=tot; to[tot]=p; val[tot]=w;
}
inline void build() {
    int l=0,r=1; dis[q[1]=1]=1;
    while (l<r) {
        int k=q[++l];
        for (int i=last[k];i;i=next[i]) {
            int gt=to[i];
            if (fa[k]==gt) continue;
            fa[q[++r]=gt]=k; v[gt]=val[i];
            dis[gt]=dis[k]+1;
        }
    }
    for (int i=r;i;i--) si[q[i]]++,si[fa[q[i]]]+=si[q[i]];
}
inline void dfs(int o,int p) {
    if (!p) p=o;
    f[o]=p; st[o]=++tot;
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
inline void change(int o,int l,int r,int ll,int p) {
    t[o]=max(t[o],p);
    if (l==ll&&r==ll) return ;
    int mid=(l+r)>>1;
    if (ll<=mid) change(o*2,l,mid,ll,p);
    else change(o*2+1,mid+1,r,ll,p);
}
inline int ask(int o,int l,int r,int ll,int rr) {
    if (l==ll&&r==rr) return t[o];
    int mid=(l+r)>>1;
    if (rr<=mid) return ask(o*2,l,mid,ll,rr);
    else if (ll>mid) return ask(o*2+1,mid+1,r,ll,rr);
    else return max(ask(o*2,l,mid,ll,mid),ask(o*2+1,mid+1,r,mid+1,rr));
}
inline int Get(int o) {
    s=max(s,ask(1,1,tot,st[f[o]],st[o]));
    return fa[f[o]];
}
inline int ask(int x,int y) {
    s=0;
    while (f[x]!=f[y]) {
        if (dis[f[x]]>dis[f[y]]) x=Get(x);
        else y=Get(y);
    }
    if (dis[x]>dis[y]) s=max(s,ask(1,1,tot,st[y]+1,st[x]));
    else if (dis[y]>dis[x]) s=max(s,ask(1,1,tot,st[x]+1,st[y]));
    return s;
}
inline int in() {
    char c=getchar();
    int s=0;
    while (c<'0'||c>'9') c=getchar();
    while (c>='0'&&c<='9') s=s*10+c-48,c=getchar();
    return s;
}
int main() {
    n=in(),m=in();
    for (i=1;i<=m;i++) a[i].x=in(),a[i].y=in(),a[a[i].id=i].z=in();
    sort(a+1,a+1+m,cmp);
    for (i=1;i<=n;i++) fa[i]=i;
    for (i=1;i<=m;i++) if (get(a[i].x)!=get(a[i].y)) fa[get(a[i].x)]=get(a[i].y),ans+=a[i].z,add(a[i].x,a[i].y,a[i].z),add(a[i].y,a[i].x,a[i].z),a[i].b=1;  for (i=1;i<=n;i++) fa[i]=0;
    build(); dfs(1,tot=0);
    for (i=1;i<=n;i++) change(1,1,tot,st[i],v[i]);
    for (i=1;i<=m;i++) if (a[i].b) A[a[i].id]=ans;
    else A[a[i].id]=ans-ask(a[i].x,a[i].y)+a[i].z;
    for (i=1;i<=m;i++) printf("%I64d\n",A[i]);
}