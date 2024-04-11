#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, K = 20;
int n, q, p[N], pos[N], st[N][K], lg[N], lp[N];
vector<int> d[N];
vector<pair<int, int>> vec[N], qry[N];
long long ans[1000005];
int cmp(int x, int y) {
	return p[x] > p[y] ? x : y;
}
int query(int l, int r) {
	int t = lg[r - l + 1];
	return cmp(st[l][t], st[r - (1 << t) + 1][t]);
}
inline void add(int x1, int x2, int y1, int y2) {
	vec[y1].emplace_back(x1, x2);
	vec[y2 + 1].emplace_back(-x1, -x2);
}
void solve(int l, int r) {
	if (l > r) {
		return;
	}
	int m = query(l, r);
	vector<pair<int, int>> v;
	for (auto x : d[p[m]]) {
		int y = p[m] / x;
		if (x == y) {
			continue;
		}
		int a, b;
		tie(a, b) = minmax(pos[x], pos[y]);
		if (a < l || b > r) {
			continue;
		}
		a = min(a, m);
		b = max(b, m);
		v.emplace_back(b, a);
	}
	sort(v.begin(), v.end());
	int mx = l - 1;
	for (auto it : v) {
		if (it.second <= mx) {
			continue;
		}
		add(mx + 1, it.second, it.first, r);
		mx = it.second;
	}
	solve(l, m - 1);
	solve(m + 1, r);
}
struct matrix {
	long long a[3][3];
	matrix() {
		memset(a, 0, sizeof a);
	}
	void init() {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				a[i][j] = (i == j);
			}
		}
	}
	bool check() {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (a[i][j] != (i == j)) {
					return true;
				}
			}
		}
		return false;
	}
} lazy[N << 2], val[N << 2];
matrix operator*(const matrix &lhs, const matrix &rhs) {
	matrix res;
	#define work(i, j, k) res.a[i][k] += lhs.a[i][j] * rhs.a[j][k]
	work(0, 0, 0);
	work(0, 0, 1);
	work(0, 1, 1);
	work(0, 0, 2);
	work(0, 1, 2);
	work(0, 2, 2);
	work(1, 1, 1);
	work(1, 1, 2);
	work(1, 2, 2);
	work(2, 2, 2);
	#undef work
	return res;
}
void operator*=(matrix &lhs, const matrix &rhs) {
	lhs = lhs * rhs;
}
matrix gen1(int x) {
	matrix A;
	A.a[0][0] = A.a[1][1] = A.a[2][2] = 1;
	A.a[0][1] = x;
	return A;
} 
matrix gen2() {
	matrix A;
	A.a[0][0] = A.a[1][1] = A.a[2][2] = A.a[1][2] = 1; 
	return A;
}
inline void push_up(int p) {
	#define work(i, j) val[p].a[i][j] = val[p << 1].a[i][j] + val[p << 1 | 1].a[i][j]
	work(0, 0);
	work(0, 1);
	work(0, 2);
	work(1, 1);
	work(1, 2);
	work(2, 2);
}
inline void tag(int p, const matrix &A) {
	val[p] *= A;
	lazy[p] *= A;
}
inline void push_down(int p) {
	if (lazy[p].check()) {
		tag(p << 1, lazy[p]);
		tag(p << 1 | 1, lazy[p]);
		lazy[p].init();
	}
}
void build(int p, int l, int r) {
	lazy[p].init();
	val[p].init();
	if (l == r) {
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	push_up(p);
}
void modify(int p, int l, int r, int ll, int rr, const matrix &A) {
	if (l >= ll && r <= rr) {
		tag(p, A);
		return;
	}
	push_down(p);
	int mid = (l + r) >> 1;
	if (mid >= ll) {
		modify(p << 1, l, mid, ll, rr, A);
	} if (mid < rr) {
		modify(p << 1 | 1, mid + 1, r, ll, rr, A);
	}
	push_up(p);
}
long long query(int p, int l, int r, int ll, int rr) {
	if (l >= ll && r <= rr) {
		return val[p].a[0][2];
	}
	push_down(p);
	int mid = (l + r) >> 1;
	long long res = 0;
	if (mid >= ll) {
		res += query(p << 1, l, mid, ll, rr);
	}
	if (mid < rr) {
		res += query(p << 1 | 1, mid + 1, r, ll, rr);
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	for (int i = 2; i < N; ++i) {
		lg[i] = lg[i / 2] + 1;
	}
	for (int i = 1; i * i < N; ++i) {
		for (int j = i * i; j < N; j += i) {
			d[j].emplace_back(i);
		}
	}
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		pos[p[i]] = i;
		st[i][0] = i;
	}
	for (int i = n; i; --i) {
		for (int k = 1; i + (1 << k) - 1 <= n; ++k) {
			st[i][k] = cmp(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
		}
	}
	solve(1, n);
	for (int i = 1; i <= q; ++i) {
		int l, r;
		cin >> l >> r;
		qry[r].emplace_back(l, i);
	}
	build(1, 1, n);
	for (int i = 1; i <= n; ++i) {
		for (auto it : vec[i]) {
			int l = it.first, r = it.second;
			if (l < 0) {
				modify(1, 1, n, -l, -r, gen1(-1));
			} else {
				modify(1, 1, n, l, r, gen1(1));
			}
		}
		tag(1, gen2());
		for (auto it : qry[i]) {
			int l = it.first, r = n, i = it.second;
			ans[i] = query(1, 1, n, l, r);
		}
	}
	for (int i = 1; i <= q; ++i) {
		cout << ans[i] << "\n";
	}
	return 0;
}