#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define N_MAX 200002

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll inv[N_MAX],fac[N_MAX],finv[N_MAX];

void init(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<N_MAX;i++){
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        fac[i]=fac[i-1]*(ll) i%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}

ll inv_(ll n){
    if(n == 1) return 1;
    else return MOD-inv_(MOD%n)*(MOD/n)%MOD;
}

ll comb(ll n, ll r){
  ll ans;
  if(n < r){
      ans = 0;
  }else{
      ans = (fac[n]*finv[r])%MOD;
      ans = (ans*finv[n-r])%MOD;
      ans = (ans+MOD)%MOD;
  }
  return ans;
}

template <typename T>
T pow(T a, ll n) {
	T ans = 1;
	T tmp = a;
	for (int i = 0; i <= 60; i++) {
		ll m = (ll)1 << i;
		if (m & n) {
		ans *= tmp;
		ans %= MOD;
		}
		tmp *= tmp;
		tmp %= MOD;
	}
	return ans;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    ll n, k;
    cin >> n >> k;
    init();
    if(k >= n){
        cout << 0 << endl;
        return 0;
    }
    if(k == 0){
        cout << fac[n]%MOD << endl;
        return 0;
    }
    ll l = n-k;
    ll cb = comb(n, l);
    ll each = 0;
    for(int i = 0; i <= l; i++){
        ll s = l-i;
        if(i%2 == 0) each += (comb(l, i)*pow<ll>(s, n))%MOD;
        else each -= (comb(l, i)*pow<ll>(s, n))%MOD;
        each %= MOD;
        each += MOD;
        each %= MOD;
    }
    cout << (2*cb*each)%MOD << endl;
}