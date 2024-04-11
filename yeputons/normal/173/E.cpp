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

struct Sum {
  int operator()(int a, int b) { return a + b; }
};
struct Max {
  int operator()(int a, int b) { return max(a, b); }
};

template<typename Op> class segm_tree {
  vi tr;
  vi xs;
  int off;

  public:
  segm_tree(const vi &_xs) : xs(_xs) {
    off = 1; while (off < sz(xs)) off <<= 1;
    tr = vi(2 * off, 0);
  }
  void update(int x, int v) { 
    x = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    for (x += off; x >= 1; x >>= 1)
      tr[x] = Op()(tr[x], v);
  }
  int get(int l, int r) {
    l = lower_bound(xs.begin(), xs.end(), l) - xs.begin();
    r = upper_bound(xs.begin(), xs.end(), r) - xs.begin() - 1;
    l += off; r += off;

    int res = 0;
    while (l <= r) {
      if (l & 1) res = Op()(res, tr[l++]);
      if (!(r & 1)) res = Op()(res, tr[r--]);
      l >>= 1; r >>= 1;
    }
    return res;
  }
};

struct Man {
  int r, a, id;
  bool operator<(const Man &m2) const { return r < m2.r; }
};

struct Req {
  int l, r, minr, id;
  bool operator<(const Req &r) const { return minr > r.minr; }
};

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, k;
  while (scanf("%d%d", &n, &k) >= 1) {
    vector<Man> ms(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &ms[i].r);
    for (int i = 0; i < n; i++)
      scanf("%d", &ms[i].a), ms[i].id = i;
    sort(ms.begin(), ms.end());

    vi nid(n);
    for (int i = 0; i < n; i++)
      nid[ms[i].id] = i;

    vi ages(n);
    for (int i = 0; i < n; i++) ages[i] = ms[i].a;
    sort(ages.begin(), ages.end());
    ages.erase(unique(ages.begin(), ages.end()), ages.end());

    vi ansLead(n);
    {
      segm_tree<Sum> tr(ages);
      int ptr = 0;
      for (int i = 0; i < sz(ms); i++) {
        while (ptr < n && ms[ptr].r <= ms[i].r)
          tr.update(ms[ptr++].a, 1);

        ansLead[i] = tr.get(ms[i].a - k, ms[i].a + k);
      }
    }

    int q;
    scanf("%d", &q);

    vector<Req> rqs(q);
    for (int i = 0; i < q; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      x = nid[x - 1];
      y = nid[y - 1];

      rqs[i].l = max(ms[x].a, ms[y].a) - k;
      rqs[i].r = min(ms[x].a, ms[y].a) + k;
      rqs[i].minr = max(ms[x].r, ms[y].r);
      rqs[i].id = i;
    }
    sort(rqs.begin(), rqs.end());

    vi ans(q, -1);

    segm_tree<Max> tr(ages);
    int ptr = n - 1;
    for (int i = 0; i < q; i++) {
      while (ptr >= 0 && ms[ptr].r >= rqs[i].minr) {
        tr.update(ms[ptr].a, ansLead[ptr]);
        ptr--;
      }
      ans[rqs[i].id] = tr.get(rqs[i].l, rqs[i].r);
    }

    for (int i = 0; i < q; i++)
      printf("%d\n", ans[i] == 0 ? -1 : ans[i]);
  }
  return 0;
}