#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

typedef long long ll;

int T,n;

ll k,a[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%lld",&n,&k);
        ll g=0;
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]),g=__gcd(g,a[i]-a[1]);
        puts((k-a[1])%g==0?"YES":"NO");
    }
}