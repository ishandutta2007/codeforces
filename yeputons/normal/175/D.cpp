#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

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

#define EPS (1e-9)

class Solver {
  int n;
  vector<double> as, bs;

  public:
  Solver(int _n = 0) : n(_n), as(n, 0), bs(n, 0) {}
  inline void init(int _n) { n = _n; as.resize(n); bs.resize(n); }
  inline void setAttr(int x, double a, double b) {
    as[x] = a; bs[x] = b; 
//    eprintf("x=%d: %.2lf %.2lf\n", x, a, b);
  }
  inline void solve(double *res) {
    if (n == 1) {
      if (fabs(1 - bs[0]) < EPS) res[0] = 0;
      else res[0] = as[0] / (1 - bs[0]);
      return;
    }
    if (!n) return;

    double cval = -bs[n - 1], na = as[n - 1];
    for (int i = 0; i + 1 < n; i++) {
      if (fabs(cval) < EPS) break;

      // += L[i] * cval
      na += as[i] * -cval;
      cval = -bs[i] * -cval;
    }
    cval += 1;
    if (fabs(cval) < EPS) {
      res[n - 1] = 0;
    } else {
      res[n - 1] = na / cval;
    }
    for (int i = n - 2; i >= 0; i--) {
      res[i] = as[i] + res[i + 1] * bs[i];
    }
    assert(fabs(res[n - 1] - (as[n - 1] + res[0] * bs[n - 1])) < EPS);
  }
};

const int MINH = -201;
const int MAXH = 201;
const int MAXT = 60;

double d[MAXH + 1][MAXH + 1][MAXT];

int t1, t2, per;
int l1, r1; double p1;
int l2, r2; double p2;

bool f1[1000], f2[1000];

inline double get(int h1, int h2, int t) {
  if (h2 <= 0) return 1;
  if (h1 <= 0) return 0;
  return d[h1][h2][t];
}

double dsum[MAXT][MAXH - MINH + 2][MAXH - MINH + 2];
inline double getCorner(int t, int x, int y) {
  assert(MINH - 1 <= x && x <= MAXH);
  assert(MINH - 1 <= y && y <= MAXH);

/*  #ifdef DEBUG
  double rres = 0;
  for (int x0 = MINH; x0 <= x; x0++)
  for (int y0 = MINH; y0 <= y; y0++)
    rres += get(x0, y0, t);
  assert(fabs(dsum[t][x + 1 - MINH][y + 1 - MINH] - rres) < EPS);
  #endif*/
  return dsum[t][x + 1 - MINH][y + 1 - MINH];
}

inline double getSquare(int t, int l1, int r1, int l2, int r2) {
  double res = getCorner(t, r1, r2) - getCorner(t, l1 - 1, r2) - getCorner(t, r1, l2 - 1) + getCorner(t, l1 - 1, l2 - 1);

  #ifdef DEBUG
  double rres = 0;
  for (int x = l1; x <= r1; x++)
  for (int y = l2; y <= r2; y++)
    rres += get(x, y, t);
  assert(fabs(rres - res) < EPS);
  #endif
  return res;
}

Solver s;
double tmp[MAXT + 1];

void calc(int h1, int h2) {
  if (h2 <= 0 || h1 <= 0) return;

  s.init(per);
  for (int t = 0; t < per; t++) {
    int nt = (t + 1 == per) ? 0 : t + 1;

    double a = 0, b = 0;

    double cp1 = 1, cp2 = 1;
    if (f1[t]) cp1 = p1;
    if (f2[t]) cp2 = p2;

    b = cp1 * cp2;

    double curk = (1 - cp1) * cp2 / (r1 - l1 + 1);
    if (fabs(curk) > EPS)
      a += getSquare(nt, h1, h1, h2 - r1, h2 - l1) * curk;

    curk = cp1 * (1 - cp2) / (r2 - l2 + 1);
    if (fabs(curk) > EPS)
      a += getSquare(nt, h1 - r2, h1 - l2, h2, h2) * curk;

    curk = (1 - cp1) * (1 - cp2) / (r1 - l1 + 1) / (r2 - l2 + 1);
    if (fabs(curk) > EPS)
      a += getSquare(nt, h1 - r2, h1 - l2, h2 - r1, h2 - l1) * curk;

    s.setAttr(t, a, b);
  }
  s.solve(d[h1][h2]);
}

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int h1, h2;
  while (scanf("%d%d%d%d%lf", &h1, &t1, &l1, &r1, &p1) >= 1) {
    scanf("%d%d%d%d%lf", &h2, &t2, &l2, &r2, &p2);
    p1 /= 100;
    p2 /= 100;

    for (int a = 0; a <= MAXH; a++)
    for (int b = 0; b <= MAXH; b++)
    for (int t = 0; t <= MAXT; t++)
      d[a][b][t] = -1;

    per = t1 * t2 / gcd(t1, t2);
    for (int a = 0; a < per; a++) f1[a] = a % t1 == 0, f2[a] = a % t2 == 0;

    int off = 0;
    for (int a = 0; a < per; a++)
      if (!f1[a] && !f2[a]) {
        off++;
      } else {
        f1[a - off] = f1[a];
        f2[a - off] = f2[a];
      }
    per -= off;

    memset(dsum, 0, sizeof dsum);

    for (int a = MINH; a <= h1; a++)
    for (int b = MINH; b <= h2; b++) {
      calc(a, b);
      for (int t = 0; t < per; t++) {
        dsum[t][a + 1 - MINH][b + 1 - MINH]
        =   dsum[t][a + 1 - MINH][b - MINH]
          + dsum[t][a     - MINH][b + 1 - MINH]
          - dsum[t][a     - MINH][b - MINH]
          + get(a, b, t);
      }
    }
    printf("%.18lf\n", get(h1, h2, 0));
  }
  return 0;
}