#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const ld eps = 1e-9;
bool ze(ld a) { return fabsl(a) < eps; }
bool eq(ld a, ld b) { return ze(a - b); }
bool lt(ld a, ld b) { return b - a > eps; }
bool le(ld a, ld b) { return b - a >= -eps; }
bool gt(ld a, ld b) { return a - b > eps; }
bool ge(ld a, ld b) { return a - b >= -eps; }
ld sqr(ld x) { return x * x; }
ld Sqrt(ld x) { return sqrtl(max<ld>(0, x)); }

struct pt {
  ld x, y;

  pt operator+(const pt& p) const { return pt{x + p.x, y + p.y}; }
  pt operator-(const pt& p) const { return pt{x - p.x, y - p.y}; }
  ld operator*(const pt& p) const { return x * p.x + y * p.y; }
  ld operator%(const pt& p) const { return x * p.y - y * p.x; }
  pt operator*(const ld& a) const { return pt{x * a, y * a}; }
  bool operator==(const pt& p) const { return eq(x, p.x) && eq(y, p.y); }

  bool up() const { return ze(y) ? x > 0 : y > 0; }

  pt norm() { return *this * (1. / abs()); }
  pt rot() { return pt{-y, x}; }
  pt rot_cw(pt e) { return pt{e * *this, e % *this}; }
  ld abs() const { return hypotl(x, y); }
  ld abs2() const { return x * x + y * y; }
};

istream &operator>>(istream &in, pt &p) { return in >> p.x >> p.y; }
ostream &operator<<(ostream &out, const pt &p) { return out << p.x << ' ' << p.y; }

bool cmp_yx(const pt& a, const pt& b) {
  if (!eq(a.y, b.y))
    return a.y < b.y;
  if (!eq(a.x, b.x))
    return a.x < b.x;
  return false;
}
bool cmp_angle(const pt& a, const pt& b) {
  bool au = a.up(), bu = b.up();
  if (au != bu)
    return au;
  return a % b > eps;
}

struct Line {
  pt v;
  ld c; // v * p = c

  //check: p1 != p2
  Line(pt p1, pt p2) {
    v = (p2 - p1).rot();
    v = v * (1. / v.abs());
    c = v * p1;
  }

  // Convert from ax + by + c = 0

  //check: a^2+b^2 > 0
  Line(ld a, ld b, ld _c): v(pt{a, b}), c(-_c) {
    ld d = v.abs();
    v = v * (1. / d);
    c /= d;
  }

  //check: v.abs() == 1
  ld signed_dist(pt p) {
    return v * p - c;
  }
};

vector<pt> circles_intersection(pt a, ld r1, pt b, ld r2) {
  ld d = (a - b).abs();
  if (ze(d) && eq(r1, r2)) {
    //stub: equal circles
    return {};
  }
  //  intersection is non-empty iff
  //  triangle with sides r1, r2, d exists
  ld per = r1 + r2 + d;
  ld mx = max(max(r1, r2), d);
  int num = 2;
  if (eq(mx * 2, per)) {
    num = 1;
  } else if (mx * 2 > per)
    return {};
  ld part = (sqr(r1) + sqr(d) - sqr(r2)) / ld(2 * d);
  pt h = a + (b - a) * (part / d);
  if (num == 1)
    return {h};
  ld dh = Sqrt(sqr(r1) - sqr(part));
  pt w = ((b - a) * (dh / d)).rot();
  return {h + w, h - w};
}

struct DSU {
  vector<int> col, rk;

  DSU(int n): col(n), rk(n) {
    iota(col.begin(), col.end(), 0);
  }

  int get(int u) {
    if (u == col[u]) {
      return u;
    }
    return col[u] = get(col[u]);
  }

  bool join(int u, int v) {
    u = get(u), v = get(v);
    if (u == v) {
      return false;
    }
    if (rk[u] > rk[v]) {
      swap(u, v);
    }
    if (rk[u] == rk[v]) {
      ++rk[v];
    }
    col[u] = v;
    return true;
  }
};

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  int n;
  cin >> n;
  vector<pt> p(n);
  vector<ld> r(n);
  vector<pt> pts;
  for (int i = 0; i < n; ++i) {
    cin >> p[i] >> r[i];
    pts.push_back(p[i] + pt{r[i], ld(0)});
  }
  DSU dsu(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      auto pp = circles_intersection(p[i], r[i], p[j], r[j]);
      if (!pp.empty()) {
        dsu.join(i, j);
      }
      for (auto p : pp) {
        pts.push_back(p);
      }
    }
  }
  sort(pts.begin(), pts.end(), cmp_yx);
  pts.erase(unique(pts.begin(), pts.end()), pts.end());
  int C = 0;
  for (int i = 0; i < n; ++i) {
    if (dsu.get(i) == i) {
      ++C;
    }
  }
  int V = (int) pts.size();
  int E = 0;
  for (int i = 0; i < n; ++i) {
    int on = 0;
    for (auto q : pts) {
      ld dist = (q - p[i]).abs();
      if (eq(dist, r[i])) {
        ++on;
      }
    }
    assert(on > 0);
    E += on;
  }
  cout << 1 + C + E - V << '\n';
}