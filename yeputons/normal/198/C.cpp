#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

#define EPS 1e-9
struct pt {
  double x, y;
  pt() : x(0), y(0) {}
  pt(double x, double y) : x(x), y(y) {}
  pt operator-(const pt &p2) const { return pt(x - p2.x, y - p2.y); }
  pt operator+(const pt &p2) const { return pt(x + p2.x, y + p2.y); }
  double dist2() const { return x * x + y * y; }
  double dist() const { return sqrt(dist2()); }
};
vector<pt> cross(double r, double a, double b, double c) {
  double d2 = a * a + b * b;
  pt p0(-a * c / d2, -b * c / d2);
  #ifdef DEBUG
  assert(fabs(p0.x * a + p0.y * b + c) < EPS);
  #endif

  double dcent2 = c * c / d2;
  double len = r * r - dcent2;
  #ifdef DEBUG
  assert(len >= -EPS);
  #endif

  vector<pt> res;
  if (len < EPS) res.pb(p0);
  else {
    len = sqrt(len / d2);
    pt step(-b * len, a * len);
    res.pb(p0 + step);
    res.pb(p0 - step);
  }
  #ifdef DEBUG
  for (int i = 0; i < sz(res); i++) {
    assert(fabs(res[i].dist() - r) < EPS);
    assert(fabs(res[i].x * a + res[i].y * b + c) < EPS);
  }
  #endif
  return res;
}

double r;
vector<pt> getTangent(pt p) {
  double r1 = p.dist2() - r * r;
  #ifdef DEBUG
  assert(r1 >= -EPS);
  #endif
  if (r1 < EPS) r1 = 0;
  else r1 = sqrt(r1);

  double a = 2 * p.x;
  double b = 2 * p.y;
  double c = -p.x * p.x - p.y * p.y + r1 * r1 - r * r;
  vector<pt> res = cross(r, a, b, c);
  #ifdef DEBUG
  for (int i = 0; i < sz(res); i++) {
    assert(fabs(res[i].dist2() - r * r) < EPS);
    assert(fabs((res[i] - p).dist2() - r1 * r1) < EPS);
  }
  #endif
  return res;
}

pt p0; double R0, v0;
double getArc(const pt &p1, const pt &p2) {
  double diff = atan2(p1.y, p1.x) - atan2(p2.y, p2.x);
  while (diff < 0) diff += 2 * M_PI;
  while (diff >= 2 * M_PI + EPS) diff -= 2 * M_PI;
  return min(fabs(diff), fabs(2 * M_PI - diff)) * r;
}

bool is_in(double x1, double x, double x2) {
  if (x1 > x2) swap(x1, x2);
  return x1 <= x + EPS && x - EPS <= x2;
}

pt pst; double vst;
vector<pt> pts1;

bool caught(double t) {
  double cd = 1e100;
  pt pp;
  {
    double tang = t * v0 / R0;
    double tx = cos(tang), ty = sin(tang);
    pp = pt(
      p0.x * tx - p0.y * ty,
      p0.x * ty + p0.y * tx
    );
  }
  {
    double a = pp.y - pst.y;
    double b = pst.x - pp.x;
    double c = -a * pp.x - b * pp.y;
    double d2 = a * a + b * b;
    double d0 = fabs(c) / sqrt(d2);

    pt p(-a * c / d2, -b * c / d2);
    if (!(is_in(pp.x, p.x, pst.x) && is_in(pp.y, p.y, pst.y) && d0 < r - EPS)) {
      cd = (pp - pst).dist();
      goto end;
    }
  }

  {
    vector<pt> pts2 = getTangent(pp);
    for (int a = 0; a < sz(pts1); a++)
    for (int b = 0; b < sz(pts2); b++) {
      double d = 0;
      d += (pts1[a] - pst).dist();
      d += getArc(pts1[a], pts2[b]);
      d += (pts2[b] - pp).dist();
      cd = min(cd, d);
    }
  }

  end:;
  return cd <= t * vst + EPS;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%lf%lf%lf%lf%lf%lf%lf", &p0.x, &p0.y, &v0, &pst.x, &pst.y, &vst, &r) >= 1) {
    R0 = p0.dist();

    pts1 = getTangent(pst);

    double L = 0, R = 2e6;
    assert(caught(R));
    if (caught(L)) R = L;
    for (int step = 0; step < 100; step++) {
      double M = (L + R) / 2;
      if (caught(M)) R = M;
      else L = M;
    }
    printf("%.18e\n", R);
  }
  return 0;
}