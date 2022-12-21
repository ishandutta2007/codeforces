#include<stdio.h>
#include<algorithm>
#define N 100005
using namespace std;
struct node {
    int x,y,z,id;
    double v;
}t[N],b[N],c[N],d[N];
long long a[N],ma[N];
int i,j,k,l,s,n,m,tot,r,T[N],st[N];
inline bool cmp(const node &x,const node &y) {
    if (x.y==y.y) return x.z>y.z;
    return x.y<y.y;
}
inline bool cmp1(const node &x,const node &y) {
    return x.x<y.x;
}
inline void up(int o) {
    while (o>1) {
        int j=o>>1;
        if (t[j].v<t[o].v) swap(t[j],t[o]);
        else return ;
        o=j;
    }
}
inline void add(int o) {
    t[++r]=c[o];
    if (c[o].y<=n) t[r].v=1+c[o].z/(a[c[o].y]*1.);
    else t[r].v=c[o].z;
    up(r);
}
inline void down(int o) {
    while (o<=r) {
        int j=o*2;
        if (j>r) return ;
        if (j+1<=r&&t[j+1].v>t[j].v) j++;
        if (t[j].v>t[o].v) swap(t[j],t[o]);
        else return ;
        o=j;
    }
}
inline void del() {
    t[1]=t[r--];
    down(1);
}
int main() {
    scanf("%d%d%d",&n,&k,&m);
    for (i=1;i<=n;i++) scanf("%I64d",&a[i]),ma[i]=a[i];
    for (i=1;i<=k;i++) {
        scanf("%d%d%d",&b[b[i].id=i].x,&b[i].y,&b[i].z);
        if (b[i].x==1) {
            if (b[i].z>ma[b[i].y]) ma[b[i].y]=b[i].z,T[b[i].y]=i;
        }
        else if (b[i].x==2) c[++tot]=b[i];
        else c[++tot]=b[i],c[tot].y=n+1;
    }
    for (i=1;i<=n;i++) if (T[i]) c[++tot]=b[T[i]],c[tot].z-=a[i];
    sort(c+1,c+1+tot,cmp);
    for (i=1;i<=tot;i++) 
    if (c[i].y!=c[i-1].y||c[i].y==n+1) add(i),st[c[i].y]=i+1;
    if (tot<=m) {
        sort(c+1,c+1+tot,cmp1);
        printf("%d\n",tot);
        for (i=1;i<=tot;i++) printf("%d ",c[i].id);
        return 0;
    }
    for (i=1;i<=m;i++) {
        node gt;
        gt=d[i]=t[1];
        del();
        if (gt.y==n+1) continue;
        if (c[st[gt.y]].y!=gt.y) continue;
        a[gt.y]+=gt.z;
        add(st[gt.y]); st[gt.y]++;
    }
    sort(d+1,d+1+m,cmp1);
    printf("%d\n",m);
    for (i=1;i<=m;i++) printf("%d ",d[i].id);
}