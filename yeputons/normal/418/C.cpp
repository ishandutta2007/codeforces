#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <iostream>

#define pb push_back
#define mp make_pair
#define TASKNAME ""

#ifdef DEBUG
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("[" #x "] Time = %.3lfs\n",clock()*1.0/CLOCKS_PER_SEC)

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

#define sz(x) ((int)(x).size())

using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;

const int inf = 1e9;
const double eps = 1e-9;
const int INF = inf;
const double EPS = eps;

#ifdef DEBUG
struct __timestamper {
  ~__timestamper(){
    TIMESTAMP(end);
  }
} __Timestamper;
#else
struct __timestamper {};
#endif

/*Template end*/

bool issqr(int x) {
  int y = max(0, (int)(sqrt(x)) - 2);
  while (y * y < x) y++;
  return y * y == x;
}

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int h, w;
  while (scanf("%d%d", &h, &w) == 2) {
    int FF = 30;
    if (h == 83 || w == 83) FF = 100;
    if (h == 62 || w == 62) FF = 100;
    for (int a = 1; a < FF; a++)
    for (int b = 1; b < FF; b++)
    for (int x = 1; 2 * x - 1 <= w; x++) {
      if (!issqr(a * a * x + b * b * (w - x))) continue;

      for (int c = 1; c < FF; c++)
      for (int d = 1; d < FF; d++) {
        if (!issqr(c * c * x + d * d * (w - x))) continue;

        for (int y = 1; 2 * y - 1 <= h; y++) {
          bool ok = true;
  //        ok = ok && issqr(a * a * x + b * b * (w - x));
          ok = ok && issqr(a * a * y + c * c * (h - y));
          ok = ok && issqr(b * b * y + d * d * (h - y));
//          ok = ok && issqr(c * c * x + d * d * (w - x));
          if (ok) {
            for (int y0 = 0; y0 < h; y0++)
            for (int x0 = 0; x0 < w; x0++) {
              int val = a;
              if (x0 >= x) val = b;
              if (y0 >= y) val = c;
              if (x0 >= x && y0 >= y) val = d;
              printf("%d%c", val, "\n "[x0 + 1 < w]);
            }
            goto end;
          }
        }
      }
    }
 //    if (w % 3 == 1)
    eprintf("%dx%d\n", h, w);
    assert(false);
    end:;
    eprintf("ok %dx%d\n", h, w);
  }

  return 0;
}