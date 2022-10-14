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

#define MAXL 100000
bool busy[MAXL];

int main() {
  int L, b, f, n;
  while (scanf("%d%d%d%d", &L, &b, &f, &n) >= 4) {
    memset(busy, 0, sizeof busy);
    
    vi pos(n, -1);
    vi lens(n, -1);
    
    for (int i = 0; i < n; i++) {
      int ty, arg;
      scanf("%d%d", &ty, &arg);
      switch (ty) {
        case 1: {
          lens[i] = arg;
          int sum = 0;
          for (int i2 = 0; i2 < arg + f && i2 < L; i2++)
            sum += busy[i2];
          
          for (int i2 = 0; i2 + arg <= L; i2++) {
            if (!sum) {
              pos[i] = i2; break;
            }
            if (i2 - b >= 0) sum -= busy[i2 - b];
            if (i2 + arg + f < L) sum += busy[i2 + arg + f];
          }
          
          if (pos[i] >= 0) {
            for (int i2 = 0; i2 < arg; i2++)
              busy[pos[i] + i2] = true;
          }
          printf("%d\n", pos[i]);
        } break;
        case 2:
          arg--;
          assert(pos[arg] >= 0);
          for (int i = 0; i < lens[arg]; i++)
            busy[pos[arg] + i] = false;
          break;
      }
    }

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}