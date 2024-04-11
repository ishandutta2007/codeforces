#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
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

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #else
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int m, k;
  while (scanf("%d%d", &m, &k) >= 1) {
    vb good(m, false);
    for (int i = 0; i < k; i++) {
      int x;
      scanf("%d", &x), x--;
      good[x] = true;
    }

    int n;
    scanf("%d", &n);
    vi mic(n, 0), mac(n, 0);

    for (int i = 0; i < n; i++) {
      scanf("%*s%d", &k);

      vb rem(m, true);
      int ucnt = 0;
      for (int i2 = 0; i2 < k; i2++) {
        int x;
        scanf("%d", &x), x--;
        if (x < 0) ucnt++;
        else {
          rem[x] = false;
          if (good[x]) {
            mic[i]++;
            mac[i]++;
          }
        }
      }

      int gcnt = 0, bcnt = 0;
      for (int i2 = 0; i2 < m; i2++)
        if (rem[i2]) {
          if (good[i2]) gcnt++;
          else bcnt++;
        }
      assert(gcnt + bcnt >= ucnt);

      mic[i] += min(ucnt, max(0, ucnt - bcnt));
      mac[i] += min(ucnt, gcnt);
      assert(mic[i] <= mac[i]);
    }

    for (int i = 0; i < n; i++) {
      bool canGood = true, canBad = false;
      for (int i2 = 0; i2 < n; i2++) if (i != i2) {
        bool cg = false, cb = false;

        for (int c1 = mic[i]; c1 <= mac[i]; c1++) {
          for (int c2 = mic[i2];; c2 += mac[i2] - mic[i2]) {
            if (c1 >= c2) cg = true;
            else cb = true;

            if (c2 == mac[i2]) break;
          }
        }
        canGood = canGood && cg;
        canBad = canBad || cb;
      }
      assert(canGood || canBad);
      if (canGood && canBad) printf("2\n");
      else printf("%d\n", canGood ? 0 : 1);
    }
    #ifdef DEBUG
    printf("\n");
    #endif
  }
  return 0;
}