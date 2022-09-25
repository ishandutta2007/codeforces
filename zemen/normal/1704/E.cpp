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

const int maxn = 1005;
int a[maxn];
char used[maxn];
int ways[maxn];
vector<int> g[maxn];
vector<int> ord;

void dfs(int u) {
  used[u] = true;
  for (int v : g[u]) {
    if (!used[v]) {
      dfs(v);
    }
  }
  ord.push_back(u);
}

signed main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int ii = 0; ii < tn; ++ii) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      g[i].clear();
      used[i] = false;
    }
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      g[u].push_back(v);
    }
    ord.clear();
    for (int i = 0; i < n; ++i) {
      if (!used[i]) {
        dfs(i);
      }
    }
    reverse(ord.begin(), ord.end());
    int total = 0;
    for (int p = n - 1; p >= 0; --p) {
      int i = ord[p];
      ways[i] = p == n - 1 ? 1 : 0;
      for (int v : g[i]) {
        udd(ways[i], ways[v]);
      }
      udd(total, mul(ways[i], a[i]));
    }
    for (int i = 0; i < n; ++i) {
      bool skip = a[ord.back()] == 0;
      bool empty = true;
      for (int p = n - 1; p >= 0; --p) {
        int u = ord[p];
        if (a[u] > 0) {
          empty = false;
          --a[u];
          for (int v : g[u]) {
            ++a[v];
          }
        }
      }
      if (empty) {
        break;
      }
      if (skip) {
        assert(i < n);
        udd(total, 1);
      }
    }
    cout << total << '\n';
  }
}