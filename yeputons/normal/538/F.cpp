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

class fenv_tree {
  static int f(int x) { return x & -x; }
  vi tr;

  int _get(int x) const {
    int res = 0;
    for (x++; x > 0; x -= f(x))
      res += tr[x];
    return res;
  }
public:
  fenv_tree(int n) : tr(n + 1) {}
  void add(int x, int v) {
    for (x++; x < sz(tr); x += f(x))
      tr[x] += v;
  }
  int get(int l, int r) const {
    return _get(r) - _get(l - 1);
  }
};

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int n;
  while (scanf("%d", &n) == 1) {
    vi as(n);
    for (int &x : as) scanf("%d", &x);

    vector<pii> vers(n);
    forn (i, n) vers[i] = mp(as[i], i);
    sort(vers.begin(), vers.end());

    vi avals = as;
    sort(avals.begin(), avals.end());
    avals.erase(unique(avals.begin(), avals.end()), avals.end());

    vi anses(n);
    fenv_tree tr(n);
    int ptr = 0;
    for (int val : avals) {
      int ptr0 = ptr;
      while (ptr < sz(vers) && vers[ptr].first == val) {
        int x = vers[ptr].second;
//        eprintf("ver=%d at %d\n", val, x);
        for (int k = 1; k <= n - 1; k++) {
          int l = x * k + 1;
          int r = l + k - 1;
          r = min(r, n - 1);
          if (l > r) break;
//          eprintf("  k=%d; %d..%d\n", k, l, r);
          anses.at(k) += tr.get(l, r);
        }
        ptr++;
      }
      for (int i = ptr0; i < ptr; i++) {
        int x = vers[i].second;
//        eprintf("add %d\n", x);
        tr.add(x, 1);
      }
    }
    anses.erase(anses.begin());
    forn (i, sz(anses))
      printf("%d%c", anses[i], "\n "[i + 1 < sz(anses)]);
  }

  return 0;
}