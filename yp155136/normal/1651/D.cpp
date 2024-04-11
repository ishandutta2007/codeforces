#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 200006;
#define F first
#define S second

vector<int> G[N];
set<pii> st[N];

int x[N], y[N];

int min_way = 0;

int q(int qx, int qy) {
  auto iter = st[qx].lower_bound(make_pair(qy + 1, -1));
  if (iter == st[qx].begin()) {
    return 0;
  }
  pii p = *prev(iter);
  if (p.S < qy) {
    return 0;
  }
  if (qy - p.F < p.S - qy) {
    min_way = -1;
  }
  else {
    min_way = 1;
  }
  // cerr << "p.F = " << p.F << " , p.S = " << p.S << endl;
  return min(qy - p.F, p.S - qy) + 1; // smallest possible answer
}

void solve(int sx, int sy) {
  int d = q(sx, sy);
  int ansx = sx, ansy = sy + d * min_way;
  for (int i = 1; i <= d; ++i) {
    int d1 = q(sx - i, sy);
    if (d1 + i < d) {
      d = d1 + i;
      ansx = sx - i;
      ansy = sy + d1 * min_way;
    }
    int d2 = q(sx + i, sy);
    if (d2 + i < d) {
      d = d2 + i;
      ansx = sx + i;
      ansy = sy + d2 * min_way;
    }
  }
  // cerr << "d = " << d << endl;
  cout << ansx << ' ' << ansy << '\n';
}

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i] >> y[i];
    G[x[i]].push_back(y[i]);
  }
  for (int i = 1; i < N; ++i) {
    sort(G[i].begin(), G[i].end());
    int last = -1, last_st = -1;
    for (int y : G[i]) {
      if (y - last != 1) {
        if (last != -1) {
          st[i].insert(make_pair(last_st, last));
          last_st = y;
        }
        else {
          last_st = y;
        }
      }
      last = y;
    }
    st[i].insert(make_pair(last_st, last));
  }
  for (int i = 1; i <= n; ++i) {
    solve(x[i], y[i]);
  }
}