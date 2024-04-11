#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct C {
  int l, r, h, cost;
  
  bool operator<(const C& c) const {
    return h < c.h;
  }
};

vector<C> c;

const int maxn = 55;
int d[maxn][maxn][maxn];

void calc(int l, int r, int H) {
  int& res = d[l][r][H];
  vector<C> c2;
  for (auto& x : c) {
    if (x.l >= l && x.r <= r) {
      c2.push_back(x);
    }
  }
  for (int c = l; c <= r; ++c) {
    int p = 0, pen = 0;
    for (int h = 0; h <= H; ++h) {
      while (p < (int) c2.size() && c2[p].h < h) {
        if (c2[p].l <= c && c2[p].r >= c) {
          pen += c2[p].cost;
        }
        ++p;
      }
      int cur = (l < c ? d[l][c - 1][h] : 0) + (c < r ? d[c + 1][r][h] : 0) + h * h - pen;
      res = max(res, cur);
    }
  }
}

signed main() {
#ifdef LOCAL
  assert(freopen("g.in", "r", stdin));
#endif
  int n, H, m;
  cin >> n >> H >> m;
  for (int i = 0; i < m; ++i) {
    int l, r, x, c;
    cin >> l >> r >> x >> c;
    ::c.push_back(C{l - 1, r - 1, x, c});
  }
  sort(c.begin(), c.end());
  for (int len = 1; len <= n; ++len) {
    for (int l = 0; l + len <= n; ++l) {
      int r = l + len - 1;
      for (int h = 0; h <= H; ++h) {
        calc(l, r, h);
      }
    }
  }
  cout << d[0][n - 1][H] << '\n';
}