#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 15054, M = 300, INF = 0x3f3f3f3f;

int n;
int a[N], b[N];
int lo[N][M], hi[N][M];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void down(int &x, const int y) {x > y ? x = y : 0;}
inline int min(const int x, const int y) {return x < y ? x : y;}
inline int max(const int x, const int y) {return x < y ? y : x;}

struct pb_ds {
	int x[N];
	inline void init() {memset(x, 63, n << 2);}
	inline void update(int h, int v) {for (; h < n; h |= h + 1) down(x[h], v);}
	inline int query(int h) {int s = INF; for (; h >= 0; h &= h + 1, --h) down(s, x[h]); return s;}
} rlo[M], rhi[M], Lo[M], Hi[M];

void work() {
	int i, j, x, _, ans = 1;
	cin >> n;
	for (i = n - 1; i >= 0; --i) cin >> x, a[i] = n - x;
//	for (i = 0; i < n; ++i) fprintf(stderr, "%d%c", a[i], i == n - 1 ? 10 : 32);
	for (_ = 0; _ < 2; ++_) {
		for (j = 1; j < M; ++j) rlo[j].init(), rhi[j].init(), Lo[j].init(), Hi[j].init();
		for (i = 0; i < n; ++i) {
			memset(lo[i], 63, sizeof lo[i]),
			memset(hi[i], 192, sizeof hi[i]);
			if (_ || !i) lo[i][1] = hi[i][1] = a[i];
			for (j = 1; j <= i && j + 1 < M; ++j)
				lo[i][j + 1] = Lo[j].query(n - a[i] - 1),
				hi[i][j + 1] = n - Hi[j].query(a[i]) - 1;
			for (j = 1; j <= i && j + 1 < M; ++j) {
				down(lo[i][j + 1], rhi[j].query(n - a[i] - 1));
				up(hi[i][j + 1], n - rlo[j].query(a[i]) - 1);
				if (lo[i][j + 1] < n || hi[i][j + 1] >= 0) up(ans, j + 1);
			}
			for (j = 1; j <= i + 1 && j < M; ++j) {
				if (lo[i][j] < n) Lo[j].update(n - a[i] - 1, lo[i][j]);
				if (hi[i][j] >= 0) Hi[j].update(a[i], n - hi[i][j] - 1);
			}
			for (j = 1; j <= i + 1 - _ && j < M; ++j) {
				x = i - j + 1 - _;
				if (hi[x][j] >= 0) rhi[j].update(n - hi[x][j] - 1, a[x]);
				if (lo[x][j] < n) rlo[j].update(lo[x][j], n - a[x] - 1);
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}