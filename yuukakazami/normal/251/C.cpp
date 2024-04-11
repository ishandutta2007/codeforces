#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
typedef long long int64;
int L, k;
int64 a, b;
const int INF = ~0U >> 3;

int64 solve(int64 a, int64 b) {
	static int dp[int(1e6)];
	int64 n = b - a + 1;
	fill(dp, dp + n, INF);
	dp[b - a] = 0;
	for (int64 i = b; i > a; --i) {
		int64 x = i - a;
		dp[x - 1] = min(dp[x - 1], dp[x] + 1);
		for (int j = 2; j <= k; ++j) {
			int64 nx = x - i % j;
			if (nx >= 0)
				dp[nx] = min(dp[nx], dp[x] + 1);
		}
	}
	return dp[0];
}

int main() {
	L = 1;
	cin >> b >> a >> k;
	for (int i = 2; i <= k; ++i) {
		L = L / __gcd(L, i) * i;
	}
	int64 x = b / L * L;
	if (x <= a) {
		cout << solve(a, b) << endl;
	} else {
		int64 y = ((a - 1) / L + 1) * L;
		int64 t = (x - y) / L;
		cout << solve(a, y) + solve(0, L) * t + solve(x, b) << endl;
	}
	return 0;
}