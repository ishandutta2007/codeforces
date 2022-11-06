#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const double eps = 1e-9;
const double pi = acos(-1);
const int MAXN = 1e3 + 123;

inline bool eq(double a, double b) { return fabs(a-b) < eps; }

struct Pt {
  double x, y; 
};

int xmax, ymax;
int n;
Pt pts[MAXN];

double norm_angle(double x) {
  while (x <= -pi+eps) x += 2*pi;
  while (x > +pi+eps) x -= 2*pi;
  return x;
}

bool check(int si, double R) { // there is a point on the boundary not within any
  struct Evt {
    int idx; // n, n+1, n+2, n+3
    double x;
    int d; // +1, -1 // add first, remove later
  };

  static vector<Evt> es; es.clear();
  auto insert = [&](int idx, double mid, double alpha, int add) {
    if (!std::isnan(alpha)) {
      es.push_back({idx, norm_angle(mid-alpha), +add});
      es.push_back({idx, norm_angle(mid+alpha), -add});
    }
  };

  // always check
  REP(i, n) {
    double dx = pts[i].x - pts[si].x, dy = pts[i].y - pts[si].y;
    double dist = sqrt(dx*dx + dy*dy);

    if (dist > eps) {
      double alpha = acos(dist/2/R);
      insert(i, atan2(dy, dx), alpha, +1);
    }
  }


  { // walls
    // up
    insert(n, pi/2, acos(fabs(ymax - pts[si].y) / R), +2);
    // down
    insert(n+1, -pi/2, acos(fabs(pts[si].y) / R), +2);
    // left
    insert(n+2, pi, acos(fabs(pts[si].x) / R), +2);
    // right
    insert(n+3, 0, acos(fabs(xmax - pts[si].x) / R), +2);
  }

  // sweep
  sort(es.begin(), es.end(), [](Evt a, Evt b) {
      if (!eq(a.x, b.x)) return a.x < b.x;
      return a.d > b.d;
    });

  static int bio[MAXN] = {0};
  static int cookie = 123; ++cookie;
  int dep = 0;

  auto process = [&](const Evt& e) {
    if (e.d > 0) { // add
      assert(bio[e.idx] != cookie);
      bio[e.idx] = cookie;
      dep += e.d;
    } else if (bio[e.idx] == cookie) { // remove if inside
      bio[e.idx] = -1;
      dep += e.d;
    }
  };

  for (auto e : es) process(e);
  if (dep < 2) return true;
  for (auto e : es) {
    process(e);
    if (dep < 2) return true;
  }
  
  return false;
}

int main(void)
{
  scanf("%d %d %d", &xmax, &ymax, &n);
  REP(i, n) {
    double x, y; scanf("%lf %lf", &x, &y);
    pts[i] = {x, y};
  }

  double ans = 0;;

  random_shuffle(pts, pts+n);
  REP(si, n) {
    if (!check(si, ans*(1+eps))) continue;
    double lo = ans, hi = max(2*xmax, 2*ymax);
    REP(iter, 85) {
      double mid = (lo + hi) / 2;
      if (check(si, mid)) lo = mid;
      else hi = mid;
    }
    ans = lo;
  }

  printf("%.12lf\n", ans);
  return 0;
}