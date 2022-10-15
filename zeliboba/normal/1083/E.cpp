#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef long double ld;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
typedef long long int64;
typedef long double float128;

const int64 is_query = -(1LL<<62), inf = 1e18;

struct Line {
  int64 m, b;
  mutable function<const Line*()> succ;
  bool operator<(const Line& rhs) const {
    if (rhs.b != is_query) return m < rhs.m;
    const Line* s = succ();
    if (!s) return 0;
    int64 x = rhs.m;
    return b - s->b < (s->m - m) * x;
  }
};

struct HullDynamic : public multiset<Line> { // will maintain upper hull for maximum
  bool bad(iterator y) {
    auto z = next(y);
    if (y == begin()) {
      if (z == end()) return 0;
      return y->m == z->m && y->b <= z->b;
    }
    auto x = prev(y);
    if (z == end()) return y->m == x->m && y->b <= x->b;
    return (float128)(x->b - y->b)*(z->m - y->m) >= (float128)(y->b - z->b)*(y->m - x->m);
  }
  void insert_line(int64 m, int64 b) {
    auto y = insert({ m, b });
    y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
    if (bad(y)) { erase(y); return; }
    while (next(y) != end() && bad(next(y))) erase(next(y));
    while (y != begin() && bad(prev(y))) erase(prev(y));
  }

  int64 eval(int64 x) {
    auto l = *lower_bound((Line) { x, is_query });
    return l.m * x + l.b;
  }
};

const int DEBUG = 0;
const int MAX = 1e9;

int main() {
  for (int t = 0; t < (DEBUG ? 1000 : 1); ++t) {
  int n = rand() % 10 + 1;
  if (!DEBUG) scanf("%d", &n);
  vector<array<ll, 3>> v(n);
  for (int i = 0; i < n; ++i) {
    if (!DEBUG) {
      for (int j = 0; j < 3; ++j) {
        scanf("%lld", &v[i][j]);
      }
    } else {
      int pr = (i > 0 ? v[i-1][1] : MAX);
      v[i] = {rand() % ((MAX - (i > 0 ? v[i - 1][0] : 0)) / (n - i)), pr - rand() % (pr / (n - i)) - 1, 0};
      v[i][2] = rand() % (v[i][0] * (ll)v[i][1]);
    }
  }
  sort(v.begin(), v.end());
  vl d(n);
  HullDynamic hd;
  hd.insert_line(0, 0);
  for (int i = 0; i < n; ++i) {
    d[i] = v[i][0] * (ll)v[i][1] - v[i][2] + hd.eval(v[i][1]);
    if (DEBUG) {
      ll dd = v[i][0] * (ll)v[i][1] - v[i][2];
      for (int j = 0; j < i; ++j) {
        dd = max(dd, (v[i][0] - v[j][0]) * (ll)v[i][1] - v[i][2] + d[j]);
      }
      assert(dd == d[i]);
    }
    hd.insert_line(-v[i][0], d[i]);
  }

  ll res = 0;
  for (int i = 0; i < n; ++i) {
    res = max(res, d[i]);
  }

  cout << res << endl;
  }
  return 0;
}