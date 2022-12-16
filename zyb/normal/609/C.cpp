#include<stdio.h>
#define N 200005
#include<algorithm>
using namespace std;
int i,j,k,l,s,n,m,ans,bb,a[N],b[N];
int main() {
    scanf("%d",&n);
    for (i=1;i<=n;i++) scanf("%d",&a[i]),s+=a[i];
    if (s%n) bb=s%n;
    s/=n;
    for (i=1;i<=n;i++) {
        if (bb) {
            if (a[i]>s) bb--,b[i]=s+1;
            else b[i]=s;
        }
        else b[i]=s;
    }
    int j=1;
    while (bb) {
        if (b[j]==s) b[j]++,bb--;
        j++;
    }
    for (i=1;i<=n;i++) ans+=abs(b[i]-a[i]);
    printf("%d\n",ans/2);
}