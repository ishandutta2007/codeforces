#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct pt {
  ll x, y;

  pt operator+(const pt& p) const { return pt{x + p.x, y + p.y}; }
  pt operator-(const pt& p) const { return pt{x - p.x, y - p.y}; }
  ll operator*(const pt& p) const { return x * p.x + y * p.y; }
  ll operator%(const pt& p) const { return x * p.y - y * p.x; }
  pt operator*(const ll& a) const { return pt{x * a, y * a}; }
  bool operator==(const pt& p) const { return x == p.x && y == p.y; }
  bool operator!=(const pt& p) const { return !operator==(p); }

  bool up() const { return y == 0 ? x > 0 : y > 0; }

  pt norm() const { return *this * (1. / abs()); }
  pt rot() const { return pt{-y, x}; }
  pt rot_cw(pt e) const { return pt{e * *this, e % *this}; }
  ld abs() const { return hypotl(x, y); }
  ll abs2() const { return x * x + y * y; }
};

istream &operator>>(istream &in, pt &p) { return in >> p.x >> p.y; }
ostream &operator<<(ostream &out, const pt &p) { return out << p.x << ' ' << p.y; }

bool cmp_xy(const pt& a, const pt& b) {
  if (a.x != b.x) {
    return a.x < b.x;
  }
  return a.y > b.y;
}

vector<pt> convex_hull(vector<pt> h) {
  sort(h.begin(), h.end(), cmp_xy);
  vector<pt> s;
  for (int i = 0; i < (int) h.size(); ++i) {
    if (i > 0 && h[i].x == h[i - 1].x) {
      continue;
    }
    while ((int) s.size() >= 2) {
      pt a = s[(int) s.size() - 2];
      pt b = s.back();
      pt c = h[i];
      ll Q = (a.x - b.x) * (a.x - c.x) * (b.x - c.x);
      assert(Q != 0);
      ll P = a.y * (b.x - c.x) -
             b.y * (a.x - c.x) +
             c.y * (a.x - b.x);
      if (Q < 0) {
        P *= -1;
        Q *= -1;
      }
      //cerr << P << ' ' << Q << '\n';
      if (P >= Q) {
        s.pop_back();
      } else {
        break;
      }
    }
    s.push_back(h[i]);
  }
  return s;
}

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  int n;
  cin >> n;
  vector<pt> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  auto h = convex_hull(p);
  cout << (int) h.size() - 1 << '\n';
}