#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7;

int T;

ll d;

bool isprime(int x)
{
    if(x==1)
        return 0;
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
            return 0;
    return 1;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld",&d);
        ll x=d+1;
        while(!isprime(x))
            x++;
        ll y=x+d;
        while(!isprime(y))
            y++;
        printf("%lld\n",x*y);
    }
}