#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

typedef long long ll;

int T,n,k,l1,r1,l2,r2;

ll ans;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        if(r1>r2)
            swap(l1,l2),swap(r1,r2);
        ll en=(r1<l2?l2-r1:0);
        ll tk=k;
        if(r1<l2)
            r1=l2;
        else
            tk-=1ll*n*(r1-max(l2,l1));
        if(tk<=0)
        {
            puts("0");
            continue;
        }
        k=tk;
        ll x=abs(l2-l1)+abs(r2-r1);
        ll ans=2e18;
        for(int i=1;i<=n;i++)
        {
            ll t=en*i;
            t+=min(i*x,1ll*k);
            t+=2*(k-min(i*x,1ll*k));
            ans=min(ans,t);
        }
        printf("%lld\n",ans);
    }
}