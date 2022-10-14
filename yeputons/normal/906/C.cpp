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

  int n, ecnt;
  while (scanf("%d%d", &n, &ecnt) == 2) {
    vi msks(n);
    forn (i, n) msks[i] = 1 << i;

    forn (i, ecnt) {
      int a, b;
      scanf("%d%d", &a, &b), a--, b--;
      msks[a] |= 1 << b;
      msks[b] |= 1 << a;
    }
    if (ecnt == n * (n - 1) / 2) {
      printf("0\n");
      continue;
    }

    vi mjoins(1 << n);
    forn (m, 1 << n) {
      forn (i, n) if (m & (1 << i))
        mjoins[m] |= msks[i];
    }

    vector<pii> dyn(1 << n, mp(n + 1, -1));
    dyn[0] = mp(0, -1);
    forn (m, 1 << n) if (dyn[m].first <= n) {
      forn (ne, n) if (m == 0 || (msks[ne] & m)) {
        int nm = m | (1 << ne);
        dyn[nm]  = min(dyn[nm], mp(dyn[m].first + 1, m * n + ne));
      }
    }
    int bans = n + 1, bm = -1;
    forn (m, 1 << n) if (mjoins[m] == (1 << n) - 1) {
      if (dyn[m].first < bans) {
        bans = dyn[m].first;
        bm = m;
      }
    }
    assert(bans <= n);
    eprintf("bans=%d, bm=%d\n", bans, bm);

    vi ans;
    for (int m = bm; m > 0;) {
      assert(dyn[m].second >= 0);
      int pm = dyn[m].second / n;
      int cur = dyn[m].second % n;
      ans.pb(cur);
      assert(pm < m);
      m = pm;
    }
    assert(sz(ans) == bans);

    reverse(ans.begin(), ans.end());
    printf("%d\n", sz(ans));
    forn (i, sz(ans))
      printf("%d%c", ans[i] + 1, "\n "[i + 1 < sz(ans)]);
  }

  return 0;
}