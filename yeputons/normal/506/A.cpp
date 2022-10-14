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
#include <unordered_map>

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

const int n = int(30001);

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int k, d0;
  while (scanf("%d%d", &k, &d0) == 2) {
    vi cnts(n, 0);
    while (k --> 0) {
      int x;
      scanf("%d", &x);
      cnts[x]++;
    }
    vector<vector<pii>> dyn(n);
    dyn[d0].pb(mp(d0, cnts[d0]));
    int ans = 0;

    static vector<pii> was(n, mp(0, 0));
    static int wver = 0;

    forn (i, n) {
      wver++;
      static vi jmps;
      jmps.clear();
      for (auto it : dyn[i]) {
        if (was[it.first].first < wver) {
          was[it.first] = mp(wver, 0);
          jmps.pb(it.first);
        }
        was[it.first].second = max(was[it.first].second, it.second);
      }
      dyn[i] = vector<pii>();

      for (int jmp : jmps) {
        int cans = was[jmp].second;
        ans = max(ans, cans);

        for (int k = -1; k <= 1; k++) {
          int ni = i + jmp + k;
          if (ni <= i || ni >= n) continue;

          int nans = cans + cnts[ni];
          ans = max(ans, nans);
          if (ni + jmp + k - 1 < n) {
            dyn[ni].pb(mp(jmp + k, nans));
          }
        }
      }
    }
    printf("%d\n", ans);
//    break;
  }

  return 0;
}