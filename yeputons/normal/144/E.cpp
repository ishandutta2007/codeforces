#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
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

struct pt {
  int x, y;
  int id;
  pt() : x(0), y(0) {}
  bool operator<(const pt &p2) const {
    if (y != p2.y) return y > p2.y;
    return x < p2.x;
  }
};

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, m;
  while (scanf("%d%d", &n, &m) >= 1) {
    vector<pt> pts(m);
    for (int i = 0; i < m; i++)
      scanf("%d%d", &pts[i].x, &pts[i].y), pts[i].x--, pts[i].y--, pts[i].id = i;

    sort(pts.begin(), pts.end());
    vi res;
    int ptr = 0;

    set<pair<pii, int> > xs;
    for (int y = n - 1; y >= 0; y--) {
      int x = n - 1 - y;
      while (ptr < sz(pts) && pts[ptr].y >= y)
        xs.insert(mp(mp(pts[ptr].x, -pts[ptr].y), ptr)), ptr++;

      set<pair<pii, int> >::iterator it = xs.lower_bound(mp(mp(x, -1e9), -1));
      if (it == xs.end()) continue;
      int i = it->second;
      xs.erase(it);
      res.pb(pts[i].id);
    }
    printf("%d\n", sz(res));
    for (int i = 0; i < sz(res); i++)
      printf("%d%c", res[i] + 1, "\n "[i + 1 < sz(res)]);
  }
  return 0;
}