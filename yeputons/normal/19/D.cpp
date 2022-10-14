#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
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

const int INF = 1e9 + 1000;
class segm_tree {
  vi tr;
  int off;

  int lr, rr, minv;
  int _upper_bound(int v, int lt, int rt) {
    if (rt < lr || rr < lt) return INF;
    if (tr[v] <= minv) return INF;
    if (v >= off) return v - off;

    int mt = (lt + rt) / 2;
    int res = _upper_bound(2 * v, lt, mt);
    if (res < INF) return res;
    return _upper_bound(2 * v + 1, mt + 1, rt);
  }

  public:
  segm_tree(int n) {
    off = 1; while (off < n) off <<= 1;
    tr = vi(2 * off, -INF);
  }
  void set(int x, int v) {
    tr[x += off] = v;
    for (x >>= 1; x >= 1; x >>= 1)
      tr[x] = max(tr[2 * x], tr[2 * x + 1]);
  }
  int upper_bound(int _lr, int _rr, int _minv) {
    lr = _lr;
    rr = _rr;
    minv = _minv;
    return _upper_bound(1, 0, off - 1);
  }
};

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vector<pair<int, pii> > rs(n);
    vi xs, ys;

    for (int i = 0; i < n; i++) {
      char op[16];
      scanf("%s%d%d", op, &rs[i].second.first, &rs[i].second.second);
      if (!strcmp(op, "add")) rs[i].first = 1;
      if (!strcmp(op, "remove")) rs[i].first = -1;
      if (!strcmp(op, "find")) rs[i].first = 0;
      xs.pb(rs[i].second.first);
    }
    sort(xs.begin(), xs.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());

    for (int i = 0; i < n; i++)
      rs[i].second.first = lower_bound(xs.begin(), xs.end(), rs[i].second.first) - xs.begin();

    vector<set<int> > cys(sz(xs));
    segm_tree tr(sz(xs));

    for (int i = 0; i < n; i++) {
      int x = rs[i].second.first;
      int y = rs[i].second.second;

      switch (rs[i].first) {
      case 1:
        cys[x].insert(y);
        tr.set(x, *cys[x].rbegin());
        break;
      case -1: 
        cys[x].erase(y);
        tr.set(x, cys[x].empty() ? -INF : *cys[x].rbegin());
        break;
      case 0:
        int rx = tr.upper_bound(x + 1, sz(xs) - 1, y);
        if (rx >= sz(xs))
          printf("-1\n");
        else
          printf("%d %d\n", xs[rx], *cys[rx].upper_bound(y));
        break;
      }
    }
    #ifdef DEBUG
    printf("\n");
    #endif
  }
  return 0;
}