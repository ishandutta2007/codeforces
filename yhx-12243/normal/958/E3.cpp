#include <bits/stdc++.h>

const int N = 20054;
const double eps = 1e-8;

#define lt(x, y) ((x) < (y) - eps)
#define gt(x, y) ((x) > (y) + eps)
#define le(x, y) ((x) <= (y) + eps)
#define ge(x, y) ((x) >= (y) - eps)
#define eq(x, y) (le(x, y) && ge(x, y))
#define dot(x, y, z) (((y) - (x)) * ((z) - (x)))
#define cross(x, y, z) (((y) - (x)) ^ ((z) - (x)))

struct vec2 {
	double x, y;
	vec2 (double x0 = 0.0, double y0 = 0.0) : x(x0), y(y0) {}
	vec2 * read() {scanf("%lf%lf", &x, &y); return this;}
	inline vec2 operator - () const {return vec2(-x, -y);}
	inline vec2 operator + (const vec2 &B) const {return vec2(x + B.x, y + B.y);}
	inline vec2 operator - (const vec2 &B) const {return vec2(x - B.x, y - B.y);}
	inline vec2 operator * (double k) const {return vec2(x * k, y * k);}
	inline vec2 operator / (double k) const {return *this * (1.0 / k);}
	inline double operator * (const vec2 &B) const {return x * B.x + y * B.y;}
	inline double operator ^ (const vec2 &B) const {return x * B.y - y * B.x;}
	inline double norm2() const {return x * x + y * y;}
	inline double norm() const {return sqrt(x * x + y * y);}
	inline bool operator < (const vec2 &B) const {return lt(x, B.x) || le(x, B.x) && lt(y, B.y);}
	inline bool operator == (const vec2 &B) const {return eq(x, B.x) && eq(y, B.y);}
	inline bool operator << (const vec2 &B) const {return lt(y, 0) ^ lt(B.y, 0) ? lt(B.y, 0) : gt(*this ^ B, 0) || ge(*this ^ B, 0) && ge(x, 0) && lt(B.x, 0);}
	inline vec2 trans(double a11, double a12, double a21, double a22) const {return vec2(x * a11 + y * a12, x * a21 + y * a22);}
};

typedef std::pair <vec2, int> pvi;

int n;
int ans[N];
pvi p[N];

inline void match(int a, int b) {a >> 31 ? ans[b] = ~a : ans[a] = ~b;}

void solve(pvi *_beg, pvi *_end) {
	if (_beg == _end) return;
	std::iter_swap(_beg, std::min_element(_beg, _end));
	std::sort(_beg + 1, _end, [_beg] (const pvi &A, const pvi &B) {return cross(_beg->first, A.first, B.first) > 0;});
	int bra = 0; pvi *it;
	for (it = _beg + 1; it != _end; ++it)
		if ((it->second ^ _beg->second) >> 31) {
			if (!bra++) break;
		} else --bra;
	assert(it != _end), match(_beg->second, it->second);
	solve(_beg + 1, it), solve(it + 1, _end);
}

int main() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) p[i].first.read(), p[i].second = i;
	for (i = 0; i < n; ++i) p[i + n].first.read(), p[i + n].second = ~i;
	solve(p, p + 2 * n);
	for (i = 0; i < n; ++i) printf("%d%c", ++ans[i], i == n - 1 ? 10 : 32);
	return 0;
}