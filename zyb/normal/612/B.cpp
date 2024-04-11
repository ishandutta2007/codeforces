#include<stdio.h>
#include<algorithm>
using namespace std;
int n,p,q,gt,a[200005],x;
long long ans;
int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&x),a[x]=i;
    for (int i=2;i<=n;i++) ans+=abs(a[i]-a[i-1]);
    printf("%I64d\n",ans);
}