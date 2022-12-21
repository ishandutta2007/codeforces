//By BLADEVIL
#include <cstdio>
#include <algorithm>
#define maxn 5010

using namespace std;

int n,m;
int a[maxn],b[maxn],g[maxn];

int calc(int x) {
    int ans(0);
    for (int i=1;i<=m;i++) while (!(x%b[i])) ans--,x/=b[i];
    for (int i=2;i*i<=x;i++) while (!(x%i)) ans++,x/=i;
    if (x>1) ans++;
    return ans;
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]),g[i]=__gcd(g[i-1],a[i]);
    for (int i=1;i<=m;i++) scanf("%d",&b[i]);
    int cur(1);
    for (int i=n;i;i--) {
        a[i]/=cur; g[i]/=cur;
        if (calc(g[i])<0) cur*=g[i],a[i]/=g[i];
    }
    //for (int i=1;i<=n;i++) printf("%d ",a[i]); printf("\n");
    int ans(0);
    for (int i=1;i<=n;i++) ans+=calc(a[i]);
    printf("%d\n",ans);
    return 0;
}