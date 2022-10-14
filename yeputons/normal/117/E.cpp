#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf
#endif
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
  vi tr, trrev;
  int off;

  void norm(int v, int lt, int rt) {
    if (!trrev[v]) return;
    if (v < off) {
      trrev[2 * v] ^= 1;
      trrev[2 * v + 1] ^= 1;
    }
    tr[v] = rt - lt - tr[v];
    trrev[v] = false;
  }

  int lr, rr;
  void _rev(int v, int lt, int rt) {
    if (rr <= lt || rt <= lr) return;
    norm(v, lt, rt);
    if (lr <= lt && rt <= rr) {
      trrev[v] = true;
      return;
    }
    int mt = (lt + rt) / 2;
    _rev(2 * v, lt, mt);
    norm(2 * v, lt, mt);

    _rev(2 * v + 1, mt, rt);
    norm(2 * v + 1, mt, rt);
    tr[v] = tr[2 * v] + tr[2 * v + 1];
  }
  int _get(int v, int lt, int rt) {
    if (rr <= lt || rt <= lr) return 0;
    norm(v, lt, rt);
    if (lr <= lt && rt <= rr) return tr[v];
    int mt = (lt + rt) / 2;
    return _get(2 * v, lt, mt) + _get(2 * v + 1, mt, rt);
  }

  int st;
  public:
  segm_tree(int _st, int en) : st(_st) {
    int n = en - st;
    off = 1; while (off < n) off <<= 1;
    tr = vi(2 * off, false);
    trrev = vi(2 * off, false);
    rev(st, en - 1);
  }
  void rev(int _l, int _r) {
    if (_l > _r) return;
    lr = _l - st; rr = _r - st + 1;
    _rev(1, 0, off);
  }
  int get(int _l, int _r) {
    if (_l > _r) return 0 ;
    lr = _l - st; rr = _r - st + 1;
    return _get(1, 0, off);
  }
};

class HLDecom {
  vi par;
  vi ws, hs;
  vb vals;

  vvi chi;

  vi col;
  vector<segm_tree> trs; vi prevs, heads;
  int ccnt;

  int paint(int v) {
    col[v] = ccnt;

    int maw = -1, mai = -1;
    for (int i = 0; i < sz(chi[v]); i++) {
      int b = chi[v][i];
      if (ws[b] > maw) {
        maw = ws[b];
        mai = b;
      }
    }
    if (mai < 0) return 1;
    return 1 + paint(mai);
  }

  void build(int v) {
    if (col[v] < 0) {
      int st = hs[v];
      heads.pb(par[v]);
      prevs.pb(par[v] < 0 ? -1 : col[par[v]]);
      int en = st + paint(v);
      trs.pb(segm_tree(st, en));
      ccnt++;
    }
    for (int i = 0; i < sz(chi[v]); i++)
      build(chi[v][i]);
  }

  int cans;
  
  public:
  HLDecom(const vvi &_chi, const vi &_ws, const vi &_hs) : par(sz(_chi), -1), ws(_ws), hs(_hs), chi(_chi) {
    for (int i = 0; i < sz(chi); i++)
    for (int i2 = 0; i2 < sz(chi[i]); i2++)
      par[chi[i][i2]] = i;
    assert(par[0] < 0);

    vals = vb(sz(chi), true);
    vals[0] = false;

    col = vi(sz(chi), -1);
    trs.clear(); prevs.clear(); heads.clear();
    ccnt = 0;
    build(0);
    cans = sz(chi) - 1;
  }
  void reverse(int a, int b) {
    if (hs[a] > hs[b]) swap(a, b);
    for (int x = col[b]; x >= 0; b = heads[x], x = prevs[x]) {
//      eprintf("trs[%d].rev(%d..%d): %d-->", x, hs[a] + 1, hs[b], cans);
      cans -= trs[x].get(0, 1e9);
      trs[x].rev(hs[a] + 1, hs[b]);
      cans += trs[x].get(0, 1e9);
//      eprintf("%d\n", cans);
    }
  }
  int get(int a, int b) {
    if (hs[a] > hs[b]) swap(a, b);
    int ans = 0;
    for (int x = col[b]; x >= 0; b = heads[x], x = prevs[x])
      ans += trs[x].get(hs[a] + 1, hs[b]);
    return ans;
  }
  int get() { return cans; }
};

