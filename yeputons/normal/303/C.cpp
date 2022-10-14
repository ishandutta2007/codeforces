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

const int MAXV = 1e6 + 10;
const int MAXK = 4;
struct TA {
  int cnt;
  int vs[2 * MAXK + 1];
} all[MAXV + 1];

int k;
void add(int v, int x) {
  if (all[v].cnt > 2 * k) return;
  if (find(all[v].vs, all[v].vs + all[v].cnt, x) != all[v].vs + all[v].cnt) return;
  all[v].vs[all[v].cnt++] = x;
}

int lasp[MAXV + 1];

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  memset(lasp, -1, sizeof lasp);
  {
    vi ps;
    for (int d = 2; d <= MAXV; d++) {
      if (lasp[d] < 0)
        ps.pb(d), lasp[d] = d;
      for (int i = 0; i < sz(ps) && ps[i] <= lasp[d]; i++) {
        ll nv = ll(d) * ps[i];
        if (nv <= MAXV) {
          assert(lasp[nv] < 0);
          lasp[nv] = ps[i];
        } else
          break;
      }
    }
  }

  eprintf("bb %d\n", clock());
  int n;
  while (scanf("%d%d", &n, &k) >= 1) {
    vi as(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i]);
    sort(as.begin(), as.end());

    for (int i = 0; i <= MAXV; i++)
      all[i].cnt = 0;

    for (int a = 0; a < n; a++) {
      for (int b = a + 1; b < n; b++) {
        int d = abs(as[a] - as[b]);
        add(d, a);
        add(d, b);
      }
    }
    eprintf("bb1 %d\n", clock());
    for (int i = MAXV; i >= 1; i--) {
      int x = i;
      while (lasp[x] >= 0) {
        int curp = lasp[x];
        x /= lasp[x];
        int ne = i / curp;

        for (int i3 = 0; i3 < all[i].cnt; i3++)
          add(ne, all[i].vs[i3]);
      }
      assert(x == 1);
    }
    eprintf("bb2 %d\n", clock());

    vi vals;
    for (int mod = 1;; mod++) {
      if (all[mod].cnt > 2 * k) continue;

      vals.clear();
      for (int i = 0; i < all[mod].cnt; i++)
        vals.pb(as[all[mod].vs[i]] % mod);

      int c1 = sz(vals);
      sort(vals.begin(), vals.end());
      vals.erase(unique(vals.begin(), vals.end()), vals.end());

      int c2 = sz(vals);
      int deled = c1 - c2;
      if (deled <= k) {
        printf("%d\n", mod);
        goto end;
      }
    }
    end:;
  }
  return 0;
}