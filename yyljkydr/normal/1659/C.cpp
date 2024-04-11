#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T;

int n,a,b,x[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&a,&b);
        for(int i=1;i<=n;i++)
            scanf("%d",&x[i]);
        long long ans=0;
        for(int i=1,j=0;i<=n;i++)
        {
            ans+=1ll*(x[i]-x[j])*b;
            if(1ll*a<=1ll*(n-i)*b)
                ans+=1ll*(x[i]-x[j])*a,j=i;
        }
        printf("%lld\n",ans);
    }
}