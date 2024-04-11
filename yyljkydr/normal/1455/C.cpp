#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e5+1e3+7;

int T;

int n;

signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        int x,y;
        scanf("%lld%lld",&x,&y);
        printf("%lld %lld\n",x-1,y);
    }
}