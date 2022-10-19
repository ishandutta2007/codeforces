#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n,a[N],b[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),b[i]=a[i];
        long long sum=0;
        int mx=0;
        for(int i=1;i<n;i++)
        {
            a[i]-=a[i+1],sum+=abs(a[i]);
            if(i==1||i==n-1)
                mx=max(mx,abs(a[i]));
        }
        long long ans=sum-mx;
        for(int i=2;i<=n-1;i++)
            ans=min(ans,sum-abs(a[i])-abs(a[i-1])+abs(b[i+1]-b[i-1]));
        printf("%lld\n",ans);
    }
}