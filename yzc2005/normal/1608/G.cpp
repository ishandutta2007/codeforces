#include <bits/stdc++.h>
using namespace std;
const int P = 998244853;
struct Z {
	int x;
	Z(int _x = 0) : x(_x) {}
	inline Z operator-() const {
		if (!x) return 0;
		return Z(P - x);
	}
	inline bool operator==(const Z &rhs) const {
		return x == rhs.x;
	}
	inline bool operator!=(const Z &rhs) const {
		return x != rhs.x;
	}
	inline Z &operator+=(const Z &rhs) {
		x += rhs.x;
		if (x >= P) x -= P;
		return *this;
	}
	inline Z &operator-=(const Z &rhs) {
		x -= rhs.x;
		if (x < 0) x += P;
		return *this;
	}
	inline Z &operator*=(const Z &rhs) {
		x = 1ull * x * rhs.x % P;
		return *this;
	}
	inline Z operator+(const Z &rhs) const {
		Z res = *this;
		return res += rhs;
	}
	inline Z operator-(const Z &rhs) const {
		Z res = *this;
		return res -= rhs;
	}
	inline Z operator*(const Z &rhs) const {
		Z res = *this;
		return res *= rhs;
	}
};
Z pw[18];
int n, m, q, l;
vector<pair<int, int>> g[100005];
int bel[200005];
char s[200005];
using PI = pair<int, int>;
using PII = pair<PI, int>;
PII x[200005], y[200005];
int buc[200005], sa[200005], rk[200005];
vector<PII> qry[200005];
int ans[100005];
int dep[100005], par[100005][18];
Z f[200005][18], f1[100005][18], f2[100005][18];
void dfs(int u, int fa) {
	for (const auto &p : g[u]) {
		int v = p.first, w = p.second;
		if (v == fa) continue;
		dep[v] = dep[u] + 1;
		par[v][0] = u;
		f1[v][0] = f2[v][0] = w;
		for (int k = 1; k < 18; ++k) {
			par[v][k] = par[par[v][k - 1]][k - 1];
			f1[v][k] = f1[v][k - 1] + pw[k - 1] * f1[par[v][k - 1]][k - 1];
			f2[v][k] = pw[k - 1] * f2[v][k - 1] + f2[par[v][k - 1]][k - 1];
		}
		dfs(v, u);
	}
}
int LCA(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (int k = 17; ~k; --k)
		if (dep[par[u][k]] >= dep[v]) u = par[u][k];
	if (u == v) return u;
	for (int k = 17; ~k; --k) {
		if (par[u][k] != par[v][k]) {
			u = par[u][k];
			v = par[v][k];
		}
	}
	return par[u][0];
}
namespace BIT {
	int c[100005];
	inline void add(int p) {
		if (!p) return;
		for (; p <= m; p += p & -p)
			++c[p];
	}
	inline int query(int p) {
		int res = 0;
		for (; p; p -= p & -p)
			res += c[p];
		return res;
	}
	inline int query(int l, int r) {
		return query(r) - query(l - 1);
	}
}
inline int cmp(int pos, int u, int v, int w) {
	int l1 = dep[u] - dep[w], l2 = dep[v] - dep[w];
	Z x = 0, y = 0, coef = 1;
	while (l1) {
		int k =  __builtin_ctz(l1);
		Z x1 = x + coef * f1[u][k];
		Z y1 = y + coef * f[pos][k];
		if (x1 != y1) {
			for (int i = k - 1; ~i; --i) {
				Z x2 = x + coef * f1[u][i];
				Z y2 = y + coef * f[pos][i];
				if (x2 == y2) {
					x = x2, y = y2;
					u = par[u][i];
					pos += 1 << i;
					coef *= pw[i];
				}
			}
			return f[pos][0].x > f1[u][0].x ? 1 : -1; 
		} else {
			x = x1, y = y1;
			u = par[u][k];
			pos += 1 << k;
			coef *= pw[k];
		}
		l1 -= 1 << k;
	}
	vector<int> ver;
	while (l2) {
		ver.emplace_back(v);
		int k = __builtin_ctz(l2);
		v = par[v][k];
		l2 -= 1 << k;
	}
	reverse(ver.begin(), ver.end());
	for (auto v : ver) {
		int k = __builtin_ctz(dep[v] - dep[u]);
		Z x1 = x + coef * f2[v][k];
		Z y1 = y + coef * f[pos][k];
		if (x1 != y1) {
			int cur = v;
			for (int i = k - 1; ~i; --i) {
				Z x2 = x + coef * f2[par[cur][i]][i];
				Z y2 = y + coef * f[pos][i];
				if (x2 != y2) {
					cur = par[cur][i];
				} else {
					x = x2, y = y2;
					pos += 1 << i;
					coef *= pw[i];
				}
			}
			return f[pos][0].x > f2[cur][0].x ? 1 : -1;
		} else {
			x = x1, y = y1;
			u = v;
			pos += 1 << k;
			coef *= pw[k];
		}
	}
	return 0;
}
int main() {
	pw[0] = 2333;
	for (int i = 1; i < 18; ++i)
		pw[i] = pw[i - 1] * pw[i - 1];
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		char c = getchar();
		while (!isalpha(c))
			c = getchar();
		g[u].emplace_back(v, c);
		g[v].emplace_back(u, c);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%s", s + l + 1);
		int len = strlen(s + l + 1);
		fill(bel + l + 1, bel + l + len + 1, i);
		l += len;
		s[++l] = '@';
	}
	for (int i = 1; i <= l; ++i)
		rk[i] = s[i];
	int tot = l;
	for (int k = 1; k < l; k <<= 1) {
		for (int i = 1; i <= l; ++i)
			x[i] = PII(PI(rk[i], i + k > l ? 0 : rk[i + k]), i);
		if (k == 1) {
			sort(x + 1, x + l + 1);
		} else {
			memset(buc + 1, 0, tot * 4);
			for (int i = 1; i <= l; ++i)
				++buc[x[i].first.second];
			for (int i = 1; i <= tot; ++i)
				buc[i] += buc[i - 1];
			for (int i = 1; i <= l; ++i)
				y[buc[x[i].first.second]--] = x[i];
			memset(buc + 1, 0, tot * 4);
			for (int i = 1; i <= l; ++i)
				++buc[y[i].first.first];
			for (int i = 1; i <= tot; ++i)
				buc[i] += buc[i - 1];
			for (int i = l; i; --i)
				x[buc[y[i].first.first]--] = y[i];
		}
		tot = 0;
		for (int i = 1; i <= l; ++i) {
			if (i == 1 || x[i].first != x[i - 1].first) ++tot;
			rk[x[i].second] = tot;
		}
		if (tot == l) break;
	}
	for (int i = 1; i <= l; ++i)
		sa[rk[i]] = i;
	for (int i = l; i; --i) {
		f[i][0] = s[i];
		for (int k = 1; i + (1 << k) - 1 <= l; ++k)
			f[i][k] = f[i][k - 1] + pw[k - 1] * f[i + (1 << (k - 1))][k - 1];
	}
	dfs(1, 0);
	for (int i = 1; i <= q; ++i) {
		int u, v, L, R;
		scanf("%d%d%d%d", &u, &v, &L, &R);
		int w = LCA(u, v);
		int l = 1, r = ::l, pos = ::l + 1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (cmp(sa[mid], u, v, w) > 0)
				pos = mid, r = mid - 1;
			else 
				l = mid + 1;
		}
		l = 1, r = pos - 1;
		int pos1 = pos;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (cmp(sa[mid], u, v, w) == 0) 
				pos1 = mid, r = mid - 1;
			else
				l = mid + 1;
		}
		if (pos1 != pos) {
			qry[pos1 - 1].push_back(PII(PI(L, R), -i));
			qry[pos - 1].push_back(PII(PI(L, R), i));
		}	
	}
	for (int i = 1; i <= l; ++i) {
		BIT::add(bel[sa[i]]);
		for (const auto &p : qry[i]) {
			int l, r, id = p.second;
			tie(l, r) = p.first;
			if (id < 0) ans[-id] -= BIT::query(l, r);
			else ans[id] += BIT::query(l, r);
		}
	}
	for (int i = 1; i <= q; ++i)
		printf("%d\n", ans[i]);
	return 0;
}