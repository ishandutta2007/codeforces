#include<stdio.h>
#include<map>
#include<algorithm>
#define N 1000005
using namespace std;
map<int,int>ma;
int q[N*2],i,F[N*2],st[N],en[N],ans,bb,j,k,l,s,n,m,r,a[N],b[N],f[N*2],c[N*2],tot;
int main() {
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]),q[++r]=a[i],q[++r]=b[i];
    sort(q+1,q+1+r);
    q[0]=q[1]-1;
    for (i=1;i<=r;i++) if (q[i]!=q[i-1]) ma[q[i]]=++tot,c[tot]=q[i];
    for (i=1;i<=n;i++) f[ma[a[i]]]++,F[ma[b[i]]]++;
    for (i=1;i<=tot;i++) {
        s+=f[i];
        if (s>=m) {
            if (!bb) bb=1,st[++ans]=c[i];
        }
        s-=F[i];
        if (s<m) {
            if (bb) bb=0,en[ans]=c[i];
        }
    }
//  if (bb) en[ans]=c[tot];
    printf("%d\n",ans);
    for (i=1;i<=ans;i++) printf("%d %d\n",st[i],en[i]);
}