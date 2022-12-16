#include<stdio.h>
#define N 200005
#include<algorithm>
using namespace std;
int i,j,k,l,s,n,m,a[N],b[N];
unsigned int ans;
int main() {
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++) scanf("%d",&a[i]),b[a[i]]++;
    for (i=1;i<=n;i++) 
    ans+=n-b[a[i]];
    ans/=2;
    printf("%d\n",ans);
}