#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

const int MAX_N = 5000 + 10;
int n, m;
int a[MAX_N], b[MAX_N], score[MAX_N];
int g[MAX_N], scoreg[MAX_N];

int calc(int x) {
	int ret = 0;
	for (int i = 2; i * i <= x; ++i) {
		while (x % i == 0) {
			if (binary_search(b, b + m, i))
				--ret;
			else
				++ret;
			x /= i;
		}
	}
	if (x > 1) {
		if (binary_search(b, b + m, x))
			--ret;
		else
			++ret;
	}
	return ret;
}

int dp[MAX_N];
const int INF = ~0U >> 2;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	a[n++] = 1;
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	sort(b, b + m);
	for (int i = 0; i < n; ++i) {
		score[i] = calc(a[i]);
	}
	g[0] = a[0];
	for (int i = 1; i < n; ++i) {
		g[i] = __gcd(g[i - 1], a[i]);
	}
	for (int i = 0; i < n; ++i) {
		scoreg[i] = calc(g[i]);
	}
	dp[0] = 0;
	fill(dp + 1, dp + n + 1, -INF);

	for (int i = 0; i < n; ++i) {
		int sum = 0;
		for (int j = i; j < n; ++j) {
			//dp[i] -> dp[j+1]
			//[i,j]
			sum += score[j];
			dp[j + 1] = max(dp[j + 1], dp[i] + sum - scoreg[j] * (j - i + 1));
		}
	}

	cout << dp[n] << endl;
}