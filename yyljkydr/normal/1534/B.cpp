#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T,n,a[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        a[n+1]=0;
        long long ans=0;
        for(int i=0;i<=n;i++)
            ans+=abs(a[i]-a[i+1]);
        for(int i=1;i<=n;i++)
            if(a[i]>a[i-1]&&a[i]>a[i+1])
                ans-=a[i]-max(a[i-1],a[i+1]);
        printf("%lld\n",ans);
    }
}