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

int main() {
  int a1, b1, c1, a2, b2, c2;
  while (scanf("%d%d%d%d%d%d", &a1, &b1, &c1, &a2, &b2, &c2) >= 6) {
    if (!a1 && !b1 && c1) { printf("0\n"); continue; }
    if (!a2 && !b2 && c2) { printf("0\n"); continue; }
    if (!a1 && !b1) {
      printf("-1\n");
      continue;
    }
    if (!a2 && !b2) {
      printf("-1\n");
      continue;
    }
    
    int d = a1 * b2 - a2 * b1;
    if (d) {
      printf("1\n");
    } else {
      if ((a1 * c2 - a2 * c1 == 0) && (b1 * c2 - b2 * c1 == 0))
        printf("-1\n");
      else
        printf("0\n");
    }
    
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}