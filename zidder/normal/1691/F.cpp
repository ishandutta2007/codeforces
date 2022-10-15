#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;

const int MOD = 1000000007;

long long binpow(long long a, long long p){
	return p?binpow(a*a%MOD, p>>1)*(p&1?a:1)%MOD:1;
}

long long bininv(long long a){
	return binpow(a, MOD-2);
}

void solve(int test_ind){
	// for r, if s contains r or vertices from different branches, then f(r, s) = n
	// f(r) = s[r] * (C(s[r], k) - sum i in children[r] C(s[i/r], k)) + sum e in E[r] f(r-e, e)
	// f(r, e) = (s[r/e]) * (C(s[r/e], k) - sum i in children[r/e] C(s[i], k)) + sum e1 in E[r/e] f(r-e1, e1)

	int n, k;
	cin >> n >> k;

	vector<int> fact(n+10, 1);
	for (int i=1;i<fact.size();++i) fact[i] = fact[i-1] * 1ll * i % MOD;
	vector<int> invfact(n+10);
	for (int i=0;i<invfact.size();++i) invfact[i] = bininv(fact[i]);

	auto C = [&](int n, int k) -> int{
		if (k < 0 || k > n) return 0;
		return fact[n] * 1ll * invfact[k] % MOD * 1ll * invfact[n-k] % MOD;
	};

	vector<vector<int> > g(n);
	for (int i=1;i<n;++i){
		int u, v;
		scanf("%d%d", &u, &v);
		--u;--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<map<int, int> > sz(n);

	function<int(int, int)> get_s = [&](int r, int e) -> int {
		if (sz[r].find(e) != sz[r].end()) return sz[r][e];
		if (sz[e].find(r) != sz[e].end()) return sz[r][e] = n - sz[e][r];
		int res = 1;
		for (int i: g[r]){
			if (i == e) continue;
			res += get_s(i, r);
		}
		return sz[r][e] = res;
	};

	for (int i=0;i<n;++i) for (int j: g[i]) get_s(i, j);
	int ans = 0;
	for (int i=0;i<n;++i) {
		int coef = C(n, k);
		for (int j: g[i]) coef = (coef + MOD - C(sz[i][j], k)) % MOD;
		// cout << i << " " << coef << endl;
		ans = (ans + n * 1ll * coef % MOD) % MOD;
	}
	
	vector<map<int, int> > f(n);
	vector<int> coeff(n, -1);
	vector<int> ress(n, -1);

	function<int(int, int)> get_f = [&](int r, int e) -> int {
		if (f[r].find(e) != f[r].end()) return f[r][e];
		if (sz[r][e] < k) return f[r][e] = 0;
		if (coeff[r] == -1) {
			int coef = 0;
			for (int j: g[r]) coef = (coef + MOD - C(sz[j][r], k)) % MOD;
			coeff[r] = coef;
		}
		int res = ((coeff[r] + C(sz[r][e], k)) % MOD + C(sz[e][r], k)) % MOD * 1ll * sz[r][e] % MOD;
		int res2;
		if (ress[r] == -1) {
			if (f[e].find(r) == f[e].end()) {
				res2 = 0;
				for (int j: g[r]) if (j != e) res2 = (res2 + get_f(j, r)) % MOD;
			} else {
				ress[r] = 0;
				for (int j: g[r]) ress[r] = (ress[r] + get_f(j, r)) % MOD;
			}
		}
		if (ress[r] != -1) res2 = (ress[r] + MOD - get_f(e, r)) % MOD;
		return f[r][e] = (res + res2) % MOD;
	};
	for (int i=0;i<n;++i) for (int j: g[i]) ans = (ans + get_f(i, j)) % MOD;
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