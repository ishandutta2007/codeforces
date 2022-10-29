#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

bool can(LL k,LL n)
{
    LL _1=0,_2=0;
    while (n > 0)
    {
        _1 += min(k,n);
        n -= min(k,n);
        _2 += n/10;
        n -= n/10;
    }
    return _1 >= _2;
}

int main ()
{
    LL n;
    scanf("%lld",&n);
    LL L=0,R=1e18;
    R += 880301;
    while (R-L != 1)
    {
        LL mid = (L+R)>>1;
        if (can(mid,n)) R = mid;
        else L = mid;
    }
    printf("%lld\n",R);
}