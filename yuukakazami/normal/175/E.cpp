/*
 * cd.cpp
 *
 *  Created on: 2012-4-20
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <cmath>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

int nf, ne, ns;
double rf, re, rs, df, de;

double ans;

double is(double l, double r, double L, double R) {
	l = max(l, L);
	r = min(r, R);
	if (l <= r)
		return r - l;
	else
		return 0;
}

const int MAX = 13;

int num[MAX];
int atk[MAX];

double common[MAX][MAX][2];

double eval(int at) {
	static double cst[MAX][2];

	for (int i = 0; i < at; ++i) {
		for (int j = 0; j < 2; ++j) {
			cst[i][j] = j ? 2 * re * de : 2 * rf * df;
			for (int k = 0; k < at; ++k) {
				cst[i][j] += num[k] * common[i][k][j];
			}
		}
	}

	static double dp[MAX * 2 + 1][21][21];

	for (int i = 0; i <= at * 2; ++i) {
		for (int j = 0; j <= nf; ++j) {
			for (int k = 0; k <= ne; ++k) {
				dp[i][j][k] = -2;
			}
		}
	}

	dp[0][0][0] = 0;
	int cur = 0;

	for (int i = 0; i < at; ++i) {
		for (int j = num[i]; j < 2; ++j) {
			for (int a = 0; a <= nf; ++a) {
				for (int b = 0; b <= ne; ++b) {
					double c = dp[cur][a][b];
					if (c < -1)
						continue;
					if (a < nf)
						dp[cur + 1][a + 1][b] = max(dp[cur + 1][a + 1][b], c + cst[i][0]);
					if (b < ne)
						dp[cur + 1][a][b + 1] = max(dp[cur + 1][a][b + 1], c + cst[i][1]);
					dp[cur + 1][a][b] = max(dp[cur + 1][a][b], c);
				}
			}
			++cur;
		}
	}

	return dp[cur][nf][ne];
}

int tot;

void rec(int at, int cs) {
	if (at == MAX) {
		if (!cs)
			ans = max(ans, eval(at));
		return;
	}
	for (int i = 0; i <= cs && i <= 2; ++i) {
		num[at] = i;
		rec(at + 1, cs - i);
	}
}

int main() {
	cin >> nf >> ne >> ns >> rf >> re >> rs >> df >> de;
	ans = 0;
	rf = sqrt(max(rf * rf - 1, 0.0));
	re = sqrt(max(re * re - 1, 0.0));
	rs = sqrt(max(rs * rs - 1, 0.0));

	for (int i = 0; i < MAX; ++i) {
		for (int j = 0; j < MAX; ++j) {
			common[i][j][0] = is(i - rs, i + rs, j - rf, j + rf) * df;
			common[i][j][1] = is(i - rs, i + rs, j - re, j + re) * de;
		}
	}

	rec(0, ns);
//	cout << tot << endl;
	printf("%0.10lf\n", ans);
	return 0;
}