#include <bits/stdc++.h>
using namespace std;
long long fact[2000009];
long long factinv[2000009];
long long n;
long long d[1000009];
const long long MOD=1000000007;
long long modinvers(long long x, long long p)
{
    long long eredmeny=1LL;
    long long kit=p-2;
    long long y=x;
    while(kit>0)
    {
        if(kit%2)
        {
            eredmeny*=y;
            eredmeny%=p;
        }
        y*=y;
        y%=p;
        kit/=2;
    }
    return eredmeny%p;
}
int main()
{
    cin>>n;
    fact[1]=1;
    factinv[1]=1;
    for(long long i=2; i<=2*n+5; i++)
    {
        fact[i]=fact[i-1]*i;
        fact[i]%=MOD;
        factinv[i]=modinvers(fact[i], MOD);
    }
    d[1]=5;
    d[2]=19;
    for(int i=3; i<=n; i++)
    {
        d[i]=d[i-1];
        long long pl1=fact[2*i+2];
        pl1*=factinv[i+1];
        pl1%=MOD;
        pl1*=factinv[i+1];
        pl1%=MOD;
        long long pl2=fact[2*i];
        pl2*=factinv[i];
        pl2%=MOD;
        pl2*=factinv[i];
        pl2%=MOD;
        d[i]+=pl1;
        d[i]%=MOD;
        d[i]+=MOD;
        d[i]-=pl2;
        d[i]%=MOD;
    }
    cout<<d[n];
    return 0;
}