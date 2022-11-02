#include<bits/stdc++.h>
#define maxn 200050
using namespace std;
typedef long long LL;

int n;
LL m,a[maxn];

int main()
{
    scanf("%d%I64d",&n,&m);
    for (int i=1;i<=n;++i)
        scanf("%I64d",&a[i]);
    
    LL pre=0,ans=0;
    for (int i=1;i<=n;++i)
    {
        if (pre)
        {
            if (pre+a[i]<=m)
                pre=0,++ans;
            else
                ans+=(pre+a[i])/m,pre=(pre+a[i])%m;
        } else
        {
            ans+=a[i]/m,
            pre=a[i]%m;
        }
    }
    
    if (pre)
        ans+=(pre-1)/m+1;
    printf("%I64d\n",ans);
    return 0;
}