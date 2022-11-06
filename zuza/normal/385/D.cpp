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
  double x, y, ang;
};

const double pi = acos(-1);
const int MAXN = 20;
const int MAXS = 1<<MAXN;

inline double pt_pt_atan2(double x1, double y1, double x2, double y2) {
  return atan2(y2-y1, x2-x1);
}

int main(void)
{
  int n; scanf("%d", &n);  
  double lo, hi; scanf("%lf %lf", &lo, &hi);

  static Pt pts[MAXN];
  static double dp[MAXS]; REP(i, 1<<n) dp[i] = -1e100;

  REP(i, n) {
    double x, y, ang; scanf("%lf %lf %lf", &x, &y, &ang);
    pts[i] = {x, y, ang/180*pi};
  }

  dp[0] = lo;  
  REP(st, 1<<n) {    
    REP(i, n) if (~st&(1<<i)) {
      double x = -pi/2 - pt_pt_atan2(pts[i].x, pts[i].y, dp[st], 0);;
      assert(x < pi/2);
      double r;
      if (pts[i].ang-x >= pi/2) r = hi;
      else r = min(hi, dp[st] + pts[i].y * (tan(x) + tan(pts[i].ang-x)));
      double& ref = dp[st | (1<<i)];
      ref = max(ref, r);
    }
  }

  printf("%.9lf\n", dp[(1<<n)-1] - lo);
  return 0;
}