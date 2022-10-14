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

void relax(int &a, int b) {
  a = min(a, b);
}

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int n;
  while (scanf("%d", &n) == 1) {
    vi ls(n), cs(n);
    for (int &l : ls) scanf("%d", &l);
    for (int &c : cs) scanf("%d", &c);

    int ans = inf;
    forn (fid, n) {
      vi ps;
      {
        int x = ls[fid];
        for (int i = 2; i * i <= x; i++) if (x % i == 0) {
          ps.pb(i);
          while (x % i == 0) x /= i;
        }
        if (x > 1) ps.pb(x);
      }
      vi dyn(1 << sz(ps), inf);
      dyn.back() = cs[fid];
      forn (i, n) {
        int mym = 0;
        forn (pid, sz(ps)) if (ls[i] % ps[pid] == 0) mym |= 1 << pid;

        forn (m, sz(dyn)) {
          relax(dyn[m & mym], dyn[m] + cs[i]);
        }
      }
      ans = min(ans, dyn[0]);
    }
    printf("%d\n", ans == inf ? -1 : ans);
  }

  return 0;
}