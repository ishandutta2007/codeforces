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

int main() {
//	freopen("in", "r", stdin);
	cin >> n;
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < n; ++c) {
			cin >> mp[r][c];
		}
	}

	memset(vis, 0, sizeof vis);
	int nS = 0, nC = 0;
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < n; ++c) {
			if (!vis[r][c] && mp[r][c]) {
				tot = 0, rs.clear(), cs.clear();
				dfs(r, c);

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
				if (t < 0.04)
					++nC;
				else
					++nS;
			}
		}
	}

	cout << nC << " " << nS << endl;
	return 0;
}