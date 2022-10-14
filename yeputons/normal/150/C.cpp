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
  vll tr, trsum, trsuf, trpref;
  int off;

  int lr, rr;
  void _get(int v, int lt, int rt, ll &res, ll &rsum, ll &rsuf, ll &rpref) {
    res = rsum = rsuf = rpref = 0;
    if (rt < lr || rr < lt) return;
//    eprintf("v=%d\n", v);
//    eprintf("%I64d %I64d %I64d %I64d\n", tr[v], trsum[v], trsuf[v], trpref[v]);
    if (lr <= lt && rt <= rr) {
      res = tr[v];
      rsum = trsum[v];
      rsuf = trsuf[v];
      rpref = trpref[v];
      return;
    }

    int mt = (lt + rt) / 2;
    ll _lres, _lsum, _lsuf, _lpref;
    ll _rres, _rsum, _rsuf, _rpref;
    _get(2 * v    , lt    , mt, _lres, _lsum, _lsuf, _lpref);
    _get(2 * v + 1, mt + 1, rt, _rres, _rsum, _rsuf, _rpref);

    rsum = _lsum + _rsum;
    rsuf = max(_lsuf + _rsum, _rsuf);
    rpref = max(_lsum + _rpref, _lpref);
    res = max(max(_lres, _rres), _lsuf + _rpref);
  }

  public:
  segm_tree(const vll &vals) {
    off = 1; while (off < sz(vals)) off <<= 1;

    tr = vll(2 * off, 0);
    trsum = vll(2 * off, 0);
    trsuf = vll(2 * off, 0);
    trpref = vll(2 * off, 0);
    for (int i = 0; i < sz(vals); i++) {
      trsum[off + i] = vals[i];
      trsuf[off + i] =
      trpref[off + i] =
      tr[off + i] = max(tr[i], vals[i]);
    }

    for (int i = off - 1; i >= 0; i--) {
      trsum[i] = trsum[2 * i] + trsum[2 * i + 1];
      trsuf[i] = max(trsuf[2 * i] + trsum[2 * i + 1], trsuf[2 * i + 1]);
      trpref[i] = max(trsum[2 * i] + trpref[2 * i + 1], trpref[2 * i]);
      tr[i] = max(max(tr[2 * i], tr[2 * i + 1]), trsuf[2 * i] + trpref[2 * i + 1]);
    }
  }

  ll get(int _l, int _r) {
    lr = _l; rr = _r; 
    ll res, rsum, rsuf, rpref;
    _get(1, 0, off - 1, res, rsum, rsuf, rpref);
    return res;
  }
};

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, m, c;
  while (scanf("%d%d%d", &n, &m, &c) >= 1) {
    vi xs(n), ps(n - 1);
    for (int i = 0; i < n; i++)
      scanf("%d", &xs[i]);
    for (int i = 0; i + 1 < n; i++)
      scanf("%d", &ps[i]);

    vector<ll> vals(n - 1);
    for (int i = 0; i + 1 < n; i++) {
      vals[i] = ll(xs[i + 1] - xs[i]) * 50 - ll(c) * ps[i];
//      eprintf("%I64d\n", vals[i]);
    }

    segm_tree tr(vals);
    ll ans = 0;
    for (int i = 0; i < m; i++) {
      int l, r;
      scanf("%d%d", &l, &r), l--, r -= 2;
      ans += tr.get(l, r);
    }
    printf("%.18lf\n", ans / 100.0);
    break;
  }
  return 0;
}