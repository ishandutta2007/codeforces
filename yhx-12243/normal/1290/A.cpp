#include <bits/stdc++.h>

const int N = 3600;

int n, K, pos;
int a[N], b[N];
int que[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void down(int &x, const int y) {x > y ? x = y : 0;}
inline int max(const int x, const int y) {return x < y ? y : x;}

void work() {
	int i, g, ans = 0, h = 0, t = 0;
	scanf("%d%d%d", &n, &pos, &K);
	for (i = 0; i < n; ++i) scanf("%d", a + i);
	for (i = 0; i < pos; ++i) b[i] = max(a[i], a[i + n - pos]);
	down(K, pos - 1), g = pos - K;
	for (i = 0; i < pos; ++i) {
		for (; h < t && que[h] <= i - g; ++h);
		for (; h < t && b[que[t - 1]] >= b[i]; --t);
		if (que[t++] = i, i >= g - 1) up(ans, b[que[h]]);
	}
	printf("%d\n", ans);
}

int main() {
	int T;
	for (scanf("%d", &T); T; --T) work();
	return 0;
}