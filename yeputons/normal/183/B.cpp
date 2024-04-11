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

int sgn(ll x) { return x < 0 ? -1 : !!x; }
struct pt {
  int x, y;
  pt(int _x = 0, int _y = 0) : x(_x), y(_y) {}
  pt operator-(const pt &p2) const { return pt(x - p2.x, y - p2.y); }
  int operator*(const pt &p2) const { return sgn(ll(x) * p2.y - ll(y) * p2.x); }
};

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int maxx, n;
  while (scanf("%d%d", &maxx, &n) >= 1) {
    vector<pt> pts(n);
    for (int i = 0; i < n; i++)
      scanf("%d%d", &pts[i].x, &pts[i].y);

    vi res(maxx + 1, 1);
    for (int a = 0; a < n; a++)
    for (int b = a + 1; b < n; b++) if (pts[a].y != pts[b].y) {
      int vx = pts[b].x - pts[a].x;
      int vy = pts[b].y - pts[a].y;

      ll tres = ll(pts[a].y) * vx;
      if (tres % vy != 0) continue;
      ll cx = pts[a].x - tres / vy;
      if (cx < 1 || cx > maxx) continue;

      assert((pts[b] - pts[a]) * (pt(cx, 0) - pts[a]) == 0);

      int cnt = 0;
      for (int c = 0; c < n; c++)
        if ((pts[c] - pts[a]) * (pts[b] - pts[a]) == 0)
          cnt++;
      res[cx] = max(res[cx], cnt);
    }

    int ans = 0;
    for (int i = 1; i <= maxx; i++) {
      ans += res[i];
//      eprintf("res[%d]=%d\n", i, res[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}