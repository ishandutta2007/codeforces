#include<stdio.h>
#define N 200005
#include<algorithm>
using namespace std;
int i,j,k,l,s,n,m,a[N],b[N];
unsigned int ans;
int main() {
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for (i=n;i;i--) {
        s+=a[i]; if (s>=m) break;
    }
    printf("%d\n",n-i+1);
}