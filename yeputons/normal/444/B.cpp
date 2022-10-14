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

ll curX;
ll getNextX() {
    curX = (curX * 37 + 10007) % 1000000007;
    return curX;
}

int d;
vi as, bs;
void initAB() {
    int i;
    for(i = 0; i < sz(as); i = i + 1) {
        as[i] = i + 1;
    }
    for(i = 0; i < sz(as); i = i + 1) {
        swap(as[i], as[getNextX() % (i + 1)]);
    }
    for(i = 0; i < sz(bs); i = i + 1) {
        bs[i] = (i < d);
    }
    for(i = 0; i < sz(bs); i = i + 1) {
        swap(bs[i], bs[getNextX() % (i + 1)]);
    }
}

const int PCSZ = 22;
const int PCMSK = (1 << PCSZ) - 1;
char PCCTZ[1 << PCSZ];
inline int myctz(unsigned long long x) {
  if (x & PCMSK) return PCCTZ[x & PCMSK]; x >>= PCSZ;
  if (x & PCMSK) return PCCTZ[x & PCMSK] + PCSZ; x >>= PCSZ;
  assert(x);
  return PCCTZ[x] + PCSZ + PCSZ;
}

const int MAXN = int(1e5) + 100;
class mbs {
  static const int SZ = (MAXN + 63) / 64;
  unsigned long long data[SZ];
public:
  mbs() {
    clear();
  }
  void clear() {
    memset(data, 0, sizeof data);
  }
  void set(int x) {
    data[x >> 6] |= 1ULL << (x & 63);
  }
  void reset(int x) {
    data[x >> 6] &= ~(1ULL << (x & 63));
  }
  void assignAndShift(const mbs &b2, int shift) {
    {
      int tmp = shift / 64;
      for (int i = SZ - 1; i >= tmp; i--) {
        data[i] = b2.data[i - tmp];
      }
      for (int i = tmp - 1; i >= 0; i--) {
        data[i] = 0;
      }
      shift -= tmp * 64;
    }
    if (!shift) return;

    assert(0 < shift && shift < 64);
    for (int i = SZ - 1; i >= 0; i--) {
      data[i] <<= shift;
      if (i > 0) {
        data[i] |= (data[i - 1] >> (64 - shift));
      }
    }
  }
  void getBitsAnd(const mbs &b2, vi &out) {
    out.clear();
    forn (i, SZ) {
      unsigned long long x = data[i] & b2.data[i];
      while (x) {
        int id = myctz(x);
        out.pb(64 * i + id);
        x ^= 1ULL << id;
      }
    }
  }
};

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  for (int i = 1; i < (1 << PCSZ); i++) {
    PCCTZ[i] = (i & 1) ? 0 : (PCCTZ[i >> 1] + 1);
//    assert(PCCTZ[i] == __builtin_ctz(i));
  }

  int n;
  while (scanf("%d%d" LLD, &n, &d, &curX) == 3) {
    as = vi(n);
    bs = vi(n);
    initAB();

    static mbs unk, msk;
    #ifdef DEBUG
    unk.clear();
    msk.clear();
    #endif
    forn (i, n) {
      unk.set(i);
      if (bs[i]) msk.set(i);
    }

    vi res(n, 0);
    vi poses(n + 1, -1);
    forn (i, n) poses[as[i]] = i;
    for (int val = n; val >= 1; val--) {
      static mbs tmp;
      tmp.assignAndShift(msk, poses[val]);

      static vi bits;
      tmp.getBitsAnd(unk, bits);
      for (int x : bits) {
        res[x] = val;
        unk.reset(x);
      }
    }

    forn (i, n) {
      assert(res[i] >= 0);
      printf("%d\n", res[i]);
    }
  }

  return 0;
}