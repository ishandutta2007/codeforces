#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define TASKNAME "std"
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

class fenv_tree {
  vi tr;
  static const int f(int x) { return x ^ (x & (x - 1)); }

  public:
  fenv_tree() {}
  fenv_tree(int n) : tr(n + 1, 0) {}
  void add(int x, int v) {
    for (x++; x < sz(tr); x += f(x))
      tr[x] += v;
  }
  int get(int x) {
    assert(x >= -1 && x + 1 < sz(tr));
    int res = 0;
    for (x++; x > 0; x -= f(x))
      res += tr[x];
    return res;
  }
  int get(int l, int r) { return get(r) - get(l - 1); }
  void set(int x, int v) { add(x, v - get(x, x)); }
};

vvi es, esid;

vi escol, espos;
vi vcol, vpos;
vi csz;
int ccol;

void dfs(int v, int par, int cid) {
  vcol[v] = ccol;
  vpos[v] = cid;
  csz[ccol]++;
  for (int i = 0; i < sz(es[v]); i++) if (es[v][i] != par) {
    escol[esid[v][i]] = ccol;
    espos[esid[v][i]] = cid;
    dfs(es[v][i], v, cid + 1);
  }
}

int root;
int lca(int a, int b) {
  if (a == root || b == root) return root;
  if (vcol[a] == vcol[b]) return vpos[a] < vpos[b] ? a : b;
  return root;
}
const int INF = 1e9;

vector<fenv_tree> trs;

int go(int a, int b) {
  assert(vpos[a] <= vpos[b]);
  if (vpos[a] == vpos[b]) return 0;
  int csum = trs[vcol[b]].get(vpos[a], vpos[b] - 1);
  if (csum) return -INF;
  return vpos[b] - vpos[a];
}

int main()  {
  #ifdef DEBUG
  freopen(TASKNAME ".in", "r", stdin);
  freopen(TASKNAME ".out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    es = vvi(n);
    esid = vvi(n);
    vector<pii> ses(n - 1);
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      scanf("%d%d", &a, &b), a--, b--;
      ses[i] = mp(a, b);
      es[a].pb(b); esid[a].pb(i);
      es[b].pb(a); esid[b].pb(i);
    }

    root = 0;
    for (int i = 0; i < n; i++)
      if (sz(es[i]) > sz(es[root])) root = i;

    escol = vi(n - 1, -1);
    espos = vi(n - 1, -1);
    vcol = vi(n, -1);
    vpos = vi(n, 0);
    csz = vi();

    ccol = 0;
    for (int i = 0; i < sz(es[root]); i++) {
      csz.pb(0);
      escol[esid[root][i]] = ccol;
      espos[esid[root][i]] = 0;
      dfs(es[root][i], root, 1);
      ccol++;
    }

    trs.resize(n);
    for (int i = 0; i < ccol; i++) {
      trs[i] = fenv_tree(csz[i]);
    }

    int q;
    scanf("%d", &q);
    for (int step = 0; step < q; step++) {
      int ty, a, b;
      scanf("%d%d", &ty, &a), a--;
      if (ty == 1 || ty == 2) {
        trs[escol[a]].set(espos[a], ty - 1);
      } else {
        scanf("%d", &b), b--;

        int c = lca(a, b);
        int ans = go(c, a) + go(c, b);
        if (ans >= 0) printf("%d\n", ans);
        else printf("-1\n");
      }
    }
  }
  return 0;
}