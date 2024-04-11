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

struct Pt {
  double x, y;
};

const double eps = 1e-9;

int ccw(Pt a, Pt b, Pt c) {
  double suma = 0;
  suma += a.x * (b.y - c.y);
  suma += b.x * (c.y - a.y);
  suma += c.x * (a.y - b.y);
  return (suma > eps) - (suma < -eps);
}

double get_sq_dist(Pt a, Pt b) {
  double dx = a.x-b.x, dy = a.y-b.y;
  return dx*dx + dy*dy;
}

int main(void)
{
  int ng; scanf("%d", &ng);
  vector<Pt> gens, pts;
  Pt gmid = {0, 0};
  
  REP(gi, ng) {
    double x, y; scanf("%lf %lf", &x, &y);
    gens.push_back({x, y});
    gmid.x += x;
    gmid.y += y;
  }
  gmid.x /= ng; gmid.y /= ng;

  int np; scanf("%d", &np);
  REP(pi, np) {
    double x, y; scanf("%lf %lf", &x, &y);
    pts.push_back({x, y});
  }

  double ans = 1e100; // cost
  bool inside = true;
  REP(pi, np) {
    int pj = (pi+1) % np;
    if (ccw(pts[pi], pts[pj], gmid) > 0) inside = false;
  }
  if (inside) {
    double sum = 0;
    REP(gi, ng) sum += get_sq_dist(gens[gi], gmid);
    ans = min(ans, sum);
  }

  REP(pi, np) {
    { double sum = 0;
      REP(gi, ng) sum += get_sq_dist(gens[gi], pts[pi]);
      ans = min(sum, ans);
    }

    int pj = (pi+1) % np;
    Pt v = {pts[pj].x - pts[pi].x, pts[pj].y - pts[pi].y};
    double alpha = ((gmid.x-pts[pi].x)*v.x + (gmid.y-pts[pi].y)*v.y) / get_sq_dist(v, {0, 0});
    if (alpha >= -eps && alpha <= 1+eps) {
      Pt cand = {pts[pi].x + alpha*v.x, pts[pi].y + alpha*v.y};
      double sum = 0;
      REP(gi, ng) sum += get_sq_dist(gens[gi], cand);
      ans = min(ans, sum);
    }
  }

  printf("%.9lf\n", ans);
  return 0;
}