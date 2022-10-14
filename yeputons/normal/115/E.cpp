#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

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

class segm_tree {
  vll tr, tradd;
  int off;

  void norm(int v) {
    if (!tradd[v]) return;
    if (v < off) {
      tradd[2 * v] += tradd[v];
      tradd[2 * v + 1] += tradd[v];
    }
    tr[v] += tradd[v];
    tradd[v] = 0;
  }

  int lr, rr; ll vr;
  void _add(int v, int lt, int rt) {
    if (rt < lr || rr < lt) return;
    norm(v);
    if (lr <= lt && rt <= rr) {
      tradd[v] += vr;
      return;
    }
    int mt = (lt + rt) / 2;
    _add(2 * v, lt, mt);
    _add(2 * v + 1, mt + 1, rt);

    norm(2 * v); norm(2 * v + 1);
    tr[v] = max(tr[2 * v], tr[2 * v + 1]);
  }
  ll _get(int v, int lt, int rt) {
    if (rt < lr || rr < lt) return 0;
    norm(v);
    if (lr <= lt && rt <= rr) return tr[v];
    int mt = (lt + rt) / 2;
    return max(_get(2 * v, lt, mt), _get(2 * v + 1, mt + 1, rt));
  }

  public:
  segm_tree(int _n) {
    off = 1; while (off < _n) off <<= 1;
    tr = vll(2 * off, 0);
    tradd = vll(2 * off, 0);
  }
  void add(int _lr, int _rr, ll _vr) {
    lr = _lr; rr = _rr; vr = _vr;
    _add(1, 0, off - 1);
  }
  ll getMax(int _lr, int _rr) {
    lr = _lr; rr = _rr;
    return _get(1, 0, off - 1);
  }
};

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, m;
  while (scanf("%d%d", &n, &m) >= 1) {
    vll pr(n);
    for (int i = 0; i < n; i++)
      scanf("%I64d", &pr[i]);

    vector<vector<pair<int, ll> > > rs(n);
    for (int i = 0; i < m; i++) {
      int a, b; ll p;
      scanf("%d%d%I64d", &a, &b, &p), a--, b--;
      rs[a].pb(mp(b, p));
    }

    segm_tree tr(n + 1);
    ll ans = 0;
    ll prval = 0;

    for (int i = n - 1; i >= 0; i--) {
      for (int i2 = 0; i2 < sz(rs[i]); i2++)
        tr.add(rs[i][i2].first + 1, n + 1, rs[i][i2].second);
      tr.add(i + 1, n + 1, -pr[i]);

      ll cval = max(prval, tr.getMax(i, n + 1));
      ans = max(ans, cval);
      tr.add(i, i, cval);
      prval = cval;
    }
    printf("%I64d\n", ans);
  }
  return 0;
}