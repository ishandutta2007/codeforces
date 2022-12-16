#include<stdio.h>
#include<algorithm>
#define N 100005
#define eps 0.5
using namespace std;
int x,ansx,ansx1,ansy,ansy1,bb,i,j,k,l,s,n,m,tot,TOT,T,st[N*4],c[10],q[4000005],r;
int X[N],Y[N];
struct node {
    int x,y;
}a[N],b[N];
struct node1 {
    int v,ls,rs;
}t[N*200];
inline bool cmp(node x,node y) {
    return x.x<y.x;
}
inline bool cmp1(node x,node y) {
    return x.y<y.y;
}
inline int getx(int o) {
    return a[o].x;
}
inline int gety(int o) {
    return b[o].y;
}
inline int Ask(int o,int l,int r,int ll,int rr) {
    if (!o) return 0;
    if (ll>rr) return 0;
    if (l==ll&&r==rr) return t[o].v;
    int mid=(l+r)>>1;
    if (rr<=mid) return Ask(t[o].ls,l,mid,ll,rr);
    else if (ll>mid) return Ask(t[o].rs,mid+1,r,ll,rr);
    else {
        int gt=Ask(t[o].ls,l,mid,ll,mid);
        gt+=Ask(t[o].rs,mid+1,r,mid+1,rr);
        return gt;
    }
}       
inline int ask(int o,int l,int r,int ll,int rr,int L,int R) {
    if (ll>rr) return 0;
    if (l==ll&&r==rr) return Ask(st[o],1,TOT,L,R);
    int mid=(l+r)>>1;
    if (rr<=mid) return ask(o*2,l,mid,ll,rr,L,R);
    else if (ll>mid) return ask(o*2+1,mid+1,r,ll,rr,L,R);
    else {
        int gt=ask(o*2,l,mid,ll,mid,L,R);
        gt+=ask(o*2+1,mid+1,r,mid+1,rr,L,R);
        return gt;
    }
}
inline bool check(int x,int x1,int y,int y1) {
    if (ask(1,1,tot,1,x,1,y)!=c[1]) return false;
    if (ask(1,1,tot,1,x,y+1,y1)!=c[2]) return false;
    if (ask(1,1,tot,1,x,y1+1,TOT)!=c[3]) return false;
    if (ask(1,1,tot,x+1,x1,1,y)!=c[4]) return false;
    if (ask(1,1,tot,x+1,x1,y+1,y1)!=c[5]) return false;
    if (ask(1,1,tot,x+1,x1,y1+1,TOT)!=c[6]) return false;
    if (ask(1,1,tot,x1+1,tot,1,y)!=c[7]) return false;
    if (ask(1,1,tot,x1+1,tot,y+1,y1)!=c[8]) return false;
    if (ask(1,1,tot,x1+1,tot,y1+1,TOT)!=c[9]) return false;
    return true;
}
inline void work(int o) {
    if (o>9) {
        int x=getx(c[1]+c[2]+c[3]),x1=getx(c[1]+c[2]+c[3]+c[4]+c[5]+c[6]);
        int y=gety(c[1]+c[4]+c[7]),y1=gety(c[1]+c[4]+c[7]+c[2]+c[5]+c[8]);
        if (check(x,x1,y,y1)) {
            ansx=x; ansy=y;
            ansx1=x1; ansy1=y1; bb=1;
        }
        return ;
    }
    if (bb) return ;
    for (int i=o;i<=9;i++) {
        c[o]=q[++l];
        work(o+1);
        q[++r]=c[o];
    }
}
inline void ls() {
    sort(a+1,a+1+n,cmp);
    int last=a[1].x; tot=1; X[tot]=a[1].x;
    for (i=1;i<=n;i++) {
        if (a[i].x!=last) tot++,X[tot]=a[i].x;
        last=a[i].x; a[i].x=tot;
    }
    sort(a+1,a+1+n,cmp1);
    last=a[1].y; TOT=1; Y[TOT]=a[1].y;
    for (i=1;i<=n;i++) {
        if (a[i].y!=last) TOT++,Y[TOT]=a[i].y;
        last=a[i].y; a[i].y=TOT;
    }
}
inline void build(int o,int l,int r) {
    st[o]=++T;
    if (l==r) return ;
    int mid=(l+r)>>1;
    build(o*2,l,mid); build(o*2+1,mid+1,r);
}
inline void Insert(int o,int l,int r,int ll) {
    t[o].v++;
    if (l==ll&&r==ll) return ;
    int mid=(l+r)>>1;
    if (ll<=mid) {
        if (!t[o].ls) t[o].ls=++T;
        Insert(t[o].ls,l,mid,ll);
    }
    else {
        if (!t[o].rs) t[o].rs=++T;
        Insert(t[o].rs,mid+1,r,ll);
    }
}
inline void insert(int o,int l,int r,int ll,int xx) {
    Insert(st[o],1,TOT,xx);
    if (l==ll&&r==ll) return ;
    int mid=(l+r)>>1;
    if (ll<=mid) insert(o*2,l,mid,ll,xx);
    else insert(o*2+1,mid+1,r,ll,xx);
}
int main() {
    scanf("%d",&n);
    for (i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
    ls();
    for (i=1;i<=n;i++) b[i]=a[i];
    build(1,1,tot);
    sort(a+1,a+1+n,cmp);
    sort(b+1,b+1+n,cmp1);
    for (i=1;i<=n;i++) insert(1,1,tot,a[i].x,a[i].y);
    for (i=1;i<=9;i++) scanf("%d",&x),q[++r]=x;
    work(1);
    if (bb) printf("%.5lf %.5lf\n%.5lf %.5lf\n",X[ansx]+eps,X[ansx1]+eps,Y[ansy]+eps,Y[ansy1]+eps);
    else printf("-1\n");
}