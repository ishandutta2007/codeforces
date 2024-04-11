#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+1e3+7;

int n,h[N],tmp[N];

bool chk(int w)
{
    for(int i=1;i<=n;i++)
        tmp[i]=h[i];
    for(int i=n;i>=3;i--)
    {
        if(tmp[i]<w)
            return 0;
        int k=min(h[i],tmp[i]-w)/3;
        tmp[i-1]+=k;
        tmp[i-2]+=k*2;
    }
    if(tmp[1]<w||tmp[2]<w)
        return 0;
    return 1;
}

int T;

signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        for(int i=1;i<=n;i++)
            scanf("%lld",&h[i]);
        int l=0,r=2e15;
        chk(32);
        while(r-l>1)
        {
            int mid=(l+r)>>1;
            if(chk(mid))
                l=mid;
            else
                r=mid;
        }
        printf("%lld\n",l);
    }
}