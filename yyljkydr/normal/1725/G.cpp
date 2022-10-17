#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

typedef long long ll;

int n;

bool chk(ll w)
{
    ll cnt=0;
    cnt+=(w/2)-(w/4);
    if(w>=1)
        cnt++;
    if(w>=4)
        cnt++;
    cnt=w-cnt;
    return cnt>=n;
}

int main()
{
    scanf("%d",&n);
    ll l=0,r=1e18;
    while(r-l>1)
    {
        ll mid=(l+r)>>1;
        if(chk(mid))
            r=mid;
        else
            l=mid;
    }
    printf("%lld\n",r);
}