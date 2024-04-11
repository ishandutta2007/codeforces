#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
const int MAX_N = int(1e6) + 10;
int dp[MAX_N], n;

int main() {
	cin >> n;
	dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		int x = i;
		dp[i] = 1 << 30;
		while (x > 0) {
			int d = x % 10;
			dp[i] = min(dp[i], dp[i - d] + 1);
			x /= 10;
		}
	}
	cout << dp[n] << endl;
	return 0;
}