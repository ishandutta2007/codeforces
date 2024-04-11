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
const int MAXW = 2000;
const int MAXCANONS = 352;

vi canons_cache[MAXH + 1];
vi mskId_cache[MAXH + 1];
vector<vector<pii>> trans_cache[MAXH + 1];

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
//          as[y][x] = abs(((rand() << 16) ^ rand()) % int(1e5)) + 1;
          scanf("%d", &as[y][x]);

      vi mskId;
      vi canons;
      if (canons_cache[h].empty() || 1) {
        mskId.resize(1 << h);
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
        canons_cache[h] = canons;
        mskId_cache[h] = mskId;
      }
      canons = canons_cache[h];
      mskId = mskId_cache[h];

      assert(canons.back() == (1 << h) - 1);
      assert(sz(canons) <= MAXCANONS);

      vector<vector<pii>> trans(sz(canons));
      if (trans_cache[h].empty()) {
        int sumTrans = 0;
        forn (i, sz(canons)) {
          int beforeCanonMsk = canons[i];

          static vector<pii> ctrans;
          ctrans.clear();
          ctrans.reserve(1 << h);
          forn (stMsk, 1 << h) if ((beforeCanonMsk & stMsk) == 0) {
            int afterCanon = mskId[beforeCanonMsk | stMsk];
            int curMsk = stMsk;
            forn (off, h) {
              ctrans.emplace_back(mskId[curMsk], afterCanon);
              curMsk = rotate(curMsk);
            }
          }
          sort(ctrans.begin(), ctrans.end());
          ctrans.erase(unique(ctrans.begin(), ctrans.end()), ctrans.end());
          trans[i] = ctrans;
  /*        eprintf("  from %d: %d\n", beforeCanonMsk, sz(trans[i]));
          for (int x : trans[i])
            eprintf("    %d\n", x);*/
          sumTrans += sz(trans[i]);
        }
        eprintf("canons=%d, sumTrans=%d\n", sz(canons), sumTrans);
        trans_cache[h] = trans;
      }
      trans = trans_cache[h];

      vector<vector<pii>> bestByMsk(sz(canons), vector<pii>(h + 1, mp(-1, -1)));
      forn (i, sz(canons)) if (canons[i])
        bestByMsk[i].resize(h / __builtin_popcount(canons[i]) + 1);

      auto insertInto = [&](int canonId, pii val) {
         auto &v = bestByMsk[canonId];
         v.back() = max(val, v.back());
         int i = sz(v) - 1;
         while (i > 0 && v[i - 1] < v[i]) {
           swap(v[i - 1], v[i]);
           i--;
         }
      };

      TIMESTAMP(before precalc);
      static int curMaxSumMsk[MAXW][MAXCANONS];
      forn (x, w) {
        static int curSum[1 << MAXH];
        forn (i, sz(canons))
          curMaxSumMsk[x][i] = 0;
        forn (msk, 1 << h) {
          if (msk) {
            int prevMsk = msk & (msk - 1);
            curSum[msk] = curSum[prevMsk];
            int curId = __builtin_ctz(msk ^ prevMsk);
            assert(curId >= 0 && curId < h);
            curSum[msk] += as[curId][x];
          }

          int id = mskId[msk];
          curMaxSumMsk[x][id] = max(curMaxSumMsk[x][id], curSum[msk]);
        }
        forn (i, sz(canons))
          insertInto(i, pii(curMaxSumMsk[x][i], x));
      }
      TIMESTAMP(after precalc);

      vb needCol(w);
      for (const auto &bests : bestByMsk)
        for (auto [colVal, col] : bests)
          if (col >= 0)
            needCol[col] = true;
      eprintf("needCols=%d\n", (int)count(needCol.begin(), needCol.end(), true));

      vi dyn(sz(canons), 0), ndyn(sz(canons));
      forn (x, w) if (needCol[x]) {
        fill(ndyn.begin(), ndyn.end(), 0);
        
        forn (prevCanon, sz(canons))
          for (auto [thisMsk, nextCanon] : trans[prevCanon]) {
            ndyn[nextCanon] = max(ndyn[nextCanon], dyn[prevCanon] + curMaxSumMsk[x][thisMsk]);
          }

        dyn.swap(ndyn);
      }
      printf("%d\n", dyn.back());
      TIMESTAMP(test);
    }
  }

  return 0;
}