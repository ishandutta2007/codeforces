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

int h;

int rotate(int msk) {
  msk = (msk << 1) | !!(msk & (1 << (h - 1)));
  msk &= (1 << h) - 1;
  return msk;
}

const int MAXH = 12;
const int MAXCANONS = 352;

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int tn;
  while (scanf("%d", &tn) == 1) {
    while (tn --> 0) {
      int w;
      scanf("%d%d", &h, &w);
      eprintf("===== h=%d, w=%d =====\n", h, w);
      assert(h <= MAXH);
      vvi as(h, vi(w));
      forn (y, h)
        forn (x, w)
//          as[y][x] = int(1e5);
          scanf("%d", &as[y][x]);

      static int mskId[1 << MAXH];
      vi canons;
      forn (stMsk, 1 << h) {
        int curMsk = stMsk;
        int minMsk = curMsk;
        forn (off, h) {
          minMsk = min(minMsk, curMsk);
          curMsk = rotate(curMsk);
        }
        if (minMsk == stMsk) {
          canons.pb(stMsk);
          mskId[stMsk] = sz(canons) - 1;
        } else {
          assert(minMsk < stMsk);
          mskId[stMsk] = mskId[minMsk];
        }
      }
      vector<vector<pii>> trans(sz(canons));
      int sumTrans = 0;
      forn (i, sz(canons)) {
        int beforeCanonMsk = canons[i];
        forn (stMsk, 1 << h) if ((beforeCanonMsk & stMsk) == 0) {
          int afterCanon = mskId[beforeCanonMsk | stMsk];
          int curMsk = stMsk;
          forn (off, h) {
            trans[i].emplace_back(mskId[curMsk], afterCanon);
            curMsk = rotate(curMsk);
          }
        }
        sort(trans[i].begin(), trans[i].end());
        trans[i].erase(unique(trans[i].begin(), trans[i].end()), trans[i].end());
/*        eprintf("  from %d: %d\n", beforeCanonMsk, sz(trans[i]));
        for (int x : trans[i])
          eprintf("    %d\n", x);*/
        sumTrans += sz(trans[i]);
      }
      assert(canons.back() == (1 << h) - 1);
      eprintf("canons=%d, sumTrans=%d\n", sz(canons), sumTrans);
      assert(sz(canons) <= MAXCANONS);

      vi dyn(sz(canons), 0), ndyn(sz(canons));
      forn (x, w) {
        fill(ndyn.begin(), ndyn.end(), 0);
        
        static int curMaxSumMsk[MAXCANONS];
        static int curSum[1 << MAXH];
        forn (i, sz(canons))
          curMaxSumMsk[i] = 0;
        forn (msk, 1 << h) {
          if (msk) {
            int prevMsk = msk & (msk - 1);
            curSum[msk] = curSum[prevMsk];
            int curId = __builtin_ctz(msk ^ prevMsk);
            assert(curId >= 0 && curId < h);
            curSum[msk] += as[curId][x];
          }

/*          int realSum = 0;
          forn (y, h)
            if (msk & (1 << y))
              realSum += as[y][x];
          assert(realSum == curSum[msk]);*/

          int id = mskId[msk];
          curMaxSumMsk[id] = max(curMaxSumMsk[id], curSum[msk]);
        }

        forn (prevCanon, sz(canons))
          for (auto [thisMsk, nextCanon] : trans[prevCanon]) {
            ndyn[nextCanon] = max(ndyn[nextCanon], dyn[prevCanon] + curMaxSumMsk[thisMsk]);
          }

        dyn.swap(ndyn);
      }
      printf("%d\n", dyn.back());
      TIMESTAMP(test);
    }
  }

  return 0;
}