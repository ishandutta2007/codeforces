#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

const int N = 200054;

int n, q;
int a[N];

inline void down(int &x, const int y) {x > y ? x = y : 0;}

int main() {
	int i, x, l, r, d, min, Ld, Rd; bool succ;
	scanf("%d%*d", &n);
	for (i = 0; i < n; ++i) scanf("%d", a + i);
	i = 0, a[n] = INT_MAX;
	for (scanf("%d", &q); q; --q) {
		for (scanf("%d", &x); i < n && a[i] < x; ++i);
		if (a[i] == x && i && a[i - 1] == x - 1) {printf("%.12lg\n", M_PI); continue;}
		if (a[i] == x || (i && a[i - 1] == x - 1)) {printf("%.12lg\n", M_PI_2); continue;}
		if (min = a[i] - x, i) down(min, x - 1 - a[i - 1]);
		l = i - 1, r = i, Ld = Rd = -1, succ = false;
		for (d = 1; d <= 2 * min; ++d) {
			for (; l >= 0 && a[l] >= x - d - 1; --l) Ld = x - 1 - a[l];
			for (; r < n && a[r] <= x + d; ++r) Rd = a[r] - x;
			if ((Ld == d || Rd == d) && Ld + Rd >= 2 * d - 1) {
				printf("%.12lg\n", 2 * atan(1. / d)), succ = true; break;
			}
		}
		if (!succ) printf("%.12lg\n", atan(1. / min));
	}
	return 0;
}