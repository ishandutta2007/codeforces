#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;

const int maxn = 6;
const int B = 2 << maxn;

struct E {
  int id;
  ld p, d;
};

vector<E> d[B];

ld p[B][B];

vector<E> merge(vector<E> a, vector<E> b) {
  vector<E> res;
  int cost = int(a.size());
  for (int iter = 0; iter < 2; ++iter) {
    for (auto e1 : a) {
      E e{e1.id, 0, 0};
      ld d2 = 0;
      for (auto e2 : b) {
        e.p += e1.p * e2.p * p[e1.id][e2.id];
        d2 = max(d2, e2.d);
      }
      e.d = e1.d + d2 + e.p * cost;
      res.push_back(e);
    }
    swap(a, b);
  }
  //ld sump = 0;
  //for (auto e : res) {
    //sump += e.p;
  //}
  //cerr << "sump " << sump << '\n';
  return res;
}

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  int n;
  cin >> n;
  for (int i = 0; i < 1 << n; ++i) {
    for (int j = 0; j < 1 << n; ++j) {
      cin >> p[i][j];
      p[i][j] /= 100;
    }
  }
  int base = 1 << n;
  for (int i = 0; i < 1 << n; ++i) {
    d[i + base].push_back(E{i, 1, 0});
  }
  for (int i = base - 1; i > 0; --i) {
    d[i] = merge(d[i * 2], d[i * 2 + 1]);
  }
  ld res = 0;
  for (auto e : d[1]) {
    res = max(res, e.d);
  }
  cout << fixed;
  cout.precision(10);
  cout << res << '\n';
}