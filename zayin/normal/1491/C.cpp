#include<bits/stdc++.h>
#define maxn 5050
using namespace std;
typedef long long LL;

int n;

LL a[maxn],sum[maxn];

int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;++i)  
            scanf("%lld",a+i),sum[i]=0;
        LL ans=0;
        for (int i=1;i<=n;++i)  {
            if (a[i]>1) {
                // cout<<"add ["<<i+2<<","<<i+a[i]<<"] "<<1<<" ~ "<<a[i]<<endl;
                if (i+a[i]<=n)   
                    sum[i+a[i]+1]--;
                ++sum[i+2];
            }

            sum[i]+=sum[i-1];
            if (sum[i]>a[i]-1)  {
                // cout<<"add ["<<i+1<<","<<i+1<<"] "<<sum[i]-a[i]+1<<endl,
                sum[i+1]+=sum[i]-a[i]+1;
                sum[i+2]-=sum[i]-a[i]+1;
            }

            ans+=max(a[i]-sum[i],1LL)-1;

            // cout<<i<<":"<<a[i]<<" "<<sum[i]<<endl;
        }
        printf("%lld\n",ans);
    }
    
    return 0;
}