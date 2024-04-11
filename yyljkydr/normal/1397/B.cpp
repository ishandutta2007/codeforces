#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int n,a[N];

long long ans=0;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    if(n<=2)
    {
        printf("%d\n",a[1]-1);
    }
    else
    {
        for(int i=1;i<=n;i++)
            ans+=a[i]-1;
        for(int i=2;i<=sqrt(a[n])+10;i++)
        {
            long long j=1;
            int fd=0;
            long long sum=0;
            for(int k=1;k<=n;k++)
            {
                if(abs(j-a[k])>ans)
                {
                    fd=1;
                    break;
                }
                sum+=abs(j-a[k]);
                j=j*i;
            }
            if(!fd)
                ans=min(ans,sum);
        }
        printf("%lld\n",ans);
    }
}