#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;

ll m,d,w;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld%lld",&m,&d,&w);
        //x + y * d = y + x * d
        //(x - y) * (d - 1) = 0 mod w
        //d = 1 -> all
        //g = gcd(d - 1, w)
        //(x - y) % (w / g) == 0
        ll t=min(m,d);
        ll r=w/__gcd(d-1,w);
        ll k=t/r;
        printf("%lld\n",t*k-(r+r*k)*k/2);
    }
}