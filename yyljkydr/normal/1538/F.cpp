#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e6+1e3+7;

int T,l,r;

int solve(int l,int r)
{
    if(!l&&!r)
        return 0;
    return r-l+solve(l/10,r/10);
}

signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",solve(l,r));
    }
}