#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL _,__;

void solve(LL a,LL b)
{
    if (a==0 || b==0)
    {
        _ = a;
        __ = b;
        return;
    }
    else if (a >= 2*b)
    {
        solve(a%(2*b),b);
        return;
    }
    else if (b >= 2*a)
    {
        solve(a,b%(2*a));
        return;
    }
    else
    {
        _ = a;
        __ = b;
        return;
    }
}

int main ()
{
    LL a,b;
    scanf("%lld %lld",&a,&b);
    solve(a,b);
    printf("%lld %lld\n",_,__);
}