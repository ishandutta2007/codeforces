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
template<typename T>
void uub(T& x, T y) {
  x = sub(x, y);
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

const int LG = 17;
const int B = 1 << LG;

vector<int> or_conv(vector<int> a) {
  vector<int> res(B);
  for (int mask = 0; mask < B; ++mask) {
    int emask = mask ^ (B - 1);
    for (int m2 = emask; m2 > 0; m2 = (m2 - 1) & emask) {
      udd(res[mask | m2], mul(a[mask], a[m2]));
    }
    udd(res[mask], mul(a[mask], a[0]));
  }
  return res;
}

int fib[B];

vector<int> fibo(vector<int> a) {
  for (int i = 0; i < B; ++i) {
    uul(a[i], fib[i]);
  }
  return a;
}

vector<int> and_conv(vector<int> a, bool inv) {
  for (int bit = 0; bit < LG; ++bit) {
    for (int i = 0; i < B; ++i) {
      if (i & (1 << bit)) {
        if (!inv) {
          udd(a[i ^ (1 << bit)], a[i]);
        } else {
          uub(a[i ^ (1 << bit)], a[i]);
        }
      }
    }
  }
  return a;
}


void rec_conv(int* f, int n) {
  if (n == 1) {
    uul(f[0], f[0]);
    return;
  }
  for (int i = 0; i < n / 2; ++i) {
    int a = f[i], b = f[i + n / 2];
    f[i] = add(a, b);
    f[i + n / 2] = sub(a, b);
  }
  rec_conv(f, n / 2);
  rec_conv(f + n / 2, n / 2);

  int inv2 = (mod + 1) / 2;
  for (int i = 0; i < n / 2; ++i) {
    int a = f[i], b = f[i + n / 2];
    f[i] = mul(add(a, b), inv2);
    f[i + n / 2] = mul(sub(a, b), inv2);
  }
}

vector<int> xor_conv(vector<int> a) {
  rec_conv(a.data(), B);
  return a;
}

void print(vector<int> a) {
  for (int i = 0; i < 10; ++i) {
    cerr << a[i] << ' ';
  }
  cerr << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("g.in", "r", stdin));
#endif
  int n;
  cin >> n;
  vector<int> a(B);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++a[x];
  }
  fib[0] = 0;
  fib[1] = 1;
  for (int i = 2; i < B; ++i) {
    fib[i] = add(fib[i - 2], fib[i - 1]);
  }
  vector<int> b = fibo(or_conv(a));
  print(b);
  vector<int> c = fibo(xor_conv(a));
  print(c);
  a = fibo(a);
  print(a);

  a = and_conv(a, false);
  b = and_conv(b, false);
  c = and_conv(c, false);
  for (int i = 0; i < B; ++i) {
    uul(a[i], b[i], c[i]);
  }
  a = and_conv(a, true);

  int res = 0;
  for (int i = 0; i < B; ++i) {
    if (__builtin_popcount(i) == 1) {
      udd(res, a[i]);
    }
  }
  cout << res << '\n';
}