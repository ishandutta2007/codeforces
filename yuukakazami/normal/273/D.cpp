#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
const int MOD = int(1e9) + 7;
const int MAX_N = 150 + 10;
typedef int MAT[MAX_N][MAX_N];
void addIt(int&x, int c) {
	x += c;
	if (x >= MOD)
		x -= MOD;
}

struct Sum {
	MAT data;

	void prepare(MAT a, int n, int m) {
		memset(data, 0, sizeof data);
		for (int r = 0; r < n; ++r) {
			for (int c = 0; c < m; ++c) {
				int t = a[r][c];
				addIt(t, data[r][c + 1]);
				addIt(t, data[r + 1][c]);
				addIt(t, MOD - data[r][c]);
				data[r + 1][c + 1] = t;
			}
		}
	}

	int calc(int r1, int r2, int c1, int c2) { //[r1,r2] [c1,c2]
		int ret = 0;
		addIt(ret, data[r2 + 1][c2 + 1]);
		addIt(ret, MOD - data[r2 + 1][c1]);
		addIt(ret, MOD - data[r1][c2 + 1]);
		addIt(ret, data[r1][c1]);
		return ret;
	}
};

MAT dp[MAX_N][2][2]; //INC,DEC
int n, m;
const int INC = 0, DEC = 1;

Sum sum[2][2];

int main() {
	cin >> n >> m;
	for (int c1 = 0; c1 < m; ++c1) {
		for (int c2 = c1; c2 < m; ++c2) {
			dp[1][INC][INC][c1][c2] = 1;
		}
	}

	for (int i = 2; i <= n; ++i) {

		for (int a = 0; a < 2; ++a) {
			for (int b = 0; b < 2; ++b) {
				sum[a][b].prepare(dp[i - 1][a][b], m, m);
			}
		}

		for (int c1 = 0; c1 < m; ++c1) {
			for (int c2 = c1; c2 < m; ++c2) {
				//inc,inc
				dp[i][INC][INC][c1][c2] = sum[INC][INC].calc(c1, c2, c1, c2);
				//inc,dec
				{
					int&r = dp[i][INC][DEC][c1][c2];
					r = sum[INC][INC].calc(c1, c2, c2 + 1, m - 1);
					addIt(r, sum[INC][DEC].calc(c1, c2, c2, m - 1));
				}
				//dec,inc
				{
					int&r = dp[i][DEC][INC][c1][c2];
					r = sum[INC][INC].calc(0, c1 - 1, c1, c2);
					addIt(r, sum[DEC][INC].calc(0, c1, c1, c2));
				}
				//dec,dec
				{
					int&r = dp[i][DEC][DEC][c1][c2];
					r = sum[INC][INC].calc(0, c1 - 1, c2 + 1, m - 1);
					addIt(r, sum[INC][DEC].calc(0, c1 - 1, c2, m - 1));
					addIt(r, sum[DEC][INC].calc(0, c1, c2 + 1, m - 1));
					addIt(r, sum[DEC][DEC].calc(0, c1, c2, m - 1));
				}
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int tot = 0;
		for (int a = 0; a < 2; ++a) {
			for (int b = 0; b < 2; ++b) {
				for (int c1 = 0; c1 < m; ++c1) {
					for (int c2 = c1; c2 < m; ++c2) {
						addIt(tot, dp[i][a][b][c1][c2]);
					}
				}
			}
		}
		addIt(ans, 1LL * tot * (n + 1 - i) % MOD);
	}
	cout << ans << endl;
	return 0;
}