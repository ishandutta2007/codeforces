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
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

const int MAX_N = 2000 + 10;

int n;
bool mp[MAX_N][MAX_N];

bool vis[MAX_N][MAX_N];

set<int> rs, cs;

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

	rs.insert(r), cs.insert(c);
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
				int exp = (*rs.rbegin() - *rs.begin() + 1) * (*cs.rbegin() - *cs.begin() + 1);
//				cout << tot << " " << exp << endl;
				if (tot == exp)
					++nS;
				else
					++nC;
			}
		}
	}

	cout << nC << " " << nS << endl;
	return 0;
}