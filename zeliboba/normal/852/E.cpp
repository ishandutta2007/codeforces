#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

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

const int maxn = 100100;
vector<int> g[maxn];
int d[maxn];

void dfs1(int u) {
  d[u] = 1;
  for (int v : g[u]) {
    g[v].erase(find(all(g[v]), u));
    dfs1(v);
    uul(d[u], d[v]);
  }
  if (!g[u].empty())
    uul(d[u], 2);
}

int main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  int n;
  cin >> n;
  forn (i, n - 1) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int l = 0;
  forn (i, n)
    if (sz(g[i]) == 1)
      ++l;
  int pw = bin(2, n - l);
  int res = mul(pw, n + l);
  cout << res << '\n';
}