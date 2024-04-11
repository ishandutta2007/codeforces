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
const int maxd = 30;
vector<pair<int, int>> g[maxn];

struct Dist {
  int k, s;

  bool operator<(const Dist& d) const {
    if (k == d.k) {
      return s < d.s;
    }
    if (max(k, d.k) >= maxd) {
      return k < d.k;
    }
    return (1 << k) + s < (1 << d.k) + d.s;
  }

  bool operator==(const Dist& d) const {
    return !(*this < d) && !(d < *this);
  }
};

Dist dist[maxn][maxd];

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].emplace_back(v, 0);
    g[v].emplace_back(u, 1);
  }
  const int inf = 1e9;

  vector<int> mink(n, inf);
  mink[0] = 0;
  deque<int> q;
  q.push_back(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop_front();
    for (auto& [v, sgn] : g[u]) {
      int cost = mink[u] % 2 != sgn;
      int ndist = mink[u] + cost;
      if (ndist >= mink[v]) {
        continue;
      }
      mink[v] = ndist;
      if (cost == 0) {
        q.push_front(v);
      } else {
        q.push_back(v);
      }
    }
  }
  //for (int i = 0; i < n; ++i) {
    //cerr << mink[i] << ' ';
  //}
  //cerr << '\n';
  for (int i = 0; i < n; ++i) {
    for (int d = 0; d < maxd; ++d) {
      dist[i][d] = {inf, inf};
    }
  }
  using Elem = pair<Dist, pair<int, int>>;
  priority_queue<Elem, vector<Elem>, greater<Elem>> o;
  dist[0][0] = {0, 0};
  o.emplace(dist[0][0], pair<int, int>{0, 0});
  while (!o.empty()) {
    auto [cdist, node] = o.top();
    o.pop();
    if (!(cdist == dist[node.first][node.second - mink[node.first]])) {
      continue;
    }
    for (auto& [v, sgn] : g[node.first]) {
      if (sgn != node.second % 2) {
        continue;
      }
      Dist ndist = cdist;
      ++ndist.s;
      pair<int, int> to{v, node.second};
      if (to.second - mink[to.first] >= maxd) {
        continue;
      }
      auto& res = dist[to.first][to.second - mink[to.first]];
      if (ndist < res) {
        res = ndist;
        o.emplace(res, to);
      }
    }
    for (int ii = 0; ii < 1; ++ii) {
      pair<int, int> to{node.first, node.second + 1};
      Dist ndist = cdist;
      ndist.k++;
      if (to.second - mink[to.first] >= maxd) {
        continue;
      }
      auto& res = dist[to.first][to.second - mink[to.first]];
      if (ndist < res) {
        res = ndist;
        o.emplace(res, to);
      }
    }
  }
  Dist ans{inf, inf};
  for (int d = 0; d < maxd; ++d) {
    ans = min(ans, dist[n - 1][d]);
  }
  //cerr << ans.k << ' ' << ans.s << '\n';
  int res = ans.s;
  int pw = 1;
  for (int it = 0; it < ans.k; ++it) {
    udd(res, pw);
    udd(pw, pw);
  }
  cout << res << '\n';
}