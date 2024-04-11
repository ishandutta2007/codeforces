#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
typedef long long int64;
const int MAX_N = 5000 + 10;
int n, m;
int v[MAX_N];

int dp[MAX_N][MAX_N];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		double x;
		cin >> v[i];
		--v[i];
		cin >> x;
	}

	memset(dp, -1, sizeof dp);
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int c = dp[i][j];
			if (c == -1)
				continue;
			dp[i + 1][j] = max(dp[i + 1][j], c + (j == v[i]));
			dp[i][j + 1] = max(dp[i][j + 1], c);
		}
	}

	int ans = *max_element(dp[n], dp[n] + m);
	cout << n - ans << endl;
	return 0;
}