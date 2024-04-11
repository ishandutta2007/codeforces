#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 50;
char map[MAX_N][MAX_N];
int n, m;
int d[MAX_N][MAX_N];
int DR[] = { 0, 0, -1, 1 }, DC[] = { -1, 1, 0, 0 };

int calc(int r, int c) {
	deque<int> que;
	que.push_back(r);
	que.push_back(c);
	que.push_back(0);
	fill(d[0], d[n], -1);
	d[r][c] = 0;
	while (!que.empty()) {
		int r = que.front();
		que.pop_front();
		int c = que.front();
		que.pop_front();
		int st = que.front();
		que.pop_front();
		for (int di = 0; di < 4; ++di) {
			int nr = r + DR[di], nc = c + DC[di];
			if (nr >= 0 && nr < n && nc >= 0 && nc < m && d[nr][nc] == -1) {
				if (map[r][c] == map[nr][nc]) {
					if (st == 0) {
						que.push_front(0);
						que.push_front(nc);
						que.push_front(nr);
						d[nr][nc] = d[r][c];
					}
				} else if (st == 1) {
					que.push_back(nr);
					que.push_back(nc);
					que.push_back(0);
					d[nr][nc] = d[r][c] + 1;
				}
			}
		}
		if (st == 0) {
			que.push_back(r);
			que.push_back(c);
			que.push_back(1);
		}
	}

	int ret = -1;
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			if (map[r][c] == 'B')
				ret = max(ret, d[r][c]);
		}
	}
	return ret;
}

int main() {
	cin >> n >> m;
	for (int r = 0; r < n; ++r) {
		scanf("%s", map[r]);
	}
	int ans = n * m;
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			ans = min(ans, calc(r, c));
		}
	}
	cout << ans + 1 << endl;
	return 0;
}