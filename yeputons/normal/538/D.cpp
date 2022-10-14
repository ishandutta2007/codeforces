#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <iostream>

#define pb push_back
#define mp make_pair
#define TASKNAME ""

#ifdef DEBUG
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("[" #x "] Time = %.3lfs\n",clock()*1.0/CLOCKS_PER_SEC)

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

#define sz(x) ((int)(x).size())
#define forn(i, n) for (int i = 0; i < (n); i++)

using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;

const int inf = 1e9;
const double eps = 1e-9;
const int INF = inf;
const double EPS = eps;

#ifdef DEBUG
struct __timestamper {
  ~__timestamper(){
    TIMESTAMP(end);
  }
} __Timestamper;
#else
struct __timestamper {};
#endif

/*Template end*/

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int n;
  while (scanf("%d", &n) == 1) {
    vector<string> f(n);
    forn (y, n) {
      static char str[51];
      scanf("%s", str);
      f[y] = str;
    }

    vvb vecs(2 * n - 1, vb(2 * n - 1, true));

    forn (y1, n)
    forn (x1, n) if (f[y1][x1] == 'o') {
      forn (y2, n)
      forn (x2, n) if (f[y2][x2] == '.') {
        vecs[y2 - y1 + n - 1][x2 - x1 + n - 1] = false;
      }
    }

    vector<string> f2(n, string(n, '.'));
    forn (y, n)
    forn (x, n) if (f[y][x] == 'o') {
      f2[y][x] = 'o';
      forn (dy, 2 * n - 1)
      forn (dx, 2 * n - 1) if (vecs[dy][dx]) {
        int nx = x + dx - (n - 1);
        int ny = y + dy - (n - 1);
        if (nx < 0 || n <= nx) continue;
        if (ny < 0 || n <= ny) continue;
        if (f2[ny][nx] == '.') {
          f2[ny][nx] = 'x';
        }
      }
    }

    if (f != f2) {
      printf("NO\n");
      continue;
    }
    printf("YES\n");
    forn (dy, 2 * n - 1) {
      forn (dx, 2 * n - 1) {
        if (dx == n - 1 && dy == n - 1)
          printf("o");
        else
          printf("%c", ".x"[!!vecs[dy][dx]]);
      }
      printf("\n");
    }
  }

  return 0;
}