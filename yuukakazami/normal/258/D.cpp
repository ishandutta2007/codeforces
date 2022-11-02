#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

const int MAX_N = 1000 + 10;
int n, m;
int a[MAX_N], b[MAX_N];
int p[MAX_N];

double dp[MAX_N][MAX_N];
double tmp[MAX_N][MAX_N];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> a[i] >> b[i];
		--a[i], --b[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			dp[i][j] = 1;
		}
	}

	for (int i = m - 1; i >= 0; --i) {
		int a = ::a[i], b = ::b[i];
		//(a,j)
		for (int j = 0; j < n; ++j) {
			tmp[a][j] = dp[a][j] / 2;
			if ((a < j) == (b < j))
				tmp[a][j] += dp[b][j] / 2;
			else
				tmp[a][j] += (1 - dp[b][j]) / 2;
			tmp[j][a] = tmp[a][j];
		}
		//(b,j)
		for (int j = 0; j < n; ++j) {
			tmp[b][j] = dp[b][j] / 2;
			if ((a < j) == (b < j))
				tmp[b][j] += dp[a][j] / 2;
			else
				tmp[b][j] += (1 - dp[a][j]) / 2;
			tmp[j][b] = tmp[b][j];
		}
		tmp[a][b] = tmp[b][a] = dp[a][b] / 2 + (1 - dp[b][a]) / 2;
		for (int j = 0; j < n; ++j) {
			dp[a][j] = dp[j][a] = tmp[a][j];
			dp[b][j] = dp[j][b] = tmp[b][j];
		}
	}

	double ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (p[j] < p[i])
				ans += 1 - dp[j][i];
			else
				ans += dp[j][i];
		}
	}
	printf("%0.10lf\n", ans);
	return 0;
}