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

int main() {
  int n;
  while (scanf("%d", &n) >= 1) {
    int cur = 0, st = 1;
    for (int i = 1; i < n; i++) {
      cur = (cur + st) % n; st++;
      printf("%d%c", cur + 1, "\n "[i + 1 < n]);
    }
    
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}