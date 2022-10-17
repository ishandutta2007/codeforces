#include<bits/stdc++.h>
using namespace std;

int T;

long long n,x,t;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld%lld",&n,&x,&t);
        //Li = min(t / x + i - 1, n)
        //Ri = i - 1
        //si = min(t / x, i)
        long long p=t/x+1;
        //1 + 2 + ... + p + p + ..
        if(p>n)
            printf("%lld\n",(1+n)*n/2-n);
        else
            printf("%lld\n",(1+p)*p/2+p*(n-p)-n);
    }
}