#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

typedef long long ll;

int T;

ll p,f,s,w,cs,cw;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld",&p,&f);
        scanf("%lld%lld",&cs,&cw);
        scanf("%lld%lld",&s,&w);
        if(s>w)
            swap(s,w),swap(cs,cw);
        ll ans=0;
        for(int i=0;i<=min(cs,p/s);i++)
        {
            ll rp=p-i*s;
            ll rf=f-min(cs-i,f/s)*s;
            ll tot=i+min(cs-i,f/s);
            tot+=min(rp/w+rf/w,cw);
            ans=max(ans,tot);
        }
        printf("%lld\n",ans);
    }
}