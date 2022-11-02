#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <bitset>
using namespace std;
const int MAX_N = 20000 + 10;
const int CAN = 15000;
int dp[2][MAX_N];
bitset<MAX_N>* how[MAX_N * 2];
bitset<MAX_N> tmp[CAN];
int n, m, p;
int x[MAX_N], y[MAX_N];
int f(int a, int b) {
	int r = x[a] + y[b];
	if (r >= p)
		r -= p;
	return r;
}

string out;

void work(int n, int m, bool fst = false) {
	memset(dp, -1, sizeof dp);
	dp[0][0] = 0;
	memset(how, 0, sizeof how);
	for (int i = 0; i < CAN; ++i) {
		how[n + m - i] = tmp + i;
	}
	for (int i = 0; i < n + m; ++i) {
		memset(dp[(i + 1) % 2], -1, sizeof dp[(i + 1) % 2]);
		int*cur = dp[i % 2], *nxt = dp[(i + 1) % 2];
		for (int j = 0; j <= i && j <= n; ++j) {
			int k = i - j;
			if (k > m)
				continue;
			int c = cur[j];
			if (c == -1)
				continue;
			static bitset<MAX_N> tt;
			bitset<MAX_N>&h = how[i + 1] != 0 ? *how[i + 1] : tt;
			if (j < n) {
				int nc = c + f(j + 1, k);
				if (nc > nxt[j + 1]) {
					nxt[j + 1] = nc;
					h[j + 1] = 1;
				}
			}
			if (k < m) {
				int nc = c + f(j, k + 1);
				if (nc > nxt[j]) {
					nxt[j] = nc;
					h[j] = 0;
				}
			}
		}
	}
	int i = n + m, j = n;
	while (i > 0) {
		if (how[i] == 0)
			break;
		if ((*how[i])[j])
			out += "C", --j;
		else
			out += "S";
		--i;
	}
	if (fst) {
		int ans = f(0, 0) + dp[(n + m) % 2][n];
		cout << ans << endl;
	}
	if (i > 0)
		work(j, i - j);
}

int main() {
//	cout << sizeof(tmp) / (1024 * 1024.0) << endl;
	cin >> n >> m >> p;
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
		x[i] %= p;
	}
	for (int i = 0; i < m; ++i) {
		cin >> y[i];
		y[i] %= p;
	}
//	n = 20000, m = 20000, p = 10;
	--n, --m;
	work(n, m, true);
	reverse(out.begin(), out.end());
	cout << out << endl;
	return 0;
}