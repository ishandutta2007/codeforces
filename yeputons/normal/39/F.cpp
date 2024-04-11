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

  int n, m, k;
  while (scanf("%d%d%d", &n, &m, &k) >= 3) {
    vi lens(m), bugs(k);
    for (int i = 0; i < m; i++) scanf("%d", &lens[i]);
    for (int i = 0; i < k; i++) scanf("%d", &bugs[i]);

    int bans = k + 1;
    vi bres;

    for (int i = 0; i < m; i++) {
      int cnt = 0;
      for (int i2 = 0; i2 < k; i2++)
        cnt += !(bugs[i2] % lens[i]);
      if (cnt < bans) {
        bans = cnt;
        bres = vi(1, i);
      } else if (cnt == bans)
        bres.pb(i);
    }

    printf("%d\n", bres.size());
    for (int i = 0; i < bres.size(); i++)
      printf("%d%c", bres[i] + 1, "\n "[i + 1 < bres.size()]);

    #ifndef DEBUG
    break;
    #endif
  } 
  return 0;
}