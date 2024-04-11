#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
const int MAX_N = 400 + 10, MAX_VALUE = MAX_N * MAX_N;
int a[MAX_N][MAX_N], n, m;
short up[MAX_N][MAX_N][MAX_N]; //row,L,R

int lastrow[MAX_VALUE], mark[MAX_VALUE], cmark;

void reset() {
	++cmark;
}

int get(int x) {
	if (mark[x] != cmark) {
		return -1;
	}
	return lastrow[x];
}

void put(int x, int r) {
	mark[x] = cmark;
	lastrow[x] = r;
}

int main() {
	cin >> n >> m;
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			scanf("%d", a[r] + c);
		}
	}
	for (int L = 0; L < m; ++L) {
		for (int R = L; R < m; ++R) {
			for (int r = 0; r < n; ++r) {
				up[r][L][R] = -1;
			}
		}
	}

	for (int c = 0; c < m; ++c) {
		reset();
		for (int i = 0; i < n; ++i) {
			up[i][c][c] = max(up[i][c][c], (short) get(a[i][c]));
			put(a[i][c], i);
		}
	}

	for (int L = 0; L < m; ++L) {
		for (int R = L + 1; R < m; ++R) {
			reset();
			for (int i = 0; i < n; ++i) {
				put(a[i][R], i);
				up[i][L][R] = max(up[i][L][R], (short) get(a[i][L]));
			}
			reset();
			for (int i = 0; i < n; ++i) {
				put(a[i][L], i);
				up[i][L][R] = max(up[i][L][R], (short) get(a[i][R]));
			}
		}
	}

	int ans = 0;

	for (int L = m - 1; L >= 0; --L) {
		for (int R = L; R < m; ++R) {
			//[L,R]
			for (int r = 0; r < n; ++r) {
				if (L < R) {
					up[r][L][R] = max(up[r][L][R], up[r][L + 1][R]);
					up[r][L][R] = max(up[r][L][R], up[r][L][R - 1]);
				}
				if (up[r][L][R] < r - 1)
					up[r][L][R] = max(up[r][L][R], up[r - 1][L][R]);
				int ret = (R - L + 1) * (r - up[r][L][R]);
				ans = max(ans, ret);
			}
		}
	}

	cout << ans << endl;
}