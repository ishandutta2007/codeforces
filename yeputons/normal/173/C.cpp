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

const int INF = 1e9;

const int MAXH = 510;
const int MAXW = 510;

int f[MAXH][MAXW];
int sums[MAXH + 1][MAXW + 1];

int getSum(int x, int y, int k) {
  return sums[y + k][x + k] - sums[y][x + k] - sums[y + k][x] + sums[y][x];
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int h, w;
  while (scanf("%d%d", &h, &w) >= 1) {
    for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++)
      scanf("%d", &f[y][x]);

    memset(sums, 0, sizeof sums);
    for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++)
      sums[y + 1][x + 1] = sums[y + 1][x] + sums[y][x + 1] - sums[y][x] + f[y][x];

    int ans = -INF;
    vvi pd(h, vi(w));
    for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++)
      pd[y][x] = f[y][x];

    vvi cd(h, vi(w));

    for (int k = 3; k <= h && k <= w; k += 2) {
      for (int y = 0; y + k <= h; y++)
      for (int x = 0; x + k <= w; x++) {
        cd[y][x] = getSum(x, y, k);
        cd[y][x] -= pd[y + 1][x + 1];
        cd[y][x] -= f[y + 1][x];

        ans = max(ans, cd[y][x]);
      }
      pd.swap(cd);
    }
    printf("%d\n", ans);
  }
  return 0;
}