#pragma GCC optimize("Ofast,no-stack-protector")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct DSU {
  vector<int> col, rk;

  DSU(int n): col(n), rk(n) {
    iota(col.begin(), col.end(), 0);
  }

  int get(int u) {
    if (u == col[u]) {
      return u;
    }
    return col[u] = get(col[u]);
  }

  bool join(int u, int v) {
    u = get(u), v = get(v);
    if (u == v) {
      return false;
    }
    if (rk[u] > rk[v]) {
      swap(u, v);
    }
    if (rk[u] == rk[v]) {
      ++rk[v];
    }
    col[u] = v;
    return true;
  }
};

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int ii = 0; ii < tn; ++ii) {
    int n;
    string s;
    cin >> n >> s;
    DSU dsu(2 * n);
    int bal = 0;
    vector<int> last(n + 1, -1);
    for (int i = 0; i < 2 * n; ++i) {
      if (s[i] == '(') {
        last[bal] = i;
        ++bal;
      } else {
        --bal;
        assert(last[bal] != -1);
        int j = last[bal];
        dsu.join(i, j);
        if (j > 0 && s[j - 1] == ')') {
          dsu.join(i, j - 1);
        }
      }
    }
    int res = 0;
    for (int i = 0; i < 2 * n; ++i) {
      if (dsu.get(i) == i) {
        ++res;
      }
    }
    cout << res << '\n';
  }
}