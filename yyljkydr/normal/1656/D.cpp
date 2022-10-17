#include<bits/stdc++.h>
using namespace std;


int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long n;
        scanf("%lld",&n);
        long long x=n;
        while(!(x&1))
            x>>=1;
        if(x==1)
            puts("-1");
        else
            printf("%lld\n",min(2*(n/x),x));
    }
}