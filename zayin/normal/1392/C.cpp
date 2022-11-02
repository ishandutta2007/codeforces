#include<bits/stdc++.h>
#define maxn 200050
using namespace std;
typedef long long LL;

int n,a[maxn];

int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;++i)
            scanf("%d",a+i);
        LL ans=0;
        for (int i=n;i>1;--i)
            ans+=max(a[i-1]-a[i],0);
        printf("%lld\n",ans);
    }
    return 0;
}