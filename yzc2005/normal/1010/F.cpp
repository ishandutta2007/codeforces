#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
inline void add(int &x, const int y) {(x += y) >= mod && (x -= mod);}
inline int Add(int x, const int y) {return add(x, y), x;}
inline void sub(int &x, const int y) {(x -= y) < 0 && (x += mod);}
inline int Sub(int x, const int y) {return sub(x, y), x;}
inline void mul(int &x, const int y) {x = 1ll * x * y % mod;}
inline int Mul(const int x, const int y) {return 1ll * x * y % mod;}
inline int power(int a, int b, int c = 1) {
  for (; b; b >>= 1, mul(a, a))
    if (b & 1) mul(c, a);
  return c;
}
const int _N = (1 << 18) + 5;
using poly = vector<int>;
int w[233];
void dft(int *a, int n) {
  for (int i = 0, j = 0; i < n; ++i) {
    if (i < j) swap(a[i], a[j]);
    for (int k = n >> 1; (j ^= k) < k; k >>= 1);
  }
  for (int k = 1, m = 0; k < n; k <<= 1, ++m) {
    int wn = ::w[m];
    for (int i = 0; i < n; i += k << 1) {
      for (int j = 0, w = 1; j < k; ++j) {
        int x  = Mul(w, a[i + j + k]);
        a[i + j + k] = Sub(a[i + j], x);
        add(a[i + j], x);
        mul(w, wn);
      }
    }
  }
}
void idft(int *a, int n) {
  reverse(a + 1, a + n);
  dft(a, n); int coef = power(n, mod - 2);
  for (int i = 0; i < n; ++i) mul(a[i], coef);
}
int extend(int n) {int x = 1; while (x < n) x <<= 1; return x;}
poly operator + (poly a, const poly &b) {
  if (a.size() < b.size()) a.resize(b.size());
  for (int i = 0; i < a.size(); ++i) add(a[i], b[i]);
  return a;
} 
poly operator * (const poly &a, const poly &b) {
  int len = a.size() + b.size() - 1;
  if (len <= 100) {
    poly c(len);
    for (int i = 0; i < a.size(); ++i) 
      for (int j = 0; j < b.size(); ++j)  
        add(c[i + j], Mul(a[i], b[j]));
    return c;
  }
  int n = extend(len);
  static int f[_N], g[_N];
  for (int i = 0; i < n; ++i)
    f[i] = i < a.size() ? a[i] : 0, 
    g[i] = i < b.size() ? b[i] : 0;
  dft(f, n), dft(g, n);
  for (int i = 0; i < n; ++i) mul(f[i], g[i]);
  idft(f, n); poly c(len);
  for (int i = 0; i < len; ++i) c[i] = f[i];
  return c;
}
const int N = 1e5 + 5;
int n, sz[N], son[N], top[N], fa[N];
vector<int> g[N];
long long x;
poly f[N], a[N];
void dfs1(int u) {
  sz[u] = 1;
  for (auto v : g[u]) {
    if (v == fa[u]) continue;
    fa[v] = u, dfs1(v);
    sz[u] += sz[v];
    if (sz[v] > sz[son[u]]) son[u] = v; 
  }
}
void dfs2(int u) {
  if (son[u]) top[son[u]] = top[u], dfs2(son[u]);
  for (auto v : g[u]) if (v != fa[u] && v != son[u]) top[v] = v, dfs2(v); 
}
pair<poly, poly> solve(int l, int r) {
  if (l == r) return make_pair(a[l], a[l]);
  int mid = l + r >> 1;
  auto lef = solve(l, mid), rig = solve(mid + 1, r);
  return make_pair(lef.first * rig.first, lef.second + lef.first * rig.second);
}
poly calc(int u) {
  for (int v = u; v; v = son[v]) {
    f[v] = {0};
    for (auto _v : g[v]) if (_v != fa[v] && _v != son[v]) f[v] = calc(_v);
    ++f[v][0], f[v].insert(f[v].begin(), 0);
  }
  int cur = 0;
  for (int v = u; v; v = son[v]) a[++cur] = f[v];
  return solve(1, cur).second;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); 
  cin >> n >> x, x %= mod; 
  for (int i = 0; i < 20; ++i)
    w[i] = power(3, (mod - 1) / (1 << i + 1));
  for (int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    g[u].emplace_back(v), g[v].emplace_back(u);
  }
  dfs1(1), top[1] = 1, dfs2(1); 
  auto res = calc(1); 
  int ans = 0, binom = 1, ix = x;
  for (int i = 1; i <= n; ++i) {
    add(ans, Mul(res[i], binom));
    add(ix, 1), mul(binom, power(i, mod - 2, ix));
  }
  cout << ans << endl;
  return 0;
}