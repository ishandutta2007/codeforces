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
ll MOD=998244353;
ll darab[1000009];
vll t[1000009];
ll n;
ll pern;
ll modinv(ll x)
{
    ll kit=MOD-2;
    ll res=1;
    while(kit>0)
    {
        if(kit%2)
        {
            res=(res*x)%MOD;
        }
        x=(x*x)%MOD;
        kit/=2;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    pern=modinv(n);
    for(int i=1; i<=n; i++)
    {
        int si;
        cin>>si;
        t[i].resize(si);
        for(int j=0; j<si; j++)
        {
            cin>>t[i][j];
            darab[t[i][j]]++;
        }
    }
    ll ans=0;
    for(int i=1; i<=n; i++)
    {
        ll prob=(pern*modinv((ll)(t[i].size())))%MOD;
        prob=(prob*pern)%MOD;
        for(int j=0; j<t[i].size(); j++)
        {
            ll most=(prob*((ll)(darab[t[i][j]])))%MOD;
            ans=(ans+most)%MOD;
        }
    }
    cout<<ans<<endl;
    return 0;
}