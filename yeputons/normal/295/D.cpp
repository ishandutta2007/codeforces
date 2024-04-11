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

const int MOD = 1e9 + 7;
void madd(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
int mmul(int a, int b) { return ll(a) * b % MOD; }

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int maxh, maxw;
  while (scanf("%d%d", &maxh, &maxw) >= 1) {
    vvi goUp(maxh + 1, vi(maxw + 1, 0));
    vvi goUp2(maxh + 1, vi(maxw + 1, 0));

    for (int w = 2; w <= maxw; w++)
      goUp[1][w] = 1;
    for (int w = 2; w <= maxw; w++)
      goUp2[1][w] = 1;

    for (int h = 2; h <= maxh; h++) {
      int cs = 0, cs2 = 0;
      for (int oldw = 2; oldw <= maxw; oldw++) {
        madd(cs, goUp[h - 1][oldw]);
        madd(cs2, mmul(goUp[h - 1][oldw], MOD - oldw));
        madd(goUp[h][oldw], cs2);
        madd(goUp[h][oldw], mmul(cs, oldw + 1));
      }

      cs = 0;
      cs2 = 0;
      for (int cw = 2; cw <= maxw; cw++) {
        madd(goUp2[h][cw], cs2);
        madd(goUp2[h][cw], mmul(cs, cw + 1));

        madd(cs, goUp[h - 1][cw]);
        madd(cs2, mmul(goUp[h - 1][cw], MOD - cw));      
      }
    }

    int ans = 0;
    for (int w = 2; w <= maxw; w++) {
      vi css(maxh, 0);
      vi css2(maxh, 0);
      {
        int cs = 0, cs2 = 0;
        for (int h2 = 0; h2 < maxh; h2++) {
          madd(cs, goUp[h2 + 1][w]);
          css[h2] = cs;

          madd(cs2, mmul(goUp[h2 + 1][w], MOD - h2));
          css2[h2] = cs2;
        }
      }

      for (int h1 = 0; h1 < maxh; h1++) {
        int star = 0;
        if (h1 > 0) {
/*          for (int wpr = 2; wpr < w; wpr++) {
            madd(star, mmul(goUp[h1][wpr], w - wpr + 1));
          }
//          eprintf("%d %d; h1=%d, w=%d\n", star, goUp2[h1 + 1][w], h1, w);
          assert(star == goUp2[h1 + 1][w]);*/
          star = goUp2[h1 + 1][w];
        } else {
          star = 1;
        }

        int cans = 0;
        int maxh2 = maxh - h1 - 1;
/*        for (int h2 = 0; h2 <= maxh2; h2++) {
          int cans2 = 1;
          cans2 = mmul(cans2, goUp[h2 + 1][w]);
          cans2 = mmul(cans2, MOD - h2);
          madd(cans, cans2);
        }*/
//        assert(cans == css2[maxh2]);
        cans = css2[maxh2];
        madd(cans, mmul(maxh - h1, css[maxh2]));
        cans = mmul(cans, star);
        cans = mmul(cans, maxw - w + 1);
        madd(ans, cans);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}