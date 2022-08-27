#include <bits/stdc++.h>
#define N 2010

typedef long long ll;

int R, C, x;
ll a[N], b[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void down(ll &x, const ll y) {x > y ? x = y : 0;}

int main() {
	int i, j, k, ht, ans = 0; ll fy, cm;
	scanf("%d%d", &R, &C);
	for (i = 1; i <= R; ++i) scanf("%lld", a + i), a[i] += a[i - 1];
	for (i = 1; i <= C; ++i) scanf("%lld", b + i), b[i] += b[i - 1];
	scanf("%d", &x);
	for (i = 1; i <= R; ++i) {
		fy = INT_MAX;
		for (j = 0; j <= R - i; ++j) down(fy, a[j + i] - a[j]);
		cm = x / fy; ht = 0;
		for (k = j = 0; j <= C; ++j) {
			for (; k <= C && b[k] - b[j] <= cm; ++k);
			up(ht, k - j - 1);
		}
//		printf("%d %d\n", i, ht);
		up(ans, i * ht);
	}
	printf("%d\n", ans);
	return 0;
}