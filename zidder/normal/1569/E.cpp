#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;

const int MOD = 998244353;

long long binpow(long long a, long long p) {
	return p?binpow(a*a%MOD, p>>1)*(p&1?a:1)%MOD:1;
}

long long bininv(long long a){
	return binpow(a, MOD-2);
}

void solve(int test_ind){
	int k, A, h;
	cin >> k >> A >> h;
	
	vector<int> coefs(6);
	coefs[0] = binpow(A, 1);
	for(int i = 1; i <= k; ++i){
		coefs[i] = binpow(A, ((1<<(i-1)) + 1));
	}
	// for (int i: coefs) cout << i << " "; cout << endl;

	int n = (1<<k);
	vector<vector<pair<int, int> > > deltas = {{}, // k -> (delta, count)
		{{n/2 * 1ll * (coefs[0] + MOD - coefs[1]) % MOD, 1}}, // 1
		{{n/4 * 1ll * (coefs[0] + MOD - coefs[2]) % MOD, 1}, {n/4 * 1ll * (coefs[1] + MOD - coefs[2]) % MOD, 1}}, // 1, 2
		{{n/8 * 1ll * (coefs[0] + MOD - coefs[3]) % MOD, 1}, {n/8 * 1ll * (coefs[1] + MOD - coefs[3]) % MOD, 1}, {n/8 * 1ll * (coefs[2] + MOD - coefs[3]) % MOD, 2}}, // 1, 2, 3, 3
		{{n/16 * 1ll * (coefs[0] + MOD - coefs[4]) % MOD, 1}, {n/16 * 1ll * (coefs[1] + MOD - coefs[4]) % MOD, 1}, {n/16 * 1ll * (coefs[2] + MOD - coefs[4]) % MOD, 2}, {n/16 * 1ll * (coefs[3] + MOD - coefs[4]) % MOD, 4}}, // 1, 2, 3, 3, 5, 5, 5, 5
		{{n/32 * 1ll * (coefs[0] + MOD - coefs[5]) % MOD, 1}, {n/32 * 1ll * (coefs[1] + MOD - coefs[5]) % MOD, 1}, {n/32 * 1ll * (coefs[2] + MOD - coefs[5]) % MOD, 2}, {n/32 * 1ll * (coefs[3] + MOD - coefs[5]) % MOD, 4}, {n/32 * 1ll * (coefs[4] + MOD - coefs[5]) % MOD, 8}} // 1, 2, 3, 3, 5, 5, 5, 5, 9, 9, 9, 9, 9, 9, 9, 9
	};

	vector<vector<int> > ans;

	function<bool(int, int, int)> dfs = [&](int t, int j, int rh) -> bool {
		if (t == k && j == deltas[t].size()) {
			// cout << rh << endl;
			if (rh == 0) {
				ans.emplace_back();
				return true;
			}
			return false;
		}
		if (j == deltas[t].size()) {
			if (dfs(t+1, 0, rh)) {
				reverse(ans.back().begin(), ans.back().end());
				ans.emplace_back();
				return true;
			} else return false;
		}
		for (int d=0;d<=deltas[t][j].second;++d){
			if (dfs(t, j+1, rh)) {
				ans.back().push_back(d);
				return true;
			}
			// cout << "d: " << MOD - deltas[t][j].first << endl;
			rh = (rh + MOD - deltas[t][j].first) % MOD;
		}
		return false;
	};

	vector<vector<int> > v(k);
	for (int i=2;i<=n;i+=2) v[k-1].push_back(i);
	for (int i=3;i<=n;i+=4) v[k-2].push_back(i);
	for (int i=5;i<=n;i+=8) v[k-3].push_back(i);
	for (int i=9;i<=n;i+=16) v[k-4].push_back(i);
	for (int i=17;i<=n;i+=32) v[k-5].push_back(i);

	// first = 1
	h = (h + MOD - A) % MOD;
	for (int i=0;i<k;++i) for (int j: v[i]) h = (h + MOD - j * binpow(A, (1<<i)+1)%MOD) % MOD;
	// cout << "  " << h << endl;
	if (!dfs(0, 0, h)) {
		cout << -1 << endl;
	} else {
		// for (int i=0;i<k;++i) {for (int j: v[i]) cout << j << " "; cout <<endl;}
		reverse(ans.begin(), ans.end());
		// for (int i=0;i<=k;++i) {for (int j: ans[i]) cout << j << " "; cout <<endl;}
		int frst = 1;
		auto fix = [&](int x, int y, int d) {
			// x ends in d-th col
			// cout << x << " to " << y << " " << d << endl;
			for (int i=d;i>=0;--i){
				for (int j=0;j<v[i].size();++j){
					if (v[i][j] == x) v[i][j] = y;
					else if (v[i][j] == y) v[i][j] = x;
					else continue;
					break;
				}
			}
			if (frst == x) frst = y;
			else if (frst == y) frst = x;
		};
		for (int i=0;i<ans.size();++i){
			int p = 1 << (k-i);
			for (int j=0;j<ans[i].size();++j){
				while (ans[i][j]) {
					// cout << i << " " << j << " " << ans[i][j] << endl;
					if (j == 0) {
						fix(frst, frst + p, i-1);
						ans[i][j]--;
					} else {
						for (int q=0;q<v[i-1].size();++q){
							if ((v[i-1][q] - 1) & p && find(v[j-1].begin(), v[j-1].end(), v[i-1][q] - p) != v[j-1].end()){
								fix(v[i-1][q], v[i-1][q] - p, i-1);
								ans[i][j]--;
								break;
							}
						}
					}
				}
			}
		}
		vector<int> anss(n);
		anss[frst-1] = 1;
		for (int i=0;i<k;++i){
			for (int j: v[i]) anss[j-1] = (1<<i) + 1;
		}
		for (int i: anss) cout << i << " ";
		cout << endl;
	}
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}