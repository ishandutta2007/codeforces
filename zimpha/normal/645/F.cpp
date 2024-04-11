#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1000000 + 10, M = 1e9 + 7;

vector<int> dv[MAXN];
int fac[MAXN], inv[MAXN];
int n, k, q;

LL pm(LL a, LL n) {
  LL r = 1;
  for (; n; n >>= 1) {
    if (n & 1) r = r * a % M;
    a = a * a % M;
  }
  return r;
}

inline LL C(int n, int m) {
  if (m > n) return 0;
  else return (LL)fac[n] * inv[n - m] % M;
}

int S[MAXN];
int f[MAXN], mx;

inline void add(int &x, int y) {
  x += y; if (x >= M) x -= M;
}
inline void sub(int &x, int y) {
  x -= y; if (x < 0) x += M;
}

int main() {
  for (int i = 1; i < MAXN; ++i) {
    for (int j = i; j < MAXN; j += i) dv[j].push_back(i);
  }
  fac[0] = inv[0] = 1; mx = 0;
  for (int i = 1; i < MAXN; ++i) {
    fac[i] = 1ll * i * fac[i - 1] % M;
    inv[i] = pm(fac[i], M - 2);
  }
  scanf("%d%d%d", &n, &k, &q);
  for (int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    for (auto &v: dv[x]) S[v]++;
    mx = max(mx, x);
  }
  int ret = 0;
  for (int g = mx; g >= 1; --g) {
    f[g] = C(S[g], k);
    for (int i = g + g; i <= mx; i += g) {
      sub(f[g], f[i]);
    }
    add(ret, (LL)f[g] * g % M);
  }
  for (int _ = 0; _ < q; ++_) {
    int x; scanf("%d", &x);
    vector<int> &d = dv[x];
    vector<int> pf(d.size());
    for (size_t i = 0; i < d.size(); ++i) pf[i] = f[d[i]];
    for (int i = d.size() - 1; i >= 0; --i) {
      int u = d[i];
      sub(ret, (LL)pf[i] * u % M);
      for (auto &v: dv[u]) if (v < u) {
        add(f[v], pf[i]);
      }
      sub(f[u], C(S[u], k));
    }

    for (auto &u: d) S[u]++;

    for (int i = d.size() - 1; i >= 0; --i) {
      int u = d[i];
      add(f[u], C(S[u], k));
      for (auto &v: dv[u]) if (v < u) {
        sub(f[v], f[u]);
      }
      add(ret, (LL)f[u] * u % M);
    }
    //for (int i = 1; i <= 20; ++i) printf("%d ", f[i]); puts("");
    printf("%lld\n", (LL)ret * inv[k] % M);
  }
  return 0;
}