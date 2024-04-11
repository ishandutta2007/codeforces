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

vvi es;
int n;

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  while (scanf("%d", &n) == 1) {
    es = vvi(n);
    forn (i, n) {
      static char buf[110];
      scanf("%s", buf);
      forn (j, n)
        if (buf[j] == '1') es[i].pb(j);
    }

    vi cur(n);
    forn (i, n)
      scanf("%d", &cur[i]);

    vi out;
    vb chk(n, false);
    for (;;) {
      bool was = false;
      vi ord(n);
      forn (i, n) ord[i] = i;
      random_shuffle(ord.begin(), ord.end());

      for (int i : ord) if (!chk[i] && !cur[i]) {
        chk[i] = true;
        out.pb(i);
        for (int b : es[i])
          --cur[b];
        was = true;
        break;
      }
      if (!was) break;
    }
    bool ans = true;
    forn (i, n) ans &= !!cur[i];
    assert(ans);

    printf("%d\n", sz(out));
    forn (i, sz(out))
      printf("%d%c", out[i] + 1, "\n "[i + 1 < sz(out)]);
  }

  return 0;
}