#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
const int MAX_N = 30 + 10;
int n, m;
char map[MAX_N][MAX_N], out[MAX_N][MAX_N];
bool used[MAX_N][MAX_N];

int id[MAX_N];
int which[MAX_N][MAX_N];
int nSquares;
bool u[7][7];
int ans;

void work() {
	memset(used, 0, sizeof used);
	memset(u, 0, sizeof u);

	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			if (!used[r][c] && map[r][c] != '.') {
				if (r + 1 < n && map[r + 1][c] == map[r][c]) { //vertical!
					int x = id[which[r][c]], y = id[which[r + 1][c]];
					if (x > y)
						swap(x, y);
//					cout << x << " " << y << endl;
					if (u[x][y])
						return;
					u[x][y] = true;
					used[r][c] = used[r + 1][c] = true;
					continue;
				}
				if (c + 1 < m && map[r][c] == map[r][c + 1]) { //hor!
					int x = id[which[r][c]], y = id[which[r][c + 1]];
					if (x > y)
						swap(x, y);
					if (u[x][y])
						return;
					u[x][y] = true;
					used[r][c] = used[r][c + 1] = true;
					continue;
				}
			}
		}
	}

	if (ans == 0) {
		for (int r = 0; r < n; ++r) {
			for (int c = 0; c < m; ++c) {
				if (map[r][c] == '.')
					out[r][c] = '.';
				else
					out[r][c] = '0' + id[which[r][c]];
			}
			out[r][m] = 0;
		}
	}
	ans++;
}

void rec(int i, int nId) {
	if (i == nSquares) {
		work();
		return;
	}
	//pair with before
	if (id[i] != -1) {
		rec(i + 1, nId);
		return;
	}
	for (int j = 0; j < nSquares; ++j) {
		if (id[j] == -1 && j != i) {
			id[i] = id[j] = nId;
			rec(i + 1, nId + 1);
			id[i] = id[j] = -1;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int r = 0; r < n; ++r) {
		scanf("%s", map[r]);
	}
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c)
			if (!used[r][c] && map[r][c] != '.') {
				for (int rr = r; rr < r + 2; ++rr) {
					for (int cc = c; cc < c + 2; ++cc) {
						used[rr][cc] = true;
						which[rr][cc] = nSquares;
					}
				}
				++nSquares;
			}
	}

	memset(id, -1, sizeof id);
	ans = 0;
	rec(0, 0);
	for (int i = 0; i < 7; ++i) {
		ans *= i + 1;
	}
	cout << ans << endl;
	for (int r = 0; r < n; ++r) {
		cout << out[r] << endl;
	}
	return 0;
}