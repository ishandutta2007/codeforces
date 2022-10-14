#include <cstdio>
#include <cstdlib>
#include <cstdarg>
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

typedef long long ll;

typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

struct el {
  int x, h, id;
  el() { x = h = id = -1; }
  el(int _x) : x(_x), h(0), id(-1) {}
  bool operator<(const el &e2) const { return x < e2.x; }
};

class line_tree {
  vi tr;
  int off;

  public:
  line_tree(int sz) {
    off = 1; while (off < sz) off <<= 1;
    tr = vi(off << 1, 0);
  }

  void set(int i, int v) {
    assert(0 <= i && i < off);
    tr[i += off] = v;
    for (i >>= 1; i >= 1; i >>= 1)
      tr[i] = max(tr[i << 1], tr[(i << 1) + 1]);
  }
  int get(int l, int r) {
    if (l > r) return 0;
    assert(0 <= l && l <= r && r < off);
    l += off; r += off;
    int a = 0;
    while (l <= r) {
      if (l & 1) a = max(a, tr[l++]);
      if (!(r & 1)) a = max(a, tr[r--]);
      l >>= 1; r >>= 1;
    }
    return a;
  }
};

int main() {
  #ifdef DEBUG
  freopen("stdin.txt", "r", stdin);
  freopen("stdout.txt", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vector<el> as(n);
    for (int i = 0; i < n; i++) scanf("%d%d", &as[i].x, &as[i].h), as[i].id = i;
    sort(as.begin(), as.end());

    vi rs(n, -1);
    line_tree tr(n);

    for (int i = n - 1; i >= 0; i--) {
      int cans = i;
      int nx = as[i].x + as[i].h - 1;

      int lb = lower_bound(as.begin(), as.end(), el(nx)) - as.begin();
      if (lb >= as.size() || as[lb].x > nx) lb--;
      assert(as[lb].x <= nx);
      assert(lb + 1 >= as.size() || as[lb + 1].x > nx);
      cans = max(cans, tr.get(i + 1, lb));

//      eprintf("cans(%d)=%d (lb=%d)\n", i, cans, lb);
      tr.set(i, cans);
      rs[i] = cans;
    }

    vi ans(n, -1);
    for (int i = 0; i < n; i++)
      ans[as[i].id] = rs[i] - i + 1;

    for (int i = 0; i < n; i++)
      printf("%d%c", ans[i], "\n "[i + 1 < n]);

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}