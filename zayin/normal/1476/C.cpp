#include<bits/stdc++.h>
#define maxn 100050
using namespace std;
typedef long long LL;

int n,a[maxn],b[maxn],c[maxn];

int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;++i) scanf("%d",c+i);
        for (int i=1;i<=n;++i) scanf("%d",a+i);
        for (int i=1;i<=n;++i) scanf("%d",b+i);

        for (int i=1;i<=n;++i) if (a[i]>b[i]) swap(a[i],b[i]);

        LL ans=0,sum=c[n];
        for (int i=n;i>1;--i)   {
            // cout<<i<<":"<<sum<<" "<<ans<<" ~ "<<a[i]<<" "<<b[i]<<endl;
            ans=max(ans,sum+b[i]-a[i]+1);
            if (a[i]==b[i])
                sum=0;
            else
                // cout<<"add:"<<a[i-1]<<" + "<<c[i-1]-b[i-1]+1<<endl,
                sum+=a[i]+c[i-1]-b[i]+1;
            sum=max(sum,(LL)c[i-1]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}