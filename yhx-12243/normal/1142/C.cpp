#include <bits/stdc++.h>
#define dot(x, y, z) (((y) - (x)) * ((z) - (x)))
#define cross(x, y, z) (((y) - (x)) ^ ((z) - (x)))

typedef long long ll;
const int N = 100054;

struct vec2 {
	ll x, y;
	vec2 (ll x0 = 0, ll y0 = 0) : x(x0), y(y0) {}
	inline vec2 operator - () const {return vec2(-x, -y);}
	inline vec2 operator + (const vec2 &B) const {return vec2(x + B.x, y + B.y);}
	inline vec2 operator - (const vec2 &B) const {return vec2(x - B.x, y - B.y);}
	inline ll operator * (const vec2 &B) const {return x * B.x + y * B.y;}
	inline ll operator ^ (const vec2 &B) const {return x * B.y - y * B.x;}
	inline ll norm2() const {return x * x + y * y;}
	inline bool operator < (const vec2 &B) const {return x < B.x || (x == B.x && y < B.y);}
} p[N], ch[N];

int andrew(int n, vec2 *p, vec2 *dest) {
	int i; vec2 *ret = dest;
	std::sort(p, p + n);
	for (i = 0; i < n; *ret++ = p[i++])
		for (; ret > dest + 1 && cross(ret[-2], p[i], ret[-1]) <= 0; --ret);
	return ret - dest;
}

int main() {
	int i, n, x, y, CH;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%d%d", &x, &y), p[i] = vec2(x, y - (ll)x * x);
	CH = andrew(n, p, ch);
	for (i = 0; i < CH && ch->x == ch[i].x; ++i);
	printf("%d\n", CH - i);
	return 0;
}