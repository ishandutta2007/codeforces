#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;
int i,j,k,l,s,n,m,tot,ans;
struct node {
    int x,y,v;
}q[5000005],a[5000005],da[5000005];
map<long long ,int>ma;
inline bool cmp(node x,node y) {
    if (x.x==y.x) return x.y<y.y;
    else return x.x<y.x;
}
inline bool work(int x,int y) {
    int i=1,j=n;
    int jsb=0;
    while (i<=j) {
        if (a[i].x+a[j].x==x&&a[i].y+a[j].y==y) {
            jsb+=(1+1-(i==j));
            i++; j--;
        }
        else if (a[i].x+a[j].x<x) i++;
        else if (a[i].x+a[j].x==x&&a[i].y+a[j].y<y) i++;
        else j--;
    }
    if (jsb>=(n-k)) return 1;
    return 0;
}
int main() {
    scanf("%d%d",&n,&k);
    if (n==k) return puts("-1"),0;
    for (i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+1+n,cmp);
    ans=0;
    for (i=1;i<=k+1;i++)
    for (j=n-k;j<=n;j++) {
        if (j<i) continue;
        if (ma[(a[i].x+a[j].x)*1000000000ll+(a[i].y+a[j].y)]) continue;
        if (work(a[i].x+a[j].x,a[i].y+a[j].y))
        da[++ans].x=a[i].x+a[j].x,da[ans].y=a[i].y+a[j].y;
        ma[(a[i].x+a[j].x)*1000000000ll+(a[i].y+a[j].y)]=1;
    }
    printf("%d\n",ans);
    sort(da+1,da+1+ans,cmp);
    for (int i=1;i<=ans;i++) printf("%.6lf %.6lf\n",da[i].x/2.0,da[i].y/2.0);
}