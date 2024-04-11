#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

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

const int INF = 1e9;
class segm_tree {
  vi tr;
  int off;

  public:
  segm_tree(int n) {
    off = 1; while (off < n) off <<= 1;
    tr = vi(2 * off, INF);
  }
  void set(int x, int val) {
    tr[x += off] = val;
    for (x >>= 1; x >= 1; x >>= 1)
      tr[x] = min(tr[2 * x], tr[2 * x + 1]);
  }
  int get(int l, int r) {
    l += off; r += off;
    int res = INF;
    while (l <= r) {
      if (l & 1) res = min(res, tr[l++]);
      if (!(r & 1)) res = min(res, tr[r--]);
      l >>= 1; r >>= 1;
    }
    return res;
  }
};

class Magic {
  int n;
  segm_tree tr;

  public:
  Magic(int _n) : n(_n), tr(n) {
    for (int i = 0; i < n; i++)
      tr.set(i, i);
  }
  int insert(int v) {
    int v1 = tr.get(v, n - 1);
    if (v1 < INF) { tr.set(v1, INF); return v1; }

    int v2 = tr.get(0, v - 1);
    if (v2 < INF) { tr.set(v2, INF); return v2; }
    assert(false);
  }
  void erase(int v) {
    tr.set(v, v);
  }
};

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int h, m, n;
  while (scanf("%d%d%d", &h, &m, &n) >= 3) {
    vector<Magic> cycs;
    vvi clist;
    vi cid(h, -1), cpos(h, -1);

    for (int i = 0; i < h; i++) if (cid[i] < 0) {
      int ccid = sz(cycs);
      int curpos = 0;
      vi curlist;

      for (int i2 = i; cid[i2] < 0; curpos++) {
        curlist.pb(i2);
        cid[i2] = ccid;
        cpos[i2] = curpos;

        i2 += m; if (i2 >= h) i2 -= h;
      }
      cycs.pb(Magic(curpos));
      clist.pb(curlist);
    }

    ll ans = 0;
    map<int, int> poses;
    for (int step = 0; step < n; step++)  {
      char ty;
      int id;
      scanf(" %c%d", &ty, &id);
      if (ty == '+') {
        int hash;
        scanf("%d", &hash);

        int opos = cpos[hash];
        int npos = cycs[cid[hash]].insert(opos);

        if (opos <= npos) ans += npos - opos;
        else ans += npos + sz(clist[cid[hash]]) - opos;

        poses[id] = clist[cid[hash]][npos];
      } else {
        int pos = poses[id];
        cycs[cid[pos]].erase(cpos[pos]);
      }
    }
    printf("%I64d\n", ans);
  }                                       
  return 0;
}