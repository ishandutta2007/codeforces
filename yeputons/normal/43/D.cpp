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

typedef pair<int, int> pii;

int main() {
  int w, h;
  while (scanf("%d%d", &w, &h) >= 1) {
    bool sw = false;
    vector<pii> res;
    if (w * h > 2 && (w == 1 || h == 1)) {
      printf("1\n%d %d 1 1\n", w, h);
      if (h == 1) { swap(w, h); sw = true; }
      for (int y = 0; y < h; y++)
	res.pb(mp(0, y));
      res.pb(mp(0, 0));
    } else if ((w & 1) && (h & 1)) {
      printf("1\n%d %d 1 1\n", w, h);
      for (int x = 0; x + 1 < w;) {
	for (int y = 0; y < h; y++) res.pb(mp(x, y)); x++;
	for (int y = h - 1; y >= 0; y--) res.pb(mp(x, y)); x++;
      }
      for (int y = 0; y < h; y++) res.pb(mp(w - 1, y));
      res.pb(mp(0, 0));
    } else {
      printf("0\n");
      if (w & 1) { swap(w, h); sw = true; }
      res.pb(mp(0, 0));
      for (int x = 0; x < w;) {
	for (int y = 1; y < h; y++) res.pb(mp(x, y)); x++;
	for (int y = h - 1; y >= 1; y--) res.pb(mp(x, y)); x++;
      }
      for (int x = w - 1; x >= 0; x--)
	res.pb(mp(x, 0));
    }
    
    for (int i = 0; i < res.size(); i++) {
      if (sw) swap(res[i].first, res[i].second);
      printf("%d %d\n", res[i].first + 1, res[i].second + 1);
    }
    
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}