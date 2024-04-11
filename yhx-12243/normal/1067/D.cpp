#include <bits/stdc++.h>
#define cross(x, y, z) (((y) - (x)) ^ ((z) - (x)))

typedef long long ll;
typedef double ld;
const int N = 100054;
const ld eps = 1e-13;

struct prob {
	int a, b; ld p;
	prob * read() {return scanf("%d%d%lf", &a, &b, &p), this;}
	inline bool operator < (const prob &B) const {return b * p < B.b * B.p;}
} v[N];

struct vec2 {
	ld x, y;
	vec2 (ld x0 = 0.0, ld y0 = 0.0) : x(x0), y(y0) {}
	inline vec2 operator - (const vec2 &B) const {return vec2(x - B.x, y - B.y);}
	inline bool operator < (const vec2 &B) const {return x < B.x || (x == B.x && y < B.y);}
	inline ld operator ^ (const vec2 &B) const {return x * B.y - y * B.x;}
} p[N], ch[N], *rt = ch;

int n, CH;
ld M;

inline void up(ld &x, const ld y) {x < y ? x = y : 0;}

ld trans(ll t, ll n, ld a, ld b, ld f_t) {
	ld ak = pow(1 - a, n), aq = (1 - ak) / a, ay = ((n - 1) + ak - (1 - a) * n) / (a * a);
	return ak * f_t + (aq * t + ay) * (a * M) + aq * b;
}

int main() {
	int i, j, k; ll t = 0, T; ld cur = 0, next, slope, slope_limit;
	scanf("%d%lld", &n, &T);
	for (i = 0; i < n; ++i) v[i].read(), p[i] = vec2(v[i].p, v[i].p * v[i].a);
	{prob *it = std::max_element(v, v + n); M = it->b * it->p;}
	std::sort(p, p + n);
	for (i = 0; i < n; *rt++ = p[i++])
		for (; rt > ch + 1 && cross(rt[-2], p[i], rt[-1]) <= 0; --rt);
	CH = rt - ch;
	for (i = 0; i < CH - 1 && ch[i].y < ch[i + 1].y; ++i);
	for (; i < CH && t < T; ++i) {
		slope_limit = (i == CH - 1 ? INFINITY : (ch[i].y - ch[i + 1].y) / (ch[i + 1].x - ch[i].x));
		slope = t * M - cur;
		if (slope > slope_limit) continue;
		for (j = 0; ; ++j) {
			next = trans(t, 1ll << j, ch[i].x, ch[i].y, cur), slope = (t + (1ll << j)) * M - next;
			if (slope > slope_limit || t + (2ll << j) >= T) break;
		}
		for (k = j; k >= 0; --k) {
			if (t + (1ll << k) >= T) continue;
			next = trans(t, 1ll << k, ch[i].x, ch[i].y, cur), slope = (t + (1ll << k)) * M - next;
			if (slope <= slope_limit) t += 1ll << k, cur = next;
		}
		cur = (1 - ch[i].x) * cur + ch[i].x * M * t + ch[i].y, ++t;
	}
	printf("%.12lg\n", cur);
	return 0;
}