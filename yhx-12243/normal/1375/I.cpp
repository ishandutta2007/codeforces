#include <bits/stdc++.h>
#define gcd std::__gcd
using std::cin;
using std::cout;
using std::vector;

typedef long long ll;
typedef long double ld;
const int N = 10054;

struct quaternion {
	ld s, x, y, z;
	quaternion (ld s0 = 0, ld x0 = 0, ld y0 = 0, ld z0 = 0) : s(s0), x(x0), y(y0), z(z0) {}
	inline quaternion operator - () const {return quaternion(-s, -x, -y, -z);}
	inline quaternion conj() const {return quaternion(s, -x, -y, -z);}
	inline quaternion operator + (const quaternion &B) const {return quaternion(s + B.s, x + B.x, y + B.y, z + B.z);}
	inline quaternion operator - (const quaternion &B) const {return quaternion(s - B.s, x - B.x, y - B.y, z - B.z);}
	inline quaternion operator * (const ld k) const {return quaternion(s * k, x * k, y * k, z * k);}
	inline quaternion operator * (const quaternion &B) const {
		return quaternion(
			s * B.s - x * B.x - y * B.y - z * B.z,
			s * B.x + x * B.s + y * B.z - z * B.y,
			s * B.y - x * B.z + y * B.s + z * B.x,
			s * B.z + x * B.y - y * B.x + z * B.s
		);
	}
	inline operator void * () const {return s || x || y || z ? (void *)this : 0;}
	inline ld norm2() const {return s * s + x * x + y * y + z * z;}
	inline ll intnorm2() const {return llroundl(norm2());}
	inline quaternion inv() const {return conj() * (1.l / norm2());}
	inline quaternion round() const {
		quaternion A(roundl(s), roundl(x), roundl(y), roundl(z)), B(floorl(s) + .5l, floorl(x) + .5l, floorl(y) + .5l, floorl(z) + .5l );
		return (*this - A).norm2() <= (*this - B).norm2() ? A : B;
	}
	inline friend quaternion Ldiv(const quaternion &A, const quaternion &B) {return (B.inv() * A).round();}
	inline friend quaternion Rdiv(const quaternion &A, const quaternion &B) {return (A * B.inv()).round();}
	inline friend quaternion Lmod(const quaternion &A, const quaternion &B) {return A - B * Ldiv(A, B);}
	inline friend quaternion Rmod(const quaternion &A, const quaternion &B) {return A - Rdiv(A, B) * B;}
	// find (Hurwitz) quaternion d where A = d u, B = d v.
	inline friend quaternion Lgcd(quaternion A, quaternion B) {
		static quaternion tmp;
		for (; B; tmp = Lmod(A, B), A = B, B = tmp);
		return A;
	}
	inline bool is_int() const {return fabsl(s - roundl(s)) < 1e-10l && fabsl(x - roundl(x)) < 1e-10l && fabsl(y - roundl(y)) < 1e-10l && fabsl(z - roundl(z)) < 1e-10l;}
} p[N], q[N], v;

int n, cnt = 0;
int potential[2003731];

bool final(int r) {
	// unique factorization for Hurwitz quaternion.
	quaternion u = Lgcd(v, quaternion(r)), x, y, z;
	ll r1 = u.norm2(); ld cf = 1. / ((ll)r * r);
	if (assert(r % r1 == 0), r1 != r) return false;
	for (int i = 0; i < n; ++i) {
		q[i] = u.conj() * p[i] * u * cf;
		if (!q[i].is_int()) return false;
	}
	x = u * quaternion(0, 1, 0, 0) * u.conj(),
	y = u * quaternion(0, 0, 1, 0) * u.conj(),
	z = u * quaternion(0, 0, 0, 1) * u.conj();
	return cout << (ll)r * r << '\n'
		   << llroundl(x.x) << ' ' << llroundl(x.y) << ' ' << llroundl(x.z) << '\n'
		   << llroundl(y.x) << ' ' << llroundl(y.y) << ' ' << llroundl(y.z) << '\n'
		   << llroundl(z.x) << ' ' << llroundl(z.y) << ' ' << llroundl(z.z) << '\n', true;
}

int main() {
	int i, x, y, z, g = 0; ll d, D = 0;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	for (i = 0; i < n; ++i)
		cin >> x >> y >> z, g = gcd(gcd(gcd(g, x), y), z),
		v = Lgcd(v, p[i] = quaternion(0, x, y, z)),
		D = gcd(D, (ll)x * x + (ll)y * y + (ll)z * z);
	assert(abs(g) == 1), d = v.intnorm2(), z = cbrtl(D);
	for (i = 1; i <= z; ++i) if (!(D % i)) {
		if (!(D % ((ll)i * i) || d % i)) potential[cnt++] = i;
		if (y = sqrtl(D / i), (ll)y * y * i == D && !(d % y)) potential[cnt++] = y;
	}
	std::sort(potential, potential + cnt, std::greater <int> ());
	for (i = 0; i < cnt; ++i) if (final(potential[i])) return 0;
	return -1;
}