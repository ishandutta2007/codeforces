#include<bits/stdc++.h>
#define maxn 105
using namespace std;
typedef long long LL;

LL num[maxn];

LL dp[maxn];

int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        LL d,m;
        scanf("%lld%lld",&d,&m);

        for (int i=0;i<maxn;++i) num[i]=0;
        for (int i=0;(1LL<<i)<=d;++i)   {
            if (((1LL<<i)^d)<(1LL<<i))
                num[i]=(d-(1LL<<i)+1)%m;
            else
                num[i]=(1LL<<i)%m;
            // cout<<"num:"<<i<<" "<<num[i]<<" "<<(1LL<<i)<<" "<<d<<" "<<((1LL<<i)<=d)<<endl;
        }
        
        LL ans=0;
        for (int i=0;i<maxn;++i)    {
            dp[i]=num[i];
            for (int j=0;j<i;++j)
                dp[i]=(dp[i]+dp[j]*num[i])%m;
            ans=(ans+dp[i])%m;

            // if (dp[i])
            //     cout<<i<<":"<<dp[i]<<endl;
        }

        printf("%lld\n",ans);
    }
    return 0;
}