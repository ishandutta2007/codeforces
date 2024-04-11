#include<bits/stdc++.h>
using namespace std;

int T;

long long n;

long long lcm(long long a,long long b)
{
    return a/__gcd(a,b)*b;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld",&n);
        long long ans=0;
        for(long long i=1,fc=1;fc<=n;i++,fc=lcm(fc,i))
        {
            ans+=(n/fc-n/lcm(fc,i+1))*(i+1);
        }
        printf("%lld\n",ans%1'000'000'007);
    }
}