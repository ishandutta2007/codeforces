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
#include <array>

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

void madd(int &a, int b, int MOD) {
  if ((a += b) >= MOD) a -= MOD;
}

int mmul(int a, int b, int MOD) {
  return ll(a) * b % MOD;
}

int mpow(int a, int b, int MOD) {
  int res = 1;
  for (; b; b >>= 1, a = mmul(a, a, MOD))
    if (b & 1) res = mmul(res, a, MOD);
  return res;
}

int phi(int n) {
  int res = 1;
  const int N0 = n;
  for (int p = 2; p * p <= N0; p++) {
    if (n % p) continue;
    res *= p - 1;
    n /= p;
    while (n % p == 0) {
      res *= p;
      n /= p;
    }
  }
  if (n > 1) {
    res *= n - 1;
  }
  return res;
}

vi mods;
const int MAXMS = 31;
const int MAXRV = 32;

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

//  precalc();
  assert(phi(2) == 1);
  assert(phi(11) == 10);
  assert(phi(12) == 4);
  assert(phi(72) == 24);
  assert(phi(86) == 42);

  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    mods = {m};
    while (mods.back() > 1) {
      mods.push_back(phi(mods.back()));
    }
    eprintf("mods (%d):\n", sz(mods));
    forn (i, sz(mods))
      eprintf("mods[%d]=%d\n", i, mods[i]);
    assert(sz(mods) <= MAXMS);

    vi as(n);
    for (int &x : as)
      scanf("%d", &x);

    int q;
    scanf("%d", &q);
    forn (qid, q) {
      int l, r;
      scanf("%d%d", &l, &r), l--, r--;
      r = min(r, l + sz(mods) - 1);

      int i = r - l;
      int prealVal = min(MAXRV, as[r]);
      int pmval = as[r] % mods[i];
      for (i--, r--; i >= 0; i--, r--) {
//        eprintf("r=%d (%d); ^ %d %d\n", i, as[r], prealVal, pmval);
        int nrealVal = 1, nmval = 1 % mods[i];
        if (as[r] == 1) {
          // do nothing
        } else if (prealVal < MAXRV) {
          for (int j = 0; j < prealVal && nrealVal < MAXRV; j++) {
            nrealVal *= as[r];
          }
          nrealVal = min(nrealVal, MAXRV);
          nmval = mpow(as[r] % mods[i], prealVal, mods[i]);
        } else {
          nrealVal = MAXRV;
          nmval = mpow(as[r] % mods[i], mods[i + 1] + pmval, mods[i]);
        }
        prealVal = nrealVal;
        pmval = nmval;
      }
      printf("%d\n", pmval);
    }
    #ifdef DEBUG
    eprintf("\n");
    printf("\n");
    #endif
  }

  return 0;
}