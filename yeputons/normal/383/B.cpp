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
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

bool cmp2(const pii &a, const pii &b) {
  return a.second == b.second ? a.first < b.first : a.second < b.second;
}

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int h, m;
  while (scanf("%d%d", &h, &m) >= 1) {
    int w = h;

    vector<pii> pts(m);
    for (int i = 0; i < m; i++)
      scanf("%d%d", &pts[i].first, &pts[i].second);
    sort(pts.begin(), pts.end(), cmp2);

    vi ys;
    ys.pb(1);
    ys.pb(2);
    ys.pb(h - 1);
    ys.pb(h);
    for (int i = 0; i < m; i++)
    for (int k = -1; k <= 1; k++)
      ys.pb(pts[i].second + k);
    {
      int ptr = 0;
      for (int i = 0; i < sz(ys); i++)
        if (1 <= ys[i] && ys[i] <= h)
          ys[ptr++] = ys[i];
      ys.resize(ptr);
    }
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    assert(sz(ys) >= 1);
    assert(ys[0] == 1);
    assert(ys.back() == h);

    set<pii> cur;
    cur.insert(mp(1, 1));

    int pptr = 0;
    for (int cyid = 0; cyid < sz(ys); cyid++) {
      int cy = ys[cyid];
//      eprintf("y=%d\n", cy);
      vi curs;
      while (pptr < m && pts[pptr].second == cy) {
        curs.pb(pts[pptr++].first);
      }
      curs.pb(w + 1);

      int bord = 0;
      for (int i = 0; i < sz(curs); i++) {
        int minx = curs[i];
//        eprintf("  process %d\n", minx);
        for (;;) {
          set<pii>::iterator it = cur.lower_bound(mp(bord + 1, -1));
          if (it == cur.end()) break;
          if (it->first > curs[i]) break;
          minx = min(minx, it->first);
//          eprintf("    remove %d..%d\n", it->first, it->second);
          if (it->second > curs[i]) {
//            eprintf("      add %d..%d\n", curs[i] + 1, it->second);
            cur.insert(mp(curs[i] + 1, it->second));
          }
          cur.erase(it);
        }
        assert(minx > bord);
        if (minx < curs[i]) {
//          eprintf("    new %d..%d\n", minx, curs[i] - 1);
          cur.insert(mp(minx, curs[i] - 1));
        }
        bord = minx;
      }
      assert(sz(cur) <= sz(curs) + 3);

/*      eprintf("  nya:\n");
      for (set<pii>::iterator it = cur.begin(); it != cur.end(); it++)
        eprintf("    %d..%d\n", it->first, it->second);*/
    }

    if (!cur.empty() && cur.rbegin()->second >= w)
      printf("%d\n", h + w - 2);
    else
      printf("-1\n");
  }
  return 0;
}