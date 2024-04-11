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

const ll INFLL = 4e18;

struct Friend {
  ll x; int k; int msk;
  bool operator<(const Friend &f2) const {
    return k < f2.k;
  }
};

void relax(ll &a, ll b) { a = min(a, b); }

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int n, m; ll b;
  while (scanf("%d%d" LLD, &n, &m, &b) == 3) {
    vector<ll> curs(1 << m, INFLL);
    curs[0] = 0;

    ll ans = INFLL;
    vector<Friend> fs(n);
    for (Friend &f : fs) {
      int cnt;
      scanf(LLD "%d%d", &f.x, &f.k, &cnt);
      while (cnt --> 0) {
        int id;
        scanf("%d", &id), id--;
        assert(0 <= id && id < m);
        f.msk |= 1 << id;
      }
    }
    sort(fs.begin(), fs.end());

    int lastcnt = 0;
    vector<ll> ncurs(1 << m);
    for (const Friend &f : fs) {
      fill(ncurs.begin(), ncurs.end(), INFLL);
      ll toadd = ll(f.k - lastcnt) * b;
      assert(toadd >= 0);
      for (int om = 0; om < (1 << m); om++) {
        ll cval = curs[om];
        if (cval >= INFLL) continue;
        cval += toadd;

        relax(ncurs[om], cval);
        relax(ncurs[om | f.msk], cval + f.x);
      }
      curs.swap(ncurs);
      lastcnt = f.k;
      ans = min(ans, curs.back());
    }

    if (ans >= INFLL) ans = -1;
    printf(LLD"\n", ans);
  }

  return 0;
}