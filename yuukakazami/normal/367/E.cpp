#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int MOD = 1000000007;
int n, m, x;

vector<vector<int> > am, nam; //cntL,totL

void add(int&x, int c) {
	x += c;
	if (x >= MOD)
		x -= MOD;
}

vector<vector<int> > build(int n, int m) {
	return vector<vector<int> >(n, vector<int>(m, 0));
}

int main() {
	cin >> n >> m >> x;
	--x;
	if (n > m) {
		cout << 0 << endl;
		return 0;
	}
//	dp = vector<vector<int> >(m + 1, vector<int>(n + 1, 0));
//	dp[0][0] = 1;
	am = build(n + 2, n + 2);
	am[0][0] = 1;

	for (int i = 0; i < m; ++i) {
		nam = build(n + 2, n + 2);
		for (int j = 0; j <= n; ++j) {
			for (int k = 0; k <= n; ++k) {
				int way = am[j][k];
				if (way == 0)
					continue;
				//put L here
				add(nam[j + 1][k + 1], way);
				//put L and R here
				add(nam[j][k + 1], way);
				//put R here
				if (j > 0 && i != x)
					add(nam[j - 1][k], way);
				//ignore
				if (i != x)
					add(nam[j][k], way);
			}
		}
		am = nam;
	}
	long long ans = am[0][n];
	for (int i = 1; i <= n; ++i) {
		ans *= i;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}