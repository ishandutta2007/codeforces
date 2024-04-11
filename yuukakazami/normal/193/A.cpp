/*
 * a.cpp
 *
 *  Created on: 2012-6-12
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
char mp[55][55];

bool vis[55][55];

const int DR[] = { -1, 1, 0, 0 }, DC[] = { 0, 0, 1, -1 };

void dfs(int r, int c) {
	if (r < 0 || r >= n || c < 0 || c >= m || vis[r][c] || mp[r][c] != '#')
		return;
	vis[r][c] = true;
	for (int d = 0; d < 4; ++d) {
		dfs(r + DR[d], c + DC[d]);
	}
}

bool isCon() {
	memset(vis, 0, sizeof vis);
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			if (mp[r][c] == '#') {
				dfs(r, c);

				for (int nr = 0; nr < n; ++nr) {
					for (int nc = 0; nc < m; ++nc) {
						if (mp[nr][nc] == '#' && !vis[nr][nc])
							return false;
					}
				}

				return true;
			}
		}
	}

	return true;
}

int main() {
	cin >> n >> m;
	for (int r = 0; r < n; ++r) {
		scanf("%s", mp[r]);
	}
	int cnt = 0;
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			if (mp[r][c] == '#')
				++cnt;
		}
	}

	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			if (mp[r][c] == '#') {
				mp[r][c] = '.';
				if (!isCon()) {
					puts("1");
					return 0;
				}
				mp[r][c] = '#';
			}
		}
	}

	if (cnt == 1) {
		puts("-1");
	} else {
		int mind = INT_MAX;
		for (int r = 0; r < n; ++r) {
			for (int c = 0; c < m; ++c)
				if (mp[r][c] == '#') {
					int cur = 0;
					for (int dr = -1; dr <= 1; ++dr)
						for (int dc = -1; dc <= 1; ++dc)
							if ((dr == 0) ^ (dc == 0)) {
								int nr = r + dr, nc = c + dc;
								if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
									if (mp[nr][nc] == '#') {
										cur++;
									}
								}
							}
					mind = min(mind, cur);
				}
		}
		if (cnt - mind == 1)
			puts("-1");
		else
			cout << mind << endl;
	}
	return 0;
}