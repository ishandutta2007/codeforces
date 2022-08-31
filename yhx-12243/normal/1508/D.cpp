#include <bits/stdc++.h>
#define EB emplace_back
#define cross(x, y, z) (((y) - (x)) ^ ((z) - (x)))
using std::cin;
using std::cout;

typedef long long ll;
typedef std::vector <int> vector;
const int N = 2054, M = 100054;

struct vec2 {
	int x, y;
	vec2 (int x0 = 0.0, int y0 = 0.0) : x(x0), y(y0) {}
	friend std::istream & operator >> (std::istream &in, vec2 &B) {return in >> B.x >> B.y;}
	inline vec2 operator - () const {return vec2(-x, -y);}
	inline vec2 operator + (const vec2 &B) const {return vec2(x + B.x, y + B.y);}
	inline vec2 operator - (const vec2 &B) const {return vec2(x - B.x, y - B.y);}
	inline ll operator ^ (const vec2 &B) const {return (ll)x * B.y - (ll)y * B.x;}
	inline bool operator < (const vec2 &B) const {return (x < B.x) || ((x == B.x) && (y < B.y));}
} p[N];

int n, m, mm, C = 0;
int ans, ansU[M], ansV[M];
int a[N], bel[N], o[N];
int dak[N];
vector c[N];
bool used[N];

namespace dsu {
	int p[N];

	inline void init(int n) {std::iota(p, p + n, 0);}

	int ancestor(int x) {return p[x] == x ? x : (p[x] = ancestor(p[x]));}

	bool test(int x, int y, bool un = false) {
		if ((x = ancestor(x)) == (y = ancestor(y))) return true;
		return un && (p[x] = y, false);
	}
}

inline void push(int u, int v) {ansU[ans] = u, ansV[ans++] = v, std::swap(a[u], a[v]);}

int main() {
	int i, j, u, v, root = 0; vec2 G(INT_MAX, INT_MAX);
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n;
	for (i = 1; i <= n; ++i) cin >> p[i] >> a[i], used[i] = a[i] == i;
	for (i = 1; i <= n; ++i) if (!used[i]) {
		c[C].EB(i), used[i] = true;
		for (j = a[i]; j != i; j = a[j]) c[C].EB(j), used[j] = true;
		for (int x : c[C]) bel[x] = C;
		++C;
	}
	for (i = 1; i <= n; ++i) if (a[i] != i && p[i] < G) G = p[i], root = i;
	if (!root) goto end;
	fprintf(stderr, "root = %d\n", root);
	for (i = 1; i <= n; ++i) if (a[i] != i && i != root) o[m++] = i;
	std::sort(o, o + m, [G] (const int x, const int y) {return cross(G, p[x], p[y]) > 0;});
	for (i = 0; i < m; ++i) fprintf(stderr, "o[%d] = %d\n", i, o[i]);
	dsu::init(C);
	for (i = 1; i < m; ++i) {
		u = o[i - 1], v = o[i];
		if (!dsu::test(bel[u], bel[v], true)) push(u, v), fprintf(stderr, "op %d %d\n", u, v);
	}
	for (i = 0; i < C; ++i) assert(dsu::test(bel[0], bel[i]));
	mm = 0, dak[mm++] = root;
	for (i = a[root]; i != root; i = a[i]) dak[mm++] = i;
	assert(m + 1 == mm);
	for (i = 1; i < mm; ++i) push(root, dak[i]);
end:
	cout << ans << '\n';
	for (i = 0; i < ans; ++i) cout << ansU[i] << ' ' << ansV[i] << '\n';
	return 0;
}