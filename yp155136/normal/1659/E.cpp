#include <bits/stdc++.h>
using namespace std;

const int N = 100006;
const int P = 30;

struct DJS {
  int p[N], sz[N];
  bool good[N];
  int and_val[N];
  void init(int n) {
    for (int i = 0; i <= n; ++i) {
      p[i] = i;
      sz[i] = 1;
      good[i] = false;
      and_val[i] = (1 << P) - 1;
    }
  }
  int Find(int x) {
    return p[x] == x ? x : p[x] = Find(p[x]);
  }
  void Union(int x, int y) {
    x = Find(x), y = Find(y);
    if (x == y) return;
    if (sz[x] > sz[y]) {
      swap(x, y);
    }
    // sz[x] <= sz[y]
    p[x] = y;
    sz[y] += sz[x];
    good[y] |= good[x];
    and_val[y] &= and_val[x];
  }
  void set_good(int pos) {
    pos = Find(pos);
    good[pos] = true;
  }
  bool is_good(int pos) {
    pos = Find(pos);
    return good[pos];
  }
  void set_and(int pos, int val) {
    pos = Find(pos);
    and_val[pos] &= val;
  }
  int Q_and(int pos) {
    pos = Find(pos);
    return and_val[pos];
  }
} djs[P];

int a[N], b[N], c[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m; cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> a[i] >> b[i] >> c[i];
  }
  for (int i = 0; i < P; ++i) {
    djs[i].init(n);
    for (int j = 1; j <= m; ++j) {
      if (((1 << i) & c[j]) == 0) {
        if ((c[j] & 1) == 0) {
          // djs[i].set_good(a[j]);
          // djs[i].set_good(b[j]);
          ;
        }
      }
      else {
        djs[i].Union(a[j], b[j]);
        djs[i].set_and(a[j], c[j]);
        if ((c[j] & 1) == 0) {
          djs[i].set_good(a[j]);
        }
      }
    }
    for (int j = 1; j <= m; ++j) {
      if (((1 << i) & c[j]) == 0) {
        if ((c[j] & 1) == 0) {
          int _ = djs[i].Q_and(a[j]);
          if ((_ & c[j]) == 0) {
            djs[i].set_good(a[j]);
          }
          int __ = djs[i].Q_and(b[j]);
          if ((__ & c[j]) == 0) {
            djs[i].set_good(b[j]);
          }
        }
      }
    }
  }
  int q; cin >> q;
  while (q--) {
    int u, v; cin >> u >> v;
    int ans = 2;
    for (int i = 0; i < P; ++i) {
      if (djs[i].Find(u) == djs[i].Find(v)) {
        ans = 0;
        break;
      }
      else if (i > 0 && djs[i].is_good(u)) {
        ans = 1;
      }
    }
    cout << ans << '\n';
  }
}