const int K = 17;

vvi es;
vvi chi;
vvi pars;
vb was;
pii be;

vi ws, hs;

void dfs(int v) {
  was[v] = true;
  ws[v] = 1;
  for (int i = 0; i < sz(es[v]); i++) {
    int b = es[v][i];
    if (b == pars[v][0]) continue;
    if (was[b]) { be = mp(b, v); continue; }

    pars[b][0] = v; hs[b] = hs[v] + 1;
    for (int i = 1; i < K; i++)
      if (pars[b][i - 1] >= 0)
        pars[b][i] = pars[pars[b][i - 1]][i - 1];

    dfs(b);
    eprintf("%d-->%d\n", v, b);
    chi[v].pb(b);
    ws[v] += ws[b];
  }
}
int jump(int a, int h) {
  for (int i = K - 1; i >= 0; i--)
    if (h >= (1 << i)) {
      a = pars[a][i];
      h -= 1 << i;
    }
  return a;
}
int lca(int a, int b) {
  if (hs[a] < hs[b]) swap(a, b);
  a = jump(a, hs[a] - hs[b]);
  for (int i = K - 1; i >= 0; i--)
    if (pars[a][i] != pars[b][i]) {
      a = pars[a][i];
      b = pars[b][i];
    }
  return (a != b) ? pars[a][0] : a;
}
int getd(int a, int b) {
  int c = lca(a, b);
  return hs[a] + hs[b] - 2 * hs[c];
}
int getKth(int a, int b, int k) {
  int c = lca(a, b);
  int d1 = hs[a] - hs[c], d2 = hs[b] - hs[c];
  if (k > d1 + d2) return -1;

  if (k <= d1) return jump(a, k);
  return jump(b, d1 + d2 - k);
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, m;
  while (scanf("%d%d", &n, &m) >= 1) {
    es = vvi(n);
    for (int i = 0; i < n; i++) {
      int a, b;
      scanf("%d%d", &a, &b), a--, b--;
      es[a].pb(b);
      es[b].pb(a);
    }

    pars = vvi(n, vi(K, -1));
    chi = vvi(n);
    be = mp(-1, -1);
    was = vb(n, false);
    hs = vi(n, 0);
    ws = vi(n, 0);
    dfs(0);
    eprintf("bad=%d %d\n", be.first, be.second);

    int bec = lca(be.first, be.second);

    HLDecom s(chi, ws, hs);
    bool bval = true;
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b), a--, b--;
      eprintf("a=%d, b=%d\n", a, b);

      int bd = getd(a, b), bp1 = -1, bp2 = -1;

      int p1 = be.first, p2 = be.second;
      for (int step = 0; step < 2; step++, swap(p1, p2)) {
        int cd = getd(a, p1) + 1 + getd(p2, b);
        bool g = cd < bd;
        if (cd == bd) {
          assert(bp1 < 0);

          int v1 = lca(a, p1), v2 = lca(b, p1), v3 = lca(a, b);
          int cent = hs[v1] > hs[v2] ? v1 : v2;
          if (hs[v3] > hs[cent]) cent = v3;
          int k = getd(a, cent) + 1;

          int alpha = getKth(a, b, k); assert(alpha >= 0);
          int beta = getKth(a, p1, k); if (beta < 0) beta = p2;
          g = beta < alpha;
        }
        if (g) { bd = cd; bp1 = p1; bp2 = p2; }
      }

      eprintf("bd=%d. %d; %d\n", bd, bp1, bp2);
      // doit
      if (bp1 < 0) {
        int c = lca(a, b);
        s.reverse(a, c);
        s.reverse(c, b);
      } else {
        int c = lca(a, bp1);
        s.reverse(a, c);
        s.reverse(c, bp1);

        bval ^= 1;
        c = lca(bp2, b);
        s.reverse(bp2, c);
        s.reverse(c, b);
      }

      int ans = 1 + s.get();
      if ((s.get(be.first, bec) + s.get(bec, be.second)) && !bval)
        ans--;
      printf("%d\n", ans);
    }
//    break;
  }
  return 0;
}