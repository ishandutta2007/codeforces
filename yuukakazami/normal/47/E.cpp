#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <cmath>
using namespace std;
int n, m;
double v;
const int MAX_N = int(1e4) + 10, MAX_M = int(1e5) + 10;
double a[MAX_N], x[MAX_N], y[MAX_N];
pair<double, double> wall[MAX_M];
int perm[MAX_N];

bool cmp(int x, int y) {
	return a[x] < a[y];
}

int main() {
	cin >> n >> v;
	for (int i = 0; i < n; ++i) {
		scanf("%lf", a + i);
		perm[i] = i;
	}
	sort(perm, perm + n, cmp);
	cin >> m;
	for (int i = 0; i < m; ++i) {
		scanf("%lf%lf", &wall[i].first, &wall[i].second);
	}
	sort(wall, wall + m);
	int j = 0;
	for (int it = 0; it < n; ++it) {
		int i = perm[it];
		double vx = v * cos(a[i]), vy = v * sin(a[i]), w = vy / 4.9 * vx;
		double t, h;
		while (j < m && wall[j].first < w) {
			t = wall[j].first / vx;
			h = vy * t - 4.9 * t * t;
			if (h <= wall[j].second)
				break;
			++j;
		}
		if (j < m && wall[j].first < w)
			x[i] = wall[j].first, y[i] = h;
		else
			x[i] = w;
	}
	for (int i = 0; i < n; ++i) {
		printf("%.9f %.9f\n", x[i], y[i]);
	}
	return 0;
}