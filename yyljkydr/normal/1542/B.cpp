#include<bits/stdc++.h>
using namespace std;

int T;

long long n,a,b;

long long lcm(long long a,long long b)
{
    return a/__gcd(a,b)*b;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld%lld",&n,&a,&b);
        int ans=0;
        if(a==1)
        {
            puts((n-1)%b?"NO":"YES");
            continue;
        }
        for(long long i=1;i<=n;i=i*a)
            if((n-i)%b==0)
                ans=1;
        puts(ans?"YES":"NO");
    }
}