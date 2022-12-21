#include<stdio.h>
#include<algorithm>
#define lowbit(o) o&-o
#define N 200005
using namespace std;
int i,j,k,l,s,m,n,f[N],fa[N];
struct node {
    int id,v;
}a[N];
inline bool cmp(node x,node y) {
    return x.v>y.v;
}
inline int get(int o) {
    if (fa[o]==o) return o;
    return fa[o]=get(fa[o]);
}
inline void change(int o,int p) {
    for (;o;o-=lowbit(o)) f[o]=max(f[o],p);
}
inline int ask(int o) {
    int s=0;
    for (;o<=n;o+=lowbit(o)) s=max(s,f[o]);
    return s;
}
int main() {
    scanf("%d",&n);
    for (i=1;i<=n;i++) scanf("%d",&a[a[i].id=i].v);
    sort(a+1,a+1+n,cmp);
    for (i=1;i<=n+1;i++) fa[i]=i;
    for (i=1;i<=n;i++) {
        int gt=a[i].id;
        int l=1,r=gt,s=0;
        while (l<=r) {
            int mid=(l+r)>>1;
            if (get(mid)==gt) s=mid,r=mid-1;
            else l=mid+1;
        }
        int ss=gt-s+1;
        fa[gt]=get(gt+1);
        int pp=get(gt);
        ss=ss+pp-gt-1;
        change(ss,a[i].v);
    }
    for (int i=1;i<=n;i++) printf("%d ",ask(i));
}