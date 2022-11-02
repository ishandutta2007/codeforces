#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
vll primes;
ll MOD=998244353;
ll choose[509][509];
vll ap, bp, cp;
ll solveA(ll as)
{
    ll res=1;
    for(int i=0; i<ap.size(); i++)
    {
        if(ap[i]>cp[i])
        {
            res=(res*choose[as][ap[i]-cp[i]])%MOD;
            as-=(ap[i]-cp[i]);
        }
    }
    return res;
}
ll solveB(ll bs)
{
    ll res=1;
    for(int i=0; i<bp.size(); i++)
    {
        if(bp[i]>cp[i])
        {
            res=(res*choose[bs][bp[i]-cp[i]])%MOD;
            bs-=(bp[i]-cp[i]);
        }
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll D;
    cin>>D;
    for(int i=0; i<=500; i++)
    {
        choose[i][0]=1;
        choose[i][i]=1;
    }
    for(int i=1; i<=500; i++)
    {
        for(int j=1; j<i; j++)
        {
            choose[i][j]=(choose[i-1][j-1]+choose[i-1][j])%MOD;
        }
    }
    ll E=D;
    if(D%2==0)
    {
        primes.push_back(2);
        while(D%2==0) D/=2;
    }
    for(ll i=3; i*i<=D; i+=2)
    {
        if(D%i==0)
        {
            primes.push_back(i);
            while(D%i==0) D/=i;
        }
    }
    if(D>1) primes.push_back(D);
    int test;
    cin>>test;
    while(test--)
    {
        ll a, b;
        cin>>a>>b;
        ap.clear();
        bp.clear();
        cp.clear();
        ll as=0;
        ll bs=0;
        for(ll p: primes)
        {
            ap.push_back(1);
            bp.push_back(1);
            while(a%p==0)
            {
                ap.back()++;
                a/=p;
            }
            while(b%p==0)
            {
                bp.back()++;
                b/=p;
            }
            cp.push_back(min(ap.back(), bp.back()));
            as+=(ap.back()-cp.back());
            bs+=(bp.back()-cp.back());
        }
        ll ans=(solveA(as)*solveB(bs))%MOD;
        cout<<ans<<'\n';
    }


    return 0;
}