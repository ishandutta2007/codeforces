#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cstring>
#include <cassert>
#include <cmath>
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

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef vector<ll> vll;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<bool> vb;

#ifdef linux
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif

ll f[1500][1500];
ll d[1500][1501];
ll maxv[1501];

int main() {
  int h, w;
  while (scanf("%d%d", &h, &w) >= 2) {
    memset(d, 0x80, sizeof d);
    for (int y = 0; y < h; y++)
      for (int x = 0; x < w; x++)
        scanf(LLD, &f[y][x]);
    
    ll csum = 0;
    for (int x = 0; x <= w; x++) {
      d[0][x] = csum;
      if (x < w) csum += f[0][x];
    }
    memset(maxv, 0x80, sizeof maxv);
    for (int x = w; x >= 0; x--) {
      maxv[x] = d[0][x];
      if (x + 1 <= w) maxv[x] = max(maxv[x], maxv[x + 1]);
    }
    
    for (int y = 1; y < h; y++) {
      csum = 0;
      for (int ccnt = 0; ccnt <= w; ccnt++) {
        if (y & 1) {
          if (ccnt + 1 <= w)
            d[y][ccnt] = maxv[ccnt + 1];
        } else {
          if (ccnt > 0)
            d[y][ccnt] = maxv[ccnt - 1];
        }
        
        d[y][ccnt] += csum;
        if (ccnt < w)
          csum += f[y][ccnt];
      }
      memset(maxv, 0x80, sizeof maxv);
      if (y & 1) {
        for (int x = 1; x <= w; x++) {
          maxv[x] = d[y][x];
          if (x) maxv[x] = max(maxv[x], maxv[x - 1]);
        }
      } else {
        for (int x = w; x >= 1; x--) {
          maxv[x] = d[y][x];
          if (x + 1 <= w) maxv[x] = max(maxv[x], maxv[x + 1]);
        }
      }
    }
    ll ans = 0x8080808080808080ll;
    for (int x = 1; x <= w; x++) ans = max(ans, d[h - 1][x]);
    printf(LLD "\n", ans);
    
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}