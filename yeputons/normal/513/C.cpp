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

vi ls, rs;

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int n;
  while (scanf("%d", &n) == 1) {
    ls = vi(n);
    rs = vi(n);
    forn (i, n) {
      scanf("%d%d", &ls[i], &rs[i]);
    }

    const int MAXV = 10010;
    vector<vector<ld>> leqThan(n, vector<ld>(MAXV + 1, 0));

    forn (bad, n) {
      ld pprob = 0;
      for (int mv = 1; mv <= MAXV; mv++) {
        ld cprob = 1;
        forn (i, n) if (i != bad) {
          int tlen = rs[i] - ls[i] + 1;
          int cl = ls[i], cr = min(rs[i], mv);
          if (cl > cr) { cprob = 0; break; }
          cprob *= double(cr - cl + 1) / tlen;
        }
        leqThan[bad][mv] = leqThan[bad][mv - 1] + (cprob - pprob) * mv;
        pprob = cprob;
//        eprintf("leqThan[%d][%d]=%.4lf\n", bad, mv, (double)leqThan[bad][mv]);
      }
    }

    ld ans = 0;
    for (int mv = 1; mv <= MAXV; mv++) {
      forn (msk, 1 << n) if (msk) {
        ld prob = 1;
        for (int i = 0; i < n; i++) {
          int tlen = rs[i] - ls[i] + 1;
          int cl = ls[i], cr = rs[i];
          if (msk & (1 << i)) {
            cl = max(cl, mv);
            cr = min(cr, mv);
          } else {
            cr = min(cr, mv - 1);
          }
          if (cl > cr) { prob = 0; break; }
          prob *= double(cr - cl + 1) / tlen;
        }
        if (prob == 0) continue;

//        eprintf("mv=%d, msk=%d; prob=%.4lf\n", mv, msk, (double)prob);
        if (__builtin_popcount(msk) > 1) {
          ans += prob * mv;
          continue;
        }
        forn (id, n) if (msk & (1 << id)) {
          ans += leqThan[id][mv - 1] * 1.0 / double(rs[id] - ls[id] + 1);
        }
      }
    }
    printf("%.18lf\n", (double)ans);
//    break;
  }

  return 0;
}