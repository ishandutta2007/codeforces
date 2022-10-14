#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>
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

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;

int n;
char f[1000][1001];
int main() {
  #ifdef DEBUG
  freopen("stdin.txt", "r", stdin);
  freopen("stdout.txt", "w", stdout);
  #endif

  int w, h;
  while (scanf("%d%d", &h, &w) >= 1) {
    for (int y = 0; y < h; y++)
      scanf("%s", f[y]);

    vi cx(w), cy(h);
    for (int y = 0; y < h; y++)
      for (int x = 0; x < w; x++) {
        cx[x] += f[y][x] == '*';
        cy[y] += f[y][x] == '*';
      }

    ll ans = 0; 
    for (int y = 0; y < h; y++)
      for (int x = 0; x < w; x++)
        if (f[y][x] == '*') {
          ans += (ll)(cx[x] - 1) * (cy[y] - 1);
        }
    printf("%I64d\n", ans);
    
    #ifndef DEBUG
    #warning No multitest!!!
    break;
    #endif
  }
  return 0;
}