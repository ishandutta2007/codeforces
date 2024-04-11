#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct func {
	int k, b;
	func(int _k = 1, int _b = 0) : k(_k), b(_b) {}
	inline void operator+=(const func &rhs) {
		k *= rhs.k;
		b = rhs.k * b + rhs.b;
	}
	inline int eval(int x) {
		return k * x + b;
	}
};
const int N = 5e5 + 5;
int root, tot, ch[N][2], val[N], pri[N];
func lazy[N];
inline int new_node() {
	int cur = ++tot;
	pri[cur] = rnd();
	ch[cur][0] = ch[cur][1] = 0;
	return cur;
}
inline void tag(int p, func f) {
	val[p] = f.eval(val[p]);
	lazy[p] += f;
	if (f.k == -1) swap(ch[p][0], ch[p][1]);	
}
inline void pushdown(int p) {
	auto &f = lazy[p];
	if (f.k != 1 || f.b) {
		if (ch[p][0]) tag(ch[p][0], f);
		if (ch[p][1]) tag(ch[p][1], f);
		f = func(1, 0);
	}
} 
void split(int p, int k, int &x, int &y) {
	if (!p) {
		x = y = 0;
		return;
	}
	pushdown(p);
	if (val[p] < k) {
		x = p;
		split(ch[p][1], k, ch[x][1], y);
	} else {
		y = p;
		split(ch[p][0], k, x, ch[y][0]);
	}
}
int merge(int p, int q) {
	if (!p || !q) return p | q;
	pushdown(p), pushdown(q);
	if (pri[p] > pri[q]) {
		ch[p][1] = merge(ch[p][1], q);
		return p;
	} else {
		ch[q][0] = merge(p, ch[q][0]);
		return q;
	}
}
bool find(int x) {
	int p = root;
	while (p) {
		if (val[p] == x) return true;
		pushdown(p);
		if (val[p] < x) p = ch[p][1];
		else p = ch[p][0];
	}
	return false;
}
void insert(int x) {
	if (find(x)) return;
	int a, b;
	split(root, x, a, b);
	int c = new_node();
	val[c] = x;
	b = merge(c, b);
	root = merge(a, b);
}
void solve() {
	int n; 
	scanf("%d", &n);
	int ans = 2 * n;
	int x; 
	scanf("%d", &x);
	tot = root = 0;
	int l = 0, r = 0;
	if (x % 2 == 0) {
		--ans;
		insert(x / 2);
	} else {
		l = 1, r = x - 1;
	}
	auto apply = [&](int x) {
		if (l) {
			l = x - l;
			r = x - r;
			swap(l, r);
		}
		tag(root, func(-1, x));
	};
	for (--n; n; --n) {
		scanf("%d", &x);
		int tmp;
		split(root, x, root, tmp);
		r = min(r, x - 1);
		if (l > r) l = r = 0;
		if (x % 2 == 0) {
			if (root == 0 && !l) {
				insert(x / 2);
				--ans;
			} else { 
				if ((l <= x / 2 && x / 2 <= r) || find(x / 2)) {
					root = 0;
					insert(x / 2);
					l = r = 0;
					ans -= 2;
				} else {
					insert(x / 2);
					--ans;
				}
				apply(x);
			}
		} else {
			if (root == 0 && !l) { 
				l = 1, r = x - 1;
			} else {
				apply(x);
				--ans;
			}
		}
	}
	printf("%d\n", ans);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}