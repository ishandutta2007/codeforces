#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>

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

#define pb push_back
#define mp make_pair

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<bool> vb;

struct pt {
  float x, y, z;
  pt() { x = y = z = 0; }
  pt(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
};

inline float dist(pt a, pt b) {
  return sqrt(
    (a.x - b.x) * (a.x - b.x) +
    (a.y - b.y) * (a.y - b.y) +
    (a.z - b.z) * (a.z - b.z)
  );
}

#define MAXN 5000
float d[MAXN][MAXN];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  long long stime = clock();

  int n;
  while (scanf("%d", &n) >= 1) {
    vector<pt> pts(n);
    for (int i = 0; i < n; i++) scanf("%f%f%f", &pts[i].x, &pts[i].y, &pts[i].z);

    float ans = 1e100;
    for (int a = 0; a < n; a++)
      for (int b = 0; b < n; b++)
        d[a][b] = dist(pts[a], pts[b]);
    for (int a = 1; a < n; a++)
      for (int b = a + 1; b < n; b++) {
        ans = min(ans, d[0][a] + d[a][b] + d[b][0]);
      }
    ans /= 2;
    printf("%.20f\n", ans);
  
    #ifndef DEBUG
    break;
    #endif
  }
  eprintf("%I64d\n", clock() - stime);
  return 0;
}