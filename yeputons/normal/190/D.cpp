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
    tr = vi(2 * off, 0);
  }
  void add(int x, int v) {
    tr[x += off] += v;
    for (x >>= 1; x >= 1; x >>= 1)
      tr[x] = max(tr[2 * x], tr[2 * x + 1]);
  }
  int getMax() const { return tr[1]; }
};

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, k;
  while (scanf("%d%d", &n, &k) >= 1) {
    vi as(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i]);

    vi vals = as;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    for (int i = 0; i < n; i++)
      as[i] = lower_bound(vals.begin(), vals.end(), as[i]) - vals.begin();

    segm_tree tr(n);
    ll ans = 0;

    int r = 0;
    for (int l = 0; l < n; l++) {
      while (tr.getMax() < k && r < n) {
        tr.add(as[r++], 1);
      }
      if (tr.getMax() >= k)
        ans += n - r + 1;
      assert(l < r);
      tr.add(as[l], -1);
    }
    printf("%I64d\n", ans);
  }
  return 0;
}