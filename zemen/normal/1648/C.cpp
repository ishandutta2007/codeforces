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

struct Fenwick {
  vector<ll> t, a;

  Fenwick(int n) : t(n), a(n) {
  }

  void add(int pos, ll delta) {
    assert(0 <= pos && pos < (int) t.size());
    a[pos] += delta;
    for (int i = pos; i < (int) t.size(); i |= i + 1) {
      t[i] += delta;
    }
  }

  void set(int pos, ll val) {
    add(pos, val - a[pos]);
  }

  ll get(int r) {
    ll res = 0;
    for (int i = r - 1; i >= 0; i = (i & (i + 1)) - 1) {
      res += t[i];
    }
    return res;
  }

  ll get(int l, int r) {
    return get(r) - get(l);
  }
};

const int N = 200200;
vector<int> fact(N, 1);
vector<int> ifact(N, 1);

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  for (int i = 1; i + 1 < N; ++i) {
    fact[i + 1] = mul(fact[i], i + 1);
    ifact[i + 1] = mul(ifact[i], inv(i + 1));
  }
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  Fenwick fw(N);
  vector<int> cnt(N);

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++cnt[x];
    fw.set(x, cnt[x]);
  }

  int ways = fact[n];
  for (int i = 0; i < N; ++i) {
    uul(ways, ifact[cnt[i]]);
  }

  vector<int> t(m);
  for (int i = 0; i < m; ++i) {
    cin >> t[i];
  }

  int res = 0;
  for (int i = 0; i < m; ++i) {
    int x = t[i];

    if (i == n) {
      udd(res, 1);
      break;
    }

    uul(ways, inv(n - i));
    udd(res, mul(ways, fw.get(x)));

    if (cnt[x] == 0) {
      break;
    }

    uul(ways, cnt[x]);
    --cnt[x];
    fw.set(x, cnt[x]);
  }

  cout << res << '\n';
}