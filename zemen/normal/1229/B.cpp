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

const int maxn = 100100;
ll x[maxn];
vector<int> g[maxn];
int res = 0;

ll gcd(ll a, ll b) {
  while (a && b) {
    if (a >= b) {
      a %= b;
    } else {
      b %= a;
    }
  }
  return a + b;
}

void dfs(int u, vector<pair<ll, int>> path, int prev = -1) {
  for (auto p : path) {
    udd(res, (p.first * p.second) % mod);
  }
  for (int v : g[u]) {
    if (v == prev) {
      continue;
    }
    vector<pair<ll, int>> npath;
    auto append = [&npath](pair<ll, int> p) {
      if (!npath.empty() && npath.back().first == p.first) {
        npath.back().second += p.second;
      } else {
        npath.push_back(p);
      }
    };
    for (auto p : path) {
      p.first = gcd(p.first, x[v]);
      append(p);
    }
    append({x[v], 1});
    dfs(v, npath, u);
  }
}

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0, {{x[0], 1}});
  cout << res << '\n';
}