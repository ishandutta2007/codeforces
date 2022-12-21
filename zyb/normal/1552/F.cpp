#include<bits/stdc++.h>
#define N 1000005
using namespace std;
#define P 998244353
int n;
long long a[N],x[N],y[N],b[N];
int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%lld%lld%lld",&x[i],&y[i],&a[i]);
    long long ans=x[n]+1;
    long long sum=0;
    for (int i=1;i<=n;i++) {
        int pos=lower_bound(x+1,x+1+n,y[i])-(x+1);
        long long t=(x[i]-y[i]+sum-b[pos])%P;
        (sum+=t)%=P;
        b[i]=sum;
        if (a[i]) (ans+=t)%=P;
    }
    (ans+=P)%=P;
    printf("%lld\n",ans);
}