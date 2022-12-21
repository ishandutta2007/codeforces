#include<stdio.h>
#include<algorithm>
using namespace std;
int i,j,k,l,s,m,n,f[200005],a[200005],v[200005],x,ans;
int main() {
    scanf("%d",&n); int p;
    for (i=1;i<=n;i++) scanf("%d",&a[i]);
    for (i=1;i<=n;i++) scanf("%d",&x),v[x]=i;
    for (i=1;i<=n;i++) if (v[a[i]]<v[a[i-1]]) break;
    printf("%d\n",n-i+1);
}