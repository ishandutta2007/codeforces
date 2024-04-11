#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct BoolArray {
  vector<int> revision;
  int cur_revision;

  BoolArray() : cur_revision(1) {
  }

  BoolArray(int n) : revision(n), cur_revision(1) {
  }

  void clear() {
    ++cur_revision;
  }

  bool operator[](int id) const {
    return revision[id] == cur_revision;
  }

  void set(int id, bool value = true) {
    revision[id] = value ? cur_revision : -1;
  }
};

const int maxn = 10005;
vector<int> g[maxn];
BoolArray used;
int mt[maxn];

bool kuhn(int u) {
  used.set(u);
  for (int v : g[u]) {
    if (mt[v] == -1 || (!used[mt[v]] && kuhn(mt[v]))) {
      mt[v] = u;
      return true;
    }
  }
  return false;
}

int solve(int n, int m) {
  assert(n * m < maxn);
  for (int i = 0; i < n * m; ++i) {
    g[i].clear();
  }
  for (int dx = -3; dx <= 3; ++dx) {
    for (int dy = -3; dy <= 3; ++dy) {
      if (abs(dx) + abs(dy) != 3) {
        continue;
      }
      for (int x1 = 0; x1 < n; ++x1) {
        for (int y1 = 0; y1 < m; ++y1) {
          int x2 = x1 + dx;
          int y2 = y1 + dy;
          if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m) {
            continue;
          }
          g[x1 * m + y1].push_back(x2 * m + y2);
        }
      }
    }
  }
  used = BoolArray(n * m);
  fill(mt, mt + n * m, -1);
  int res = n * m;
  for (int i = 0; i < n * m; ++i) {
    int x = i / m, y = i % m;
    if ((x + y) % 2) {
      continue;
    }
    used.clear();
    if (kuhn(i)) {
      res -= 2;
    }
  }
  return res;
}

const int B = 12;
int f(int x) {
  if (x < B) {
    return x;
  }
  return (x - B) % 6 + B;
}

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  int n, m;
  cin >> n >> m;
  //for (int i = 0; i < 100; ++i) {
    //cerr << "check " << i << '\n';
    //for (int j = 0; j < 100; ++j) {
      //if (solve(i, j) != solve(f(i), f(j))) {
        //cerr << "suck " << i << ' ' << j << '\n';
        //return 0;
      //}
    //}
  //}
  cout << ll(n) * ll(m) - solve(f(n), f(m)) << '\n';
}