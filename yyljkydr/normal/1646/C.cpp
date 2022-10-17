#include<bits/stdc++.h>
using namespace std;

int T;

long long n;

int main()
{
    vector<long long>v;
    for(long long i=3,j=6;j<=1e12;i++,j*=i)
        v.push_back(j);
    sort(v.begin(),v.end());
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld",&n);
        long long ans=1e18;
        for(int S=0;S<(1<<12);S++)
        {
            long long s=0;
            for(int i=0;i<12;i++)
                if(S&(1<<i))
                    s+=v[i];
            if(s>n)
                continue;
            ans=min(ans,(long long)(__builtin_popcount(S)+__builtin_popcountll(n-s)));
        }
        printf("%lld\n",ans);
    }
}