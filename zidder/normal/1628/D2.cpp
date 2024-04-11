#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int MOD = 1000000007;

long long binpow(long long a, long long p){
	return p?binpow(a*a%MOD, p/2)*(p&1?a:1)%MOD:1;
}

long long bininv(long long a){
	return binpow(a, MOD-2);
}

void solve(int test_ind){
	int n, m;
	long long k;
	cin >> n >> m >> k;
	// m out of n is addition
	// f(n, m) = MAX_X[MIN(f(n-1, m) - X, f(n-1, m-1) + X)]
	// f(n, m) = [f(n-1, m) + f(n-1, m-1)] / 2
	// f(0, 0) = 0
	// f(n, 0) = 0
	// f(n, n) = n
	// 0
	// 0 1
	// 0 1/2 2
	// 0 1/4 5/4 3
	// 0 1/8 3/2 9/8 4
	// X
	// E X
	// O O X
	// O O O X
	// O O O O X
	// O O S O O X

	vector<int> fct(n + m + 2);
	fct[0] = 1;
	for (int i=1;i<fct.size();++i){
		fct[i] = fct[i-1] * 1ll * i % MOD;
	}

	auto C = [&](int n, int k){
		return fct[n] * bininv(fct[k]) % MOD * bininv(fct[n-k]) % MOD;
	};

	int inv2 = bininv(2);

	long long ans = 0;
	if (n == m) ans = n; else
	if (m == 0) ans = 0; else
	for (int i=1;i<=m;++i){
		// (n, m) to (n-1, m) or (n-1, m-1)
		// (n, n-m) to (n-1, n-m) or (n-1, n-)
		// from n-i, m-i is left
		long long r = C(n-1-i, m-i);
		(r *= binpow(inv2, n - i)) %= MOD;
		(r *= i) %= MOD;
		(ans += r) %= MOD;
	}

	cout << ans * k % MOD << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}