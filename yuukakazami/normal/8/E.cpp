#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
//first one is always 0
typedef long long int64;
const int MAX_N = 50 + 10;
int n;
int64 k;
//a<rev(a),a<flip(a),a<rev(flip(a))
//011 001

int64 countWays(string s) {
	int64 dp[MAX_N][2][2]; //l,same,same_rev
	bool can[MAX_N][2];
	for (int i = 0; i < n; ++i) {
		can[i][0] = s[i] == '0' || s[i] == '?';
		can[i][1] = s[i] == '1' || s[i] == '?';
	}
	memset(dp, 0, sizeof dp);
	dp[0][1][1] = 1;
	int l, r;
	for (l = 0, r = n - 1; l <= r; ++l, --r)
		for (int s1 = 0; s1 < 2; ++s1) {
			for (int s2 = 0; s2 < 2; ++s2) {
				for (int a = 0; a < 2; ++a)
					if (can[l][a]) {
						for (int b = 0; b < 2; ++b)
							if (can[r][b]) {
								int rb = 1 - b;
								if (s1 && a > b)
									continue;
								if (s2 && a > rb)
									continue;
								if (l == r && a != b)
									continue;
								if (l == 0 && a == 1)
									continue;
								int ns1 = s1 && (a == b);
								int ns2 = s2 && (a == rb);
								dp[l + 1][ns1][ns2] += dp[l][s1][s2];
							}
					}
			}
		}
	int64 ans = dp[l][0][0] + dp[l][0][1] + dp[l][1][0] + dp[l][1][1];
	return ans;
}

int main() {
	cin >> n >> k;
	++k;
	string s(n, '?');
	int64 tot = countWays(s);
	if (tot < k) {
		puts("-1");
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2; ++j) {
			s[i] = '0' + j;
			int64 c = countWays(s);
			if (c >= k)
				break;
			k -= c;
		}
	}
	cout << s << endl;
	return 0;
}