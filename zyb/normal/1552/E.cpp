#include<bits/stdc++.h>
#define N 10005
using namespace std;
#define P 998244353
int n,A[105],a[N],b[N],x[N],y[N],k,vis[N];
int main() {
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n*k;i++) scanf("%d",&a[i]);
    int s=0;
    for (int i=1;i<=n*k;i++) {
        if (vis[a[i]]) continue;
        if (!A[a[i]]) A[a[i]]=i;
        else {
            x[a[i]]=A[a[i]];
            y[a[i]]=i;
            vis[a[i]]=1;
            s++;
        }
        if (s>=(n/(k-1) + ((n%(k-1))>0))) {
            s=0;
            memset(A,0,sizeof(A));
        }
    }
    for (int i=1;i<=n;i++) {
        assert(x[i]);
        assert(y[i]);
        printf("%d %d\n",x[i],y[i]);
    }
}