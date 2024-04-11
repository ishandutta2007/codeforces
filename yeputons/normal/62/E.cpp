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

const ll INFLL = 1e18;

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int h, w;
  while (scanf("%d%d", &h, &w) >= 1) {
    vvi hos(w, vi(h, 0));
    for (int x = 1; x < w; x++)
      for (int y = 0; y < h; y++)
        scanf("%d", &hos[x][y]);
    vvi ver(w, vi(h));
    for (int x = 0; x < w; x++)
      for (int y = 0; y < h; y++)
        scanf("%d", &ver[x][y]);

    vi y2(h, 0);
    for (int i = 0; i < h; i++)
      y2[i] = (i + 1) % h;

    vector<ll> pd(1 << h, INFLL), cd(1 << h, INFLL);
    vector<ll> csum(1 << h, 0), dsum(1 << h, 0);

    pd[0] = 0;
    for (int x = 1; x < w; x++) {
      for (int cm = 0; cm < (1 << h); cm++) {
        csum[cm] = 0;
        dsum[cm] = 0;
        for (int y = 0; y < h; y++) {
          if (!!(cm & (1 << y)) != !!(cm & (1 << y2[y])))
            csum[cm] += ver[x][y];
          if (cm & (1 << y))
            dsum[cm] += hos[x][y];
        }
      }

      for (int cm = 0; cm < (1 << h); cm++) {
        cd[cm] = INFLL;
        for (int pm = 0; pm < (1 << h); pm++)
          cd[cm] = min(cd[cm], pd[pm] + csum[cm] + dsum[cm ^ pm]);
      }
      pd.swap(cd);
    }

    printf("%I64d\n", pd[(1 << h) - 1]);
  }
  return 0;
}