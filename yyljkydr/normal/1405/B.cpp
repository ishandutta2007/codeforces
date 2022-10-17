#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T;

int n,a[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        long long ans=0,sum=0;
        for(int i=1,j=n;i<=n;i++)
        {
            sum+=a[i];
            ans=max(ans,-sum);
        }
        printf("%lld\n",ans);
    }
}