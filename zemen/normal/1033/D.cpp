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

ll pw(ll x, int deg) {
  ll q = 1;
  for (int i = 0; i < deg; ++i) {
    q *= x;
  }
  return q;
}

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

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  int n;
  cin >> n;
  vector<ll> a(n);
  map<ll, int> dc;
  set<int> dbl;
  vector<ll> b;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    bool fuck = false;
    for (int r : {4, 3, 2}) {
      ll x = powl(a[i], 1. / r);
      while (pw(x, r) < a[i]) {
        ++x;
      }
      while (pw(x, r) > a[i]) {
        --x;
      }
      if (pw(x, r) == a[i]) {
        fuck = true;
        dc[x] += r;
        break;
      }
    }
    if (fuck) {
      continue;
    }
    b.push_back(a[i]);
    dbl.insert(a[i]);
  }
  for (auto x : b) {
    bool fuck = false;
    for (auto y : a) {
      ll g = gcd(x, y);
      if (g > 1 && g < x) {
        fuck = true;
        dc[g]++;
        dc[x / g]++;
        break;
      }
    }
    if (!fuck) {
      dc[x]++;
    }
  }

  int res = 1;
  for (auto [p, d] : dc) {
    if (dbl.count(p)) {
      uul(res, pw(d + 1, 2));
    } else {
      uul(res, d + 1);
    }
  }
  cout << res << '\n';
}