#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

using pt = pair<int, int>;

set<pt> a, q;
map<pt, int> deg;

const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

pt go(pt a, int dir) {
  return pt{a.first + dx[dir], a.second + dy[dir]};
}

void place(pt p) {
  a.insert(p);
  for (int dir = 0; dir < 8; ++dir) {
    pt x = go(p, dir);
    if (++deg[x] >= 4) {
      if (!a.count(x)) {
        q.insert(x);
      }
    }
  }
}

void place(int x, int y) {
  place({x, y});
}

void go() {
  int init = a.size();
  while (!q.empty()) {
    pt x = *q.begin();
    q.erase(x);
    if (!a.count(x)) {
      place(x);
    }
  }
  int res = a.size();
  cerr << init << ' ' << init * init / 10 << ' ' << res << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  //for (int i = 0; i < 50; ++i) {
    //cerr << i << ' ' << i * i / 10 << '\n';
  //}
  int n;
  cin >> n;
  int rem = n;
  for (int i = 0; ; ++i) {
    for (int j = 0; j < 3; ++j) {
      if ((i + j) % 2) {
        //place(i, j);
        cout << i << ' ' << j << '\n';
        if (--rem == 0) {
          //go();
          return 0;
        }
      }
    }
  }
}