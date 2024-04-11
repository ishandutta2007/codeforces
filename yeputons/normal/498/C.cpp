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

class Solver {
  struct Edge {
    int to, w, ne;
  };
  vector<Edge> es;
  vi firs;

  vi was;
  int wver;
  int en;

  bool dfs(int v) {
    if (v == en) return true;
    if (was[v] >= wver) return false;
    was[v] = wver;
    for (int i = firs[v]; i >= 0; i = es[i].ne) if (es[i].w > 0) {
      if (dfs(es[i].to)) {
        es[i].w--;
        es[i ^ 1].w++;
        return true;
      }
    }
    return false;
  }

public:
  Solver() : wver(0) {}
  void reset(int n) {
    es.clear();
    firs.resize(n);
    fill(firs.begin(), firs.end(), -1);
    was.resize(n);
//    eprintf("reset %d\n", n);
  }
  void adde(int a, int b, int w) {
    es.pb({ b, w, firs[a] }); firs[a] = sz(es) - 1;
    es.pb({ a, 0, firs[b] }); firs[b] = sz(es) - 1;
//    eprintf("%d-->%d (%d)\n", a, b, w);
  }
  int solve(int st, int _en) {
    en = _en;
    int res = 0;
    for (;;) {
      wver++;
      if (!dfs(st)) break;
      res++;
    }
//    eprintf("solve(%d..%d) = %d\n", st, en, res);
    return res;
  }
};

const int FINF = 30;

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    vi as(n);
    forn (i, n) scanf("%d", &as[i]);

    vector<pii> goods(m);
    forn (i, m) {
      scanf("%d%d", &goods[i].first, &goods[i].second);
      goods[i].first--, goods[i].second--;
      if (goods[i].first & 1) {
        swap(goods[i].first, goods[i].second);
      }
      assert(!(goods[i].first & 1));
      assert( (goods[i].second & 1));
    }

    map<int, vector<pii>> byPs;
    forn (i, n) {
      int x = as[i];
      for (int i2 = 2; i2 * i2 <= x; i2++) {
        int cdeg = 0;
        while (x % i2 == 0) {
          x /= i2;
          cdeg++;
        }
        if (cdeg) byPs[i2].pb(mp(i, cdeg));
      }
      if (x > 1) {
        byPs[x].pb(mp(i, 1));
      }
    }

    int ans = 0;
    Solver s;

    for (const auto &_curp : byPs) {
      const vector<pii> &nums = _curp.second;
//      eprintf("p=%d\n", _curp.first);

      vi myId(n, -1);
      forn (i, sz(nums)) {
        myId[nums[i].first] = i;
      }

      s.reset(sz(nums) + 2);
      const int st = sz(nums), en = sz(nums) + 1;
      for (pii e : goods) {
        int a = myId[e.first];
        int b = myId[e.second];
        if (a < 0 || b < 0) continue;
//        eprintf("a=%d, b=%d (%d %d)\n", a, b, e.first, e.second);
        s.adde(a, b, FINF);
      }
      forn (a, sz(nums)) {
        if ((nums[a].first & 1) == 0) {
          s.adde(st, a, nums[a].second);
        } else {
          s.adde(a, en, nums[a].second);
        }
      }
      ans += s.solve(st, en);
    }
    printf("%d\n", ans);
  }

  return 0;
}