#include <bits/stdc++.h>
#define dot(x, y, z) (((y) - (x)) * ((z) - (x)))
#define cross(x, y, z) (((y) - (x)) ^ ((z) - (x)))

typedef long long ll;
const int N = 25400;

struct vec2 {
	int x, y;
	vec2 (int x0 = 0.0, int y0 = 0.0) : x(x0), y(y0) {}
	vec2 * read() {return scanf("%d%d", &x, &y), this;}
	inline vec2 operator - () const {return vec2(-x, -y);}
	inline vec2 operator - (const vec2 &B) const {return vec2(x - B.x, y - B.y);}
	inline ll operator * (const vec2 &B) const {return (ll)x * B.x + (ll)y * B.y;}
	inline ll operator ^ (const vec2 &B) const {return (ll)x * B.y - (ll)y * B.x;}
	inline ll norm2() const {return (ll)x * x + (ll)y * y;}
	inline bool operator < (const vec2 &B) const {return x < B.x || (x == B.x && y < B.y);}
	inline bool operator == (const vec2 &B) const {return x == B.x && y == B.y;}
	inline bool operator << (const vec2 &B) const {return (y < 0) ^ (B.y < 0) ? B.y < 0 : (*this ^ B) > 0 || ((*this ^ B) == 0 && x >= 0 && B.x < 0);}
} a[N], b[N], ch[N], *o;

int A, B, CH, O;

inline int & inc(int &x) {return ++x == CH ? x = 0 : x;} 
inline int & dec(int &x) {return --(x ? x : x = CH);}
inline bool up(vec2 &x, const vec2 y) {return x << y ? x = y, 1 : 0;}
inline bool down(vec2 &x, const vec2 y) {return y << x ? x = y, 1 : 0;}

inline vec2 angle_vec(const vec2 O, const vec2 u, const vec2 v) {return vec2(dot(O, u, v), cross(O, u, v));}

int graham(int n, vec2 *p, vec2 *dest) {
	int i; vec2 *ret = dest;
	std::iter_swap(p, std::min_element(p, p + n));
	std::sort(p + 1, p + n, [p] (const vec2 A, const vec2 B) {ll r = cross(*p, A, B); return r > 0 || (r == 0 && (A - *p).norm2() < (B - *p).norm2());});
	for (i = 0; i < n; *ret++ = p[i++])
		for (; ret > dest + 1 && cross(ret[-2], p[i], ret[-1]) >= 0; --ret);
	return *ret = *p, ret - dest;
}

bool check_inside(int L, int R) {
	int i, p = -1; vec2 ang, min(1, 0), max(INT_MAX, -1);
	for (i = L + 1; i < R; ++i) if (up(min, angle_vec(ch[i], ch[L], ch[R]))) p = i;
	for (; inc(i) != L; down(max, -angle_vec(ch[i], ch[L], ch[R])));
	for (i = 0; i < O; ++i) {
		ang = angle_vec(o[i], ch[L], ch[R]);
		if (!ang.y) {if (ang.x <= 0) break;}
		else if (ang.y < 0) down(max, ang);
		else up(min, -ang);
		if (!(min << max)) break;
	}
	return i == O || (~p && (check_inside(L, p) || check_inside(p, R)));
}

int main() {
	int i;
	scanf("%d%d", &A, &B);
	for (i = 0; i < A; ++i) a[i].read();
	for (i = 0; i < B; ++i) b[i].read();
	CH = graham(A, a, ch), O = B, o = b;
	if (CH == 1 || check_inside(0, CH - 1)) return puts("YES"), 0;
	CH = graham(B, b, ch), O = A, o = a;
	if (CH == 1 || check_inside(0, CH - 1)) return puts("YES"), 0;
	return puts("NO"), 0;
}