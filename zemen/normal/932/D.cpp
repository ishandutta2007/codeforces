#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 400400;
const int lg = 19;
ll w[maxn];
int p[maxn][lg];
int h[maxn];
ll wsum[maxn];

void add(int u, int v, ll x) {
  w[v] = x;
  for (int d = lg - 1; d >= 0; --d) {
    if (w[p[u][d]] < x) {
      u = p[u][d];
    }
  }
  if (w[u] < x) {
    u = p[u][0];
  }
  wsum[v] = x;
  if (w[u] < x) {
    u = v;
    p[v][0] = u;
    h[v] = 0;
  } else {
    wsum[v] += wsum[u];
    p[v][0] = u;
    h[v] = h[u] + 1;
  }
  for (int d = 1; d < lg; ++d) {
    p[v][d] = p[p[v][d - 1]][d - 1];
  }
}

int ask(int u, ll x) {
  ll W = wsum[u];
  if (w[u] > x) {
    return 0;
  }
  int v = u;
  for (int d = lg - 1; d >= 0; --d) {
    if (W - wsum[p[v][d]] <= x) {
      v = p[v][d];
    }
  }
  int cnt = h[u] - h[v];
  if (W - wsum[v] + w[v] <= x) {
    ++cnt;
  }
  return cnt;
}

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  int last = 0;
  int cnt = 1;
  for (int i = 0; i < q; ++i) {
    int t;
    ll p, q;
    cin >> t >> p >> q;
    p ^= last;
    q ^= last;
    assert(1 <= p && p <= cnt);
    if (t == 1) {
      add(p, ++cnt, q);
    } else {
      last = ask(p, q);
      cout << last << '\n';
    }
  }
}