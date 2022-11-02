#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
const int MAX_N = 50 + 10;
int n, p;
int a[MAX_N];
double dp[MAX_N][MAX_N][MAX_N]; //i,cnt,p
double f[MAX_N];
double comb[MAX_N][MAX_N];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= i; ++j) {
			comb[i][j] = (!i || !j) ? 1 : comb[i - 1][j - 1] + comb[i - 1][j];
		}
	}
	cin >> p;
	dp[0][0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			for (int k = 0; k <= p; ++k) {
				double c = dp[i][j][k];
				if (c < 0.5)
					continue;
				//ignore
				dp[i + 1][j][k] += c;
				//use
				if (k + a[i] <= p)
					dp[i + 1][j + 1][k + a[i]] += c;
			}
		}
	}
//the prob E>=i
	f[0] = 1;
	double ans = 0;
	for (int i = 1; i <= n; ++i) {
		f[i] = 0;
		for (int j = 0; j <= p; ++j) {
			f[i] += dp[n][i][j];
		}
		f[i] /= comb[n][i];
		ans += f[i];
	}
	printf("%0.10lf\n", ans);
	return 0;
}