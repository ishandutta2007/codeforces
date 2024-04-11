#include<bits/stdc++.h>
#define maxn 500050
using namespace std;
typedef long long LL;

LL gcd(LL a,LL b)   {
    return !b?a:gcd(b,a%b);
}

int n;
LL m,a[maxn];

int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%lld",&n,&m);
        for (int i=1;i<=n;++i)
            scanf("%lld",a+i);
        sort(a+1,a+n+1);

        LL d=0;
        for (int i=2;i<=n;++i)
            d=gcd(d,a[i]-a[1]);
        
        puts((m-a[1])%d==0?"YES":"NO");
    }
    return 0;
}