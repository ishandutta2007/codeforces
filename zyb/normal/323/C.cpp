#include<stdio.h>
#include<algorithm>
#define N 1000005
using namespace std;
struct node {
    int v,ls,rs;
}f[N*35];
int a[N],b[N],x,y,xx,yy,lastans,i,j,k,l,s,n,m,tot,st[N];
inline void up(int o) {
    f[o].v=f[f[o].ls].v+f[f[o].rs].v;
}
inline void build(int o,int l,int r) {
    if (l==r) return ;
    f[o].ls=++tot; f[o].rs=++tot;
    int mid=(l+r)>>1;
    build(f[o].ls,l,mid); build(f[o].rs,mid+1,r);
}
inline void change(int o,int p,int l,int r,int ll) {
    if (l==ll&&r==ll) {
        f[o].v++;
        return ;
    }
    int mid=(l+r)>>1;
    if (ll<=mid) {
        f[o].rs=f[p].rs;
        f[o].ls=++tot;
        change(f[o].ls,f[p].ls,l,mid,ll);
    }
    else {
        f[o].ls=f[p].ls;
        f[o].rs=++tot;
        change(f[o].rs,f[p].rs,mid+1,r,ll);
    }
    up(o);
}
inline int ask(int o,int p,int l,int r,int ll,int rr) {
    if (l==ll&&r==rr) return f[o].v-f[p].v;
    int mid=(l+r)>>1;
    if (rr<=mid) return ask(f[o].ls,f[p].ls,l,mid,ll,rr);
    else if (ll>mid) return ask(f[o].rs,f[p].rs,mid+1,r,ll,rr);
    else return ask(f[o].ls,f[p].ls,l,mid,ll,mid)+ask(f[o].rs,f[p].rs,mid+1,r,mid+1,rr);
}
int main() {
    scanf("%d",&n);
    for (i=1;i<=n;i++) scanf("%d",&x),a[x]=i;
    for (i=1;i<=n;i++) scanf("%d",&b[i]);
    st[0]=tot=1;
    build(1,1,n);
    for (i=1;i<=n;i++) st[i]=++tot,change(st[i],st[i-1],1,n,a[b[i]]);
    scanf("%d",&m);
    lastans=-1;
    for (i=1;i<=m;i++) {
        scanf("%d%d%d%d",&x,&y,&xx,&yy);
        lastans++;
        x=(x-1+lastans)%n+1;
        y=(y-1+lastans)%n+1;
        xx=(xx-1+lastans)%n+1;
        yy=(yy-1+lastans)%n+1;  
        if (x>y) swap(x,y);
        if (xx>yy) swap(xx,yy);
        printf("%d\n",lastans=ask(st[yy],st[xx-1],1,n,x,y));
    }
}