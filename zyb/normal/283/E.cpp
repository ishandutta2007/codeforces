#include<stdio.h>
#include<map>
#include<algorithm>
#define N 100005
using namespace std;
int i,j,tot,k,l,s,r,n,m,q[N*3],a[N],v[N*3];
map<int,int>ma;
long long ans;
struct node {
    int x,y;
}b[N],c[N];
struct node1 {
    int d,s[3];
}f[N*12];
inline bool cmp(node x,node y) {
    return x.x<y.x;
}
inline bool cmp1(node x,node y) {
    return x.y<y.y;
}
inline void up(int o) {
    f[o].s[1]=f[o*2].s[1]+f[o*2+1].s[1];
    f[o].s[2]=f[o*2].s[2]+f[o*2+1].s[2];
}
inline void build(int o,int l,int r) {
    if (l==r) {
        f[o].s[1]=v[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(o*2,l,mid); build(o*2+1,mid+1,r);
    //f[o].t=f[o*2].t+f[o*2+1].t;
    up(o);
}

inline void down(int o) {
    swap(f[o*2].s[1],f[o*2].s[2]);
    swap(f[o*2+1].s[1],f[o*2+1].s[2]);
    f[o*2].d^=1;
    f[o*2+1].d^=1;
    f[o].d=0;
}
inline int ask(int o,int l,int r,int ll,int rr,int p) {
    if (ll>rr) return 0;
    if (l==ll&&r==rr) return f[o].s[p];
    if (f[o].d) down(o);
    int mid=(l+r)>>1;
    int gt=0;
    if (rr<=mid) gt=ask(o*2,l,mid,ll,rr,p);
    else if (ll>mid) gt=ask(o*2+1,mid+1,r,ll,rr,p);
    else gt=ask(o*2,l,mid,ll,mid,p)+ask(o*2+1,mid+1,r,mid+1,rr,p);
    up(o); return gt;
}
inline void change(int o,int l,int r,int ll,int rr) {
    if (l==ll&&r==rr) {
        //f[o].s=f[o].t-f[o].s;
        swap(f[o].s[1],f[o].s[2]);
        f[o].d^=1;
        return ;
    }
    if (f[o].d) down(o);
    int mid=(l+r)>>1;
    if (rr<=mid) change(o*2,l,mid,ll,rr);
    else if (ll>mid) change(o*2+1,mid+1,r,ll,rr);
    else {
        change(o*2,l,mid,ll,mid);
        change(o*2+1,mid+1,r,mid+1,rr);
    }
    up(o);
}
inline long long C(int o,int p) {
    long long s=1;
    for (int i=1;i<=p;i++) s=s*(o-i+1);
    long long s1=1;
    for (int i=1;i<=p;i++) s1*=i;
    return s/s1;
}
int main() {
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++) scanf("%d",&a[i]),q[++r]=a[i];
    sort(a+1,a+1+n);
    for (i=1;i<=m;i++) scanf("%d%d",&b[i].x,&b[i].y),q[++r]=b[i].x,q[++r]=b[i].y;
    sort(q+1,q+1+r);
    for (i=1;i<=r;i++) if (!ma[q[i]]) ma[q[i]]=++tot;
    for (i=1;i<=m;i++) b[i].x=ma[b[i].x],b[i].y=ma[b[i].y],c[i]=b[i];
    for (i=1;i<=n;i++) a[i]=ma[a[i]],v[a[i]]=1;
    sort(b+1,b+1+m,cmp);
    sort(c+1,c+1+m,cmp1);
    build(1,1,tot);
    j=1; k=1;
    ans=C(n,3);
    for (i=1;i<=n;i++) {
        while (b[j].x<=a[i]&&j<=m) change(1,1,tot,b[j].x,b[j].y),j++;
        while (c[k].y<a[i]&&k<=m) change(1,1,tot,c[k].x,c[k].y),k++;
        ans-=C(ask(1,1,tot,1,a[i]-1,1)+ask(1,1,tot,a[i]+1,tot,2),2);
        
    }
    printf("%I64d\n",ans);
}