#include<bits/stdc++.h>
using namespace std;

#define int long long

int T,a,b,c,pw[11];

int gen(int x)
{
    int l=pw[x],r=pw[x+1]-1;
    return 1ll*rand()*rand()%(r-l+1)+l;
}

signed main()
{
    pw[1]=1;
    for(int i=2;i<=10;i++)
        pw[i]=pw[i-1]*10;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        int x=gen(a-c+1),y=gen(b-c+1);
        while(__gcd(x,y)!=1)
            y=gen(b-c+1);
        printf("%lld %lld\n",x*pw[c],y*pw[c]);
    }
}