#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int MOD = 998244353;

void solve(int test_ind){
	int n;
	cin >> n;
	vector<pair<int, int> > points(n);
	for (int i=0;i<n;++i) scanf("%d%d", &points[i].first, &points[i].second);
	auto dist = [&](int i, int j){
		return abs(points[i].first - points[j].first) + abs(points[i].second - points[j].second);
	};
	vector<vector<int> > mindist(n);
	for (int i=0;i<n;++i) {
		for (int j=0;j<n;++j) {
			if (i != j) {
				if (mindist[i].empty()) mindist[i].push_back(j);
				else {
					if (dist(i, j) < dist(i, mindist[i].front())) {
						mindist[i] = {j};
						continue;
					}
					if (dist(i, j) == dist(i, mindist[i].front())) {
						mindist[i].push_back(j);
					}
				}
			}
		}
	}


	for (int i=0;i<n;++i) {
		mindist[i].push_back(i);
		sort(mindist[i].begin(), mindist[i].end());
	}

	vector<bool> vis(n, false);

	vector<int> csize;

	for (int i=0;i<n;++i) {
		if (vis[i]) continue;
		vector<int> component = mindist[i];
		bool ok = true;
		for (int j: mindist[i]) {
			if (mindist[j] != mindist[i]) ok = false;
		}
		if (ok) {
			csize.push_back(component.size());
			for (int j: component) vis[j] = true;
		} else {
			csize.push_back(1);
			vis[i] = true;
		}
	}

	sort(csize.begin(), csize.end());

	vector<vector<int> > dp(csize.size()+1, vector<int>(n+1));

	auto A = [&](int n, int k) {
		int ans = 1;
		for (int i=0;i<k;++i) ans = ans * 1ll * (n - i) % MOD;
		return ans;
	};

	for (int i=0;i<=n;++i) dp[0][i] = 1;

	for (int i=1;i<=csize.size();++i) {
		for (int j=csize[i-1];j<=n;++j) {
			if (csize[i-1] == 1) {
				dp[i][j] = dp[i-1][j-1] * 1ll * j % MOD;
				// cout << dp[i-1][j-1] << " " << j << endl;
			} else {
				dp[i][j] = (dp[i-1][j-1] * 1ll * j % MOD + dp[i-1][j-csize[i-1]] * 1ll * A(j, csize[i-1]) % MOD) % MOD;
			}
			// cout << i << " " << j << " " << dp[i][j] << " " << csize[i-1] << endl;
		}
	}
	cout << dp[csize.size()][n] << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}