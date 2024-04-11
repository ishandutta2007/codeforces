#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T;

long long n;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld",&n);
        if(n&1)
            n++;
        if(n<=6)
            puts("15");
        else
            printf("%lld\n",n*5/2);
    }
}