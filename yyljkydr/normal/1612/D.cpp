#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=111;

int a,b,x,T;

signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld%lld",&a,&b,&x);
        bool ans=0;
        while(a&&b)
        {
            if(a<b)
                swap(a,b);
            if(a-b<b&&a-b!=0)
                b=a-b;
            if((a-x)%b==0&&x<=a)
                ans=1;
            a%=b;
        }
        puts(ans?"YES":"NO");
    }
}