#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>

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

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;

#define INF 2000000000
#define mp make_pair
#define pb push_back

#ifdef linux
#define LLD "%lld"
#elif _WIN32
#define LLD "%I64d"
#endif

char buf[26];
int main() {
  int h, w;
  while (scanf("%d%d", &h, &w) >= 2) {
    vvb f(h, vb(w, false));
    for (int y = 0; y < h; y++) {
      scanf("%s", buf);
      for (int x = 0; x < w; x++)
        f[y][x] = (buf[x] == '0');
    }

    int maxp = 0;
    for (int x1 = 0; x1 < w; x1++)
      for (int y1 = 0; y1 < h; y1++)
        for (int ch = 0; y1 + ch < h; ch++) {
          bool good = true;
          for (int cw = 0; x1 + cw < w; cw++) {
            for (int y = y1; y <= y1 + ch; y++)
              good = good && f[y][x1 + cw];
            if (!good) break;

            int curp = (cw + 1) * 2 + (ch + 1) * 2;
            maxp = max(maxp, curp);
          }
        }
    printf("%d\n", maxp);
    
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}