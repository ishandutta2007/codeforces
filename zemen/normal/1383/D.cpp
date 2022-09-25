#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  int n, m;
  cin >> n >> m;
  vector<int> r(n);
  vector<int> c(m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x;
      cin >> x;
      r[i] = max(r[i], x);
      c[j] = max(c[j], x);
    }
  }
  sort(r.rbegin(), r.rend());
  sort(c.rbegin(), c.rend());
  struct Cell {
    int x, y, type;
  };
  vector<Cell> free;
  vector<vector<int>> a(n, vector<int>(m, -1));

  auto add_cell = [&](int x, int y, int type) {
    //cerr << "add " << x << ' ' << y << ' ' << type << '\n';
    if (x >= 0 && y >= 0 && x < n && y < m && a[x][y] == -1) {
      if (type == 0 && (a[x - 1][y] < 0 || a[x][y + 1] < 0)) {
        return;
      }
      if (type == 1 && (a[x + 1][y] < 0 || a[x][y - 1] < 0)) {
        return;
      }
      a[x][y] = -2;
      free.emplace_back(Cell{x, y, type});
    }
  };

  int rp = 0, cp = 0;
  for (int val = n * m; val >= 1; --val) {
    bool nr = false, nc = false;
    if (rp < (int) r.size() && r[rp] == val) {
      ++rp;
      nr = true;
    }
    if (cp < (int) c.size() && c[cp] == val) {
      ++cp;
      nc = true;
    }
    if (nr || nc) {
      int x = rp - 1;
      int y = cp - 1;
      //cerr << "upd " << x << ' ' << y << '\n';
      a[x][y] = val;
      add_cell(x, y - 1, 0);
      add_cell(x - 1, y, 1);
    } else {
      if (free.empty()) {
        cout << -1 << '\n';
        return 0;
      }
      auto [x, y, type] = free.back();
      free.pop_back();
      a[x][y] = val;
      if (type == 0) {
        add_cell(x + 1, y, 0);
        add_cell(x, y - 1, 0);
      } else {
        add_cell(x - 1, y, 1);
        add_cell(x, y + 1, 1);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }
}