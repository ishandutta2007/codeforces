#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+1e3+7;

int T,n,m;

signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        if(n==1&&m==1)
            puts("0");
        else if(n==1||m==1)
            puts("1");
        else
            puts("2");
    }
}