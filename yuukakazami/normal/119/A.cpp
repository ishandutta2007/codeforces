#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
int main() {
	int a, b, n;
	int dp[1000][2];
	cin >> a >> b >> n;
	dp[0][0] = dp[0][1] = 0;
	for (int i = 1; i <= n; ++i) {
		dp[i][0] = !dp[i - gcd(a, i)][1];
		dp[i][1] = !dp[i - gcd(b, i)][0];
	}
	cout << 1 - dp[n][0] << endl;
	return 0;
}