#include<bits/stdc++.h>
using namespace std;

#define int long long

int T,k;

signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&k);
        if(k&1)
            puts("-1");
        else
        {
            vector<int>ans;
            k/=2;
            for(int i=60;i>=1;i--)
                while(((1ll<<i)-1)<=k)
                {
                    k-=(1ll<<i)-1;
                    ans.push_back(1);
                    for(int j=1;j<i;j++)
                        ans.push_back(0);
                }
            printf("%lld\n",(int)ans.size());
            for(auto x:ans)
                printf("%lld ",x);
            puts("");
        }
    }
}