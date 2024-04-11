#include<bits/stdc++.h>
using namespace std;

const int N=5e3+1e2+7;

int T,n,a[N],cnt[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            cnt[i]=0;
        for(int j=a[1];j<=n;j++)
            cnt[j]++;
        long long ans=0;
        for(int i=2;i<=n;i++)
        {
            int cr=a[n]<a[i];
            for(int j=n-1;j>i;j--)
            {
                ans+=cnt[a[j]]*cr;
                cr+=a[j]<a[i];
            }
            for(int j=a[i];j<=n;j++)
                cnt[j]++;
        }
        printf("%lld\n",ans);
    }
}