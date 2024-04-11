/*
 * b.cpp
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
#include <queue>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

int n, m;
char mp[1600][1600];
pair<int, int> what[1600][1600];

const int DR[] = { 1, -1, 0, 0 }, DC[] = { 0, 0, 1, -1 };

bool inBorder(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < m;
}

bool vis[1600][1600];

queue<int> que;

int main() {
	cin >> n >> m;
	for (int r = 0; r < n; ++r) {
		scanf("%s", mp[r]);
	}

	memset(vis, 0, sizeof vis);

	int sr, sc;

	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			if (mp[r][c] == 'S') {
				sr = r, sc = c;
				break;
			}
		}
	}

	que.push(sr), que.push(sc);
	vis[sr][sc] = true;
	what[sr][sc] = make_pair(sr, sc);

	while (!que.empty()) {
		int r = que.front();
		que.pop();
		int c = que.front();
		que.pop();
		for (int d = 0; d < 4; ++d) {
			int nr = r + DR[d], nc = c + DC[d];
			pair<int, int> key = make_pair(nr, nc);

			int ar = (nr % n + n) % n, ac = (nc % m + m) % m;

			if (mp[ar][ac] == '#')
				continue;
			if (!vis[ar][ac]) {
				vis[ar][ac] = true;
				what[ar][ac] = key;
				que.push(nr), que.push(nc);
			} else {
//				cout << what[nr][c].first << " " << what[nr][nc].second << " " << key.first << " " << key.second << endl;
				if (what[ar][ac] != key) {
					puts("Yes");
					return 0;
				}
			}
		}
	}

	puts("No");
	return 0;
}