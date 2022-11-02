#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD=1000000007;
ll T, n;
ll ans=0;
vector<ll> v;
ll fact[200009];
ll factinv[200009];
ll hat2[200009];
ll hat2inv[200009];
long long modpow(ll a, ll pwr)
{
    ll res=1;
    while(pwr>0)
    {
        if(pwr%2)
        {
            res=(res*a)%MOD;
        }
        a=(a*a)%MOD;
        pwr/=2;
    }
    return res;
}
ll nck(ll i, ll j)
{
    if(j>i) return 0ll;
    ll res=fact[i];
    res=(res*factinv[j])%MOD;
    res=(res*factinv[i-j])%MOD;
    res=(res*hat2inv[i])%MOD;
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>T;
    v.push_back(0ll);
    for(int i=0; i<n; i++)
    {
        ll szam;
        cin>>szam;
        v.push_back(v.back()+szam);
    }
    fact[0]=1;
    factinv[0]=1;
    hat2[0]=1;
    hat2inv[0]=1;
    for(ll i=1; i<=n+2; i++)
    {
        fact[i]=(i*fact[i-1])%MOD;
        factinv[i]=modpow(fact[i], MOD-2);
        hat2[i]=(hat2[i-1]*2)%MOD;
        hat2inv[i]=modpow(hat2[i], MOD-2);
    }
    for(ll i=1; i<=n; i++)
    {
        if(v[i]>T) break;
        ll minimum=0;
        if(i<n)
        {
            minimum=max(0ll, T-v[i+1]+1);
        }
        ll maximum=T-v[i];
        ll tmpans=0;
        for(ll j=minimum; j<=min(i, maximum); j++)
        {
            tmpans=(tmpans+nck(i, j))%MOD;
        }
        if(minimum>0)
        {
            tmpans=(tmpans+(nck(i, minimum-1)*modpow(2, MOD-2))%MOD)%MOD;
        }
        tmpans=(tmpans*i)%MOD;
        ans=(ans+tmpans)%MOD;
    }
    cout<<ans<<endl;
    return 0;
}