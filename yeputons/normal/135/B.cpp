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

struct pt {
  int x, y;
  pt() {}
  pt(int _x, int _y) : x(_x), y(_y) {}
  bool operator<(const pt &p2) const { return x != p2.x ? x < p2.x : y < p2. y; }
  pt operator-(const pt &p2) const { return pt(x - p2.x, y - p2.y); }
  int operator*(const pt &p2) const { return x * p2.x + y * p2.y; }
  int dist() const { return x * x + y * y; }
};

bool isrect(vector<pt> pts, bool sq = false) {
  sort(pts.begin(), pts.end());
  do {
    bool g = true;
    int len = -1;
    for (int i = 0; i < 4; i++) {
      int pr = (i + 3) % 4;
      int ne = (i + 1) % 4;
      int clen = (pts[ne] - pts[i]).dist();
      if (!clen) g = false;
      if (sq && len >= 0 && clen != len) g = false;
      len = clen;
      if ((pts[ne] - pts[i]) * (pts[pr] - pts[i])) g = false;
    }
    if (!g) continue;
    return true;
  } while (next_permutation(pts.begin(), pts.end()));
  return false;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  for (;;) {
    vector<pt> pts(8);
    bool cont = true;
    for (int i = 0; i < 8; i++)
      if (scanf("%d%d", &pts[i].x, &pts[i].y) < 2) {
        cont = false;
        break;
      }
    if (!cont) break;

    for (int a = 0; a < (1 << 8); a++) if (__builtin_popcount(a) == 4) {
      vector<pt> pt1, pt2;
      for (int i = 0; i < 8; i++) if (a & (1 << i)) pt1.pb(pts[i]); else pt2.pb(pts[i]);
      if (!isrect(pt1, true)) continue;
      if (!isrect(pt2)) continue;

      printf("YES\n");
      for (int i = 0; i < 8; i++)
        if (a & (1 << i)) printf("%d ", i + 1);
      printf("\n");
      for (int i = 0; i < 8; i++)
        if (!(a & (1 << i))) printf("%d ", i + 1);
      printf("\n");
      goto end;
    }
    printf("NO\n");
    end:;
  }
  return 0;
}