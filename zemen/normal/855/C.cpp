#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
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
void udd(T &x, Ts... y) {
  x = add(x, y...);
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
void uul(T &x, Ts... y) {
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


const int maxn = 100100;
vector<int> g[maxn];
int d[maxn][11][3];
int m, k, x;

int f[2][11][3];

void dfs(int u) {
  for (int v : g[u]) {
    auto it = find(g[v].begin(), g[v].end(), u);
    g[v].erase(it);
    dfs(v);
  }
  int q = 0;
  memset(f, 0, sizeof(f));
  f[q][0][0] = k;
  f[q][1][1] = 1;
  f[q][0][2] = m - k - 1;
  for (int v : g[u]) {
    memset(f[q ^ 1], 0, sizeof(f[q ^ 1]));
    for (int j = 0; j <= x; ++j) {
      for (int t = 0; t < 3; ++t) {
        int cur = d[v][j][t];
        if (!cur)
          continue;
        for (int j2 = 0; j + j2 <= x; ++j2) {
          for (int t2 = 0; t2 < 3; ++t2) {
            if (t == 1 && t2 != 0)
              continue;
            if (t2 == 1 && t != 0)
              continue;
            udd(f[q ^ 1][j + j2][t2], mul(cur, f[q][j2][t2]));
          }
        }
      }
    }
    q ^= 1;
  }
  for (int j = 0; j <= x; ++j) {
    for (int t = 0; t < 3; ++t) {
      d[u][j][t] = f[q][j][t];
    }
  }
}

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  int n;
  cin >> n >> m;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  cin >> k >> x;
  --k;
  const int root = 0 % n;
  dfs(root);
  int res = 0;
  for (int j = 0; j <= x; ++j) {
    for (int t = 0; t < 3; ++t) {
      udd(res, d[root][j][t]);
    }
  }
  cout << res << '\n';
}