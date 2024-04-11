/*
 * cd4.cpp
 *
 *  Created on: 2011-11-4
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
int n, m;
int p[200][200];
typedef long long int64;
int r[20000], c[20000];
const int64 MAX = int64(1e18) + 1;
void aj(int64&x) {
	if (x > MAX) {
		x = MAX;
	}
}

char M[200][200];

int64 eval(int64 k) {
	int w[300];
	for (int sum = 0; sum < n + m - 1; ++sum) {
		bool has[3] = { };
		for (int r = 0; r < n; ++r) {
			int c = sum - r;
			if (c >= 0 && c < m) {
				if (M[r][c] == '(')
					has[0] = true;
				else if (M[r][c] == ')') {
					has[1] = true;
				}
			}
		}
		if (has[0] && has[1]) {
			return 0;
		}
		if (has[0] || has[1]) {
			w[sum] = has[0] ? 0 : 1;
		} else {
			w[sum] = -1;
		}
	}

	static int64 dp[300][300];
	memset(dp, 0, sizeof dp);
	dp[0][0] = 1;
	for (int i = 0; i < n + m - 1; ++i) {
		for (int j = 0; j <= n + m; ++j) {
			if (!dp[i][j])
				continue;
			int64 ch = dp[i][j];
			if (w[i] != 1) //(
				aj(dp[i + 1][j + 1] += ch);
			if (w[i] != 0 && j > 0)
				aj(dp[i + 1][j - 1] += ch);
		}
	}
	return dp[n + m - 1][0];
}

int main() {
	cin >> n >> m;
	int64 k;
	cin >> k;
	--k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int p;
			cin >> p;
			r[p - 1] = i;
			c[p - 1] = j;
			M[i][j] = '?';
		}
	}

	for (int i = 0; i < n * m; ++i) {
		int R = r[i], C = c[i];
		if (M[R][C] == '?') {
			M[R][C] = '(';
			int64 ev = eval(k);
			if (k < ev) {
				int sum = R + C;
				for (int rr = 0; rr < n; ++rr) {
					int cc = sum - rr;
					if (cc >= 0 && cc < m) {
						M[rr][cc] = '(';
					}
				}
				continue;
			}
			k -= ev;
			M[R][C] = ')';
			int sum = R + C;
			for (int rr = 0; rr < n; ++rr) {
				int cc = sum - rr;
				if (cc >= 0 && cc < m) {
					M[rr][cc] = ')';
				}
			}
			continue;
		}
	}

	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			cout << M[r][c];
		}
		cout << endl;
	}
	return 0;
}