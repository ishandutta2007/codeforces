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

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #else
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int h, w;
  while (scanf("%d%d", &h, &w) >= 1) {
    vvi as(h, vi(w));
    for (int y = 0; y < h; y++)
      for (int x = 0; x < w; x++)
        scanf("%d", &as[y][x]);

    vi cs(3);
    scanf("%d%d%d", &cs[0], &cs[1], &cs[2]);
    sort(cs.begin(), cs.end());

    int ans = 0;
    for (int step = 0; step < 2; step++) {
      for (int x1 = 1; x1 < w; x1++)
        for (int x2 = x1 + 1; x2 < w; x2++) {
          vi ccs(3);
          for (int x = 0; x < x1; x++)
            for (int y = 0; y < h; y++)
              ccs[0] += as[y][x];
          for (int x = x1; x < x2; x++)
            for (int y = 0; y < h; y++)
              ccs[1] += as[y][x];
          for (int x = x2; x < w; x++)
            for (int y = 0; y < h; y++)
              ccs[2] += as[y][x];
          sort(ccs.begin(), ccs.end());
          ans += ccs == cs;
        }

      // turn
      vvi nas(w, vi(h));
      for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
          nas[x][y] = as[y][x];
      nas.swap(as);
      swap(w, h);
    }
    printf("%d\n", ans);
  }
  return 0;
}