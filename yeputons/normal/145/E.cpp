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
  vi tra, trb, tr0, tr1;
  vi trrev;
  int off;

  void norm(int v) {
    if (!trrev[v]) return;
    swap(tra[v], trb[v]);
    swap(tr0[v], tr1[v]);
    if (v < off) {
      trrev[2 * v] ^= 1;
      trrev[2 * v + 1] ^= 1;
    }
    trrev[v] = false;
  }

  int lr, rr;
  void _rev(int v, int lt, int rt) {
    if (rt < lr || rr < lt) return;
    if (lr <= lt && rt <= rr) {
      trrev[v] ^= 1;
      return;
    }
    norm(v);
    int mt = (lt + rt) / 2;
    _rev(2 * v, lt, mt); norm(2 * v);
    _rev(2 * v + 1, mt + 1, rt); norm(2 * v + 1);

    tr0[v] = tr0[2 * v] + tr0[2 * v + 1];
    tr1[v] = tr1[2 * v] + tr1[2 * v + 1];
    tra[v] = max(tra[2 * v] + tr1[2 * v + 1], tr0[2 * v] + tra[2 * v + 1]);
    trb[v] = max(trb[2 * v] + tr0[2 * v + 1], tr1[2 * v] + trb[2 * v + 1]);
  }

  public:
  segm_tree(int n) {
    off = 1; while (off < n) off <<= 1;
    tr0 = vi(2 * off, 0);
    tr1 = vi(2 * off, 0);
    trrev = vi(2 * off, 0);
    for (int i = 0; i < n; i++)
      tr0[off + i] = 1;
    for (int i = off - 1; i >= 1; i--)
      tr0[i] = tr0[2 * i] + tr0[2 * i + 1];
    tra = trb = tr0;
  }

  void rev(int _l, int _r) {
    lr = _l; rr = _r;
    _rev(1, 0, off - 1);
  }
  int get() { norm(1); return tra[1]; }
};

const int MAXL = 1e6;
char s[MAXL + 1];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, m;
  while (scanf("%d%d%s", &n, &m, s) >= 1) {
    segm_tree tr(n);
    for (int i = 0; i < n; i++)
      if (s[i] == '7') tr.rev(i, i);

    for (int i = 0; i < m; i++) {
      scanf("%s", s);
      if (!strcmp(s, "count")) {
        printf("%d\n", tr.get());
      } else {
        int l, r;
        scanf("%d%d", &l, &r), l--, r--;
        tr.rev(l, r);
      }
    }
  }
  return 0;
}