#include<bits/stdc++.h>
using namespace std;

#define int long long

int T,n;

bool ok(int x)
{
    int g=x,s=0;
    while(x)
        s+=x%10,x/=10;
    if(__gcd(g,s)>1)
        return 1;
    else
        return 0;
}

signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        for(int i=n;i<=n+2;i++)
            if(ok(i))
            {
                printf("%lld\n",i);
                break;
            }
    }
}