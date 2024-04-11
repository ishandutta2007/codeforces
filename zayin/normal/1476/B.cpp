#include<bits/stdc++.h>
#define maxn 100050
using namespace std;
typedef long long LL;

int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        int n,k;
        scanf("%d%d",&n,&k);

        LL ans=0,sum=0,a;
        for (int i=0;i<n;++i)  {
            scanf("%lld",&a);
            if (i)  {
                // cout<<i<<":"<<(a*100-1)/k+1-sum<<endl;
                ans=max(ans,(a*100-1)/k+1-sum);
            }
            sum+=a;
        }
        printf("%lld\n",ans);
    }
    return 0;
}