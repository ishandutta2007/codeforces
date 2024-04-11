#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int dp[501][500];

void solve(int test_ind){
	int n, l, k1;
	for (int i=0;i<=500;++i){
		for (int j=0;j<500;++j){
			dp[i][j] = -1;
		}
	}
	cin >> n >> l >> k1;
	vector<pair<int, int> > d(n);
	for (int i=0;i<n;++i){
		cin >> d[i].first;
	}
	for (int i=0;i<n;++i){
		cin >> d[i].second;
	}
	d.push_back(make_pair(l, 0));
	dp[0][0] = 0;
	for (int i=1;i<=n;++i){
		int nxt = i+1==n?l:d[i+1].first;
		for (int j=0;j<i;++j){
			for (int k=0;k<=j;++k){
				if (dp[i-k-1][j-k] == -1) continue;
				// not remove
				int valn = dp[i-k-1][j-k] + (d[i].first - d[i-k-1].first) * d[i-k-1].second;
				if (dp[i][j] == -1 || valn < dp[i][j]){
					// cout << i << " " << j << " " << k << " " <<  valn << " " << dp[i][j][0] << endl;
					dp[i][j] = valn;
				}
			}
		}
	}
	int ans = 1000000000;
	for (int k=0;k<=k1;++k){
		if (dp[n][k] == -1) continue;
		ans = min(ans, dp[n][k]);
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