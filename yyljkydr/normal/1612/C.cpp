#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=111;

int T,k,x;

int calc(int l)
{
    if(l<=k)
        return l*(l+1)/2;
    else
    {
        return k*(k+1)/2+(k-1+2*k-l)*(k-1-(2*k-l)+1)/2;
    }
}

signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld",&k,&x);
        int l=0,r=2*k-1;
        while(r-l>1)
        {
            int mid=(l+r)>>1;
            int cnt=calc(mid);
            if(cnt>=x)
                r=mid;
            else
                l=mid;
        }
        printf("%lld\n",r);
    }
}