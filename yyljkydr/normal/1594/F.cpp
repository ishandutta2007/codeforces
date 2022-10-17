#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;

ll n,s,k;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld%lld",&s,&n,&k);
        if(s==k)
        {
            puts("YES");
            continue;
        }
        if(k>s)
        {
            puts("NO");
            continue;
        }
        ll t=s+k+1;
        ll x=t/(k*2)*k,y=t%(k*2);
        if(x+max(0ll,y-k)>=n+1)
            puts("NO");
        else
            puts("YES");
    }
}