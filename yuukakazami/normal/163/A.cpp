#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
string s, t;
int n, m;

const int MOD = 1000000007;
const int MAX_N = 5000 + 10;

int dp[MAX_N][MAX_N];

void addIt(int&x, int c) {
	x += c;
	if (x >= MOD)
		x -= MOD;
}

int main() {
	cin >> s >> t;

	for (int i = s.size() - 1; i >= 0; --i) {
		for (int j = t.size(); j >= 0; --j) {
			dp[i][j] = 0;
			if (j < t.size() && s[i] == t[j]) {
				addIt(dp[i][j], dp[i + 1][j + 1]);
				addIt(dp[i][j], 1);
			}
			addIt(dp[i][j], dp[i][j + 1]);
		}
	}

	int ans = 0;
	for (int i = 0; i <= s.size(); ++i) {
		addIt(ans, dp[i][0]);
	}
	cout << ans << endl;
	return 0;
}