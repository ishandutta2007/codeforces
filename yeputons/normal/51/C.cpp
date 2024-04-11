#include <cstdio>
#include <cstdlib>
#include <cmath>
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

int n;
vi x;
double getSans(int l, int r) {
  return (x[r] - x[l]) / 2.0;
}

double getHAns(int r1, int r2) {
  return max(getSans(0, r1), getSans(r1 + 1, r2));
}
double getAns(int r1, int r2) {
  return max(getHAns(r1, r2), getSans(r2 + 1, n - 1));
}

int main() {
  #ifdef DEBUG
  freopen("stdin.txt", "r", stdin);
  freopen("stdout.txt", "w", stdout);
  #endif

  while (scanf("%d", &n) >= 1) {
    x = vi(n);
    for (int i = 0; i < n; i++) scanf("%d", &x[i]);
    sort(x.begin(), x.end());
    x.resize(n = (unique(x.begin(), x.end()) - x.begin()));

    if (n < 3) {
      printf("%.6lf\n", 0.0);
      for (int i = 0; i < 3; i++)
        printf("%.6lf%c", (i < n) ? (double)x[i] : 0.0, "\n "[i + 1 < 3]);
      #ifdef DEBUG
      continue;
      #else
      break;
      #endif
    }
    int r1 = 0;
    double bans = 1e100;
    double x1 = 1e100, x2 = 1e100, x3 = 1e100;
    for (int r2 = 1; r2 + 1 < n; r2++) {
      while (r1 + 1 < r2 && getHAns(r1 + 1, r2) < getHAns(r1, r2)) r1++;
      double cans = getAns(r1, r2);
      if (bans > cans) {
        bans = cans;
        x1 = (x[0] + x[r1]) / 2.0;
        x2 = (x[r1 + 1] + x[r2]) / 2.0;
        x3 = (x[r2 + 1] + x[n - 1]) / 2.0;
      }
    }
    printf("%.6lf\n%.6lf %.6lf %.6lf\n", bans, x1, x2, x3);
    
    #ifndef DEBUG
    #warning No multitest!!!
    break;
    #endif
  }
  return 0;
}