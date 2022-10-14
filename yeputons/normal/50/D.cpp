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

int eprintf(const char* format, ...) {
  #ifdef DEBUG
  va_list args;
  va_start(args, format);
  int ret = vfprintf(stderr, format, args);
  va_end(args);
  return ret;
  #else
  return 0;
  #endif
}

#define pb push_back
#define mp make_pair
#define EPS (dbl)1e-11
#define sqr(x) ((x) * (x))

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<bool> vb;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

typedef long double dbl;

struct pt {
  dbl x, y;
  pt() {}
  pt(dbl _x, dbl _y) : x(_x), y(_y) {}
};

int n, k;
pt p0;
vector<pt> pts;

dbl d[110][110];

dbl getProb(int id, dbl r) {
  dbl dist = sqr(pts[id].x - p0.x) + sqr(pts[id].y - p0.y);
  if (fabs(r) < EPS) return fabs(dist) < EPS ? 1.0 : 0.0;

  r *= r;
  if (dist <= r + EPS) return 1.0;
  return exp(1.0 - dist / r);
}

dbl get(dbl r) {
  memset(d, 0, sizeof d);
  d[0][0] = 1;
  for (int i = 0; i < n; i++)
    for (int ck = 0; ck <= n; ck++) {
      dbl pr = getProb(i, r);
      d[i + 1][ck] += d[i][ck] * (1 - pr);
      if (ck < n)
        d[i + 1][ck + 1] += d[i][ck] * pr;
    }

  dbl res = 0;
  for (int ck = k; ck <= n; ck++)
    res += d[n][ck];
  return res;
}

int main() {
  #ifdef DEBUG
  freopen("stdin.txt", "r", stdin);
  freopen("stdout.txt", "w", stdout);
  #endif
  
  double _need;
  while (scanf("%d%d%lf", &n, &k, &_need) >= 3) {
    dbl need = (1000 - _need) / 1000.0;

    double x, y;
    scanf("%lf%lf", &x, &y); p0 = pt(x, y);
    pts = vector<pt>(n);
    for (int i = 0; i < n; i++) {
      scanf("%lf%lf", &x, &y);
      pts[i] = pt(x, y);
    }

    if (get(0) >= need - EPS) {
      printf("0\n");
    } else {
      dbl L = 0, R = 3000;
      while (L + 1e-10 < R) {
        dbl M = (L + R) / 2.0;
        if (get(M) >= need - EPS) R = M;
        else L = M;
      }
      printf("%.15lf\n", (double)R);
    }

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}