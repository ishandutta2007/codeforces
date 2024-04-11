/*
 * e.cpp
 *
 *  Created on: 2012-10-2
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <cmath>
#include <iomanip>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
const int MAX_N = 1000 + 10;
int n, m;
int a[MAX_N], h[MAX_N];
vector<int> val;
vector<int> have[MAX_N];
typedef long double ld;
ld dp[MAX_N][MAX_N]; //i,nthrow
ld cnt[MAX_N][MAX_N];
ld p[MAX_N][MAX_N];
ld comb[MAX_N][MAX_N];

int main() {
	for (int r = 0; r < MAX_N; ++r) {
		for (int c = 0; c <= r; ++c) {
			comb[r][c] = (r == 0 || c == 0) ? 1 : comb[r - 1][c] + comb[r - 1][c - 1];
		}
	}
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			int x;
			scanf("%d", &x);
			have[i].push_back(x);
			val.push_back(x);
		}
	}
	sort(val.rbegin(), val.rend());
	int cut = val[n - 1];
	int sumA = 0;
	for (int i = 0; i < m; ++i) {
		for (vector<int>::iterator e = have[i].begin(); e != have[i].end(); ++e) {
			if (*e > cut)
				++a[i];
			if (*e == cut)
				++h[i];
		}
		sumA += a[i];
	}
	for (int i = 0; i < m; ++i) {
		for (int j = a[i]; j <= a[i] + h[i]; ++j) {
			int A = a[i], H = h[i], O = have[i].size() - A - H;
			p[i][j] = comb[H][j - A] / comb[A + H + O][j];
		}
	}
	memset(dp, 0, sizeof dp);
	memset(cnt, 0, sizeof cnt);
	cnt[0][0] = 1;
	dp[0][0] = 1;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j <= n; ++j) {
			ld c = dp[i][j];
			if (fabs(c) > 1e-12) {
				for (int k = a[i]; k <= a[i] + h[i] && j + k <= n; ++k) {
					dp[i + 1][j + k] += c * p[i][k];
				}
			}
			c = cnt[i][j];
			if (fabs(c) > 1e-12) {
				for (int k = a[i]; k <= a[i] + h[i] && j + k <= n; ++k) {
					cnt[i + 1][j + k] += c;
				}
			}
		}
	}
//	printf("%0.15lf\n", (double) ());
	cout.setf(ios::fixed);
	cout << setprecision(15) << dp[m][n] / cnt[m][n] << endl; //0.10
	return 0;
}