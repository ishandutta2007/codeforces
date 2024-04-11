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


const int maxn = 200200;
vector<int> g[maxn];
int deg[maxn];
int d[maxn];

signed main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    deg[v]++;
  }
  queue<int> q;
  int res = 1;
  for (int i = 0; i < 2 * n; ++i) {
    d[i] = 1;
    if (deg[i] == 0) {
      q.push(i);
    }
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (g[u].empty()) {
      uul(res, d[u]);
    } else {
      int v = g[u][0];
      udd(d[v], d[u]);
      if (--deg[v] == 0)
        q.push(v);
    }
  }
  for (int u = 0; u < 2 * n; ++u) {
    if (deg[u] == 0)
      continue;
    if (g[u][0] != u) {
      uul(res, 2);
    }
    while (deg[u] > 0) {
      --deg[u];
      u = g[u][0];
    }
  }
  cout << res << '\n';
}