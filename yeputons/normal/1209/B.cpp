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
#define eb emplace_back
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

const int MAXT = 1000;

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int n;
  while (scanf("%d", &n) == 1) {
    static char init[110];
    scanf("%s", init);
    forn (i, n) init[i] -= '0';

    vector<vector<char>> states(MAXT, std::vector<char>(init, init + n));
    forn (i, n) {
      int period, next;
      assert(scanf("%d%d", &period, &next) == 2);
      char cur = init[i];
      assert(cur == !!cur);
      forn (t, MAXT) {
        assert(sz(states[t]) == n);
        if (t == next) {
          cur = !cur;
          next += period;
        }
        states[t][i] = cur;
      }
    }
    int ans = 0;
    forn (t, MAXT) {
      int cans = 0;
      forn (i, n) {
//        eprintf("%d", states[t][i]);
        cans += !!states[t][i];
      }
//      eprintf(": %d\n", cans);
      ans = max(ans, cans);
    }
    printf("%d\n", ans);
  }

  return 0;
}