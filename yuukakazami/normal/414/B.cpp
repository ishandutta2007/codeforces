#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
const int MOD = int(1e9) + 7;
const int MAX_N = 2000 + 10;
int dp[MAX_N][MAX_N]; //len,last

void addIt(int&x, int c) {
	x += c;
	if (x >= MOD)
		x -= MOD;
}

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		dp[1][i] = 1;
	}
	for (int l = 1; l < k; ++l) {
		for (int i = 1; i <= n; ++i) {
			for (int j = i; j <= n; j += i) {
				addIt(dp[l + 1][j], dp[l][i]);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
//		ans += dp[k][i];
		addIt(ans, dp[k][i]);
	}
	cout << ans << endl;
}