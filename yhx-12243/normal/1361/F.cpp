#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using std::cin;
using std::cout;

typedef long long ll;
typedef __gnu_pbds::tree <int, __gnu_pbds::null_type, std::less <int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> BST;
const int N = 200054;

int n, q;
int p[N], w[N];
ll I;

inline ll min(const ll x, const ll y) {return x < y ? x : y;}

namespace Cartesian {
	struct node {
		int p, lc, rc, lb, mb, rb; ll iv; BST e;
		inline void set_inv(ll new_val) {
			I -= min(iv, (mb - lb + 1ll) * (rb - mb + 1ll) - iv), iv = new_val,
			I += min(iv, (mb - lb + 1ll) * (rb - mb + 1ll) - iv);
		}
	} g[N * 2];

	int root;

	int single_node(int x) {return g[x + n].e.insert(p[x]), x + n;}

	int build(int L, int R) {
		int x = std::min_element(w + L, w + (R + 1)) - w; ll is = 0;
		g[x].lb = L, g[x].mb = x, g[x].rb = R, g[x].e = BST(p + L, p + (R + 2));
		g[x].lc = (L == x ? single_node(L) : build(L, x - 1));
		g[x].rc = (R == x ? single_node(R + 1) : build(x + 1, R));
		if (g[x].lc && g[x].rc) for (int v : g[x].lc[g].e) is += g[x].rc[g].e.order_of_key(v);
		g[x].set_inv(is);
		return x;
	}

	inline void init() {root = build(1, n - 1);}

	void adj(int h, int v, bool del = false) {
		int x = root, c = del ? -1 : 1;
		for (; ; ) {
			del ? (void)g[x].e.erase(v) : (void)g[x].e.insert(v);
			if (x > n) break;
			g[x].set_inv(g[x].iv + c * int(h <= g[x].mb ? g[x].rc[g].e.order_of_key(v) : g[x].lc[g].e.size() - g[x].lc[g].e.order_of_key(v)));
			x = (h <= g[x].mb ? g[x].lc : g[x].rc);
		}
	}
}

int main() {
	int i, j;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	for (i = 1; i <= n; ++i) cin >> p[i];
	for (i = 1; i < n; ++i) cin >> w[i];
	Cartesian::init();
	for (cin >> q; q; --q)
		cin >> i >> j,
		Cartesian::adj(i, p[i], true), Cartesian::adj(j, p[j], true),
		std::swap(p[i], p[j]),
		Cartesian::adj(i, p[i], false), Cartesian::adj(j, p[j], false),
		cout << I << '\n';
	return 0;
}