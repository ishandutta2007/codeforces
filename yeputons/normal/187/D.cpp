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
  vi tr;
  vi xs;

  int off;
  int xoff, mod;
  int init;

  int _get(int l, int r) {
    l = lower_bound(xs.begin(), xs.end(), l) - xs.begin() + off;
    r = upper_bound(xs.begin(), xs.end(), r) - xs.begin() - 1 + off;
    int res = init;
    while (l <= r) {
      if (l & 1) res = min(res, tr[l++]);
      if (!(r & 1)) res = min(res, tr[r--]);
      l >>= 1; r >>= 1;
    }
    return res;
  }

  public:
  segm_tree(int n, int _init, const vi &_xs) : xs(_xs), mod(n), init(_init) {
    off = 1; while (off < sz(xs)) off <<= 1;
    tr = vi(2 * off, init);
    xoff = 0;
  }
  void addToX(int diff) {
    diff %= mod;
    if (diff < 0) diff += mod;
    xoff += diff;
    if (xoff >= mod) xoff -= mod;
  }
  void relax(int x, int v) {
    x = (x + mod - xoff) % mod;
    assert(binary_search(xs.begin(), xs.end(), x));
    x = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    for (x += off; x >= 1; x >>= 1)
      tr[x] = min(tr[x], v);
  }
  int get(int l, int r) {
    l = (l + mod - xoff) % mod;
    r = (r + mod - xoff) % mod;
    if (l <= r) return _get(l, r);
    else return min(_get(l, mod - 1),_get(0, r));
  }
};

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, g, r;
  while (scanf("%d%d%d", &n, &g, &r) >= 1) {
    int l0;
    vi ls(n);
    scanf("%d", &l0);
    for (int i = 0; i < n; i++)
      scanf("%d", &ls[i]);

    int mod = g + r;

    vector<ll> saz(n + 1);
    saz[n] = 0;
    vector<ll> poses(n + 1);
    for (int i = 0; i < n; i++)
      poses[i + 1] = poses[i] + ls[i];

    vi xs;
    {
      int csum = 0;
      for (int i = n - 1;; i--) {
        xs.pb(csum);
        if (i < 0) break;
        csum -= ls[i];
        csum %= mod;
        if (csum < 0) csum += mod;
      }
      sort(xs.begin(), xs.end());
      xs.erase(unique(xs.begin(), xs.end()), xs.end());
    }

    segm_tree tr(mod, n, xs);
    tr.relax(0, n);
    for (int i = n - 1; i >= 0; i--) {
      tr.addToX(ls[i]);
      int ne = tr.get(g, g + r - 1);
      ll timTo = poses[ne] - poses[i];
      if (ne != n) {
        assert(timTo % mod >= g);
        timTo += mod - timTo % mod;
      }
      saz[i] = timTo + saz[ne];
      tr.relax(0, i);
    }

    int q;
    scanf("%d", &q);
    while (q --> 0) {
      ll t;
      scanf("%I64d", &t);
      t += l0;
      tr.addToX(t);

      int ne = tr.get(g, g + r - 1);
      ll timTo = t + poses[ne];
      if (ne != n) {
        assert(timTo % mod >= g);
        timTo += mod - timTo % mod;
      }
      printf("%I64d\n", timTo + saz[ne]);
      tr.addToX(-t);
    }
  }
  return 0;
}