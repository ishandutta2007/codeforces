#include<bits/stdc++.h>
using namespace std;

#define int long long

int T,n;

signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        int even=0,odd=0;
        int x=n,bs=1;
        while(x)
        {
            odd+=x%10*bs;
            x/=100;
            bs*=10;
        }
        x=n/10,bs=1;
        while(x)
        {
            even+=x%10*bs;
            x/=100;
            bs*=10;
        }
        //even odd
        if(!even)
            printf("%lld\n",odd-1);
        else
            printf("%lld\n",(even+1)*(odd+1)-2);
    }
}