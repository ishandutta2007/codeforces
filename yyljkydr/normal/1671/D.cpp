#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n,x,a[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&x);
        long long ans=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),ans+=abs(a[i]-a[i-1]);
        ans-=a[1];
        int mn=*min_element(a+1,a+n+1),mx=*max_element(a+1,a+n+1);
        if(mn>=1)
            ans+=min({2*mn-2,a[1]-1,a[n]-1});
        if(mx<=x)
            ans+=min({2*x-2*mx,x-a[1],x-a[n]});
        printf("%lld\n",ans);
    }
}
/*

a x b
b - a


*/