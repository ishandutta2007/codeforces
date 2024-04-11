#pragma GCC optimize("Ofast,no-stack-protector")
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

const int N = 300300;
vector<int> d(N);
vector<int> f(N);
vector<int> fi(N);

int ways(int a, int b) {
  assert(a >= 0 && b >= 0 && a + b < N);
  return mul(f[a + b], fi[a], fi[b]);
}

int calc(int n) {
  int res = 0;
  int pw2 = 1;
  int mt = 1;
  for (int k = 0; 4 * k <= n; ++k) {
    int m = n - 4 * k;
    udd(res, mul(d[m], pw2, ways(m, 2 * k), mt));
    uul(pw2, 2);
    uul(mt, k * 2 + 1);
  }
  return res;
}

int naive(int n) {
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  int res = 0;
  do {
    bool ok = true;
    vector<int> pi(n);
    for (int i = 0; i < n; ++i) {
      pi[p[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
      if (abs(p[i] - pi[i]) > 1) {
        ok = false;
      }
    }
    res += ok;
  } while (next_permutation(p.begin(), p.end()));
  return res;
}

signed main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  d[0] = d[1] = 1;
  for (int i = 2; i < N; ++i) {
    d[i] = add(d[i - 1], mul(i - 1, d[i - 2]));
  }
  f[0] = fi[0] = 1;
  for (int i = 1; i < N; ++i) {
    f[i] = mul(f[i - 1], i);
    fi[i] = inv(f[i]);
  }

  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    int n;
    cin >> n;
    cout << calc(n) << '\n';
    //cerr << naive(n) << '\n';
  }
}