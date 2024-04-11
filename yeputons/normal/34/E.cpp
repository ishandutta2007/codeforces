#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cmath>
#include <algorithm>
#include <vector>
#include <deque>

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
#define TASKNAME ""

typedef vector<int> vi;
typedef pair<int, int> pii;

struct Ev {
  double t;
  int a, b;

  Ev() { t = 1e10; a = b = -1; }
  Ev(double _t, int _a = -1, int _b = -1) { t = _t; a = _a; b = _b; }
  bool operator<(const Ev &evb) const { return t < evb.t; }
};

#define EPS 1e-10

double getEv(double x1, double v1, double x2, double v2) {
  if (fabs(v1 - v2) < EPS) return 1e10;
  double t = (x2 - x1) / (v1 - v2);
  if (t <= -EPS) return 1e10;
  if (t <= EPS) t = 0;
  if (fabs(t) < EPS) {
    if (v1 < -EPS && v2 > EPS) return 1e10;
    if (v1 > EPS && v2 > v1 + EPS) return 1e10;
    if (v1 < EPS && v1 < v2 - EPS) return 1e10;
  }
  return t;
}

int n;

int main() {
  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  
  double fint;
  while (scanf("%d%lf", &n, &fint) >= 2) {
    vector<double> x(n), v(n), m(n);
    for (int i = 0; i < n; i++) scanf("%lf%lf%lf", &x[i], &v[i], &m[i]);

    vi /*spos(n), */opos(n);
    {
      vector<pair<double, int> > ord(n);
      for (int i = 0; i < n; i++) ord[i] = mp(x[i], i);
      sort(ord.begin(), ord.end());
      for (int i = 0; i < n; i++) {
        opos[i] = ord[i].second;
      }
    }

    Ev cev;

    double t = 0;
    while (t < fint - EPS) {
      cev = Ev(fint);
      for (int _a = 0; _a + 1 < n; _a++) {
        int a = opos[_a], b = opos[_a + 1];
        double ct = t + getEv(x[a], v[a], x[b], v[b]);
        cev = min(cev, Ev(ct, a, b));
      }

      double dt = cev.t - t;

      for (int i = 0; i < n; i++)
        x[i] += v[i] * dt;

      for (int _i = 0; _i + 1 < n; _i++) {
        int a = opos[_i], b = opos[_i + 1];

        if (fabs(x[a] - x[b]) > EPS) continue;

        double v1 = (m[a] - m[b]) * v[a] + 2 * m[b] * v[b];
        double v2 = (m[b] - m[a]) * v[b] + 2 * m[a] * v[a];
        v1 /= m[a] + m[b];
        v2 /= m[a] + m[b];
        v[a] = v1;
        v[b] = v2;
      }
      t += dt;
    }
    for (int i = 0; i < n; i++)
      printf("%.9lf%c", x[i], "\n "[i + 1 < n]);

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}