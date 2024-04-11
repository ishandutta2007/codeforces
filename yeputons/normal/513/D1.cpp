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

class fenv_tree {
  static int f(int x) { return x & -x; }
  vi tr;
public:
  fenv_tree(int n) : tr(n + 1, -inf) {}
  void relax(int x, int v) {
    for (x++; x < sz(tr); x += f(x))
      tr[x] = max(tr[x], v);
  }
  int get(int x) {
    int res = -inf;
    for (x++; x > 0; x -= f(x))
      res = max(res, tr[x]);
    return res;
  }
};

vector<vector<pii>> rests;

int n;
vi rig, spl;
vi ans;
void restore(int v) {
  if (v + 1 < spl[v]) {
    rig[v + 1] = spl[v] - 1;
    restore(v + 1);
  }
  ans.pb(v);
  if (spl[v] <= rig[v]) {
    rig[spl[v]] = rig[v];
    restore(spl[v]);
  }
}

bool check() {
  rig = vi(n);
  forn (i, n) rig[i] = i;

  spl = vi(n);
  fenv_tree tr(n);
  forn (i, n) tr.relax(i, rig[i]);

  for (int i = n - 1; i >= 0; i--) {
    for (pii r : rests[i]) {
      if (r.first <= i) return false;
      rig[i] = max(rig[i], rig[r.first]);
    }
    rig[i] = tr.get(rig[i]);
    tr.relax(i, rig[i]);

    vector<pii> seq;
//    eprintf("i=%d, rig=%d\n", i, rig[i]);
    for (int i2 = i + 1; i2 <= rig[i];) {
      seq.pb(mp(i2, rig[i2]));
//      eprintf("  seq=%d..%d\n", i2, rig[i2]);
      i2 = rig[i2] + 1;
    }

    int b1 = 0, b2 = sz(seq);
    for (pii r : rests[i]) {
      int id = upper_bound(seq.begin(), seq.end(), mp(r.first, inf)) - seq.begin() - 1;
//      eprintf("  -->%d; id=%d\n", r.first, id);
      if (r.second == 0) {
        b1 = max(b1, id + 1);
      } else {
        b2 = min(b2, id);
      }
    }
    if (b1 > b2) return false;
    if (seq.empty()) {
      spl[i] = i + 1;
    } else {
      spl[i] = b1 == sz(seq) ? rig[i] + 1 : seq[b1].first;
    }
  }
  ans.clear();
  rig[0] = n - 1;
  restore(0);
  forn (i, n)
    printf("%d%c", ans[i] + 1, "\n "[i + 1 < n]);
  return true;
}

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int m;
  while (scanf("%d%d", &n, &m) == 2) {
    rests = vector<vector<pii>>(n);
    forn (i, m) {
      int a, b; char ty[10];
      scanf("%d%d%s", &a, &b, ty), a--, b--;
      rests[a].pb(mp(b, !strcmp(ty, "LEFT") ? 0 : 1));
    }
    if (!check()) {
      printf("IMPOSSIBLE\n");
    }
  }

  return 0;
}