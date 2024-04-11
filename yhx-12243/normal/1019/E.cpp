#include <bits/stdc++.h>
#define EB emplace_back
#define cross(x, y, z) (((y) - (x)) ^ ((z) - (x)))
using std::vector;

typedef long long ll;
typedef __int128 lll;

const int N = 100054, M = N * 2, Z = 2003731;

struct vec2 {
	ll x, y;
	vec2 (ll _x = 0, ll _y = 0) : x(_x), y(_y) {}
	inline vec2 operator - () const {return vec2(-x, -y);}
	inline vec2 operator + (const vec2 &B) const {return vec2(x + B.x, y + B.y);}
	inline vec2 operator - (const vec2 &B) const {return vec2(x - B.x, y - B.y);}
	inline lll operator * (const vec2 &B) const {return (lll)x * B.x + (lll)y * B.y;}
	inline lll operator ^ (const vec2 &B) const {return (lll)x * B.y - (lll)y * B.x;}
	inline lll norm2() const {return (lll)x * x + (lll)y * y;}
	inline bool operator < (const vec2 &B) const {return x < B.x || (x == B.x && y < B.y);}
	inline bool operator == (const vec2 &B) const {return x == B.x && y == B.y;}
} p[N];

vec2 P1[Z], P2[Z];
vector<vec2> graham(const vector<vec2> &ps) {
	int i, n = ps.size(); vec2 *ret = P2;
	if (n <= 2) return ps;
	std::copy(ps.begin(), ps.end(), P1), std::iter_swap(P1, std::min_element(P1, P1 + n));
	std::stable_sort(P1 + 1, P1 + n, [] (const vec2 &A, const vec2 &B) {lll r = cross(*P1, A, B); return r > 0 || (r == 0 && (A - *P1).norm2() < (B - *P1).norm2());});
	for (i = 0; i < n; *ret++ = P1[i++])
		for (; ret > P2 + 1 && cross(ret[-2], P1[i], ret[-1]) >= 0; --ret);
	return vector<vec2>(P2, ret);
}

inline bool geStraight(const vec2 A, const vec2 B) {return (A ^ B) < 0 || (!(A ^ B) && A * B < 0);}

vector<vec2> minkowski(const vector<vec2> &lp, const vector<vec2> &rp) {
	if (lp.empty() || rp.empty()) return vector<vec2>();
	static vector<vec2> tmp;
	int l, r, i, j, L = lp.size(), R = rp.size(); tmp.clear(), tmp.reserve(L + R);
	if (L < 2 || R < 2) {
		for (i = 0; i < L; ++i) for (j = 0; j < R; ++j) tmp.EB(lp[i] + rp[j]);
		return graham(tmp);
	} else {
		i = l = std::min_element(lp.begin(), lp.end()) - lp.begin();
		j = r = std::min_element(rp.begin(), rp.end()) - rp.begin();
		do
			geStraight(lp[ (i+1)%L ] - lp[i], rp[ (j+1)%R ] - rp[j]) ? ++j %= R : ++i %= L, tmp.EB(lp[i] + rp[j]);
		while (i != l || j != r);
		return tmp;
	}
}

// -------- CG ends -------- //

struct edge {
	int u, v, x, y;
	edge (int u0 = 0, int v0 = 0, int x0 = 0, int y0 = 0) : u(u0), v(v0), x(x0), y(y0) {}
} e[M];

int n, E = 0, TR;
int first[N], next[M], size[N];
bool fi[N];
vector<vec2> ps[N], *cur, *all[N];
vector<vec2> lh, rh, hh, CH;

inline void up(int &x, const int y) {x < y ? x = y : 0;}

inline void addedge(int u, int v, int x, int y) {
	e[++E] = edge(u, v, x, y), next[E] = first[u], first[u] = E;
	e[++E] = edge(v, u, x, y), next[E] = first[v], first[v] = E;
}

namespace Centroid {
	#define get_centroid(x, y) (Centroid::init(y), Centroid::get(x))
	int V, Gm, G, size[N];

	void init(int _V) {V = _V, Gm = INT_MAX;}

	int get(int x, int px = 0) {
		int i, y, Max = 0; size[x] = 1;
		for (i = first[x]; i; i = next[i])
			if ((y = e[i].v) != px && !fi[y])
				get(y, x), up(Max, size[y]), size[x] += size[y];
		up(Max, V - size[x]);
		return Max <= Gm ? (Gm = Max, G = x) : G;
	}
}

void dfs(int x, int px, ll X, ll Y) {
	int i, y; size[x] = 1; cur->EB(X, Y);
	for (i = first[x]; i; i = next[i])
		if ((y = e[i].v) != px && !fi[y])
			dfs(y, x, X + e[i].x, Y + e[i].y), size[x] += size[y];
}

void simulated_edge_DC(int L, int R) {
	if (L + 1 >= R) return;
	int i, M = (L + R) / 2;
	simulated_edge_DC(L, M), simulated_edge_DC(M, R);
	lh.clear(), rh.clear();
	for (i = L; i < M; ++i) lh.insert(lh.end(), all[i]->begin(), all[i]->end());
	for (i = M; i < R; ++i) rh.insert(rh.end(), all[i]->begin(), all[i]->end());
	hh = minkowski(graham(lh), graham(rh)), CH.insert(CH.end(), hh.begin(), hh.end());
}

void solve(int x) {
	int i, y, G, deg = 0; all[deg++] = ps;
	fi[x] = true;
	for (i = first[x]; i; i = next[i])
		if (!fi[y = e[i].v])
			all[deg++] = cur = ps + y, cur->clear(), dfs(y, x, e[i].x, e[i].y);
	simulated_edge_DC(0, deg);
	for (i = first[x]; i; i = next[i])
		if (!fi[y = e[i].v])
			G = get_centroid(y, size[y]), solve(G);
}

int main() {
	int i, j, k, G, size, first = 0;
	scanf("%d%d", &n, &TR);
	for (i = 1; i < n; ++i) {int u, v, x, y; scanf("%d%d%d%d", &u, &v, &x, &y), addedge(u, v, x, y);}
	ps->EB(0, 0), G = get_centroid(1, n), solve(G), CH = graham(CH), size = CH.size();
	if (!size) {for (; --TR; putchar(48), putchar(32)); return putchar(48), putchar(10), 0;}
	for (i = 1; i < size; ++i) if (CH[i].y > CH[first].y) first = i;
	i = first, j = (i ? i : size) - 1;
	for (k = 0; k < TR; ++k) {
		for (; (CH[j] - CH[i]) * vec2(k, 1) > 0; i = j, j = (i ? i : size) - 1);
		printf("%lld%c", ll(CH[i] * vec2(k, 1)), k == TR - 1 ? 10 : 32);
	}
	return 0;
}