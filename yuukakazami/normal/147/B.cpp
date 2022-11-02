#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
const int MAX_N = 300 + 10, INF = ~0U >> 3;
int n, m;

struct Matrix {
	int a[MAX_N][MAX_N];
	Matrix() {
		fill(a[0], a[MAX_N], -INF);
	}
};

Matrix operator*(const Matrix&a, const Matrix&b) {
	Matrix ret;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int c = -INF;
			for (int k = 0; k < n; ++k) {
				c = max(c, a.a[i][k] + b.a[k][j]);
			}
			ret.a[i][j] = c;
		}
	}
	return ret;
}
const int MAX_LOG = 10;
Matrix pow2[MAX_LOG];
Matrix one, zero;

bool check(const Matrix&a) {
	for (int i = 0; i < n; ++i) {
		if (a.a[i][i] > 0)
			return true;
	}
	return false;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int i, j, ij, ji;
		cin >> i >> j >> ij >> ji;
		--i, --j;
		one.a[i][j] = ij, one.a[j][i] = ji;
	}
	for (int i = 0; i < n; ++i) {
		one.a[i][i] = zero.a[i][i] = 0;
	}
	pow2[0] = one;
	int mxlog = 0;
	for (int i = 0; (1 << i) <= n; ++i) {
		pow2[i + 1] = pow2[i] * pow2[i];
		mxlog = i + 1;
	}
	if (!check(pow2[mxlog])) {
		puts("0");
		return 0;
	}
	Matrix cur = zero;
	int ans = 0;
	for (int i = mxlog; i >= 0; --i) {
		Matrix ncur = cur * pow2[i];
		if (!check(ncur)) {
			cur = ncur;
			ans += 1 << i;
		}
	}
	cout << ans + 1 << endl;
	return 0;
}