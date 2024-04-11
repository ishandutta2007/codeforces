#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 1000 + 10;

const int DR[] = { 0, 0, 1, -1 }, DC[] = { 1, -1, 0, 0 };

char map[MAX_N][MAX_N];
int n, m;

int dist[MAX_N][MAX_N][4];
bool inQue[MAX_N][MAX_N][4];

queue<int> que;

const int INF = INT_MAX / 4;

int main() {
	cin >> n >> m;
	for (int r = 0; r < n; ++r) {
		scanf(" ");
		scanf("%s", map[r]);
	}

	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			for (int d = 0; d < 4; ++d) {
				dist[r][c][d] = INF;
				inQue[r][c][d] = false;
			}
		}
	}

	dist[0][0][0] = 0;
	inQue[0][0][0] = true;
	que.push(0);
	que.push(0);
	que.push(0);

	while (!que.empty()) {
		int r = que.front();
		que.pop();
		int c = que.front();
		que.pop();
		int d = que.front();
		que.pop();

		int cst = dist[r][c][d];
		inQue[r][c][d] = false;

		//move
		int nr = r + DR[d], nc = c + DC[d];
		if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
			if (cst < dist[nr][nc][d]) {
				dist[nr][nc][d] = cst;
				if (!inQue[nr][nc][d]) {
					inQue[nr][nc][d] = true;
					que.push(nr), que.push(nc), que.push(d);
				}
			}
		}

		if (map[r][c] == '#') {
			for (int nd = 0; nd < 4; ++nd) {
				int ncst = cst + 1;
				if (ncst < dist[r][c][nd]) {
					dist[r][c][nd] = ncst;
					if (!inQue[r][c][nd]) {
						inQue[r][c][nd] = true;
						que.push(r), que.push(c), que.push(nd);
					}
				}
			}
		}
	}

	int ans = dist[n - 1][m - 1][0];
	if (ans == INF)
		cout << -1 << endl;
	else
		cout << ans << endl;
	return 0;
}