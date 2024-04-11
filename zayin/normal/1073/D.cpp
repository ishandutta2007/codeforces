#include<bits/stdc++.h>
#define maxn 200050
using namespace std;
typedef long long LL;

int n;
LL m,a[maxn],mn=1LL<<60;

void get(LL T,LL &cnt,LL &sum)
{
    for (int i=0;i<n;++i)
        if (T>=a[i])
            ++cnt,sum+=a[i],T-=a[i];
}

int main()
{
    scanf("%d%lld",&n,&m);
    for (int i=0;i<n;++i)
        scanf("%d",a+i),mn=min(mn,a[i]);
    LL ans=0;
    while (m>=mn)
    {
        LL cnt=0,sum=0;
        get(m,cnt,sum);
        ans+=cnt*(m/sum);
        m%=sum;
    }
    printf("%lld\n",ans);
    return 0;
}