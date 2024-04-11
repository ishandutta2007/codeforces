#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 305;
string s[maxn][maxn];
int n, m;

struct Move {
  int x1, y1, x2, y2;
};

Move rev(Move m) {
  return Move{m.x2, m.y2, m.x1, m.y1};
}

vector<Move> solve() {
  vector<Move> res;
  for (int y : {0, 1}) {
    int down = 0;
    while (!s[0][y].empty()) {
      auto e = s[0][y].back();
      s[0][y].pop_back();
      if (e == '0' + y) {
        res.push_back(Move{0, y, 1, y});
        ++down;
      } else {
        res.push_back(Move{0, y, 0, y ^ 1});
      }
    }
    s[1][y] = string(down, '0' + y) + s[1][y];
  }
  for (int x = 0; x < n; ++x) {
    int cnt[2] = {0, 0};
    for (int y = 2; y < m; ++y) {
      reverse(s[x][y].begin(), s[x][y].end());
      for (auto e : s[x][y]) {
        res.push_back(Move{x, y, x, e - '0'});
        cnt[e - '0']++;
      }
    }
    if (x > 0) {
      for (int y : {0, 1}) {
        while (!s[x][y].empty()) {
          auto e = s[x][y].back();
          s[x][y].pop_back();
          if (e == '0' + y) {
            res.push_back(Move{x, y, 0, y});
          } else {
            res.push_back(Move{x, y, x, y ^ 1});
            ++cnt[y ^ 1];
          }
        }
      }
      for (int y : {0, 1}) {
        for (int i = 0; i < cnt[y]; ++i) {
          res.push_back(Move{x, y, 0, y});
        }
      }
    }
  }
  return res;
}

signed main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> s[i][j];
    }
  }
  auto res = solve();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> s[i][j];
      reverse(s[i][j].begin(), s[i][j].end());
    }
  }
  auto res2 = solve();
  reverse(res2.begin(), res2.end());
  for (auto& x : res2) {
    x = rev(x);
  }
  res.insert(res.end(), res2.begin(), res2.end());
  cout << (int) res.size() << '\n';
  for (auto x : res) {
    cout << x.x1+1 << ' ' << x.y1+1 << ' ' << x.x2+1 << ' ' << x.y2+1 << '\n';
  }
}