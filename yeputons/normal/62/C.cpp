#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef long double ld;

#define EPS 1e-3
#define EPS2 1e-2
struct pt {
  ld x, y;
  pt() : x(0), y(0) {}
  pt(ld _x, ld _y) : x(_x), y(_y) {}
  pt operator-(const pt &p2) const { return pt(x - p2.x, y - p2.y); }
  ld operator*(const pt &p2) const { return x * p2.y - y * p2.x; }
  bool operator<(const pt &p2) const {
    if (fabs(x - p2.x) < EPS) return y < p2.y - EPS;
    return x < p2.x - EPS;
  }
  bool operator==(const pt &p2) const {
    return fabs(x - p2.x) < EPS && fabs(y - p2.y) < EPS;
  }
};
struct line {
  ld a, b, c;
  line() : a(0), b(0), c(1) {}
  line(pt p1, pt p2) {
    a = p2.y - p1.y;
    b = p1.x - p2.x;
    c = -a * p1.x - b * p1.y;
  }

  bool operator&(const pt &p) const {
    return fabs(a * p.x + b * p.y + c) < EPS;
  }

  pt operator&(const line &l2) const {
    ld d = a * l2.b - b * l2.a;
    if (fabs(d) < EPS) throw 0;
    pt ans(
      (b * l2.c - c * l2.b) / d,
      (a * l2.c - c * l2.a) / -d
    );
    assert(*this & ans);
    assert(l2 & ans);
    return ans;
  }
};

bool is_in(pt p1, pt p2, pt p) {
  if (p.x < p1.x - EPS && p.x < p2.x - EPS) return false;
  if (p.x > p1.x + EPS && p.x > p2.x + EPS) return false;
  if (p.y < p1.y - EPS && p.y < p2.y - EPS) return false;
  if (p.y > p1.y + EPS && p.y > p2.y + EPS) return false;
  return true;
}
pt cross(pt a1, pt b1, pt a2, pt b2) {
  line l1(a1, b1);
  line l2(a2, b2);
  pt ans = l1 & l2;
  if (!is_in(a1, b1, ans)) throw 1;
  if (!is_in(a2, b2, ans)) throw 1;
  return ans;
}
ld len(pt a, pt b) {
  ld x = b.x - a.x, y = b.y - a.y;
  return sqrt(x * x + y * y);
}

ld getSq(vector<pt> tr) {
  assert(tr.size() == 4);
  pt a = tr[1] - tr[0];
  pt b = tr[2] - tr[0];
  return fabs(a * b) / 2;
}
bool contain(vector<pt> tr, pt p, bool strict = true) {
  assert(tr.size() == 4);
  ld sq = getSq(tr);
  ld sq2 = 0;
  for (int i = 0; i < 3; i++) {
    pt old = tr[i];
    tr[i] = p;
    sq2 += getSq(tr);
    tr[i] = old;
  }

  if (fabs(sq - sq2) > EPS2) return false;
  if (!strict) return true;
  for (int i = 0; i < 3; i++)
    if (line(tr[i], tr[i + 1]) & p) return false;
  return true;
}

int n;
vector<vector<pt> > ts;

bool border(pt p1, pt p2, int me) {
  pt p3((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
  for (int i = 0; i < n; i++) if (i != me)
    if (contain(ts[i], p1) || contain(ts[i], p2) || contain(ts[i], p3, false)) {
      return false;
    }
  return true;
}
ld add(pt p1, pt p2, int me) {
  vector<pt> pts;
  for (int i = 0; i < n; i++) {
    for (int i2 = 0; i2 < 3; i2++) {
      try {
        pts.pb(cross(p1, p2, ts[i][i2], ts[i][i2 + 1]));
      } catch (...) {}
    }
  }
  sort(pts.begin(), pts.end());

  ld res = 0;
  for (int i = 0; i + 1 < pts.size(); i++)
    if (border(pts[i], pts[i + 1], me))
      res += len(pts[i], pts[i + 1]);
  return res;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif
  
  while (scanf("%d", &n) >= 1) {
    ts = vector<vector<pt> >(n, vector<pt>(4));
    for (int i = 0; i < n; i++) {
      for (int i2 = 0; i2 < 3; i2++) {
        double x, y;
        scanf("%lf%lf", &x, &y);
        ts[i][i2] = pt(x, y);
      }
      ts[i][3] = ts[i][0];
    }

    ld ans = 0;
    for (int i = 0; i < n; i++)
      for (int i2 = 0; i2 < 3; i2++)
        ans += add(ts[i][i2], ts[i][i2 + 1], i);
    printf("%.18lf\n", (double)ans);

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}