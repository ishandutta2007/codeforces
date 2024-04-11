#include <bits/stdc++.h>
#define N 100054

typedef long long ll;

struct point {
	int x, y;
	point * read() {scanf("%d%d", &x, &y); return this;}
	inline bool operator < (const point &B) const {return x < B.x || (x == B.x && y < B.y);}
	inline bool operator == (const point &B) const {return x == B.x && y == B.y;}
} p[N], q[N];

int n;
int col[N];
ll aX = 0, aY = 0;

inline int min(const int x, const int y) {return x < y ? x : y;}
inline int max(const int x, const int y) {return x < y ? y : x;}
inline void up(ll &x, const ll y) {x < y ? x = y : 0;}

ll solve() {
	int i, h = n / 2, cur;
	if (n & 1) {
		for (i = 0; i < n; ++i) col[i] = (q[i].x < p[h].x ? 0 : q[i].x > p[h].x ? 1 : -1);
		for (cur = -1; ; ) {
			for (i = 0; i < h; ++i) if (~col[i]) {if (~cur && cur != col[i]) break; cur = col[i];} if (i < h) break;
			for (++i; i < n; ++i) if (~col[i]) {if (~cur && cur == col[i]) break; cur = !col[i];} break;
		}
		bool flag = col[h] == -1 && !(q[h] == q[h - 1] || q[h] == q[h + 1]);
		return aY + (i == n || !flag ? 0 : 2ll * max(q[h - 1].y - q[h].y, q[h].y - q[h + 1].y));
	} else {
		for (i = 0; i < n; ++i) col[i] = (q[i].x < p[h].x ? 0 : q[i].x > p[h - 1].x ? 1 : -1);
		for (cur = -1; ; ) {
			for (i = 0; i < h; ++i) if (~col[i]) {if (~cur && cur != col[i]) break; cur = col[i];} if (i < h) break;
			for (; i < n; ++i) if (~col[i]) {if (~cur && cur == col[i]) break; cur = !col[i];} break;
		}
		return aY + (i == n ? 0 : 2ll * (q[h - 1].y - q[h].y));
	}
}

int main() {
	int i; ll ans;
#ifndef ONLINE_JUDGE
	freopen("distance.in", "r", stdin);
	freopen("distance.out", "w", stdout);
#endif
	scanf("%d", &n);
	for (i = 0; i < n; ++i) q[i] = *p[i].read();
	std::sort(p, p + n);
	std::sort(q, q + n, [] (const point &A, const point &B) {return A.y < B.y || (A.y == B.y && A.x < B.x);});
	for (i = 1; i < n; ++i) aX += 2ll * min(i, n - i) * (p[i].x - p[i - 1].x);
	for (i = 1; i < n; ++i) aY += 2ll * min(i, n - i) * (q[i].y - q[i - 1].y);
	ans = aX + solve();
	for (i = 0; i < n; ++i) std::swap(p[i].x, q[i].y), std::swap(p[i].y, q[i].x);
	std::swap(aX, aY);
	ans = std::max(ans, aX + solve());
	printf("%lld\n", ans);
	return 0;
}