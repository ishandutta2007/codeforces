#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
int dp[201][40010][2];
int h[201];
int a, b;
const int INF = ~0U >> 2;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	cin >> a >> b;
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= a; ++j) {
			for (int k = 0; k < 2; ++k) {
				dp[i][j][k] = INF;
			}
		}
	}
	dp[0][0][0] = 0;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= a; ++j) {
			int ej = sum - j;
			if (ej > b)
				continue;

			for (int k = 0; k < 2; ++k) {
				int c = dp[i][j][k];
				if (c == INF)
					continue;
				//put 0
				int nc = c;
				if (i > 0 && k != 0) {
					nc += min(h[i], h[i - 1]);
				}
				if (j + h[i] <= a)
					dp[i + 1][j + h[i]][0] = min(dp[i + 1][j + h[i]][0], nc);
				//put 1
				nc = c;
				if (i > 0 && k != 1) {
					nc += min(h[i], h[i - 1]);
				}
				dp[i + 1][j][1] = min(dp[i + 1][j][1], nc);
			}
		}
		sum += h[i];
	}
	int ans = INF;
	for (int j = 0; j <= a; ++j) {
		int ej = sum - j;
		if (ej > b)
			continue;
		ans = min(ans, dp[n][j][0]);
		ans = min(ans, dp[n][j][1]);
	}
	if (ans >= INF / 2)
		ans = -1;
	cout << ans << endl;
	return 0;
}