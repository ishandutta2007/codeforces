#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= int(b); i++)
#define per(i, a, b) for (int i = (a); i >= int(b); i--)
#define fir first
#define sec second
#define tct template<class type>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int maxn = 2e3, mod = 1e9 + 7;
int n, K, L, x[maxn + 5], y[maxn + 5], c[maxn + 5], m, py[maxn + 5], cur, hei;
int Q, M, X[maxn + 5], Y[maxn + 5], st[maxn + 5], lc[maxn + 5], rc[maxn + 5];
ll A;
vector<int> vec[maxn + 5];
set<P> S;

inline void red(int &x) { x += x >> 31 & mod; }
tct inline void cmax(type &x, type y) { x < y ? x = y : 0; }
tct inline void cmin(type &x, type y) { x > y ? x = y : 0; }

inline bool comp(int i, int j) { return x[i] == x[j] ? y[i] < y[j] : x[i] < x[j]; }

struct rect {
	int l, r, h;
	rect(int l = 0, int r = 0, int h = 0): l(l), r(r), h(h) {}
	bool operator < (const rect &o) const { return l < o.l; }
} foo[3 * maxn + 5];

void work(int x, int l, int r) {
	if (Y[x] > cur) foo[++Q] = rect(X[l - 1] + 1, X[r + 1] - 1, Y[x] - cur);
	if (lc[x]) work(lc[x], l, x - 1);
	if (rc[x]) work(rc[x], x + 1, r);
}

int F(int x) {
	return 1ll * x * (x + 1) / 2 % mod;
}

void insert(int x, int y) {
	auto it = S.lower_bound(P(x + 1, 0));
	while (it != S.begin()) {
		if ((--it) -> sec > y) break;
		int L = 0, D = 0;
		if (it != S.begin()) {
			auto it0 = it;
			L = (--it0) -> fir;
		}
		auto it0 = it; ++it0;
		if (it0 != S.end()) {
			D = it0 -> sec;
		}
		A -= 1ll * (it -> fir - L) * (it -> sec - D);
		S.erase(it);
		it = S.lower_bound(P(x + 1, 0));
	}
	it = S.lower_bound(P(x, 0));
	if (it != S.end() && it -> sec >= y) return;
	int L = 0, D = 0;
	if (it != S.end()) D = it -> sec;
	if (it != S.begin()) L = (--it) -> fir;
	A += 1ll * (x - L) * (y - D);
	S.insert(P(x, y));
}

int main() {
	scanf("%d %d %d", &n, &K, &L);
	rep(i, 1, n) {
		scanf("%d %d %d", &x[i], &y[i], &c[i]);
		x[i]++, y[i]++, py[i] = y[i];
	}
	sort(py + 1, py + n + 1);
	m = unique(py + 1, py + n + 1) - (py + 1);
	int ans = 0;
	rep(k, 1, m) {
		cur = py[k], hei = L + 1 - cur;
		rep(i, 1, K) vector<int>().swap(vec[i]);
		rep(i, 1, n) if (y[i] >= py[k]) vec[c[i]].push_back(i);
		bool fl = false;
		rep(i, 1, K) if (vec[i].empty()) { fl = true; break; }
		if (fl) break;
		Q = 0;
		rep(i, 1, K) {
			sort(vec[i].begin(), vec[i].end(), comp);
			M = 0;
			rep(j, 0, vec[i].size() - 1) if (!j || x[vec[i][j]] != x[vec[i][j - 1]]) {
				X[++M] = x[vec[i][j]], Y[M] = y[vec[i][j]];
			}
			sort(X + 1, X + M + 1);
			X[0] = 0, X[M + 1] = L + 1;
			rep(i, 1, M) lc[i] = rc[i] = 0;
			int rt = 1, top = 0;
			rep(i, 1, M) {
				if (Y[i] <= Y[rt]) rt = i;
				int x = 0;
				while (top && Y[st[top]] >= Y[i]) x = st[top--];
				if (top) rc[st[top]] = i;
				lc[i] = x;
				st[++top] = i;
			}
			work(rt, 1, M);
			rep(i, 1, M + 1) if (X[i] > X[i - 1] + 1) {
				foo[++Q] = rect(X[i - 1] + 1, X[i] - 1, hei);
			}
		}
		sort(foo + 1, foo + Q + 1);
		foo[Q + 1].l = L + 1;
		set<P>().swap(S), A = 0;
		int res = 0;
		rep(i, 1, Q) {
			insert(foo[i].r, foo[i].h);
			int x = foo[i].l;
			while (!S.empty()) {
				auto it = S.begin();
				int y = min(it -> fir + 1, foo[i + 1].l);
				red(res += A % mod * (y - x) % mod - mod);
				red(res -= 1ll * (x + y - 3) * (y - x) / 2 % mod * it -> sec % mod);
				x = y;
				if (it -> fir + 1 > foo[i + 1].l) break;
				int D = 0;
				auto it0 = it; it0++;
				if (it0 != S.end()) D = it0 -> sec;
				A -= 1ll * it -> fir * (it -> sec - D);
				S.erase(it);
			}
		}
		red(res = 1ll * F(L) * hei % mod - res);
		red(ans += 1ll * (py[k] - py[k - 1]) * res % mod - mod);
	}
	printf("%d\n", ans);
	return 0;
}