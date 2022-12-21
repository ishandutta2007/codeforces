#include<bits/stdc++.h>
#define N 300005
using namespace std;
#define pb push_back
#define lowbit(x) x&-x
int n,m,a[N],b[N],q[N];
long long f[N],F[N];
int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) scanf("%d",&b[i]);
    int r=0;
    for (int i=1;i<=n;i++) {
        F[i]=f[i-1];
        while (r) {
            if (a[i]<a[q[r]]) F[i]=max(F[i],F[q[r]]),r--;
            else break;
        }   
        q[++r]=i;
        f[i]=F[i]+b[i];
        if (r>1) f[i]=max(f[i],f[q[r-1]]);
        
    }
    printf("%lld\n",f[n]);
}