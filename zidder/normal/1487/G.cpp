#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#pragma GCC optimize "trapv"
using namespace std;

const int MOD = 998244353;

void solve(int test_ind){
	int n;
	cin >> n;
	vector<int> c(26);
	for (int i=0;i<26;++i) cin >> c[i];

	int n1 = n/2;
	int n2 = (n+1)/2;

	int a1 = 26;
	for (int i=1;i<n1;++i) a1 = a1 * 25ll % MOD;
	int a2 = 26;
	for (int i=1;i<n2;++i) a2 = a2 * 25ll % MOD;
	int ans = a1 * 1ll * a2 % MOD;

	// cout << ans << endl;
	// exclude one > ci
	{
		vector<pair<int, int> > dp1(n1 + 1, {0, 0}); // (ci, other)
		for (int j=0;j<n1;++j){
			if (j == 0) {
				dp1[0] = {0, 25};
				dp1[1] = {1, 0};
				continue;
			}
			for (int k=n1;k>=0;--k){
				dp1[k].second = (dp1[k].second * 24ll + dp1[k].first * 25ll) % MOD;
				if (k) dp1[k].first = dp1[k-1].second;
			}
		}
		vector<pair<int, int> > dp2(n2 + 1, {0, 0}); // (ci, other)
		for (int j=0;j<n2;++j){
			if (j == 0) {
				dp2[0] = {0, 25};
				dp2[1] = {1, 0};
				continue;
			}
			for (int k=n2;k>=0;--k){
				dp2[k].second = (dp2[k].second * 24ll + dp2[k].first * 25ll) % MOD;
				if (k) dp2[k].first = dp2[k-1].second;
			}
		}
		for (int j=0;j<=n1;++j){
			for (int k=0;k<=n2;++k){
				for (int i=0;i<26;++i){
					// count[i] > ci
					if (j + k > c[i]) {
						ans = (ans + MOD - (dp1[j].first + 0ll + dp1[j].second) * 1ll * (dp2[k].first + 0ll+ dp2[k].second) % MOD) % MOD;
					}
				}
			}
		}
	}

	// cout << ans << endl;

	// include two > ci
	{
		vector<vector<pair<pair<int, int>, int> > > dp1((n2 + 1)/2+1, vector<pair<pair<int, int>, int> >((n2+1)/2+1, {{0, 0}, 0})); // ((ci, cj), other)
		auto dpprev = dp1;
		for (int j=0;j<n2;++j){
			if (j == 0) {
				dp1[0][0] = {{0, 0}, 24};
				dp1[1][0] = {{1, 0}, 0};
				dp1[0][1] = {{0, 1}, 0};
				continue;
			}
			dpprev = dp1;
			for (int k=dp1.size()-1;k>=0;--k){
				for (int t=dp1.size()-1;t>=0;--t){
					dp1[k][t].second = (dp1[k][t].second * 23ll + dp1[k][t].first.first * 24ll + dp1[k][t].first.second * 24ll) % MOD;
					if (k) dp1[k][t].first.first = (dp1[k-1][t].second + dp1[k-1][t].first.second) % MOD;
					if (t) dp1[k][t].first.second = (dp1[k][t-1].first.first + dp1[k][t-1].second) % MOD;
				}
			}
		}
		// [>=j][>=k] sum
		auto sm = [&](vector<vector<pair<pair<int, int>, int> > > dp){
			vector<vector<int> > dpsm(dp.size()+1, vector<int>(dp.size()+1));
			for (int i=dp.size()-1;i>=0;--i){
				for (int j=dp.size()-1;j>=0;--j){
					dpsm[i][j] = (dpsm[i][j+1] + 0ll + dpsm[i+1][j] + 0ll + MOD + 0ll - dpsm[i+1][j+1] + (dp[i][j].first.first + 0ll + dp[i][j].first.second + 0ll + dp[i][j].second)) % MOD;
				}
			}
			return dpsm;
		};
		vector<vector<int> > dprevsm = sm(n1==n2?dp1:dpprev);
		for (int j=0;j<dp1.size();++j){
			for (int k=0;k<dp1.size();++k){
				for (int i=0;i<26;++i){
					for (int q=i+1;q<26;++q){
						// if (i == q) continue;
						// count[i] > ci
						int j1 = max(0, c[i] - j+1);
						int k1 = max(0, c[q] - k+1);
						if (j1 >= dp1.size() || k1 >= dp1.size()) continue;
						// cout << j << " " << k << " " << (dp1[j][k].first.first + 0ll + dp1[j][k].first.second + 0ll + dp1[j][k].second) * 1ll * dprevsm[j1][k1] % MOD << endl;
						ans = (ans + (dp1[j][k].first.first + 0ll + dp1[j][k].first.second + 0ll + dp1[j][k].second) * 1ll * dprevsm[j1][k1] % MOD) % MOD;
					}
				}
			}
		}
	}
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