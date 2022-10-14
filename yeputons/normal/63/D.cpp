#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif
  
  int a, b, c, d, n;
  while (scanf("%d%d%d%d%d", &a, &b, &c, &d, &n) >= 5) {
    int w = a + c;
    int h = max(b, d);
    vvb good(h, vb(w, false));
    for (int y = 0; y < b; y++)
      for (int x = 0; x < a; x++)
        good[y][x] = true;
    for (int y = 0; y < d; y++)
      for (int x = 0; x < c; x++)
        good[y][a + x] = true;

    vector<pii> ord;
    {
      bool typ = (b >= d) == (min(b, d) % 2 == 0);
      int x = typ ? 0 : w - 1, y = 0;
      int d = typ ? 1 : -1;
      for (;;) {
        assert(good[y][x]);
        ord.pb(mp(x, y));
        if (x + d >= w || x + d < 0 || !good[y][x + d]) {
          y++;
          d = -d;
        } else
          x += d;
        if (y >= h) break;
      }
    }

    vi sz(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &sz[i]);

    try {
      vector<string> res(h, string(w, '.'));
      int p = 0;
      for (int i = 0; i < n; i++) {
        for (int i2 = 0; i2 < sz[i]; i2++, p++)
          res[ord[p].second][ord[p].first] = 'a' + i;
      }

      printf("YES\n");
      for (int y = 0; y < h; y++)
        printf("%s\n", res[y].c_str());
    } catch (...) {
      printf("NO\n");
    }

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}