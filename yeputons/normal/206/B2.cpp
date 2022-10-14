#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
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

class segm_tree {
  vector<pii> tr;
  int off;

  public:
  segm_tree(const vi &as) {
    off = 1; while (off < sz(as)) off <<= 1;
    tr = vector<pii>(2 * off, mp(-1, -1));
    for (int i = 0; i < sz(as); i++)
      tr[off + i] = mp(as[i], i);
    for (int i = off - 1; i >= 1; i--)
      tr[i] = max(tr[2 * i], tr[2 * i + 1]);
  }
  pii get(int l, int r) {
    l += off; r += off;
    pii res(-1, -1);
    while (l <= r) {
      if (l & 1) res = max(res, tr[l++]);
      if (!(r & 1)) res = max(res, tr[r--]);
      l >>= 1; r >>= 1;
    }
    return res;
  }
};

const int K = 18;
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vi as(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i]);
    reverse(as.begin(), as.end());

    for (int i = 0; i < n; i++)
      as.pb(as[i]);

    vi maxr(sz(as));
    for (int i = 0; i < sz(as); i++)
      maxr[i] = min(i + as[i], sz(as) - 1);
    segm_tree tr(maxr);

    vector<vector<pii> > ne(sz(as), vector<pii>(K, mp(-1, -1)));
    for (int i = sz(as) - 1; i >= 0; i--) {
      ne[i][0] = mp(i + 1 == sz(as) ? i : tr.get(i + 1, maxr[i]).second, i);
      for (int i2 = 1; i2 < K; i2++)
        ne[i][i2] = ne[ne[i][i2 - 1].first][i2 - 1];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      int clen = 0, goal = n + i - 1;
      pii cv(i, -1);

      for (int i2 = K - 1; i2 >= 0; i2--)
        if (ne[cv.first][i2].first < goal) {
          cv = ne[cv.first][i2];
          assert(cv.second >= 0);
          clen += 1 << i2;
        }
      assert(cv.first < goal);
      assert(ne[cv.first][0].first >= goal);

      if (cv.second >= 0 && maxr[cv.second] >= goal) {
      } else {
        clen++;
      }
      ans += clen;
    }
    printf("%I64d\n", ans);
//    break;
  }
  return 0;
}