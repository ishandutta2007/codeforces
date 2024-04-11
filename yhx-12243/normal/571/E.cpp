#include <bits/stdc++.h>
#define ctz __builtin_ctz

typedef long long ll;
typedef std::pair <int, ll> pr;
typedef std::map <int, ll> map, fnum;
const int N = 254, mod = 1000000007;

int n;
int ps[N];
fnum A, Q;

ll PowerMod(ll a, ll n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

ll exgcd(ll a, ll b, ll &x, ll &y) {
	if (b) {ll d = exgcd(b, a % b, y, x); y -= a / b * x; return d;}
	else {x = 1; y = 0; return a;}
}

map factor(int n) {
	int i, j; map ret;
	if (!(n & 1)) n >>= ret[2] = ctz(n);
	for (i = 3; i * i <= n; i += 2)
		if (!(n % i)) {for (j = 0; !(n % i); n /= i, ++j); ret[i] = j;}
	return n > 1 && (ret[n] = 1), ret;
}

inline fnum get_factored_int() {int _; return scanf("%d", &_), factor(_);}

inline int value_of(const fnum &n) {ll ret = 1; for (const pr &p : n) ret = PowerMod(p.first, p.second, ret); return ret;}

inline ll query_expo(const fnum &n, int p) {map::const_iterator it = n.find(p); return it == n.end() ? 0 : it->second;}

// find minimum x >= max(a1, a2) s.t. exists u, v : x = a1 + d1 u = a2 + d2 v.
bool linear_solve(ll a1, ll d1, ll a2, ll d2, ll &ac, ll &dc) {
	if (!(d1 || d2)) return a1 == a2 && (ac = a1, dc = 0, 1);
	if (d1 > d2) std::swap(d1, d2), std::swap(a1, a2);
	ll C1, C2, d = exgcd(d1, d2, C1, C2), M = std::max(a1, a2);
	if ((a1 - a2) % d) return false;
	if (!d1) return (ac = a1) >= M;
	ac = (a1 - a2) / d % d1 * C2 % d1;
	dc = d1 / d * d2;
	ac = (ac * d2 + a2) % dc;
	return ac = M + (ac < M ? dc - 1 - (M - ac - 1) % dc : (ac - M) % dc), true;
}

// the structure line with general form A x + B y + C = 0.
struct line {
	ll A, B, C;
	line (ll A0 = 0, ll B0 = 0, ll C0 = 0) : A(A0), B(B0), C(C0) {}
	inline bool normalize() {
		ll d = llabs(std::__gcd(A, B));
		if (C % d) return false;
		if (A < 0 || (!A && B < 0)) A = -A, B = -B, C = -C;
		return A /= d, B /= d, C /= d, true;
	}
	inline ll operator () (const ll x, const ll y) {return A * x + B * y + C;}
	inline bool operator < (const line &B) const {return A < B.A || (A == B.A && B < B.B);}
} l[N];	

// two-line intersection.
inline bool LI(const line &u, const line &v, ll &x, ll &y) {
	ll det = u.A * v.B - u.B * v.A;
	lldiv_t _ = lldiv(u.B * v.C - u.C * v.B, det);
	if (x = _.quot, _.rem) return false;
	_ = lldiv(u.C * v.A - u.A * v.C, det);
	return y = _.quot, !_.rem;
}

// compute the intersection of two geometric progressions.
bool intersect(fnum &A1, fnum &Q1, const fnum &A2, const fnum &Q2) {
	int i, P = 0, cnt = 0; ll a, d, a1, d1, a2, d2;
	for (const pr &p : A1) ps[P++] = p.first;
	for (const pr &p : Q1) ps[P++] = p.first;
	for (const pr &p : A2) ps[P++] = p.first;
	for (const pr &p : Q2) ps[P++] = p.first;
	std::sort(ps, ps + P), P = std::unique(ps, ps + P) - ps;
	for (i = 0; i < P; ++i) {
		a1 = query_expo(A1, ps[i]), d1 = query_expo(Q1, ps[i]);
		a2 = query_expo(A2, ps[i]), d2 = query_expo(Q2, ps[i]);
		if (!(d1 || d2)) {if (a1 != a2) return false; else continue;}
		l[cnt] = line(d1, -d2, a1 - a2);
		if (!l[cnt++].normalize()) return false;
	}
	std::sort(l, l + cnt);
	if (!cnt) ;
	else if (l->A == l[cnt - 1].A && l->B == l[cnt - 1].B) { // all same
		for (i = 1; i < cnt && l->C == l[i].C; ++i);
		if (i != cnt) return false;
		for (i = 0; i < P; ++i) {
			a1 = query_expo(A1, ps[i]), d1 = query_expo(Q1, ps[i]);
			a2 = query_expo(A2, ps[i]), d2 = query_expo(Q2, ps[i]);
			if (!linear_solve(a1, d1, a2, d2, a, d)) return false;
			A1[ps[i]] = a, Q1[ps[i]] = d;
		}
	} else { // intersecting
		ll x, y;
		if (!LI(*l, l[cnt - 1], x, y) || x < 0 || y < 0) return false;
		for (i = 1; i < cnt && !l[i](x, y); ++i);
		if (i != cnt) return false;
		for (i = 0; i < P; ++i)
			a1 = query_expo(A1, ps[i]), d1 = query_expo(Q1, ps[i]),
			A1[ps[i]] = a1 + d1 * x, Q1[ps[i]] = 0;
	}
	return true;
}

int main() {
	scanf("%d", &n), A = get_factored_int(), Q = get_factored_int();
	for (int i = 1; i < n; ++i) {
		fnum a = get_factored_int(), q = get_factored_int();
		if (!intersect(A, Q, a, q)) return puts("-1"), 0;
	}
	printf("%d\n", value_of(A));
	return 0;
}