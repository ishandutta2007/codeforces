#include<bits/stdc++.h>
#define maxn 300050
using namespace std;
typedef long long LL;

int n;
LL a[maxn],ans;

LL sq(LL x) {
    return x*x;
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%lld",a+i);
    sort(a+1,a+n+1);

    for (int i=1;i<=n/2;++i)
        ans+=sq(a[i]+a[n-i+1]);
    printf("%lld\n",ans);
    return 0;
}