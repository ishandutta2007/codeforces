#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

const int N = 100054;

int n, w, q;
int a[N], b[N], min[N], max[N], ans[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void down(int &x, const int y) {x > y ? x = y : 0;}

int main() {
	int i, j;
	scanf("%d%d%d", &n, &w, &q);
	for (i = 0; i < n; ++i) scanf("%d", a + i);
	for (i = 0; i < q; ++i) scanf("%d", b + i), b[i] = w - b[i], min[i] = max[i] = *a;
	for (j = 1; j < n; ++j)
		for (i = 0; i < q; ++i) {
			up(max[i], a[j]), down(min[i], a[j]);
			if (max[i] - min[i] > b[i]) ++ans[i], min[i] = max[i] = a[j];
		}
	for (i = 0; i < q; ++i) printf("%d\n", ans[i]);
	return 0;
}