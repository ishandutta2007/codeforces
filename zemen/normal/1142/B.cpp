#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxd = 18;
const int maxn = 200200;
int f[maxn][maxd];

const int base = 1 << maxd;
int t[base * 2];

int get(int l, int r, int v = 1, int cl = 0, int cr = base) {
  if (l <= cl && cr <= r) {
    return t[v];
  }
  if (r <= cl || cr <= l) {
    return 1e9;
  }
  int cc = (cl + cr) / 2;
  return min(get(l, r, v * 2, cl, cc), get(l, r, v * 2 + 1, cc, cr));
}

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> p(n);
  vector<int> nx(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
  }
  for (int i = 0; i < n; ++i) {
    nx[p[i]] = p[(i+1)%n];
  }
  vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
    --a[i];
  }
  vector<int> last(n, m);
  for (int i = m - 1; i >= 0; --i) {
    last[a[i]] = i;
    f[i][0] = last[nx[a[i]]];
  }
  f[m][0] = m;
  for (int d = 0; d + 1 < maxd; ++d) {
    for (int i = 0; i <= m; ++i) {
      f[i][d + 1] = f[f[i][d]][d];
    }
  }
  vector<int> val(m);
  for (int i = 0; i < m; ++i) {
    val[i] = i;
    for (int d = 0; d < maxd; ++d) {
      if ((n - 1) & (1 << d)) {
        val[i] = f[val[i]][d];
      }
    }
    t[i + base] = val[i];
    //cerr << val[i] << ' ';
  }
  //cerr << '\n';
  for (int i = base - 1; i > 0; --i) {
    t[i] = min(t[i * 2], t[i * 2 + 1]);
  }
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    --l;
    int to = get(l, r);
    //cerr << to << '\n';
    cout << (to < r);
  }
  cout << '\n';
}