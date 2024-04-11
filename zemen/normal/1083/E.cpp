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

int cmp_z(pt a, pt b) {
  ld s1 = a.x / ld(a.y);
  ld s2 = b.x / ld(b.y);
  if (s1 == s2) {
    return 0;
  } else if (s1 > s2) {
    return 1;
  } else {
    return -1;
  }
}

struct Hull {
  vector<pt> L, R;

  //check: add points in strictly increasing order
  void append(pt p) {
    while (R.size() > 1 && cmp_z(p - R.back(), p - *next(R.rbegin())) >= 0) {
      R.pop_back();
    }
    R.push_back(p);
    while (L.size() > 1 && cmp_z(p - L.back(), p - *next(L.rbegin())) <= 0) {
      L.pop_back();
    }
    L.push_back(p);
  }

  pt mostDistant(pt dir) {
    dir = dir.rot();
    auto &v = dir.y < 0 ? L : R;
    int l = -1, r = v.size() - 1;
    while (l + 1 < r) {
      int c = (l + r) / 2;
      if (cmp_z(dir, (v[c + 1] - v[c])) > 0)
        r = c;
      else
        l = c;
    }
    return v[r];
  }
};

signed main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  struct E {
    ll x, y, a;
  };
  vector<E> v;
  for (int i = 0; i < n; ++i) {
    int x, y;
    ll a;
    cin >> x >> y >> a;
    v.push_back(E{x, y, a});
  }
  sort(v.begin(), v.end(), [](E a, E b) {
    return a.x < b.x;
  });
  Hull h;
  h.append(pt{0, 0});
  ll res = 0;
  for (auto e : v) {
    pt c = h.mostDistant(pt{1, -e.y});
    ll d = c.x - c.y * e.y + e.x * e.y - e.a;
    h.append(pt{d, e.x});
    res = max(res, d);
  }
  cout << res << '\n';
}