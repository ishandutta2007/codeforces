#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=5e3+1e2+7;

int n,a[N],b[N];

signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%lld",&b[i]);
    int ans,tot=0;
    for(int i=1;i<=n;i++)
        tot+=a[i]*b[i];
    ans=tot;
    for(int i=2;i<=n*2;i++)
    {
        int x=i>>1,y=i-x;
        int now=tot;
        for(;x>=1&&y<=n;x--,y++)
        {
            now-=a[x]*b[x]+a[y]*b[y];
            now+=a[x]*b[y]+a[y]*b[x];
            ans=max(ans,now);
        }
    }
    printf("%lld\n",ans);
}