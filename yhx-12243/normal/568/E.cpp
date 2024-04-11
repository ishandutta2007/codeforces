#include <bits/stdc++.h>

const int N = 100054, INF = 0x3f3f3f3f;

int n, m, K;
int a[N], b[N], c[N];
int cu = 0, used[N];
int len = 1, f[N], D[N];
int from[N], last[N], pred[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline int min(const int x, const int y) {return x < y ? x : y;}

int main() {
	int i, j, k, l, r, empty, avai;
	scanf("%d", &n), a[++n] = INF;
	for (i = 1; i < n; ++i) scanf("%d", a + i);
	scanf("%d", &m);
	for (i = 0; i < m; ++i) scanf("%d", b + i);
	std::sort(b, b + m), memcpy(c, b, m << 2), K = std::unique(c, c + m) - c;
	*f = 1, *pred = *from = -1;
	memset(last, -1, sizeof last), last[1] = 0;
	for (i = 1; i <= n; ++i)
		if (~a[i])
			f[i] = j = std::lower_bound(D + 1, D + (len + 1), a[i]) - D,
			from[i] = last[j - 1], pred[i] = last[j], last[j] = i, D[j] = a[i], up(len, j);
		else
			for (j = len + 1, k = K - 1; k >= 0; --k) {
				for (; j > 1 && D[j - 1] >= c[k]; --j);
				D[j] = c[k], last[j] = -1, up(len, j);
			}
	for (i = n; i > 0; ) {
		if (~from[i]) {i = from[i]; continue;}
		empty = 0, r = std::lower_bound(c, c + K, a[i]) - c;
		for (j = i - 1; j >= 0; --j)
			if (!~a[j]) ++empty;
			else if (a[j] < a[i]) {
				l = std::upper_bound(c, c + K, a[j]) - c;
				avai = min(r - l, empty);
				assert(f[i] >= f[j] + avai + 1);
				if (f[i] == f[j] + avai + 1) {
					for (; i > j && r > l; ~a[i] || (used[cu++] = a[i] = c[--r]), --i);
					i = j; break;
				}
			}
		assert(~j);
	}
	std::sort(used, used + cu);
	K = std::set_difference(b, b + m, used, used + cu, c) - c, std::reverse(c, c + K);
	for (i = 1; i < n; ++i) ~a[i] || (a[i] = c[--K]);
	for (i = 1; i < n; ++i) printf("%d%c", a[i], i == n ? 10 : 32);
	return 0;
}