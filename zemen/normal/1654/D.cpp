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

struct Sieve {
  vector<int> minp;
  vector<int> ps;

  void build() {
    int B = (int) minp.size();
    for (int i = 2; i < B; ++i) {
      if (minp[i] == 0) {
        ps.push_back(i);
        minp[i] = i;
      }
      for (auto p : ps) {
        if (p * i >= B || p > minp[i]) {
          break;
        }
        minp[p * i] = p;
      }
    }
  }

  Sieve(int n): minp(n) {
    build();
  }
} sieve(3e5);

struct E {
  int to, x, y;
};
vector<vector<E>> g;

vector<int> dmin, d;
int res;
void dfs(int u, int cur, int prev = -1) {
  udd(res, cur);
  for (auto e : g[u]) {
    if (prev == e.to) {
      continue;
    }
    vector<pair<int, int>> ps;
    auto fac = [&](int x, int delta) {
      while (x > 1) {
        ps.emplace_back(sieve.minp[x], delta);
        x /= sieve.minp[x];
      }
    };
    fac(e.x, -1);
    fac(e.y, +1);
    for (auto [p, delta] : ps) {
      d[p] += delta;
      dmin[p] = min(dmin[p], d[p]);
    }
    dfs(e.to, mul(cur, inv(e.x), e.y), u);
    for (auto [p, delta] : ps) {
      d[p] -= delta;
    }
  }
}

void solve() {
  int n;
  cin >> n;
  g.assign(n, {});
  for (int i = 0; i < n - 1; ++i) {
    int u, v, x, y;
    cin >> u >> v >> x >> y;
    --u, --v;
    int gc = gcd(x, y);
    x /= gc;
    y /= gc;
    g[u].push_back(E{v, x, y});
    g[v].push_back(E{u, y, x});
  }
  d.assign(n + 1, 0);
  dmin = d;
  res = 0;
  dfs(0, 1);
  for (int i = 0; i <= n; ++i) {
    if (dmin[i] < 0) {
      //cerr << i << ' ' << dmin[i] << '\n';
      uul(res, bin(i, -dmin[i]));
    }
  }
  cout << res << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}