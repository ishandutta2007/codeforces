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

const int PER = 60;

class segm_tree {
  struct Data {
    int toadd[PER];

    Data() {
      fill(toadd, toadd + PER, 0);
    }
    Data(int x) {
      assert(2 <= x && PER % x == 0);
      fill(toadd, toadd + PER, 1);
      for (int i = 0; i < PER; i += x)
        toadd[i]++;
    }
    int &operator[](int x) { return toadd[x]; }
    int  operator[](int x) const { return toadd[x]; }

    friend Data operator+(const Data &a, const Data &b) {
      Data res;
      for (int st = 0; st < PER; st++) {
        res[st] = a[st] + b[(st + a[st]) % PER];
      }
      return res;
    }
  };
  int off;
  vector<Data> tr;

public:
  segm_tree(vector<int> &as) {
    off = 1; while (off < sz(as)) off <<= 1;
    tr = vector<Data>(2 * off);
    forn (i, sz(as))
      tr[off + i] = as[i];
    for (int i = off - 1; i >= 1; i--)
      tr[i] = tr[2 * i] + tr[2 * i + 1];
  }
  void set(int x, int v) {
    tr[x += off] = v;
    for (x >>= 1; x >= 1; x >>= 1)
      tr[x] = tr[2 * x] + tr[2 * x + 1];
  }
  int get(int l, int r) {
    Data resl, resr;
    l += off; r += off;
    while (l <= r) {
      if (l & 1) resl = resl + tr[l++];
      if (!(r & 1)) resr = tr[r--] + resr;
      l >>= 1; r >>= 1;
    }
    Data res = resl + resr;
    return res[0];
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
    forn (i, n) scanf("%d", &as[i]);

    segm_tree tr(as);
    int q;
    scanf("%d", &q);
    while (q --> 0) {
      char op;
      scanf(" %c", &op);
      if (op == 'A') {
        int l, r;
        scanf("%d%d", &l, &r), l--, r -= 2;
        printf("%d\n", tr.get(l, r));
      } else if (op == 'C') {
        int x, v;
        scanf("%d%d", &x, &v), x--;
        tr.set(x, v);
      } else {
        assert(false);
      }
    }
  }

  return 0;
}