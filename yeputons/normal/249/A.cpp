#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
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

const double EPS = 1e-9;

struct line {
  double a, b, c;
  line(double x1, double y1, double x2, double y2) {
    a = y2 - y1;
    b = x1 - x2;
    c = -a * x1 - b * y1;
    double d = sqrt(a * a + b * b);
    a /= d;
    b /= d;
    c /= d;
  }
  double getd(double x, double y) { return fabs(a * x + b * y + c); }
};

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  double y1, y2, ywall, xst, yst, r;
  while (scanf("%lf%lf%lf%lf%lf%lf", &y1, &y2, &ywall, &xst, &yst, &r) >= 1) {
    ywall -= r;
    double ytarg = 2 * ywall - (y1 + r + 1.01e-8);

    line l(xst, yst, 0, ytarg);
    double d = l.getd(0, 2 * ywall - y2);
    if (d <= r + EPS)
      printf("-1\n");
    else {
      double xans = xst - xst * (ywall - yst) / (ytarg - yst);
      double tmp = ywall - (ywall - yst) * xans / (xst - xans);
      eprintf("%.18lf\n", tmp);
      printf("%.18e\n", xans);
    }
  }
  return 0;
}