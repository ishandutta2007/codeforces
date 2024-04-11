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

const int maxn = 1100100;
int a[maxn];
vector<int> g[maxn];
ll s[maxn];
int c0[maxn];
int cnt[maxn];
int d[maxn];
bool ok[maxn];

ll dfs(int u) {
  s[u] = a[u];
  for (int v : g[u]) {
    s[u] += dfs(v);
  }
  return s[u];
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
  assert(freopen("c.in", "r", stdin));
#endif
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i < n; ++i) {
    int p;
    scanf("%d", &p);
    --p;
    g[p].push_back(i);
  }
  dfs(0);
  for (int i = 0; i < n; ++i) {
    ll g = gcd(s[0], s[i]);
    ll x = s[0] / g;
    if (x <= n) {
      c0[x]++;
      //cerr << "q: " << x << '\n';
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; j += i) {
      cnt[j] += c0[i];
    }
  }
  for (int i = 1; i <= n; ++i) {
    assert(cnt[i] <= i);
    if (cnt[i] == i) {
      //cerr << "v: " << i << '\n';
      ok[i] = true;
    }
  }
  d[1] = 1;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (!ok[i]) {
      continue;
    }
    udd(ans, d[i]);
    for (int j = i * 2; j <= n; j += i) {
      if (ok[j]) {
        udd(d[j], d[i]);
      }
    }
  }
  cout << ans << '\n';
}