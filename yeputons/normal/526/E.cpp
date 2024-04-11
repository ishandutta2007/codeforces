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

  int n, q;
  while (scanf("%d%d", &n, &q) == 2) {
    vi as(3 * n);
    forn (i, n) {
      scanf("%d", &as[i]);
      as[    n + i] = as[i];
      as[2 * n + i] = as[i];
    }
    vector<ll> sums(3 * n + 1);
    forn (i, sz(as))
      sums[i + 1] = sums[i] + as[i];

    vi ne(3 * n);

    while (q --> 0) {
      ll maxv;
      scanf("%I64d", &maxv);
//      eprintf("maxv=%I64d\n", maxv);

      {
        int r = 0;
        forn (i, 3 * n) {
          r = max(r, i);
          while (r < sz(as) && sums[r + 1] - sums[i] <= maxv) r++;
          ne[i] = r;
        }
      }
      int ans = 0;
      static vector<pii> segs;
      segs.clear();
      for (int x = 0; x < n;) {
        int y = min(n, ne[x]);
        segs.pb(mp(y - x, x));
        x = y;
        ans++;
      }

      if (ans > 1) {
        segs.pb(segs[0]);
        int maxDiff = inf, cst = -1;
        forn (i, sz(segs) - 1) {
          pii s1 = segs[i];
          pii s2 = segs[i + 1];
          int clen = s1.first + s2.first;
          if (clen < maxDiff) {
            maxDiff = clen;
            cst = s1.second;
          }
        }

        for (int diff = 0; diff < maxDiff; diff++) {
          int st = cst + diff;
          int x = st;
          int cans = 0;
          while (x < st + n && cans < ans) {
            cans++;
//            eprintf("%d --> %d\n", x, ne[x]);
            x = ne[x];
          }
//          eprintf("st=%d; cans=%d\n", st, cans);
          if (cans < ans) {
            ans = cans;
            break;
          }
        }
      }
      printf("%d\n", ans);
    }
  }

  return 0;
}