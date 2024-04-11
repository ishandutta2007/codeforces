#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cstdarg>
#include <cassert>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>

#define pb push_back
#define mp make_pair

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

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

int dist(int x1, int y1, int x2, int y2) {
  assert((x1 == x2) || (y1 == y2));
  return abs(x2 - x1) + abs(y2 - y1);
}

int main() {
  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int n, m;
  while (scanf("%d%d", &n, &m) >= 2) {
    vi xs(n), ys(n);
    for (int i = 0; i < n; i++) scanf("%d%d", &xs[i], &ys[i]);

    vi lens(m);
    for (int i = 0; i < m; i++)
      scanf("%d", &lens[i]);

    xs.pb(xs[0]); ys.pb(ys[0]);
    xs.pb(xs[1]); ys.pb(ys[1]);

    bool good = false;
    for (int st = 1; st <= 2; st++) {
      bool cur = true;
      vi used(m, -1);

      for (int i = st; i < n + st; i += 2) {
        int clen = dist(xs[i - 1], ys[i - 1], xs[i], ys[i]) + dist(xs[i], ys[i], xs[i + 1], ys[i + 1]);
        cur = false;
        for (int i2 = 0; i2 < m; i2++)
          if ((used[i2] < 0) && (lens[i2] == clen)) {
            used[i2] = (i >= n) ? (i - n) : i;
            cur = true;
            break;
          }
        if (!cur) {
          break;
        }
      }
      if (cur) {
        vi ans(n, -1);
        for (int i = 0; i < m; i++)
          if (used[i] >= 0) ans[used[i]] = i + 1;

        printf("YES\n");
        for (int i = 0; i < n; i++)
          printf("%d%c", ans[i], "\n "[i + 1 < n]);

        good = true;
        break;
      }
    }
    if (!good) printf("NO\n");

    #ifndef DEBUG
    break;
    #endif
  }

  return 0;
}