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

int p;

const int maxn = 2005;
int e[maxn][maxn];
int d[maxn];
int c[maxn][maxn];
const int N = maxn - 2;

vector<int> ppow;
vector<int> ippow;

int c2(ll x) {
  return (x * (x - 1) / 2) % mod;
}

void pre() {
  ppow.resize(maxn);
  ippow.resize(maxn);
  for (int i = 0; i < N; ++i) {
    ppow[i] = i ? mul(ppow[i - 1], p) : 1;
    ippow[i] = i ? mul(ippow[i - 1], sub(1, p)) : 1;
  }

  for (int i = 0; i < N; ++i) {
    e[i][0] = e[i][i] = 1;
  }
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j < i; ++j) {
      e[i][j] = add(mul(e[i - 1][j], ppow[j]), mul(e[i - 1][j - 1], ippow[i - j]));
    }
  }

  for (int n = 1; n < N; ++n) {
    int sum = 0;
    for (int s = 1; s < n; ++s) {
      uul(e[n][s], e[s][s]);
      udd(sum, e[n][s]);
    }
    e[n][n] = sub(1, sum);
  }

  //for (int i = 1; i < 10; ++i) {
    //int sum = 0;
    //cerr << "n: " << i << " ... ";
    //for (int j = 1; j <= i; ++j) {
      //udd(sum, e[i][j]);
      //cerr << mul(8, e[i][j]) << ' ';
    //}
    //cerr << "sum: " << sum << '\n';
  //}


  d[1] = 0;
  for (int n = 2; n < N; ++n) {
    int bad = e[n][n];
    assert(bad != 1);
    int iall = inv(sub(1, bad));
    d[n] = mul(iall, c2(n));

    for (int s = 1; s < n; ++s) {
      int prob = mul(e[n][s], iall);
      int es = add(d[s], d[n - s]);
      es = sub(es, c2(n - s));
      udd(d[n], mul(es, prob));
    }
  }
}

signed main() {
#ifdef LOCAL
  assert(freopen("f.in", "r", stdin));
#endif
  int n, a, b;
  cin >> n >> a >> b;
  p = mul(a, inv(b));
  pre();
  cout << d[n] << '\n';
}