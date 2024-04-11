/*
 * d.cpp
 *
 *  Created on: 2012-4-27
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

const int MAX_N = 3000 + 10, MAX_M = 300 + 10;

typedef long double ld;

ld prob[MAX_N][MAX_M];
int n, m;

struct Data {
	vector<ld> dp[MAX_N];
	ld p[MAX_N];
	int k; //nxt
	ld upd;

	//>=0's prob

	void init(int me) {
		for (int i = 0; i < n; ++i) {
			p[i] = prob[i][me];
		}
//		cout << endl;
		k = 0;
		for (int i = 0; i <= n; ++i) {
			dp[i].resize(1, 1); //>=0 :1
		}
	}

	void addK() {
		++k;
		for (int i = 0; i <= n; ++i) {
			dp[i].push_back(0);
		}

		//>=k dp[i][k-1],dp[i][k]
		for (int i = 1; i <= n; ++i) {
			//>=k-1 -> >=k
			//=k-1
			ld eq = (k - 1 > 0 ? dp[i - 1][k - 2] : 0) * p[i - 1] + dp[i - 1][k - 1] * (1 - p[i - 1]);
//			cout << "EQ:" << eq << endl;
			dp[i][k] = dp[i][k - 1] - eq;
			dp[i][k - 1] = eq;
		}
		upd = dp[n][k];
	}
};

Data ds[MAX_M];

int main() {
	cin >> n >> m;
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			int x;
			scanf("%d", &x);
			prob[r][c] = x / 1000.0;
		}
	}

	for (int c = 0; c < m; ++c) {
		ds[c].init(c);
		ds[c].addK();
	}

	ld ans = 0;
	for (int i = 0; i < n; ++i) {
		int mx = -1;
		ld mxupd = -1;
		for (int c = 0; c < m; ++c) {
			if (ds[c].upd > mxupd) {
				mxupd = ds[c].upd;
				mx = c;
			}
		}
		ans += mxupd;
		ds[mx].addK();
	}
	printf("%0.10lf\n", (double) ans);
	return 0;
}