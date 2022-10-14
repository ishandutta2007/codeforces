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

#define min(a, b) (((a) < (b)) ? (a) : (b)) 
#define max(a, b) (((a) > (b)) ? (a) : (b)) 
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

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };

char buf[1001];
bool was[1000][1000];
int main() {
  #ifdef DEBUG
  freopen("task.in", "r", stdin);
  freopen("task.out", "w", stdout);
  #endif

  while (scanf("%s", buf) >= 1) {
    memset(was, 0, sizeof was);

    bool good = true;
    int x = 500, y = 500, prd = -1;
    for (int i = 0;; i++) {
      if (was[y][x]) good = false;
      was[y][x] = true;
      for (int d = 0; d < 4; d++)
        if (d != prd)
          if (was[y + dy[d]][x + dx[d]])
            good = false;
      if (!buf[i]) break;

      int d;
      switch (buf[i]) {
      case 'U': d = 0; break;
      case 'R': d = 1; break;
      case 'D': d = 2; break;
      case 'L': d = 3; break;
      default: assert(false); break;
      }
      x += dx[d], y += dy[d];
      prd = (d + 2) % 4;
    }
    printf(good ? "OK\n" : "BUG\n");

    #ifndef DEBUG
    break;
    #endif
  }

  return 0;
}