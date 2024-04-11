#include <cstdio>
#include <cstdlib>
#include <cstring>
//#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
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

const int INF = 2e9 + 1e3;
class segm_tree {
  vector<pii> tr;
  int off;

  public:
  segm_tree(int n) {
    off = 1; while (off < n) off <<= 1;
    tr = vector<pii>(2 * off, mp(INF, -1));
  }
  void set(int x, int v) {
    x += off;
    tr[x] = mp(v, x - off);
    for (x >>= 1; x >= 1; x >>= 1)
      tr[x] = min(tr[2 * x], tr[2 * x + 1]);
  }
  pii get(int l, int r) {
    l += off; r += off;
    pii res(INF, -1);
    while (l <= r) {
      if (l & 1) res = min(res, tr[l++]);
      if (!(r & 1)) res = min(res, tr[r--]);
      l >>= 1; r >>= 1;
    }
    return res;
  }
};

struct Obj {
  ll d, r;
  int m, p;
  bool operator<(const Obj &o2) const { return d < o2.d; }
};

int x0, y0;
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int x0, y0;
  while (scanf("%d%d", &x0, &y0) >= 1) {
    vector<Obj> os(1);
    scanf("%d%I64d", &os[0].p, &os[0].r), os[0].m = 0, os[0].d = 0;
    os[0].r *= os[0].r;

    int n;
    scanf("%d", &n), n++;
    os.resize(n);
    for (int i = 1; i < n; i++) {
      int x, y;
      scanf("%d%d%d%d%I64d", &x, &y, &os[i].m, &os[i].p, &os[i].r);
      os[i].r *= os[i].r;
      os[i].d = ll(x - x0) * ll(x - x0) + ll(y - y0) * ll(y - y0);
    }
    sort(os.begin(), os.end());

    segm_tree has(n);
    for (int i = 1; i < n; i++)
      has.set(i, os[i].m);

    deque<int> q;
    q.pb(0);
    int ans = 0;
    while (!q.empty()) {
      int v = q.front();
      ans++;
      q.pop_front();

      Obj cobj = os[v];
      cobj.d = cobj.r;
      int maxr = upper_bound(os.begin(), os.end(), cobj) - os.begin() - 1;

      for (;;) {
        pii cur = has.get(0, maxr);
        if (cur.first > os[v].p) break;
        has.set(cur.second, INF);
        q.pb(cur.second);
      }
    }
    printf("%d\n", ans - 1);
  }
  return 0;
}