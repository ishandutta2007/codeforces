#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
#define ll long long
const int MOD = 1000000007;

ll binpow(ll a, ll p){
	return p?binpow(a*a%MOD,p>>1)*(p&1?a:1)%MOD:1;
}
ll bininv(ll a){return binpow(a, MOD-2);}


void solve(int test_ind){
	int k;
	ll n;
	ll m, invm;
	m = 2;
	cin >> n >> k;
	// k--;
	invm = bininv(m);

	// x1 ^ k + ... + xn ^ k = d^k [(m - 1 + e^t) / m]^n / dt^k {t=0}
	//                       = 1 / m^n * d^k (m - 1 + e^t)^n / dt^k {t=0}
	vector<ll> d(k+1);
	d[0] = 1;
	for (int i=0;i<k;++i){
		// i derivations done before
		for (int j=i;j>=0;--j){
			ll a = 0, b;
			// (m - 1 + e^t)^{n-j} * e^{jt}
			a = d[j+1] * (j + 1) % MOD;
			b = d[j] * (n - j) % MOD;
			d[j+1] = (a + b) % MOD;
		}
		d[0] = 0;
		// for (ll q: d) cout << q << " ";
		// cout << endl;
	}
	ll ans = 0;	
	for (int i=0;i<=k;++i){
		if (n >= i) (ans += d[i] * binpow(m, n-i) % MOD) %= MOD;
	}
	cout << ans % MOD << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}