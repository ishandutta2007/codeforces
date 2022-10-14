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

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define sqr(a, b) ((a) * (a))
#define INF 2000000000
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

int main() {
  #ifdef DEBUG
  freopen("stdin", "r", stdin);
  freopen("stdout", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vi a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    vi d(n, 0), fr(n, -1);
    int ans = 0, ai = -1;

    for (int i = 0; i < n; i++) {
      if (a[i] <= 0) continue;
      if (a[i] > 1) {
        for (int i2 = 0; i2 < i; i2++)
          if (a[i2] == a[i] - 1 && d[i2] > d[i]) {
            d[i] = d[i2] + 1;
            fr[i] = i2;
          }
      } else {
        d[i] = 1;
      }

      if (d[i] > ans) {
        ans = d[i]; ai = i;
      }
    }

    printf("%d\n", ans);
    vi res;
    for (int i = ai; i >= 0; i = fr[i]) res.pb(2001 + i);

    assert(res.size() == ans);
    for (int i = 0; i < ans; i++)
      printf("%d%c", res[ans - i - 1], "\n "[i + 1 < ans]);

    #ifndef DEBUG
    break;
    #endif
  } 
  return 0;
}