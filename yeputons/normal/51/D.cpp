#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

inline int eprintf(const char* format, ...) {
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
typedef vector<int> vi;
#define EPS 1e-9

bool eq(int a1, int a0, double d, bool e) {
  if (!a0) {
    if (a1) throw 0;
    return true;
  }
  if (!e) return true;
  return fabs((double)a1 / a0 - d) <= EPS;
}

int n;
void precalc(const vi &a, vi &e, vector<double> &ds, bool rev) {
  bool exd = false;
  e = vi(n, -1);
  ds = vector<double>(n);
  double d;

  e[0] = 0;
  for (int i = 1; i < n; i++) {
    try {
      int a1 = a[i], a0 = a[i - 1];
      if (rev) swap(a1, a0);

      if (!eq(a1, a0, d, exd)) throw 0;
      if (!exd && a0) {
        d = (double)a1 / a0;
        exd = true;
      }

      e[i] = exd;
      ds[i] = d;
    } catch (...) {
      return;
    }
  }
}
/*bool check(int l, int r, double &d) {
  bool exd = false;
  for (int i = l + 1; i <= r; i++) {
    if (!eq(a[i], a[i - 1], d, exd)) throw 0;
    if (!exd && a[i - 1]) {
      d = (double)a[i] / a[i - 1];
      exd = true;
    }
  }
  return exd;
}*/

int main() {
  #ifdef DEBUG
  freopen("stdin.txt", "r", stdin);
  freopen("stdout.txt", "w", stdout);
  #endif

  while (scanf("%d", &n) >= 1) {
    vi a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    vi le, re;
    vector<double> ld, rd;         
    precalc(a, le, ld, false);
    reverse(a.begin(), a.end());
    precalc(a, re, rd, true);
    reverse(a.begin(), a.end());
    reverse(re.begin(), re.end());
    reverse(rd.begin(), rd.end());

/*    for (int i = 0; i < n; i++)
      eprintf("%d %.6lf\n", le[i], ld[i]);
    eprintf("---\n");
    for (int i = 0; i < n; i++)
      eprintf("%d %.6lf\n", re[i], rd[i]);
    eprintf("===============\n");*/
    if (le[n - 1] >= 0) {
      printf("0\n");
      goto end;
    }
    for (int sk = 0; sk < n; sk++) {
      try {
        bool e1 = false, e2 = false;
        double d1, d2;
        if (sk - 1 >= 0) {
          if (le[sk - 1] < 0) throw 0;
          e1 = le[sk - 1]; d1 = ld[sk - 1];
        }
        if (sk + 1 < n) {
          if (re[sk + 1] < 0) throw 0;
          e2 = re[sk + 1]; d2 = rd[sk + 1];
        }
/*        double d1, d2;
        bool e1 = checkl(sk - 1, d1);
        bool e2 = checkr(sk + 1, d2);*/
        if (e1 && e2)
          if (fabs(d1 - d2) > EPS) continue;

        if (sk - 1 >= 0 && sk + 1 < n) {
          if (!eq(a[sk + 1], a[sk - 1], d1, e1)) continue;
          if (!eq(a[sk + 1], a[sk - 1], d2, e2)) continue;
        }

        printf("1\n");
        goto end;
      } catch (...) {
      }
    }
    printf("2\n");

    end:; 
    #ifndef DEBUG
    #warning No multitest!!!
    break;
    #endif
  }
  return 0;
}