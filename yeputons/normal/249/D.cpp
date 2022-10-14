#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
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

class fenv_tree {
  static int f(int x) { return x & -x; }
  vi tr;
  public:
  fenv_tree(int n) : tr(n + 1, 0) {}
  int get(int x) {
    int res = 0;
    for (x++; x > 0; x -= f(x)) res = max(res, tr[x]);
    return res;
  }
  void update(int x, int val) {
    for (x++; x < sz(tr); x += f(x)) tr[x] = max(tr[x], val);
  }
};

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  int va, vb, vc, vd;
  while (scanf("%d%d/%d%d/%d", &n, &va, &vb, &vc, &vd) >= 1) {
    vector<pair<ll, ll> > pts(n);
    for (int i = 0; i < n; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      pts[i].first = ll(x) * vc + ll(y) * -vd;
      pts[i].second = ll(x) * -va + ll(y) * vb;
    }

    vll ys(n);
    for (int i = 0; i < n; i++) ys[i] = pts[i].second;
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    for (int i = 0; i < n; i++)
      pts[i].second = -(lower_bound(ys.begin(), ys.end(), pts[i].second) - ys.begin());
    sort(pts.begin(), pts.end());
    for (int i = 0; i < n; i++)
      pts[i].second = -pts[i].second;

    fenv_tree tr(sz(ys));
    int ans = 0;
    for (int i = 0; i < sz(pts); i++) if (pts[i].first > 0 && ys[pts[i].second] > 0) {
      int cdyn = 1 + tr.get(pts[i].second - 1);
      ans = max(ans, cdyn);
      tr.update(pts[i].second, cdyn);
    }
    printf("%d\n", ans);
  }
  return 0;
}