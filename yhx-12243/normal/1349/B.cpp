#include <bits/stdc++.h>

const int N = 100054;

int n, K;
int a[N];

inline void down(int &x, const int y) {x > y ? x = y : 0;}

bool work() {
	int i, s = 0, min = 0; bool r = false;
	scanf("%d%d", &n, &K);
	for (i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		if (a[i] < K) a[i] = -1;
		else if (a[i] == K) a[i] = 1, r = true;
		else a[i] = 1;
	}
	if (!r) return false;
	if (n == 1) return true;
	min = 0;
	for (i = 1; i < n; ++i) {
		if (s + a[i] + a[i + 1] > min) return true;
		down(min, s += a[i]);
	}
	return false;
}

int main() {
	int T;
	for (scanf("%d", &T); T; --T) puts(work() ? "yes" : "no");
	return 0;
}