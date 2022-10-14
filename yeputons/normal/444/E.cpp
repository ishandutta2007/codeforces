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

class Dsu {
  vi par, ss, vals;

  int get(int x) { return par[x] == x ? x : par[x] = get(par[x]); }
public:
  Dsu(const vi &_vals) : par(sz(_vals)), ss(sz(_vals), 1), vals(_vals) {
    forn (i, sz(vals)) par[i] = i;
  }
  int getVal(int x) { return vals[get(x)]; }
  int getSz(int x) { return ss[get(x)]; }
  void merge(int a, int b) {
    a = get(a); b = get(b);
    if (a == b) return;
    if (ss[a] > ss[b]) swap(a, b);
    par[a] = b;
    ss[b] += ss[a];
    vals[b] += vals[a];
  }
};

struct Edge {
  int a, b, w;
  bool operator<(const Edge &e2) const { return w < e2.w; }
};

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int n;
  while (scanf("%d", &n) == 1) {
    vector<Edge> es(n);
    for (int i = 0; i < n - 1; i++) {
      int a, b, w;
      scanf("%d%d%d", &a, &b, &w), a--, b--;
      es.pb({ a, b, w });
    }
    sort(es.begin(), es.end());

    vi xs(n);
    int sumx = 0;
    for (int &x : xs) scanf("%d", &x), sumx += x;

    int ans = 0;
    Dsu dsu(xs);
    for (int i = 0; i < sz(es); i++) {
      dsu.merge(es[i].a, es[i].b);
      bool ok = true;
      for (int i2 = 0; i2 < n; i2++)
        ok = ok && dsu.getSz(i2) <= sumx - dsu.getVal(i2);
      if (!ok) break;
      assert(i + 1 < sz(es));
      ans = es[i + 1].w;
    }
    printf("%d\n", ans);
  }

  return 0;
}