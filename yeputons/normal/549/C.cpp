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

const int MAXN = 20;
int mem[MAXN + 1][MAXN + 1][MAXN + 1][2];

int go(int a, int b, int k, int turn) {
  int res = mem[a][b][k][turn];
  if (res >= 0) return res;

  if (!k) {
    return res = (b % 2 == turn);
  }
  if (a && !go(a - 1, b, k - 1, !turn)) return res = true;
  if (b && !go(a, b - 1, k - 1, !turn)) return res = true;
  return res = false;
}

int calc1(int a, int b, int k) {
  if (k == 0) {
    return b % 2;
  }
  if (k % 2 == 0) {
    if (a <= k / 2) {
      return (a + b) % 2;
    }
    if (a + b <= k) {
      return (a + b) % 2;
    }
    return 0;
  }
  if (a + b <= k - 1) {
    return (a + b) % 2;
  }
  if (a >= (k + 1) / 2) {
    return b >= (k + 1) / 2;
  }
  return (a + b + 1) % 2;
}

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  memset(mem, -1, sizeof mem);
  forn (k, MAXN + 1) {
//    eprintf("k=%d\n", k);
    forn (a, MAXN) {
      forn (b, MAXN) {
//        eprintf("%d", go(a, b, k, 1));
        int tmp = calc1(a, b, k);
        if (tmp >= 0) {
          if (go(a, b, k, 1) != tmp) {
            eprintf("\nbad %d %d %d; expected %d, got %d\n", a, b, k, go(a, b, k, 1), tmp);
            return 0;
          }
        }
      }
//      eprintf("\n");
    }
  }

  int n, k;
  while (scanf("%d%d", &n, &k) == 2) {
    k = n - k;
    int a = 0, b = 0;
    forn (i, n) {
      int x;
      scanf("%d", &x);
      if (x % 2 == 0) a++;
      else b++;
    }
    bool res = calc1(a, b, k);
    if (res) printf("Stannis\n");
    else printf("Daenerys\n");
  }

  return 0;
}