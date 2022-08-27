#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::pair;

typedef long long ll;
const int N = 100054;
const double eps = 1e-8, pi = 3.14159265358979323846264338327950288419716939937510582097494;

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
} p[N], P[N], P1[N];

bool zeroQ;
int n;
ll K;
pair <int, int> a[N], b[N];

namespace DC {
	const int N = ::N * 2; 
	int F[N];
	pair <double, int> D[N];

	int Discretize(int n) {
		int i, cnt = 0; std::sort(D, D + n);
		for (i = 0; i < n; ++i) F[D[i].second] = (D[cnt] = D[i], cnt++);
		return cnt;
	}
}

namespace BIT {
	int n, x[2 * N];

	inline void clear() {memset(x, 0, n << 2);}
	int sum(int h) {int s = 0; for (; h >= 0; h &= h + 1, --h) s += x[h]; return s;}
	void add(int h, int v) {for (; h < n; h |= h + 1) x[h] += v;}
}

int pre[2 * N], suf[2 * N];

ll count(double r) {
	int i, j, c = 0, u, v, w, A = 0, B = 0; double r2 = r * r, le, mid, ri, tr;
	ll ret;
	for (i = 0; i < n; ++i) if (p[i].norm2() > r2) P[c++] = p[i];
	ret = (n - c) * (n + c - 1ll) / 2;
	for (i = 0; i < c; ++i) {
		mid = atan2(P[i].y, P[i].x);
		if (mid < 0) mid += 2 * pi;
		tr = acos(r / P[i].norm());
		le = mid - tr, ri = mid + tr;
		if (le < 0) le += 2 * pi;
		if (ri >= 2 * pi) ri -= 2 * pi;
		DC::D[i] = pair <double, int> (le, i);
		DC::D[i + c] = pair <double, int> (ri, i + c);
//		fprintf(stderr, "%d : (%.12lg, %.12lg), (%.12lg, %.12lg)\n", i, P[i].x, P[i].y, le, ri);
	}
	BIT::n = w = DC::Discretize(2 * c);
	for (i = 0; i < c; ++i) {
		u = DC::F[i], v = DC::F[i + c];
//		fprintf(stderr, "%d : [%d, %d)\n", i, u, v);
		if (u <= v) a[A++] = pair <int, int> (u, -v);
		else b[B++] = pair <int, int> (u, -v);
	}
	std::sort(a, a + A), std::sort(b, b + B);
	BIT::clear();
	for (i = A - 1; i >= 0; --i) ret += BIT::sum(-a[i].second), BIT::add(-a[i].second, 1);
	memset(pre, 0, w << 2), memset(suf, 0, w << 2);
	for (i = 0; i < A; ++i) ++pre[-a[i].second], ++suf[a[i].first];
	for (i = 1; i < w; ++i) pre[i] += pre[i - 1];
	for (i = w - 2; i >= 0; --i) suf[i] += suf[i + 1];
	for (i = 0; i < A; ++i) ret += suf[-a[i].second];
	BIT::clear();
	for (i = B - 1; i >= 0; --i)
		ret += BIT::sum(-b[i].second), BIT::add(-b[i].second, 1),
		ret += pre[-b[i].second] + suf[b[i].first];
	for (i = 0; i < B; ++i) b[i] = pair <int, int> (-b[i].second, -b[i].first);
	std::sort(b, b + B),
	BIT::clear();
	for (i = B - 1, j = A - 1; i >= 0; --i) {
		for (; j >= 0 && a[j].first >= b[i].first; --j) BIT::add(-a[j].second, 1);
		ret += BIT::sum(-b[i].second);
	}
//	fprintf(stderr, "(<= radius %.12lg) => %lld\n", r, ret);
	return ret;
}

int main() {
	int i, j, x0, y0; double L = 0., R = 14400., M;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> K;
	for (i = 0; i < n; ++i) {
		cin >> x0 >> y0, p[i] = vec2(x0, y0);
		if (!(x0 || y0)) zeroQ = true, j = i;
	}
	if (zeroQ) {
		std::swap(p[j], p[--n]);
		if ((K -= n) < 0) return cout << '0' << '\n', 0;
	}
	for (; R - L > 4e-8; ) count(M = (L + R) * .5) < K ? L = M : R = M;
	cout << std::setprecision(12) << (L + R) * .5 << '\n';
	return 0;
}