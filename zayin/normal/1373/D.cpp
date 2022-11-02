#include<bits/stdc++.h>
#define maxn 200050
using namespace std;
typedef long long LL;

int n;
LL a[maxn];

int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);

        LL mx=0,ans=0,sum=0,now=0;
        for (int i=1;i<=n;++i)  {
            scanf("%lld",a+i);
            if (i&1)
                sum+=a[i];
            else    {
                now+=a[i]-a[i-1];
                mx=min(mx,now);
                // cout<<i<<" "<<now<<" "<<mx<<endl;
                ans=max(ans,now-mx);
            }
        }

        mx=0,now=0;
        for (int i=3;i<=n;++i)  {
            if (~i&1) continue;
            now+=-a[i]+a[i-1];
            mx=min(mx,now);
            // cout<<i<<":"<<now<<" "<<mx<<endl;
            ans=max(ans,now-mx);
        }
        // cout<<ans<<" "<<sum<<endl;
        printf("%lld\n",sum+ans);
    }
    return 0;
}