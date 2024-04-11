#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int mod = 998244353;
template<typename T>
T add(T x) {
  return x;
}
template<typename T, typename... Ts>
T add(T x, Ts... y) {
  T res = x + add(y...);
  if (res >= mod)
    res -= mod;
  return res;
}
template<typename T, typename... Ts>
T sub(T x, Ts... y) {
  return add(x, mod - add(y...));
}
template<typename T, typename... Ts>
void udd(T& x, Ts... y) {
  x = add(x, y...);
}
template<typename T, typename... Ts>
void uub(T& x, Ts... y) {
  x = sub(x, y...);
}
template<typename T>
T mul(T x) {
  return x;
}
template<typename T, typename... Ts>
T mul(T x, Ts... y) {
  return (x * 1ll * mul(y...)) % mod;
}
template<typename T, typename... Ts>
void uul(T& x, Ts... y) {
  x = mul(x, y...);
}
int bin(int a, ll deg) {
  int r = 1;
  while (deg) {
    if (deg & 1)
      uul(r, a);
    deg >>= 1;
    uul(a, a);
  }
  return r;
}
int inv(int x) {
  assert(x);
  return bin(x, mod - 2);
}

const int maxn = 200200;
vector<int> to[maxn];
int f[maxn];
int g[maxn];

void dfs(int u) {
  if (to[u].empty()) {
    f[u] = g[u] = 1;
    return;
  }
  vector<int> fs, gs, pref{1}, suf{1};
  int fg = 1;
  for (int v : to[u]) {
    dfs(v);
    fs.push_back(f[v]);
    gs.push_back(g[v]);
    uul(fg, add(f[v], g[v]));
  }
  int k = (int) to[u].size();
  for (int i = 0; i < k; ++i) {
    pref.push_back(mul(pref.back(), fs[i]));
  }
  for (int i = k - 1; i >= 0; --i) {
    suf.push_back(mul(suf.back(), fs[i]));
  }
  g[u] = sub(fg, pref.back());
  f[u] = fg;
  for (int i = 0; i < k; ++i) {
    uub(f[u], mul(pref[i], suf[k - i - 1], gs[i]));
  }
}

signed main() {
#ifdef LOCAL
  assert(freopen("f.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    to[p - 1].push_back(i);
  }
  dfs(0);
  cout << f[0] << '\n';
}