#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 500054;

struct edge {
	int u, v; ll w;
	edge (int u0 = 0, int v0 = 0, ll w0 = 0) : u(u0), v(v0), w(w0) {}
	inline bool operator < (const edge &B) const {return w < B.w;}
} e[N];

int n, E, C, Es = 0, Et = 0;
int col[N];
int p[N], w[N], st[N];
bool fake[N];

namespace UFSex {
	int p[N], size[N], w[N];
	int t = 0, hist[N * 8];

	void init(int n) {for (; n; --n) p[n] = n, size[n] = 1;}

	int ancestor(int x, int *d = NULL) {return p[x] == x ? x : (d && (*d ^= w[x]), ancestor(p[x], d));}

	void Union(int x, int y, int weight) {
		if ((x = ancestor(x)) != (y = ancestor(y))) {
			if (size[x] > size[y]) std::swap(x, y);
			p[x] = y, size[y] += size[x], w[x] = weight, hist[++t] = x;
		}
	}

	inline void Undo(int _t) {for (int x; t > _t; --t) x = hist[t], size[p[x]] -= size[x], p[x] = x, w[x] = 0;}
}

inline void connect(int x, int y, int c) {
	int Dx = 0, Dy = 0;
	int X = UFSex::ancestor(x, &Dx), Y = UFSex::ancestor(y, &Dy), D = Dx ^ Dy ^ 1;
	if (X == Y) {
		if (D) {fake[c] = true; return;}
	} else UFSex::Union(X, Y, D);
}

int main() {
	int i, j, u, v, Cr = 0, ti; ll ans;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> E >> C;
	for (i = 1; i <= n; ++i) cin >> col[i];
	UFSex::init(n);
	for (i = 1; i <= E; ++i) {
		cin >> u >> v;
		if (col[u] == col[v]) {
			if (!fake[col[u]]) connect(u, v, col[u]);
		} else e[++Es] = edge(u, v, 0);
	}
	for (i = 1; i <= C; ++i) Cr += !fake[i];
//		fprintf(stderr, "fake[%d] = %d\n", i, fake[i]);
	ans = Cr * (Cr - 1ll) / 2;
	for (i = 1; i <= Es; ++i) {
		u = col[e[i].u], v = col[e[i].v];
		if (!fake[u] && !fake[v]) {
			if (u > v) std::swap(u, v);
			e[++Et] = edge(e[i].u, e[i].v, u | (ll)v << 32);
		}
	}
	std::sort(e + 1, e + (Et + 1));
	ti = UFSex::t;
	for (j = i = 1; i <= Et; i = j) {
		UFSex::Undo(ti), fake[0] = false;
		for (; j <= Et && e[i].w == e[j].w; ++j) {
			if (!fake[0]) connect(e[j].u, e[j].v, 0);
		}
		ans -= fake[0];
	}
	cout << ans << '\n';
	return 0;
}