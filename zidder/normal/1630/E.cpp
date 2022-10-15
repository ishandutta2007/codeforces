#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int MOD = 998244353;

long long binpow(long long a, long long p){
	return p?binpow(a*a%MOD,p>>1)*(p&1?a:1)%MOD:1;
}

long long bininv(long long a){
	return binpow(a,MOD-2);
}

void solve(int test_ind){
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i=0;i<n;++i){
		scanf("%d", &a[i]);
	}
	map<int, int> cnts;
	for (int i=0;i<n;++i){
		cnts[a[i]]++;
	}
	vector<int> sizes;
	for (auto it:cnts){
		sizes.push_back(it.second);
	}
	if (sizes.size() == 1){
		printf("1\n");
		return;
	}
	map<int, int> cntcnts;

	sort(sizes.begin(), sizes.end());
	int gs = 0;
	for (int i: sizes){
		cntcnts[i]++;
		gs = __gcd(i, gs);
	}

	vector<int> fct(n+1);
	fct[0] = 1;
	for (int i=1;i<=n;++i){
		fct[i] = fct[i-1] * 1ll * i % MOD;
	}

	auto C = [&](int g){
		int coef = n / g;
		int ans = fct[g];
		for (auto &pp: cntcnts){
			ans = ans * binpow(bininv(fct[pp.first / coef]), pp.second) % MOD;
		}
		return ans;
	};

	long long invn = bininv(n);
	long long ans = 0;
	long long total_cnt = 0;

	// g^0 s, g^1 s, .... g^k s
	// \sum_distinct s f(s) = sum_s f(s) / order(s) = 1/n * sum_(i=1 to n) f(s) * n/order(s) = 1/n * sum(i = 1 to n) f(s) * N(k|g^k s = s)
	// f([1, 1, 1, 2]) = 2
	// 2 = f([1, 1, 1, 2]) / 4 + f([1, 1, 2, 1]) / 4 + f([1, 2, 1, 1]) / 4 + f([2, 1, 1, 1]) / 4 = 1/4 * sum_(i=1 to n) sum_s f(s) * 1

	for (int i=0;i<n;++i){
		int g = __gcd(i, n);
		int coef = n / g;
		if (gs%coef) continue;
		// anything of size g
		int cnt = C(g);
		// g! / P k!
		long long p = 0;
		for (auto &pp: cntcnts){
			int j = pp.first / coef;
			// g * [(g-2)! / P k!  * k[j] * (k[j]-1)] / [g! / P k!)
			(p += pp.second * 1ll * j % MOD * 1ll * (j - 1) % MOD * bininv(g-1) % MOD) %= MOD;
		}
		// cout << g << " " << coef << " " << p << endl;
		(ans += (g + MOD - p) % MOD * coef % MOD * cnt % MOD) %= MOD;
		(total_cnt += cnt) %= MOD;
	}
	cout << ans * bininv(total_cnt) % MOD << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}