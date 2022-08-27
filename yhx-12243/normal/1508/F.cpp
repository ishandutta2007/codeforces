#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 25400, M = N * 4;

int n, m, ans;
int p[N], lm[N];
int lpre[N], lsuf[N], rpre[N], rsuf[N];

inline void linkA(int l, int r) {rsuf[l] = r, lpre[r] = l, ++ans;}
inline void linkD(int l, int r) {rpre[l] = r, lsuf[r] = l, ++ans;}
inline void cutA(int l, int r) {ans -= rsuf[l] == r && lpre[r] == l;}
inline void cutD(int l, int r) {ans -= rpre[l] == r && lsuf[r] == l;}

inline void update(int l, int r) {
	if (p[l] < p[r]) {
		if (p[l] > p[lpre[r]]) cutA(l, rsuf[l]), cutA(lpre[r], r), linkA(l, r);
	} else {
		if (p[r] > p[rpre[l]]) cutD(l, rpre[l]), cutD(lsuf[r], r), linkD(l, r);
	}
}

int main() {
	int i, l, r;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> m;
	for (i = 1; i <= n; ++i) cin >> p[i], lm[i] = i;
	for (; m; --m) {
		cin >> l >> r, i = std::upper_bound(lm + 1, lm + (n + 1), l) - lm;
		for (; i <= r; ++i) for (; lm[i] > l; update(--lm[i], i));
		cout << ans << '\n';
	}
	return 0;
}