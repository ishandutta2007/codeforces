#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

const int MAX_N = 500 + 10;

int dp[3][MAX_N][MAX_N];

int a[MAX_N][MAX_N];

int n, m;

int sumr[MAX_N][MAX_N];

int sumc[MAX_N][MAX_N];

int getr(int r, int a, int b) {
	return sumr[r][b] - (a ? sumr[r][a - 1] : 0);
}

int getc(int c, int a, int b) {
	return sumc[c][b] - (a ? sumc[c][a - 1] : 0);
}

int main() {
	int ans = INT_MIN;

	cin >> n >> m;
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			scanf("%d", a[r] + c);
			sumr[r][c] = sumc[c][r] = a[r][c];
		}
	}

	for (int r = 0; r < n; ++r) {
		partial_sum(sumr[r], sumr[r] + m, sumr[r]);
	}

	for (int c = 0; c < m; ++c) {
		partial_sum(sumc[c], sumc[c] + n, sumc[c]);
	}

	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			dp[0][r][c] = a[r][c];
		}
	}

	for (int r = 0; r + 3 <= n; ++r) {
		for (int c = 0; c + 3 <= m; ++c) {
			dp[1][r][c] = getr(r, c, c + 2) + getr(r + 2, c, c + 2) + a[r + 1][c + 2];
			ans = max(ans, dp[1][r][c]);
		}
	}

	int cur = 2;

	for (int k = 5; k <= n && k <= m; k += 2) {
		//update to next
		//cur
		int p1 = (cur + 2) % 3, p2 = (cur + 1) % 3;

		for (int r = 0; r + k <= n; ++r) {
			for (int c = 0; c + k <= m; ++c) {
				dp[cur][r][c] = dp[p2][r + 2][c + 2] + getr(r, c, c + k - 1) + getc(c + k - 1, r + 1, r + k - 1) + getr(r + k - 1, c, c + k - 2) + getc(c, r + 2, r + k - 2) + a[r + 2][c + 1];
				ans = max(ans, dp[cur][r][c]);
			}
		}

		cur = (cur + 1) % 3;
	}

	cout << ans << endl;
	return 0;
}