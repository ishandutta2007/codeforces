#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
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

const int INF = 2e9 + 100;

struct Panel {
  int x1, x2, y;
  bool operator<(const Panel &p2) const { return y < p2.y; }
};

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d%*d", &n) >= 1) {
    vector<Panel> ps(n);
    for (int i = 0; i < n; i++) {
      scanf("%d%d%d", &ps[i].y, &ps[i].x1, &ps[i].x2);
    }
    sort(ps.begin(), ps.end());

    vi canses(n, -1);
    set<pii> gs;
    gs.insert(mp(-1e9 - 10, -1));
    gs.insert(mp(1e9 + 10, -1));
    for (int i = 0; i < sz(ps); i++) {
      int cans = -INF;

      set<pii>::iterator it = gs.upper_bound(mp(ps[i].x1, -2));
      assert(it != gs.end());

      if (it != gs.begin()) it--;
      pii las = *it;
      while (it != gs.end() && it->first < ps[i].x2) {
        set<pii>::iterator nit = it;
        nit++;
        if (nit == gs.end()) break;

        las = *it;
        if (it->second >= 0) {
          int b = it->second;
          int l = max(ps[i].x1, it->first);
          int r = min(ps[i].x2, nit->first);

          if ((l == ps[i].x1 || l == ps[b].x1) && 
              (r == ps[i].x2 || r == ps[b].x2)) {
            cans = max(cans, min(r - l, canses[b]));
          }
        }
        it = nit;
      }

      it = gs.lower_bound(mp(ps[i].x1, -2));
      while (it != gs.end() && it->first < ps[i].x2) {
        set<pii>::iterator nit = it;
        nit++;

        gs.erase(it);
        it = nit;
      }
      if (cans < 0)
        cans = ps[i].x2 - ps[i].x1;
      gs.insert(mp(ps[i].x1, i));

      it = gs.lower_bound(mp(ps[i].x2, -2));
      if (it == gs.end() || it->first > ps[i].x2) {
        gs.insert(mp(ps[i].x2, las.second));
      }
//      eprintf("  cans=%d\n", cans);
      canses[i] = cans;

/*      #ifdef DEBUG
      eprintf("i=%d (%d..%d; %d)\n", i, ps[i].x1, ps[i].x2, ps[i].y);
      for (set<pii>::iterator it = gs.begin(); it != gs.end(); it++)
        eprintf("  %d %d\n", it->first, it->second);
      #endif*/
    }

    int ans = 0;
    for (set<pii>::iterator it = gs.begin(); it != gs.end(); it++) {
      if (it->second >= 0) {
        set<pii>::iterator nit = it; nit++;
        if (it->first == ps[it->second].x1 &&
            nit->first == ps[it->second].x2) {
          ans = max(ans, min(nit->first - it->first, canses[it->second]));
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}