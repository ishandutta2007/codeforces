#include <bits/stdc++.h>

const int N = 200054;

int n;
char s[N], t[N], rs[N];

void work() {
	int i, m, l, r, cnt;
	scanf("%d%s", &n, s), t[n] = 0;
	for (m = 48; m < 58; ++m) {
		l = -1, r = n, cnt = 0;
		for (i = 0; i < n; ++i) {
			if (s[i] < m) t[i] = 49, r = i;
			else if (s[i] > m) t[i] = 50, ~l || (l = i);
		}
		for (i = 0; i < n; ++i) if (s[i] == m) {
			if (i < l) t[i] = 50;
			else if (i > r) t[i] = 49;
			else i = n + 1;
		}
		if (i == n + 1) continue;
		for (i = 0; i < n; ++i)
			if (t[i] == 49) rs[cnt++] = s[i];
		for (i = 0; i < n; ++i)
			if (t[i] == 50) rs[cnt++] = s[i];
		if (cnt == n && std::is_sorted(rs, rs + n)) {
			puts(t); return;
		}
	}
	puts("-");
}

int main() {
	int T;
	for (scanf("%d", &T); T; --T) work();
	return 0;
}