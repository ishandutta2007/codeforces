#include<bits/stdc++.h>
using namespace std;

int T,n;

long long fac(int x)
{
    if(x==0)
        return 1;
    return x*fac(x-1)%998244353;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        if(n&1)
            puts("0");
        else
            printf("%lld\n",fac(n/2)*fac(n/2)%998244353);
    }
}