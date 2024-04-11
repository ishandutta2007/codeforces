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

const int MAXID = 8 * 7 * 6 * 5 / 4 / 3 / 2 / 1;
const int MAXM = 1 << 8;
const ll INFLL = 1e18;

struct DistMat {
  ll d[MAXID][MAXID];

  DistMat(ll v = INFLL) {
    forn (i, MAXID)
    forn (j, MAXID)
      d[i][j] = INFLL;
    forn (i, MAXID)
      d[i][i] = v;
  }
};
DistMat operator+(const DistMat &a, const DistMat &b) {
  DistMat res;
  forn (i, MAXID)
  forn (j, MAXID)
  forn (k, MAXID)
    res.d[i][j] = min(res.d[i][j], a.d[i][k] + b.d[k][j]);
  return res;
}

int x, k, idcnt;
int id2msk[MAXID];
int msk2id[MAXM];

DistMat construct(const vi &jumps) {
  assert(sz(jumps) == k);

  DistMat res;
  forn (id, idcnt) {
    int m = id2msk[id];
    if (!(m & 1)) {
      int nm = m >> 1;
      int id2 = msk2id[nm];
      assert(0 <= id2 && id2 < idcnt);

      res.d[id][id2] = 0;
      continue;
    }
    forn (jmp, k) {
      int nm = m >> 1;
      if (nm & (1 << jmp)) continue;
      nm |= 1 << jmp;

      int id2 = msk2id[nm];
      assert(0 <= id2 && id2 < idcnt);

      res.d[id][id2] = min(res.d[id][id2], (ll)jumps[jmp]);
    }
  }
  return res;
}

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int n, q;
  while (scanf("%d%d%d%d", &x, &k, &n, &q) == 4) {
    memset(id2msk, -1, sizeof id2msk);
    memset(msk2id, -1, sizeof msk2id);

    idcnt = 0;
    forn (m, 1 << k)
      if (__builtin_popcount(m) == x) {
        id2msk[idcnt] = m;
        msk2id[m] = idcnt;
        idcnt++;
      }
    assert(idcnt <= MAXID);

    vi cs(k);
    for (int &c : cs) scanf("%d", &c);

    vi evs = { 0, n - x };

    vector<pii> specs(q);
    for (pii &s : specs) {
      scanf("%d%d", &s.first, &s.second), s.first--;
      for (int i = 0; i <= k; i++) {
        int p = s.first - i;
        p = max(p, 0);
        p = min(p, n - x);
        evs.eb(p);
      }
    }
    sort(evs.begin(), evs.end());
    evs.erase(unique(evs.begin(), evs.end()), evs.end());

    vector<DistMat> bases = { construct(cs) };
    for (int i = 1; i <= 27; i++)
      bases.eb(bases.back() + bases.back());

    DistMat cur = 0;
    for (int eid = 0; eid + 1 < sz(evs); eid++) {
      int i = evs[eid], ni = evs[eid + 1];
      vi jumps = cs;
      for (pii s : specs)
        if (i < s.first && s.first <= i + k) {
          jumps[s.first - i - 1] += s.second;
        }
      if (jumps != cs) {
        DistMat cm = construct(jumps);
        assert(i + 1 == ni);
        cur = cur + cm;
      } else {
        int diff = ni - i;
        forn (id, sz(bases))
          if (diff & (1 << id))
            cur = cur + bases[id];
      }
    }
    int sid = msk2id[(1 << x) - 1];
    assert(0 <= sid && sid < idcnt);
    printf(LLD"\n", cur.d[sid][sid]);
  }

  return 0;
}