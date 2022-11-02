#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
const int MAX_N = 2000 + 10;
int L[MAX_N][MAX_N], R[MAX_N][MAX_N];
bool used[MAX_N][MAX_N];
int n, m, nQ;
int ans;
pair<int, int> ret;
int x, y;

void check(int r, int c) {
	if (r < 0 || r > n || c < 0 || c > m)
		return;
	int d = abs(r - x) + abs(y - c);
	if (d < ans) {
		ans = d;
		ret = make_pair(r, c);
	} else if (d == ans) {
		ret = min(ret, make_pair(r, c));
	}
}

int main() {
	cin >> n >> m >> nQ;
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			L[r][c] = c;
			R[r][c] = c;
		}
	}
	for (int i = 0; i < nQ; ++i) {
		scanf("%d%d", &x, &y), --x, --y;
		ans = n + m + 2;
		for (int d = 0; d <= ans; ++d) {
			if (x - d >= 0) {
				check(x - d, L[x - d][y]);
				check(x - d, R[x - d][y]);
			}
			if (x + d < n) {
				check(x + d, L[x + d][y]);
				check(x + d, R[x + d][y]);
			}
		}
		printf("%d %d\n", ret.first + 1, ret.second + 1);
		x = ret.first, y = ret.second;
		used[x][y] = true;
		L[x][y] = y == 0 ? -1 : L[x][y - 1];
		for (int j = y; j < m && used[x][j]; ++j) {
			L[x][j] = L[x][y];
		}
		R[x][y] = y == m - 1 ? -1 : R[x][y + 1];
		for (int j = y; j >= 0 && used[x][j]; --j) {
			R[x][j] = R[x][y];
		}
	}
	return 0;
}