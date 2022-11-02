/*
 * e.cpp
 *
 *  Created on: 2012-4-28
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

const int MAX_N = 2000 + 10;

int n;
bool mp[MAX_N][MAX_N];

bool vis[MAX_N][MAX_N];

vector<int> rs, cs;

int tot;

void dfs(int r, int c) {
	if (vis[r][c])
		return;
	vis[r][c] = true;
	++tot;

	bool atBorder = false;

	for (int dx = -1; dx <= 1; ++dx) {
		for (int dy = -1; dy <= 1; ++dy) {
			int nr = r + dx, nc = c + dy;
			if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
				if (!mp[nr][nc]) {
					atBorder = true;
				} else {
					dfs(nr, nc);
				}
			}
		}
	}
	if (atBorder) {
		rs.push_back(r);
		cs.push_back(c);
	}
}

int center(vector<int>&a) {
	return (*max_element(a.begin(), a.end()) + *min_element(a.begin(), a.end())) / 2;
}

void genMap() {
	bool tmp[MAX_N][MAX_N];
	memcpy(tmp, mp, sizeof mp);
	memset(mp, 0, sizeof mp);
	for (int r = 3; r + 3 < n; ++r) {
		for (int c = 3; c + 3 < n; ++c) {
			int cnt = 0;
			for (int dx = -3; dx <= 3; ++dx) {
				for (int dy = -3; dy <= 3; ++dy) {
					cnt += tmp[r + dx][c + dy];
				}
			}
			if (cnt >= 24) {
				mp[r][c] = true;
			}
		}
	}
}

int main() {

//	double dp[50][50] = { };
//	dp[0][0] = 1;
//	for (int i = 0; i < 49; ++i) {
//		for (int j = 0; j < 49; ++j) {
//			dp[i + 1][j] += dp[i][j] / 5;
//			dp[i + 1][j + 1] += dp[i][j] / 5 * 4;
//		}
//	}
//
//	for (int j = 49 - 1; j >= 0; --j) {
//		dp[49][j] += dp[49][j + 1];
//	}
//
//	for (int i = 0; i <= 49; ++i) {
//		cout << i << ":" << dp[49][i] << endl;
//	}

//	freopen("in", "r", stdin);
	cin >> n;
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < n; ++c) {
			cin >> mp[r][c];
		}
	}

	genMap();

	memset(vis, 0, sizeof vis);
	int nS = 0, nC = 0;
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < n; ++c) {
			if (!vis[r][c] && mp[r][c]) {
				tot = 0, rs.clear(), cs.clear();
				dfs(r, c);

				if (tot <= 30)
					continue;

				int cr = center(rs), cc = center(cs);

				static double ds[MAX_N * MAX_N];
				int cnt = 0;
				for (int i = 0; i < rs.size(); ++i) {
					ds[cnt++] = hypot(cr - rs[i], cc - cs[i]);
				}
				double mx = *max_element(ds, ds + cnt);
				for (int i = 0; i < cnt; ++i) {
					ds[i] /= mx;
				}
				double avg = accumulate(ds, ds + cnt, 0.0) / cnt;

				double t = 0;
				for (int i = 0; i < cnt; ++i) {
					t += (ds[i] - avg) * (ds[i] - avg);
				}
				t /= cnt;
				t = sqrt(t);
//				cout << t << endl;
				if (t < 0.06)
					++nC;
				else
					++nS;
			}
		}
	}

	cout << nC << " " << nS << endl;
	return 0;
}