#include <bits/stdc++.h>
#define ctz __builtin_ctz
using std::cin;
using std::cout;

const int N = 525000, INF = 0x3f3f3f3f;

int n, D;
int a[N];
int ans[N];

inline void down(int &x, const int y) {x > y ? x = y : 0;}
inline int min(const int x, const int y) {return x < y ? x : y;}
inline int max(const int x, const int y) {return x > y ? x : y;}

namespace trie {
	#define segc int lc = id << 1, rc = lc | 1

	struct node {
		int l, r, cl; bool rev;
		inline void init() {l = cl = INF, r = -INF, rev = false;}
	} x[N * 2];

	inline void update(node &ret, const node &l, const node &r, int d) {
		if (ret.rev) {
			ret.l = min(r.l, l.l + (1 << d)), ret.r = max(r.r, l.r + (1 << d)),
			ret.cl = min(l.cl, r.cl);
			if (r.r >= 0 && l.l < INF) down(ret.cl, l.l - r.r + (1 << d));
		} else {
			ret.l = min(l.l, r.l + (1 << d)), ret.r = max(l.r, r.r + (1 << d)),
			ret.cl = min(l.cl, r.cl);
			if (l.r >= 0 && r.l < INF) down(ret.cl, r.l - l.r + (1 << d));
		}
	}

	void insert(int id, int v, int d) {
		if (!~d) {x[id].l = x[id].r = 0; return;}
		segc;
		insert(v >> d & 1 ? rc : lc, v, d - 1),
		update(x[id], x[lc], x[rc], d);
	}

	void flip(int id, int dlim, int d) {
		segc;
		if (!dlim) {
			x[id].rev = !x[id].rev;
			return update(x[id], x[lc], x[rc], d);
		}
		flip(lc, dlim - 1, d - 1), flip(rc, dlim - 1, d - 1),
		update(x[id], x[lc], x[rc], d);
	}
}

int main() {
	int i, c, X = 0;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> D;
	for (i = 0; i < 2 * N; ++i) trie::x[i].init();
	for (i = 0; i < n; ++i) cin >> a[i], trie::insert(1, a[i], D - 1);
	*ans = trie::x[1].cl;
	for (i = 1; i < (1 << D); ++i)
		c = ctz(i), X ^= 1 << (D - c - 1),
		trie::flip(1, c, D - 1), ans[X] = trie::x[1].cl;
	for (i = 0; i < (1 << D); ++i)
		cout << ans[i] << (i + 1 == (1 << D) ? '\n' : ' ');
	return 0;
}