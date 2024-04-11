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

const int N = 100100;
int fac[N];
int ifac[N];

int C(int n, int k) {
  assert(0 <= k && k <= n && n < N);
  return mul(fac[n], ifac[k], ifac[n - k]);
}

int zways(int zl, int zr, bool first) {
  if (!first) {
    ++zl, ++zr;
  }
  int res = 0;
  for (int d = 0; d <= min(zl, zr); ++d) {
    udd(res, mul(C(zl, d), C(zr, d)));
  }
  return res;
}

signed main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  fac[0] = ifac[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = mul(fac[i - 1], i);
    ifac[i] = inv(fac[i]);
  }
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int ii = 0; ii < tn; ++ii) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int l = 0, r = n - 1;
    bool first = true;
    int res = 1;
    while (l <= r) {
      int zl = 0, zr = 0;
      while (l < n && a[l] == 0) {
        ++l;
        ++zl;
      }
      while (r >= 0 && a[r] == 0) {
        --r;
        ++zr;
      }
      if (l > r) {
        assert(zl == zr);
        int deg = zl - 1;
        if (!first) {
          deg += 2;
        }
        uul(res, bin(2, deg));
        break;
      }
      ll sl = a[l], sr = a[r];
      assert(sl > 0 && sr > 0);
      while (sl != sr) {
        assert(l < n && r >= 0);
        if (sl < sr) {
          ++l;
          sl += a[l];
        } else {
          --r;
          sr += a[r];
        }
      }
      uul(res, zways(zl, zr, first));
      if (l + 1 == r) {
        uul(res, 2);
      }
      ++l, --r;
      first = false;
    }
    cout << res << '\n';
  }
}