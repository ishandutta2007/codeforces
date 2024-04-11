#include<bits/stdc++.h>
using namespace std;

int T;

long long a,b;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld",&a,&b);
        if(a==b)
        {
            puts("0 0");
        }
        else
        {
            printf("%lld %lld\n",abs(a-b),min(min(a,b)%abs(a-b),abs(a-b)-min(a,b)%abs(a-b)));
        }
    }
}