#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int a[1001][1001], x[1001], y[1001];

inline long long sqr(long long x) {
	return x * x;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		x[i] = 0;
		for (int j = 0; j < m; ++j) {
			scanf("%d", a[i] + j);
			x[i] += a[i][j];
		}
	}
	for (int j = 0; j < m; ++j) {
		y[j] = 0;
		for (int i = 0; i < n; ++i)
			y[j] += a[i][j];
	}
	int xres = 0;
	long long xsum = 1000000000000000000;
	for (int i = 0; i <= n; ++i) {
		long long sc = 0;
		for (int j = 0; j < n; ++j)
			sc += (long long) x[j] * sqr((long long) (j >= i ? 4 * (j - i) + 2 : 4 * (i - j - 1) + 2));
		if (sc < xsum) {
			xres = i;
			xsum = sc;
		}
	}
	int yres = 0;
	long long ysum = 1000000000000000000;
	for (int i = 0; i <= m; ++i) {
		long long sc = 0;
		for (int j = 0; j < m; ++j)
			sc += (long long) y[j] * sqr((long long) (j >= i ? 4 * (j - i) + 2 : 4 * (i - j - 1) + 2));
		if (sc < ysum) {
			yres = i;
			ysum = sc;
		}
	}
	cout << xsum + ysum << '\n' << xres << ' ' << yres;
}