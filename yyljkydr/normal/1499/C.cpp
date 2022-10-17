#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n;

int c[N];

long long sum[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&c[i]);
        int mnx=c[1],mny=1e9;
        long long ans=1e18;
        sum[1]=c[1];
        int tot[2]={0,1};
        for(int i=2;i<=n;i++)
        {
            tot[i&1]++;
            sum[i]=sum[i-1]+c[i];
            if(i&1)
                mnx=min(mnx,c[i]);
            else
                mny=min(mny,c[i]);
            ans=min(ans,sum[i]-mnx-mny+1ll*(n-tot[1]+1)*mnx+1ll*(n-tot[0]+1)*mny);
        }
        printf("%lld\n",ans);
    }
}