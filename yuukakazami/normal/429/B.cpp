#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
const int MAX_N = 1000 + 10;
int n, m;
int a[MAX_N][MAX_N];

int LU[MAX_N][MAX_N], LD[MAX_N][MAX_N], RU[MAX_N][MAX_N], RD[MAX_N][MAX_N];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", a[i] + j);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			LU[i][j] = 0;
			if (i > 0)
				LU[i][j] = max(LU[i][j], LU[i - 1][j]);
			if (j > 0)
				LU[i][j] = max(LU[i][j], LU[i][j - 1]);
			LU[i][j] += a[i][j];
		}
		for (int j = m - 1; j >= 0; --j) {
			RU[i][j] = 0;
			if (i > 0)
				RU[i][j] = max(RU[i][j], RU[i - 1][j]);
			if (j + 1 < m)
				RU[i][j] = max(RU[i][j], RU[i][j + 1]);
			RU[i][j] += a[i][j];
		}
	}

	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < m; ++j) {
			LD[i][j] = 0;
			if (i + 1 < n)
				LD[i][j] = max(LD[i][j], LD[i + 1][j]);
			if (j > 0)
				LD[i][j] = max(LD[i][j], LD[i][j - 1]);
			LD[i][j] += a[i][j];
		}
		for (int j = m - 1; j >= 0; --j) {
			RD[i][j] = 0;
			if (i + 1 < n)
				RD[i][j] = max(RD[i][j], RD[i + 1][j]);
			if (j + 1 < m)
				RD[i][j] = max(RD[i][j], RD[i][j + 1]);
			RD[i][j] += a[i][j];
		}
	}

	int ans = 0;
	for (int i = 1; i < n - 1; ++i) {
		for (int j = 1; j < m - 1; ++j) {
			//meet at (i,j)
			int tmp = LU[i - 1][j] + RD[i + 1][j] + RU[i][j + 1] + LD[i][j - 1];
			ans = max(ans, tmp);
			tmp = LU[i][j - 1] + RD[i][j + 1] + RU[i - 1][j] + LD[i + 1][j];
			ans = max(ans, tmp);
		}
	}

	cout << ans << endl;
}