#include <bits/stdc++.h>
#define N 510000

typedef long long ll;

int n;
int d[N];
ll suf[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}

int solve() {
	int i, j = n, ret = 0; ll lhs = 0, rhs, fy;
	suf[n + 1] = 0;
	for (i = n; i; --i) suf[i] = suf[i + 1] + d[i];
	for (i = 1; i <= n; ++i) {
		for (up(j, i); i < j && d[j] < i; --j);
		lhs += d[i];
		rhs = i * (i - 1ll) + (ll)(j - i) * i + suf[j + 1];
		if ((fy = lhs - rhs) > 0) {
			if (fy > i) puts("-1"), exit(0);
			up(ret, (int)fy);
		}
	}
	return ret;
}

int main() {
	int i, odev = 0, min, max;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) scanf("%d", d + i), odev ^= d[i];
	std::sort(d + 1, d + (n + 1), std::greater <int> ());
	min = solve();
	min += (min ^ odev) & 1;
	for (i = 1; i <= n; ++i) d[i] = n - d[i];
	std::reverse(d + 1, d + (n + 1));
	max = n - solve();
	max -= (max ^ odev) & 1;
	if (min > max) return puts("-1"), 0;
	for (; min <= max; min += 2) printf("%d%c", min, min == max ? 10 : 32);
	return 0;
}