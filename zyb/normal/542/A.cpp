#include<stdio.h>
#include<algorithm>
#define inf 100000000
#define N 800005
#include<map>
using namespace std;
struct node1 {
    long long id,x,y,z;
}a[N],b[N];
long long ans1,ans2,i,j,k,l,c[N],s,n,m,ans,tot,r,q[N];
map<long long,long long>ma;
struct node {
    long long f[N*4],ans,ans1,F[N*4];
    inline void build(long long o,long long l,long long r,long long p) {
        f[o]=p;
        if (l==r) return ;
        long long mid=(l+r)>>1;
        build(o*2,l,mid,p),build(o*2+1,mid+1,r,p);
    }
    inline void add(long long o,long long l,long long r,long long ll,long long p,long long w,long long u) {
        if (w) {
            if (p>f[o]) f[o]=p,F[o]=u;
        }
        else {
            if (p<f[o]) f[o]=p,F[o]=u;
        }
        if (l==ll&&r==ll) return ;
        long long mid=(l+r)>>1;
        if (ll<=mid) add(o*2,l,mid,ll,p,w,u);
        else add(o*2+1,mid+1,r,ll,p,w,u);
    }
    inline void ask(long long o,long long l,long long r,long long ll,long long rr,long long p) {
        if (l==ll&&r==rr) {
            if (p) {
                if (f[o]>ans) ans=f[o],ans1=F[o];
            }
            else {
                if (f[o]<ans) ans=f[o],ans1=F[o];
            }
            return ;
        }
        long long mid=(l+r)>>1;
        if (rr<=mid) ask(o*2,l,mid,ll,rr,p);
        else if (ll>mid) ask(o*2+1,mid+1,r,ll,rr,p);
        else {
            ask(o*2,l,mid,ll,mid,p),ask(o*2+1,mid+1,r,mid+1,rr,p);
        }
    }
}A,B;
inline bool cmp(const node1 &x,const node1 &y) {
    return x.x>y.x;
}
int main() {
    scanf("%I64d%I64d",&n,&m);
    for (i=1;i<=n;i++) scanf("%I64d%I64d",&a[a[i].id=i].x,&a[i].y),a[i].x++,a[i].y++,q[++r]=a[i].x,q[++r]=a[i].y;
    for (i=1;i<=m;i++) scanf("%I64d%I64d%I64d",&b[b[i].id=i].x,&b[i].y,&b[i].z),b[i].x++,b[i].y++,q[++r]=b[i].x,q[++r]=b[i].y;
    sort(q+1,q+1+r);
    q[0]=q[1]-1;
    for (i=1;i<=r;i++) if (q[i]!=q[i-1]) ma[q[i]]=++tot,c[tot]=q[i];
    for (i=1;i<=n;i++) a[i].x=ma[a[i].x],a[i].y=ma[a[i].y];
    for (i=1;i<=m;i++) b[i].x=ma[b[i].x],b[i].y=ma[b[i].y];
    B.build(1,1,tot,inf);
    for (i=1;i<=n;i++) A.add(1,1,tot,a[i].x,a[i].y,1,i),B.add(1,1,tot,a[i].y,a[i].x,0,i);
    for (i=1;i<=m;i++) {
        A.ans=0;
        A.ask(1,1,tot,1,b[i].x,1);
        long long gt=A.ans;
        if (gt>b[i].y) gt=b[i].y;
        B.ans=inf;
        if ((c[gt]-c[b[i].x])*b[i].z>ans)
        ans=(c[gt]-c[b[i].x])*b[i].z,ans1=A.ans1,ans2=b[i].id;
        B.ask(1,1,tot,b[i].y,tot,0);
        gt=B.ans;
        if (gt<b[i].x) gt=b[i].x;
        if (gt==inf) continue;
        if ((c[b[i].y]-c[gt])*b[i].z>ans)
        ans=(c[b[i].y]-c[gt])*b[i].z,ans1=B.ans1,ans2=b[i].id;
    }
    A.build(1,1,tot,0);
    sort(a+1,a+1+n,cmp); sort(b+1,b+1+m,cmp);
    j=1;
    for (i=1;i<=m;i++) {
        while (a[j].x>=b[i].x&&j<=n) {
            A.add(1,1,tot,a[j].y,c[a[j].y]-c[a[j].x],1,a[j].id); j++;
        }
        A.ans=0;
        A.ask(1,1,tot,b[i].x,b[i].y,1);
        if (ans<A.ans*b[i].z) ans=A.ans*b[i].z,ans1=A.ans1,ans2=b[i].id;
    }
    printf("%I64d\n",ans);
    if (ans) printf("%I64d %I64d\n",ans1,ans2);
}