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

const int INF = 1e9 + 1000;
class fenv_tree {
  vi tr;
  static int f(int x) { return x ^ (x & (x - 1)); }

  public:
  fenv_tree(int n) : tr(n + 1, -INF) {}
  void relax(int x, int v) {
    for (x++; x > 0; x -= f(x))
      tr[x] = max(tr[x], v);
  }
  int get(int x) {
    int res = -INF;
    for (x++; x < sz(tr); x += f(x))
      res = max(res, tr[x]);
    return res;
  }
};

struct pt {
  int x, y, val;
  bool operator<(const pt &p2) const { return x != p2.x ? x > p2.x : y > p2.y; }
};

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vector<pt> pts(n);
    vi ys;
    for (int i = 0; i < n; i++)
      scanf("%d", &pts[i].x);
    for (int i = 0; i < n; i++) {
      scanf("%d", &pts[i].y);
      ys.pb(pts[i].y);
    }
    for (int i = 0; i < n; i++)
      scanf("%d", &pts[i].val);
    sort(ys.begin(), ys.end());
    ys.resize(unique(ys.begin(), ys.end()) - ys.begin());
    for (int i = 0; i < n; i++)
      pts[i].y = lower_bound(ys.begin(), ys.end(), pts[i].y) - ys.begin();

    fenv_tree tr(sz(ys));
    sort(pts.begin(), pts.end());
    int ans = 0;
    for (int st = 0; st < sz(pts);) {
      int en = st;
      while (en < sz(pts) && pts[st].x == pts[en].x) en++;

      for (int i = st; i < en; i++) {
        int mz = tr.get(pts[i].y + 1);
        if (mz > pts[i].val) ans++;
      }
      for (int i = st; i < en; i++)
        tr.relax(pts[i].y, pts[i].val);
      st = en;
    }
    printf("%d\n", ans);
  }
  return 0;
}