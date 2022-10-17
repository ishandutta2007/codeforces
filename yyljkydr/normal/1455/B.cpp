#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e5+1e3+7;

int T;

int n;

signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        if(n==1)
        {
            puts("1");
            continue;
        }
        if(n==2)
        {
            puts("3");
            continue;
        }
        int sum=0,ans;
        for(int i=1;i<=n;i++)
        {
            sum+=i;
            if(sum-2>=n||sum==n)
            {
                ans=i;
                break;
            }
        }
        printf("%lld\n",ans);
    }
}