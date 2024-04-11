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

ll MOD=998244353;

ll modinv(ll a) {
  ll res=1;
  ll xp=MOD-2;
  while(xp>0) {
    if(xp%2) res=(res*a)%MOD;
    xp/=2;
    a=(a*a)%MOD;
  }
  return res;
}

ll fact[300009];
ll factinv[300009];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    fact[0]=1;
    fact[1]=1;
    factinv[0]=0;
    factinv[1]=1;
    for(ll i=2; i<=2*n; i++) {
      fact[i]=(fact[i-1]*i)%MOD;
    }
    for(ll i=2; i<=n; i++) {
      factinv[i]=(modinv(fact[i]))%MOD;
    }
    vll a(2*n);
    for(int i=0; i<2*n; i++) {
      cin>>a[i];
    }
    sort(a.begin(), a.end());
    ll ans=0;
    for(int i=0; i<n; i++) {
      ans=(ans-a[i]+MOD)%MOD;
    }
    for(int i=n; i<2*n; i++) {
      ans=(ans+a[i])%MOD;
    }
    ans=(ans*fact[2*n])%MOD;
    ans=(ans*factinv[n])%MOD;
    ans=(ans*factinv[n])%MOD;
    cout<<ans<<endl;
    return 0;
}