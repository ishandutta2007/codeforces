#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int eprintf(const char *format, ...) {
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

#define sqr(a, b) ((a) * (a))
#define INF 2000000000
#define EPS 1e-9
#define pb push_back
#define mp make_pair

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef double dbl;
typedef vector<dbl> vdbl;

typedef long long ll;
typedef vector<ll> vll;

typedef pair<int, int> pii;

typedef vector<bool> vb;
typedef vector<string> vs;

struct pt {
  dbl x, y;
  pt() { x = y = 0; }
  pt(dbl _x, dbl _y) { x = _x; y = _y; }
  pt operator+(const pt &b) const { return pt(x + b.x, y + b.y); }
  pt operator-(const pt &b) const { return pt(x - b.x, y - b.y); }
  pt operator*(const dbl b) const { return pt(x * b, y * b); }
  pt operator/(const dbl b) const { return pt(x / b, y / b); }
  pt turn90() const { return pt(-y, x); }
};

struct line {
  dbl a, b, c;
  line() { a = b = c = 0; }
  line(dbl _a, dbl _b, pt p) {
    a = _a; b = _b;;
    c = -a * p.x - b * p.y;
    assert(contains(p));
  }

  bool contains(pt p) const {
    return abs(a * p.x + b * p.y + c) < EPS;
  }

  pt operator&(const line &l2) const {
    dbl d = a * l2.b - b * l2.a;
    if (abs(d) < EPS) throw 0;
    pt ans(
      (b * l2.c - l2.b * c) / d,
      (a * l2.c - l2.a * c) / -d
    );
    assert(contains(ans) && l2.contains(ans));
    return ans;
  }
};

dbl getAng(pt a, pt b) {
  dbl cosa = a.x * b.x + a.y * b.y;
  dbl sina = a.x * b.y - a.y * b.x;
  return abs(atan2(sina, cosa));
}

#define EPS2 1e-2
bool check(dbl x) {
  int x2 = (int)(x + 0.5);
  if (abs(x - x2) < EPS2) return true;
  return false;
}

int main() {
  #ifdef DEBUG
  freopen("task.in", "r", stdin);
  freopen("task.out", "w", stdout);
  #endif

  pt a, b, c;
  while (scanf("%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y) >= 6) {
    b = b - a; c = c - a; a = pt(0, 0);
    pt b2 = b / 2, c2 = c / 2;

    line bl(b2.x, b2.y, b2), cl(c2.x, c2.y, c2);
    pt O = bl & cl;
    a = a - O; b = b - O; c = c - O; O = pt(0, 0);
    
    dbl a1 = getAng(a, b), a2 = getAng(b, c), a3 = getAng(c, a);
    eprintf("angs=%lf %lf %lf\n", a1 * 180 / M_PI, a2 * 180 / M_PI, a3 * 180 / M_PI);
//    assert(abs(abs(a1 + a2 + a3) - 2.0 * M_PI) < EPS);

    dbl r2 = a.x * a.x + a.y * a.y;
    dbl s = 0;
    for (int n = 3;; n++) {
      dbl cang = 2 * M_PI / n;
//      eprintf("n=%d, cang=%lf\n", n, cang);
      if (cang > a1 + EPS2) continue;
      if (cang > a2 + EPS2) continue;
      if (cang > a3 + EPS2) continue;

      if (!check(a1 / cang)) continue;
      if (!check(a2 / cang)) continue;
      if (!check(a3 / cang)) continue;
      s = n * r2 * sin(cang) / 2.0;
      break;
    }
    printf("%.6lf\n", s);

    #ifndef DEBUG
    break;
    #endif
  } 
  return 0;
}