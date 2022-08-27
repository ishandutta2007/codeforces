#include <bits/stdc++.h>
#define cross(x, y, z) (((y) - (x)) ^ ((z) - (x)))

typedef long long ll;
const int N = 20054, INF = 0x3f3f3f3f;

struct vec2 {
	int x, y;
	vec2 (int x0 = 0, int y0 = 0) : x(x0), y(y0) {}
	inline vec2 operator - (const vec2 &B) const {return vec2(x - B.x, y - B.y);}
	inline ll operator * (const vec2 &B) const {return (ll)x * B.x + (ll)y * B.y;}
	inline ll operator ^ (const vec2 &B) const {return (ll)x * B.y - (ll)y * B.x;}
	inline ll norm2() const {return (ll)x * x + (ll)y * y;}
};

int n, K;
int a[N], pp[N], po[N];
int dp[2][N], *cur = *dp, *nxt = dp[1];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void down(int &x, const int y) {x > y ? x = y : 0;}

namespace hull {
	vec2 ch[N], *tail;

	inline void reset() {tail = ch;}

	void insert(const vec2 &P) {
	    if (tail != ch && tail[-1].x == P.x && tail[-1].y <= P.y) return;
		for (; tail > ch + 1 && cross(tail[-2], P, tail[-1]) <= 0; --tail);
		*tail++ = P;
	}

	int query(const vec2 &P) {
		if (ch == tail) return INF;
		int L = 0, R = tail - ch - 1, M;
		for (; L < R; M = (L + R) / 2, ch[M] * P > ch[M + 1] * P ? L = M + 1 : R = M);
		return (int)std::min<ll>(ch[L] * P, INF);
	}
}

void solve(int L, int R) {
	if (L + 1 == R) return;
	int i, j, M = (L + R) / 2, lm, rm;
	j = M, lm = rm = 0, hull::reset();
	for (i = M; i < R; ++i) {
		for (up(rm, a[i]); j > L && lm <= a[i]; )
			if (up(lm, a[--j]), cur[j] < INF) hull::insert(vec2(j, cur[j]));
		down(nxt[i], hull::query(vec2(-rm, 1)) + i * rm), pp[i] = j;
	}
	for (po[ j = M - 1 ] = a[M]; j > L; --j) up(po[j - 1] = po[j], a[j]);
	j = L, lm = rm = 0, hull::reset();
	for (i = R - 1; i >= M; --i) {
		for (; j < pp[i]; ++j) if (cur[j] < INF) hull::insert(vec2(po[j], cur[j] - j * po[j]));
		down(nxt[i], hull::query(vec2(i, 1)));
	}
	solve(L, M), solve(M, R);
}

int main() {
	int i;
	scanf("%d%d", &n, &K);
	for (i = 0; i < n; ++i) scanf("%d", a + i);
	for (*nxt = *a, i = 1; i < n; ++i) up(nxt[i] = nxt[i - 1], a[i]);
	for (i = 0; i < n; ++i) nxt[i] *= i + 1;
	for (; --K; std::swap(cur, nxt), memset(nxt, 63, n << 2), solve(0, n));
	printf("%d\n", nxt[n - 1]);
	return 0;
}