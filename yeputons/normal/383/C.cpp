#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <map>
#include <set>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

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

class fenv_tree {
  vi tr;
  static int f(int x) { return x & -x; }

  int _get(int x) {
    int res = 0;
    for (x++; x > 0; x -= f(x))
      res += tr[x];
    return res;
  }
  void _add(int x, int val) {
    for (x++; x < sz(tr); x += f(x))
      tr[x] += val;
  }

  public:
  fenv_tree(int n) : tr(n + 1, 0) {}
  int get(int x) {
    return _get(x);
  }
  void add(int l, int r, int val) {
    _add(l, val);
    _add(r + 1, -val);
  }
};

vvi es;
vi seq, start, end;
vi hs;

void dfs(int v) {
  if (start[v] >= 0) return;
  start[v] = sz(seq);
  seq.pb(v);
  for (int i = 0; i < sz(es[v]); i++) {
    int b = es[v][i];
    hs[b] = hs[v] ^ 1;
    dfs(b);
  }
  end[v] = sz(seq) - 1;
}

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n, m;
  while (scanf("%d%d", &n, &m) >= 1) {
    vi svals(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &svals[i]);

    es = vvi(n);
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      scanf("%d%d", &a, &b), a--, b--;
      es[a].pb(b);
      es[b].pb(a);
    }

    seq = vi();
    start = vi(n, -1);
    end = vi(n, -1);
    hs = vi(n, 0);
    dfs(0);

    assert(sz(seq) == n);
    fenv_tree trs[2] = { fenv_tree(n), fenv_tree(n) };
    for (int i = 0; i < n; i++) {
      trs[hs[i]].add(start[i], start[i], svals[i]);
    }

//    for (int i = 0; i < n; i++)
//      eprintf("%d%c", seq[i] + 1, "\n "[i + 1 < n]);

    while (m --> 0) {
      int ty, x;
      scanf("%d%d", &ty, &x), x--;
      if (ty == 1) {
        int val;
        scanf("%d", &val);

        trs[hs[x]].add(start[x], end[x], val);
        trs[!hs[x]].add(start[x], end[x], -val);
      } else {
        int res = 0;
        res += trs[hs[x]].get(start[x]);
        printf("%d\n", res);
      }
    }
  }
  return 0;
}