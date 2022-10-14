#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
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

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vector<vvi> bs(n);
    int scnt = 0;
    for (int i = 0; i < n; i++) {
      int k, a, x, y, m;
      scanf("%d%d%d%d%d", &k, &a, &x, &y, &m);

      vi cs(k);
      for (int i2 = 0; i2 < k; i2++) {
        cs[i2] = a;
        a = (ll(a) * x + y) % m;
      }
      vi cur;
      int pr = -1;
      for (int i2 = 0; i2 <= k; i2++) {
        if (i2 >= k || pr > cs[i2]) {
          bs[i].pb(cur);
          cur.clear();
        }
        if (i2 < k) {
          cur.pb(cs[i2]);
          pr = cs[i2];
        }
      }
      scnt += k;
    }
    bool needOut = scnt <= 200000;

    int ans = 0;
    vector<pii> ord;
    vi ptrs(n, 0);

    for (int bptr = 0;; bptr++) {
      priority_queue<pii> cps;
      for (int i = 0; i < n; i++)
        if (sz(bs[i]) > bptr) {
          ptrs[i] = 0;
          cps.push(mp(-bs[i][bptr][ptrs[i]], i));
        }
      if (cps.empty()) break;

      while (!cps.empty()) {
        pii cur = cps.top(); cps.pop();
        int i = cur.second;
        int i2 = ++ptrs[i];
        if (needOut) {
          ord.pb(mp(bs[i][bptr][i2 - 1], i));
        }
        if (i2 < sz(bs[i][bptr])) {
          cps.push(mp(-bs[i][bptr][i2], i));
        }
      }
      if (bptr > 0) ans++;
    }

    printf("%d\n", ans);
    if (needOut) {
      for (int i = 0; i < sz(ord); i++)
        printf("%d %d\n", ord[i].first, ord[i].second + 1);
    }
  }
  return 0;
}