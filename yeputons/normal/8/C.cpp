#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>

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

template<typename T> void printv(const char* name, const char* fmt, vector<T> v) {
  #ifdef DEBUG
  eprintf("%s:", name);
  for (unsigned int i = 0; i < v.size(); i++) {
    eprintf(" ");
    eprintf(fmt, v[i]);
  }
  eprintf("\n");
  #endif
}
void printv(const char* name, const char* fmt, vector<bool> v) {
  #ifdef DEBUG
  eprintf("%s:", name);
  for (unsigned int i = 0; i < v.size(); i++) {
    eprintf(" ");
    eprintf(fmt, !!v[i]);
  }
  eprintf("\n");
  #endif
}

#define sqr(a) ((a) * (a))
#define INF 2000000000
#define mp make_pair
#define pb push_back

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

typedef double dbl;
typedef vector<dbl> vd;

typedef long long ll;
typedef vector<ll> vll;

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef vector<string> vs;

int dist(int x1, int y1, int x2, int y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
  #ifdef DEBUG
  freopen("task.in", "r", stdin);
  freopen("task.out", "w", stdout);
  #endif

  int x0, y0, n;
  while (scanf("%d%d%d", &x0, &y0, &n) >= 3) {
    int begans = 0;
    vi xs(n), ys(n);
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &xs[i], &ys[i]);
      xs[i] -= x0, ys[i] -= y0;
      begans += xs[i] * xs[i] + ys[i] * ys[i];
    }

    vi dyn(1 << n, INF);
    vpii fr(1 << n);
    dyn[0] = 0;
    for (int m = 1; m < (1 << n); m++) {
      int first = 0;
      for (; !(m & (1 << first)); first++);

      int nm = m ^ (1 << first);
      int cans = dist(0, 0, xs[first], ys[first]) + dyn[nm];
      pii cfr(first, -1);

      for (int second = first + 1; second < n; second++)
        if (m & (1 << second)) {
          int nans = dist(xs[first], ys[first], xs[second], ys[second]) + dyn[nm ^ (1 << second)];
          if (cans > nans) {
            cans = nans;
            cfr.second = second;
          }
        }
      dyn[m] = cans;
      fr[m] = cfr;
    }

    printf("%d\n", begans + dyn[(1 << n) - 1]);
    vi ans; ans.pb(0);
    for (int m = (1 << n) - 1; m;) {
      int a = fr[m].first, b = fr[m].second;
      ans.pb(a + 1); m ^= 1 << a;
      if (b >= 0) { ans.pb(b + 1); m ^= 1 << b; }
      ans.pb(0);
    }
    for (int i = 0; i < ans.size(); i++) printf("%d%c", ans[i], "\n "[i + 1 < ans.size()]);

    #ifndef DEBUG
    break;
    #endif
  }

  return 0;
}