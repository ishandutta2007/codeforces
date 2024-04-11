#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int MOD = 1000000007;

long long binpow(long long a, long long p) {
	return p?binpow(a*a%MOD, p>>1)*(p&1?a:1) % MOD:1;
}

long long bininv(long long a){
	return binpow(a, MOD-2);
}

void solve(int test_ind){
	long long n, l, r, z;
	cin >> n >> l >> r >> z;
	vector<int> fact(n+5);
	fact[0] = 1;
	for (int i=1;i<fact.size();++i) fact[i] = fact[i-1] * 1ll * i % MOD;
	auto C = [&](int n, int k) -> long long{
		return fact[n] * bininv(fact[k]) % MOD * bininv(fact[n-k]) % MOD;
	};


	auto f = [&](long long x) -> int {
		vector<vector<int> > dp(61, vector<int>(n, 0));
		// if (x == 0) return 0;
		int ans = 0;
		dp[60][0] = 1;
		for (int i=60;i>0;--i){
			int zi = 0;
			if (z&(1ll<<(i-1))) zi=1;
			int xi = 0;
			if (x&(1ll<<(i-1))) xi=1;

			for (int j=zi;j<=n;j+=2){
				long long cn = C(n, j);
				for (int k=0;k<n;++k){
					if (dp[i][k] == 0) continue;
					int pk = 2*k+xi-j;
					if (pk >= n) {
						(ans += (cn * dp[i][k] % MOD) * binpow(binpow(2, n-1), i-1) % MOD) %= MOD;
						// cout << i << " " << k << " " << dp[i][k] << " " << pk << endl;
						// cout << "hey" << endl;
						continue;
					}
					if (pk < 0) continue;
					(dp[i-1][pk] += cn * dp[i][k] % MOD) %= MOD;
					// cout << i << " " << k << " " << dp[i][k] << " " << pk << " " << dp[i-1][pk] << endl;
				}
			}
		}
		for (int k=0;k<n;++k)
			(ans += dp[0][k]) %= MOD;
		return ans;
	};
	int ans = f(r);
	(ans += MOD - f(l-1)) %= MOD;
	cout << ans << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}