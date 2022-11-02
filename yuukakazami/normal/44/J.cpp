#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
int n, m;
const int MAX_N = 1000 + 10;
char map[MAX_N][MAX_N];
int id[MAX_N][MAX_N], nId;
vector<int> rs[MAX_N * MAX_N], cs[MAX_N * MAX_N];

bool put(int r, int c, char w) {
	if (r < 0 || r > n || c < 0 || c > m)
		return false;
	if (map[r][c] != w) {
		return false;
	}
	id[r][c] = nId;
	rs[nId].push_back(r);
	cs[nId].push_back(c);
	map[r][c] = '.';
	return true;
}

bool ver(int r, int c) {
	for (int nr = r; nr < r + 3; ++nr) {
		if (!put(nr, c, "wbw"[nr - r]))
			return false;
	}
	nId++;
	return true;
}

bool hor(int r, int c) {
	for (int nc = c; nc < c + 3; ++nc) {
		if (!put(r, nc, "wbw"[nc - c]))
			return false;
	}
	nId++;
	return true;
}

bool work() {
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			if (map[r][c] == 'b') {
				if (!hor(r, c - 1))
					return false;
			}
		}
		for (int c = 0; c < m; ++c) {
			if (map[r][c] == 'w')
				if (!ver(r, c))
					return false;
		}
	}

	return true;
}

int col[MAX_N * MAX_N];
const int DI[] = { -1, 1, 0, 0 }, DJ[] = { 0, 0, -1, 1 };

int main() {
	cin >> n >> m;
	for (int r = 0; r < n; ++r) {
		scanf("%s", map[r]);
	}
	memset(id, -1, sizeof id);
	if (!work())
		puts("NO");
	else {
		puts("YES");
		memset(col, -1, sizeof col);
		static bool used[26];
		for (int i = 0; i < nId; ++i) {
			memset(used, 0, sizeof used);
			for (int it = 0; it < rs[i].size(); ++it) {
				int r = rs[i][it], c = cs[i][it];
				for (int d = 0; d < 4; ++d) {
					int nr = r + DI[d], nc = c + DJ[d];
					if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
						if (id[nr][nc] != -1 && id[nr][nc] < id[r][c]) {
							used[col[id[nr][nc]]] = true;
						}
					}
				}
			}
			for (int j = 0; j < 26; ++j) {
				if (!used[j]) {
					col[i] = j;
					break;
				}
			}
		}
		for (int r = 0; r < n; ++r) {
			for (int c = 0; c < m; ++c) {
				if (id[r][c] == -1)
					putchar('.');
				else
					putchar('a' + col[id[r][c]]);
			}
			puts("");
		}
	}
	return 0;
}