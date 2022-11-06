#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;


//

int main() {
	int dp[101][3];
	for (int i = 0; i < 101; ++i) {
		for (int j = 0; j < 3; ++j) {
			dp[i][j] = -1e8;
		}
	}
	dp[0][0] = 0;
	int N; cin >> N;
	vector<int>as(N);
	for (int i = 0; i < N; ++i) {
		int a; cin >> a;
		as[i] = a;
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 3; ++j) {
			dp[i + 1][0] = max(dp[i][j], dp[i + 1][0]);
			if (j == 0) {
				if (as[i] % 2 == 1) {
					dp[i + 1][1] = max(dp[i][j] + 1, dp[i + 1][1]);
				}
				if (as[i] >= 2) {
					dp[i + 1][2] = max(dp[i][j] + 1, dp[i + 1][2]);

				}
			}
			else if (j == 1) {
				if (as[i] >= 2) {
					dp[i + 1][2] = max(dp[i][j] + 1, dp[i + 1][2]);

				}
			}
			else {
				if (as[i] % 2 == 1) {
					dp[i + 1][1] = max(dp[i][j] + 1, dp[i + 1][1]);
				}
			}
		}
	}
	int ans = dp[N][0];
	ans = max(ans,dp[N][1]);
	ans = max(ans, dp[N][2]);
	cout << N - ans << endl;
	return 0;
}