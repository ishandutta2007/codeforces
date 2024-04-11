#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int MAX_N = 1000 + 10, MAX_T = 100 + 10;
int n, T;
int dp[MAX_T][MAX_N];
vector<int> at[MAX_T];

int main() {
	cin >> n >> T;
	for (int i = 0; i < n; ++i) {
		int t, p;
		cin >> t >> p;
		at[T - t].push_back(p);
	}
	memset(dp, -1, sizeof dp);
	dp[0][1] = 0;
	for (int t = 0; t <= T; ++t) {
		sort(at[t].rbegin(), at[t].rend());
		static int sum[MAX_N];
		sum[0] = 0;
		for (int j = 0; j < at[t].size(); ++j) {
			sum[j + 1] = sum[j] + at[t][j];
		}
		for (int j = 0; j <= n; ++j) {
			if (dp[t][j] == -1)
				continue;
			int c = dp[t][j];
			for (int pick = 0; pick <= j && pick <= at[t].size(); ++pick) {
				int nc = c + sum[pick];
				int nj = (j - pick) * 2;
				if (nj > n)
					nj = n;
				dp[t + 1][nj] = max(dp[t + 1][nj], nc);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= n; ++i) {
		ans = max(ans, dp[T + 1][i]);
	}
	cout << ans << endl;
	return 0;
}