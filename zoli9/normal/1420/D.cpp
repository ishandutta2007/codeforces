#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//(double)clock() / CLOCKS_PER_SEC;

int n;
ll k;
ll MOD=998244353;

vpii v;

ll fact[300009];
ll factinv[300009];

ll ch(ll x, ll y)
{
    if(x<y) return 0;
    ll res=fact[x];
    res=(res*factinv[y])%MOD;
    res=(res*factinv[x-y])%MOD;
    return res;
}

ll modinv(ll x)
{
    ll xp=MOD-2;
    ll res=1;
    while(xp>0)
    {
        if(xp%2) res=(res*x)%MOD;
        xp/=2;
        x=(x*x)%MOD;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    fact[0]=1;
    factinv[0]=1;
    fact[1]=1;
    factinv[1]=1;
    for(int i=2; i<=n; i++)
    {
        fact[i]=(i*fact[i-1])%MOD;
        factinv[i]=modinv(fact[i]);
    }
    for(int i=1; i<=n; i++)
    {
        int le, ri;
        cin>>le>>ri;
        v.push_back({le, -1});
        v.push_back({ri, 1});
    }
    sort(v.begin(), v.end());
    ll cnt=0;
    ll ans=0;
    for(pii p: v)
    {
        if(p.S==-1) cnt++;
        else
        {
            cnt--;
            if(cnt>=k-1)
            {
                ans+=ch(cnt, k-1);
                ans%=MOD;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}