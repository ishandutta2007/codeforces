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
    vvi a(n, vi(n));
    vi p(n);
    forn (i, n) {
      map<int, int> was;
      forn (j, n) {
        scanf("%d", &a[i][j]);
        was[a[i][j]]++;
      }
      int non1 = -1;
      for (auto x = was.begin(); x != was.end(); x++)
        if (x->second != 1) {
          assert(non1 == -1);
          non1 = x->first;
        }
      if (non1 != -1) {
        p[i] = non1;
      }
    }
    vi bad;
    set<int> met;
    forn (i, n)
      if (!p[i])
        bad.pb(i);
      else
        met.insert(p[i]);
    assert(sz(bad) == 2);
    assert(sz(met) == n - 2);
    for (int i = 1; i <= n - 2; i++)
      assert(met.count(i));

    p[bad[0]] = n - 1;
    p[bad[1]] = n;
    eprintf("try them\n");
    vi ans;
    for (int step = 0; step < 2; step++, swap(p[bad[0]], p[bad[1]])) {
      vvi ra(n, vi(n));
      forn (i, n)
        forn (j, n)
          if (i != j) {
            ra[i][j] = min(p[i], p[j]);
          }
      if (ra == a) {
        eprintf("found\n");
        ans = p;
      }
    }
    assert(sz(ans) == n);
    forn (i, n)
      printf("%d%c", ans[i], "\n "[i + 1 < n]);
  }

  return 0;
}