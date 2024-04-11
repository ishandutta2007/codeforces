#include<bits/stdc++.h>
#define maxn 1000050
using namespace std;
typedef long long LL;

int n,a[maxn];

const int lim=4e5;

LL sum[maxn];


int main()  {
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%d",a+i),sum[i-a[i]+lim]+=a[i];

    LL ans=0;
    for (int i=0;i<maxn;++i)
        ans=max(ans,sum[i]);
    printf("%lld\n",ans);
    
    return 0;
}