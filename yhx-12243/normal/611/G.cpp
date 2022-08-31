#include <bits/stdc++.h>
#define cross(x, y, z) (((y) - (x)) ^ ((z) - (x)))

typedef long long ll;
const int N = 1000054, mod = 1000000007;

struct vec2 {
	int x, y;
	vec2 (int x0 = 0, int y0 = 0) : x(x0), y(y0) {}
	vec2 * read() {scanf("%d%d", &x, &y); return this;}
	inline vec2 operator + (const vec2 &B) const {return vec2(x + B.x, y + B.y);}
	inline vec2 operator - (const vec2 &B) const {return vec2(x - B.x, y - B.y);}
	inline ll operator ^ (const vec2 &B) const {return (ll)x * B.y - (ll)y * B.x;}
};

int n, ans = 0;
vec2 p[N], P[N];
ll S;
int X[N], Xs[N];

int main() {
	int i, j, x; ll cur = 0, di;
	scanf("%d", &n), di = n * (n - 3ll);
	for (i = n - 1; i >= 0; --i) p[i].read();
	std::copy(p, p + n, p + n), p[2 * n] = *p;
	for (i = 0; i < n; ++i) S += p[i] ^ p[i + 1];
	assert(S > 0);
	for (i = 1; i <= 2 * n; ++i) {
		x = (p[i - 1] ^ p[i]) % mod;
		X[i] = (X[i - 1] + x) % mod;
		Xs[i] = (Xs[i - 1] + (ll)x * i) % mod;
		P[i] = P[i - 1] + p[i], P[i].x %= mod, P[i].y %= mod;
	}
	for (j = i = 0; i < n; ++i) {
		for (; j < 2 * n && cur * 2llu < S; ++j) cur += cross(p[i], p[j], p[j + 1]);
		--j, di -= cur * 2llu == S;
		ans = (ans + (X[j] - X[i]) * (j + 1ll) - (Xs[j] - Xs[i]) + ((P[j] - P[i]) ^ p[i])) % mod;
		assert(j > i), cur -= cross(p[i], p[i + 1], p[++j]);
	}
	assert(!(di & 1));
	ans = ((S % mod) * (di / 2 % mod) - 2 * ans) % mod;
	printf("%d\n", ans + (ans >> 31 & mod));
	return 0;
}