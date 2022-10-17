#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T;

int n,d[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&d[i]);
        sort(d+1,d+n+1);
        long long ans=0,sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=d[i];
            ans+=1ll*d[i]*i-sum;
        }
        ans-=d[n];
        printf("%lld\n",-ans);
    }
}