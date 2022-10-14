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

class Solver {
  struct Node {
    int toadd;
    int miv, micnt;
    Node() : toadd(0), miv(0), micnt(0) {}
    Node(int x, int y) : toadd(0), miv(x), micnt(y) {}
    void add(int v) {
      toadd += v;
      miv += v;
    }
    friend Node operator+(const Node &a, const Node &b) {
      if (a.miv < b.miv) return Node(a.miv, a.micnt);
      if (a.miv > b.miv) return Node(b.miv, b.micnt);
      return Node(a.miv, a.micnt + b.micnt);
    }
  };
  vector<Node> tr;
  int off;

  void push(int v) {
    if (!tr[v].toadd) return;
    if (v < off) {
      tr[2 * v    ].add(tr[v].toadd);
      tr[2 * v + 1].add(tr[v].toadd);
    }
    tr[v].toadd = 0;
  }
  void _add(int v, int l, int r, int L, int R, int V) {
    if (r < L || R < l) return;
    if (L <= l && r <= R) {
      tr[v].add(V);
      return;
    }
    push(v);
    int m = (l + r) / 2;
    _add(2 * v    , l    , m, L, R, V);
    _add(2 * v + 1, m + 1, r, L, R, V);
    tr[v] = tr[2 * v] + tr[2 * v + 1];
  }

public:
  Solver(int n) {
    off = 1;
    while (off < n) off <<= 1;
    tr = vector<Node>(2 * off);
    forn (i, n)
      tr[off + i].micnt = 1;
    for (int i = off - 1; i >= 1; i--)
      tr[i] = tr[2 * i] + tr[2 * i + 1];
  }
  void addTo(int l, int r, int v) {
    _add(1, 0, off - 1, l, r, v);
  }
  int countZeros() {
    assert(tr[1].miv >= 0);
    return tr[1].miv == 0 ? tr[1].micnt : 0;
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
    forn (i, n) {
      int x, y;
      scanf("%d%d", &x, &y), x--, y--;
      as[x] = y;
    }

    ll ans = 0;
    Solver s(n);
    vector<pii> mas(1, mp( inf, n));
    vector<pii> mis(1, mp(-inf, n));
    for (int i = n - 1; i >= 0; i--) {
      {
        int x = i + 1;
        while (mas.back().first < as[i]) {
          int y = mas.back().second;
          s.addTo(x, y, as[i] - mas.back().first);
          mas.pop_back();
          x = y + 1;
        }
        mas.pb(mp(as[i], x - 1));
      }
      {
        int x = i + 1;
        while (mis.back().first > as[i]) {
          int y = mis.back().second;
          s.addTo(x, y, mis.back().first - as[i]);
          mis.pop_back();
          x = y + 1;
        }
        mis.pb(mp(as[i], x - 1));
      }
      if (i + 1 < n) {
        s.addTo(i + 1, n - 1, -1);
      }
      ans += s.countZeros() - i;
    }
    printf("%I64d\n", ans);
  }

  return 0;
}