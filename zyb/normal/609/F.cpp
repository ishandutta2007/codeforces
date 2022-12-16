#include<stdio.h>
#define N 1000000006
#define M 200005
#include<set>
#define inf 1000000002
using namespace std;
int i,j,x,y,k,l,s,n,m,gt,gtw,tot;
struct lhy {
    int x,y;
}yy;
struct syf {
    bool operator()(const lhy &a,const lhy &b) {
        if (a.x!=b.x)
        return a.x<b.x;
        return a.y<b.y;
    }
};
multiset<lhy,syf>A;
multiset<lhy,syf>::iterator B;
struct node {
    int x,s;
    long long y;
}a[M];
struct node1 {
    int ls,rs,x,y,dx,dy;
}f[M*100];
inline void up(int o) {
    int ls=f[o].ls,rs=f[o].rs;
    if (f[ls].x&&f[rs].x) {
        if (f[ls].x<f[rs].x) f[o].x=f[ls].x,f[o].y=f[ls].y;
        else f[o].x=f[rs].x,f[o].y=f[rs].y;
    }
    else if (f[ls].x) f[o].x=f[ls].x,f[o].y=f[ls].y;
    else if (f[rs].x) f[o].x=f[rs].x,f[o].y=f[rs].y;
    else f[o].x=f[o].y=inf;
}
inline void down(int o) {
    if (!f[o].ls) {
        f[o].ls=++tot;
        int ls=f[o].ls;
        f[ls].dx=f[ls].x=f[o].dx;
        f[ls].dy=f[ls].y=f[o].dy;
    }
    else {
        int ls=f[o].ls;
        if (f[o].dx<f[ls].x) f[ls].x=f[ls].dx=f[o].dx,f[ls].y=f[ls].dy=f[o].dy;
        if (f[ls].dx==-1||f[ls].dx>f[o].dx) f[ls].dx=f[o].dx,f[ls].dy=f[o].dy;
    }
    if (!f[o].rs) {
        f[o].rs=++tot;
        int rs=f[o].rs;
        f[rs].dx=f[rs].x=f[o].dx;
        f[rs].dy=f[rs].y=f[o].dy;
    }
    else {
        int rs=f[o].rs;
        if (f[o].dx<f[rs].x) f[rs].x=f[rs].dx=f[o].dx,f[rs].y=f[rs].dy=f[o].dy;
        if (f[rs].dx==-1||f[rs].dx>f[o].dx) f[rs].dx=f[o].dx,f[rs].dy=f[o].dy;
    }
    f[o].dx=f[o].dy=-1;
}
inline void change(int o,int l,int r,int ll,int rr,int p,int w) {
    if (l==ll&&r==rr) {
        if (f[o].x>p) {
            f[o].x=p,f[o].y=w;
        } 
        if (f[o].dx==-1) {
            f[o].dx=p; f[o].dy=w;
        }
        else if (p<f[o].dx) f[o].dx=p,f[o].dy=w;
        return ;

    }
    int mid=(l+r)>>1;
    if (f[o].dx!=-1)
    down(o);
    if (rr<=mid) {
        if (!f[o].ls) f[o].ls=++tot,f[tot].x=inf,f[tot].dx=f[tot].dy=-1;
        change(f[o].ls,l,mid,ll,rr,p,w);
    }
    else if (ll>mid) {
        if (!f[o].rs) f[o].rs=++tot,f[tot].x=inf,f[tot].dx=f[tot].dy=-1;
        change(f[o].rs,mid+1,r,ll,rr,p,w);
    }
    else {
        if (!f[o].ls) f[o].ls=++tot,f[tot].x=inf,f[tot].dx=f[tot].dy=-1;
        if (!f[o].rs) f[o].rs=++tot,f[tot].x=inf,f[tot].dx=f[tot].dy=-1;
        change(f[o].ls,l,mid,ll,mid,p,w);
        change(f[o].rs,mid+1,r,mid+1,rr,p,w);
    }
    up(o);
}
inline void ask(int o,int l,int r,int ll) {
    if (!o) return ;
    if (l==ll&&r==ll) {
        if (f[o].x<gt) gt=f[o].x,gtw=f[o].y;
        return ;
    }
    if (f[o].dx!=-1) down(o);
    int mid=(l+r)>>1;
    if (ll<=mid) ask(f[o].ls,l,mid,ll);
    else ask(f[o].rs,mid+1,r,ll);
    up(o);
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
    tot=1; f[1].x=inf;f[1].dx=f[1].dy=-1;
    for (i=1;i<=n;i++) {
        a[i].x=in()+1,a[i].y=in();
        change(1,1,N-5,a[i].x,min(1ll*N-5,a[i].x+a[i].y),a[i].x,i);
    }
    for (i=1;i<=m;i++) {
        x=in()+1,y=in();
        yy.x=x,yy.y=y;
        A.insert(yy);
        while (A.size()) {
            B=A.lower_bound(yy);
            if (B==A.end()) break;
            gt=inf*2; gtw=0; ask(1,1,N-5,(*B).x);
            if (gtw) {
                a[gtw].y+=(*B).y; a[gtw].s++;
                change(1,1,N-5,a[gtw].x,min(1ll*(N-5),a[gtw].x+a[gtw].y),a[gtw].x,gtw);
                A.erase(B);
            }
            else break;
        }
    }   
    for (i=1;i<=n;i++) printf("%d %I64d\n",a[i].s,a[i].y);
}