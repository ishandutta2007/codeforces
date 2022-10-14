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
  int off;

  public:
  segm_tree(int n) {
    off = 1; while (off < n) off <<= 1;
    tr = vi(2 * off, -1);
  }
  void set(int x, int v) {
    tr[x += off] = v;
    for (x >>= 1; x >= 1; x >>= 1)
      tr[x] = max(tr[2 * x], tr[2 * x + 1]);
  }
  int get(int l, int r) {
    l = max(l, 0) + off;
    r = min(r, off - 1) + off;

    int res = -1;
    while (l <= r) {
      if (l & 1) res = max(res, tr[l++]);
      if (!(r & 1)) res = max(res, tr[r--]);
      l >>= 1; r >>= 1;
    }
    return res;
  }
  int getMax() const { return tr[1]; }
};

segm_tree was(0);
int n;
vvi nes;

vi cur;

void dfs(int v) {
  was.set(v, -1);
  cur.pb(v);

  int pr = -1;
  for (int i = 0; i < sz(nes[v]); i++) {
    int cur = nes[v][i];
    for (;;) {
      int b = was.get(pr + 1, cur - 1);
      if (b < 0) break;
      dfs(b);
    }
    pr = cur;
  }
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int m;
  while (scanf("%d%d", &n, &m) >= 1) {
    nes = vvi(n);
    for (int i = 0; i < n; i++) {
      nes[i].pb(n);
    }
    for (int i = 0; i < m; i++)  {
      int a, b;
      scanf("%d%d", &a, &b), a--, b--;
      nes[a].pb(b);
      nes[b].pb(a);
    }

    for (int i = 0; i < n; i++)
      sort(nes[i].begin(), nes[i].end());

    was = segm_tree(n);
    for (int i = 0; i < n; i++)
      was.set(i, i);

    vvi out;
    for (int i = 0; i < n; i++) if (was.get(i, i) == i) {
      cur.clear();
      dfs(i);
      out.pb(cur);
    }
    printf("%d\n", sz(out));
    for (int i = 0; i < sz(out); i++) {
      sort(out[i].begin(), out[i].end());
      printf("%d", sz(out[i]));
      for (int i2 = 0; i2 < sz(out[i]); i2++)
        printf(" %d", out[i][i2] + 1);
      printf("\n");
    }
  }
  return 0;
}