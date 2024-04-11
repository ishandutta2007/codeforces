#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < m; ++j) {
      a[i][j] = s[j] == '1';
    }
  }
  using pt = pair<int, int>;
  vector<vector<pt>> res;

  auto flip = [&](vector<pt> v) {
    assert(v.size() == 3);
    res.push_back(v);
    for (auto p : v) {
      a[p.first][p.second] ^= 1;
    }
  };

  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < m - 1; ++j) {
      if (i < n - 2 || j < m - 2) {
        bool last = i == n - 2;
        vector<pt> op;
        if (a[i][j]) {
          op.emplace_back(i, j);
        }
        if (last) {
          if (a[i + 1][j]) {
            op.emplace_back(i + 1, j);
          }
        } else {
          if (a[i][j + 1]) {
            op.emplace_back(i, j + 1);
          }
        }
        if (op.empty()) {
          continue;
        }
        if (last) {
          op.emplace_back(i, j + 1);
        } else {
          op.emplace_back(i + 1, j);
        }
        if (op.size() < 3) {
          op.emplace_back(i + 1, j + 1);
        }
        flip(op);
      } else {
        while (true) {
          vector<pt> op;
          for (int x : {i, i + 1}) {
            for (int y : {j, j + 1}) {
              if (a[x][y]) {
                op.emplace_back(x, y);
              }
            }
          }
          if (op.empty()) {
            break;
          }
          int s = (int) op.size();
          for (int x : {i, i + 1}) {
            for (int y : {j, j + 1}) {
              if (!a[x][y]) {
                op.emplace_back(x, y);
              }
            }
          }
          if (s == 2) {
            reverse(op.begin(), op.end());
          }
          op.pop_back();
          flip(op);
        }
      }
    }
  }
  //for (int i = 0; i < n; ++i) {
    //for (int j = 0; j < m; ++j) {
      //cerr << a[i][j];
    //}
    //cerr << '\n';
  //}
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      assert(a[i][j] == 0);
    }
  }
  assert((int) res.size() <= n * m);
  cout << res.size() << '\n';
  for (auto v : res) {
    for (auto p : v) {
      cout << p.first + 1 << ' ' << p.second + 1 << ' ';
    }
    cout << '\n';
  }
}

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}