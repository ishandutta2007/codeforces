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
//const int mod = ;

typedef long long int64;
typedef long double float128;

const int64 is_query = -(1LL<<62), inf = 1e18;

struct Line {
  int64 m, b;
  int ind;
  mutable function<const Line*()> succ;
  bool operator<(const Line& rhs) const {
    if (rhs.b != is_query) return m < rhs.m || (m == rhs.m && ind > rhs.ind);
    const Line* s = succ();
    if (!s) return 0;
    int64 x = rhs.m;
    int64 dif = b - s->b - (s->m - m) * x;
    return dif < 0 || (dif == 0 && ind > rhs.ind);
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
  void insert_line(int64 m, int64 b, int ind) {
    m *= -1; b *= -1;
    auto y = insert({ m, b, ind });
    y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
    if (bad(y)) { erase(y); return; }
    while (next(y) != end() && bad(next(y))) erase(next(y));
    while (y != begin() && bad(prev(y))) erase(prev(y));
  }

  pair<int64, int> eval(int64 x) {
    auto l = *lower_bound((Line) { x, is_query });
    return make_pair(l.m * x + l.b, l.ind);
  }
};

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  ll L, Q, B = 0, X = 0;
  cin >> L >> Q;
  HullDynamic hd;
  hd.insert_line(0, 0, 0);
  for (int q = 0; q < Q; ++q) {
    int type, k;
    cin >> type;
    if (type == 1) {
      cin >> k;
      L += k;
      B = X = 0;
      hd.clear();
      hd.insert_line(0, 0, 0);
    } else if (type == 2) {
      cin >> k;
      hd.insert_line(L, -B - L * X, L);
      L += k;
    } else {
      ll b, s;
      cin >> b >> s;
      B += b;
      X += s;
    }
//    cerr << "B: " << B << " X: " << X << endl;
//    for (const auto& it : hd) cerr << it.m << ' ' << it.b << ' ' << it.ind << endl;
    auto res = hd.eval(X);
    cout << res.second + 1 << ' ' << -res.first + B << '\n';
  }
  return 0;
}