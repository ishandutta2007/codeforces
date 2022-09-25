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

const int maxn = 4000;
int d[maxn][maxn];

vector<int> pre(const vector<char>& a) {
  int n = (int) a.size();
  memset(d, 0, sizeof(d));
  d[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    bool ok = i + 1 < n && !a[i] && !a[i + 1];
    for (int j = 0; j <= n; ++j) {
      udd(d[i + 1][j], d[i][j]);
      if (ok) {
        udd(d[i + 2][j + 1], d[i][j]);
      }
    }
  }
  vector<int> res(n + 1);
  for (int i = 0; i <= n; ++i) {
    res[i] = d[n][i];
  }
  return res;
}

int c[maxn][maxn];
int fact[maxn];

signed main() {
#ifdef LOCAL
  assert(freopen("f.in", "r", stdin));
#endif
  fact[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    fact[i] = mul(fact[i - 1], i);
  }
  for (int i = 0; i < maxn; ++i) {
    c[i][0] = c[i][i] = 1;
  }
  for (int i = 0; i < maxn; ++i) {
    for (int j = 1; j < i; ++j) {
      c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
    }
  }
  int h, w, n;
  cin >> h >> w >> n;
  vector<char> a[2];
  a[0].resize(h);
  a[1].resize(w);
  for (int i = 0; i < n; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    a[0][x1 - 1] = true;
    a[0][x2 - 1] = true;
    a[1][y1 - 1] = true;
    a[1][y2 - 1] = true;
  }
  vector<int> d[2];
  int s[2];
  for (int i = 0; i < 2; ++i) {
    s[i] = 0;
    for (auto c : a[i]) {
      s[i] += !c;
    }
    d[i] = pre(a[i]);
  }

  int res = 0;
  for (int a = 0; a * 2 <= s[0]; ++a) {
    for (int b = 0; b * 2 <= s[1]; ++b) {
      int ra = s[0] - a * 2;
      int rb = s[1] - b * 2;
      if (ra < b || rb < a) {
        continue;
      }
      int w = mul(d[0][a], d[1][b], c[ra][b], c[rb][a], fact[a], fact[b]);
      udd(res, w);
    }
  }
  cout << res << '\n';
}