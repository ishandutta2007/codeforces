/*
 * b.cpp
 *
 *  Created on: 2012-3-27
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <utility>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

const int MAX_N = 200 + 10;

double dp[MAX_N][MAX_N][MAX_N];
double p[MAX_N];
int a[MAX_N];

pair<int, double> ps[MAX_N];

int main() {
	int n, l, k;
	cin >> n >> l >> k;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		p[i] /= 100;
	}
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		ps[i] = make_pair(a[i], p[i]);
	}
	sort(ps, ps + n);
	reverse(ps, ps + n);
	for (int i = 0; i < n; ++i) {
		p[i] = ps[i].second;
		a[i] = ps[i].first;
	}
	memset(dp, 0, sizeof dp);
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (i >= l)
				dp[n][i][j] = 1;
		}
	}
	for (int nxt = n - 1; nxt >= 0; --nxt) {
		for (int win = 0; win <= n; ++win) {
			for (int cap = 0; cap <= n; ++cap) {
				double&c = dp[nxt][win][cap];
				if (a[nxt] == -1) {
					if (cap > 0)
						c += dp[nxt + 1][win + 1][cap - 1] * p[nxt];
					c += dp[nxt + 1][win][cap] * (1 - p[nxt]);
				} else {
					c += dp[nxt + 1][win + 1][min(cap + a[nxt], n)] * p[nxt];
					c += dp[nxt + 1][win][cap] * (1 - p[nxt]);
				}
			}
		}
	}

	printf("%0.10lf\n", dp[0][0][min(n,k)]);
	return 0;
}