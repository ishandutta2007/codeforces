#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7;

int T,n,k;

ll a[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        ll s=a[1],ans=0;
        for(int i=2;i<=n;i++)
        {
            if(a[i]*100>s*k)
                ans=max(ans,(a[i]*100-(s*k)+k-1)/k);
            s+=a[i];
        }
        printf("%lld\n",ans);
    }
}