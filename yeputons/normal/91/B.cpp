#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdarg>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())

typedef long long ll;
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
    tr = vi(off << 1, -1);
  }

  void set(int v, int x) {
    tr[v += off] = x;
    for (v >>= 1; v >= 1; v >>= 1)
      tr[v] = max(tr[v * 2], tr[v * 2 + 1]);
  }
  int get(int l, int r) {
    l += off, r += off;

    int res = -1;
    while (l <= r) {
      if (l & 1) res = max(res, tr[l++]);
      if (!(r & 1)) res = max(res, tr[r--]);
      l >>= 1, r >>= 1;
    }
    return res;
  }
};

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vi as(n);
    vector<pii> ord(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i]), ord[i] = mp(as[i], i);

    segm_tree tr(n);
    sort(ord.begin(), ord.end());

    vi ans(n, -2);
    for (int i = 0; i < n; i++) {
      int pos = ord[i].second;

      int maxr = tr.get(pos, n - 1);
      if (maxr >= 0) ans[pos] = maxr - pos - 1;
      else ans[pos] = -1;

      tr.set(pos, pos);
    }
    for (int i = 0; i < n; i++)
      printf("%d%c", ans[i], "\n "[i + 1 < n]);
    
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}