#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 100 + 10;
const int MAX_K = 7;

int dp[MAX_N][MAX_N][1 << MAX_K];
int prev[MAX_N][MAX_N][1 << MAX_K];
int n, m, k;
int a[MAX_N][MAX_N], id[MAX_N][MAX_N];
const int dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, -1, 1 };

const int INF = ~0U >> 3;
bool map[MAX_N][MAX_N];

void build(int r, int c, int msk) {
	int w = id[r][c];
	int me = dp[r][c][msk];
	map[r][c] = true;

	if (w != -1 && (msk >> w & 1) && dp[r][c][msk ^ (1 << w)] == me) {
		build(r, c, msk ^ (1 << w));
		return;
	}

	if (prev[r][c][msk] != -1) {
		int pr = prev[r][c][msk] / m;
		int pc = prev[r][c][msk] % m;
		build(pr, pc, msk);
		return;
	}

	for (int nmsk = msk; nmsk > 0; (--nmsk) &= msk)
		if (nmsk < msk && dp[r][c][nmsk] + dp[r][c][msk ^ nmsk] - a[r][c] == me) {
			build(r, c, nmsk);
			build(r, c, nmsk ^ msk);
			return;
		}
}

int main() {
	cin >> n >> m >> k;
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			cin >> a[r][c];
		}
	}
	memset(id, -1, sizeof id);
	for (int i = 0; i < k; ++i) {
		int r, c;
		cin >> r >> c;
		id[--r][--c] = i;
	}

	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			for (int i = 0; i < (1 << k); ++i) {
				dp[r][c][i] = INF;
				prev[r][c][i] = -1;
			}
		}
	}

	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			dp[r][c][0] = a[r][c];
		}
	}

	for (int msk = 0; msk < (1 << k); ++msk) {
		for (int r = 0; r < n; ++r) {
			for (int c = 0; c < m; ++c) {
				for (int nmsk = msk; nmsk > 0; (--nmsk) &= msk)
					if (nmsk < msk)
						dp[r][c][msk] = min(dp[r][c][msk],
								dp[r][c][nmsk] + dp[r][c][msk ^ nmsk] - a[r][c]);
			}
		}

		priority_queue<pair<int, int> > que;
		for (int r = 0; r < n; ++r) {
			for (int c = 0; c < m; ++c) {
				que.push(make_pair(-dp[r][c][msk], r * m + c));
			}
		}

		static bool used[MAX_N][MAX_N];
		memset(used, false, sizeof used);

		while (!que.empty()) {
			int me = que.top().second;
			int r = me / m, c = me % m;
			que.pop();
			if (used[r][c])
				continue;
			used[r][c] = true;
			int cost = dp[r][c][msk];
			for (int d = 0; d < 4; ++d) {
				int nr = r + dx[d], nc = c + dy[d];
				if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
					int ncost = cost + a[nr][nc];
					if (ncost < dp[nr][nc][msk]) {
						dp[nr][nc][msk] = ncost;
						prev[nr][nc][msk] = r * m + c;
						que.push(make_pair(-ncost, nr * m + nc));
					}
				}
			}
		}

		for (int r = 0; r < n; ++r) {
			for (int c = 0; c < m; ++c) {
				if (id[r][c] != -1)
					dp[r][c][msk | (1 << id[r][c])] = min(dp[r][c][msk | (1 << id[r][c])],
							dp[r][c][msk]);
			}
		}
	}

	int ans = INF, br = -1, bc = -1;
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			if (dp[r][c][(1 << k) - 1] < ans) {
				ans = dp[r][c][(1 << k) - 1];
				br = r, bc = c;
			}
		}
	}

	memset(map, 0, sizeof map);
	build(br, bc, (1 << k) - 1);
	cout << ans << endl;
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			cout << (map[r][c] ? 'X' : '.');
		}
		cout << endl;
	}
	return 0;
}