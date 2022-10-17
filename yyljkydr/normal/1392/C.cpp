#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n,a[N];

signed main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int mx=0,last=0;
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            mx=max(mx,a[i]);
            int val=mx-a[i];
            ans+=max(val-last,0);
            last=val;
        }
        printf("%lld\n",ans);
    }
}