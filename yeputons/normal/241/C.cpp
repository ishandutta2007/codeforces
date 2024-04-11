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

const int W = 1e5;
const int H = 100;

struct Mirror {
  char t;
  int x1, x2, score;
};
const double EPS = 1e-9;

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  double yst, yen; int n;
  while (scanf("%lf%lf%d", &yst, &yen, &n) >= 1) {
    vector<Mirror> ms(n);
    for (int i = 0; i < n; i++) {
      scanf(" %d %c%d%d", &ms[i].score, &ms[i].t, &ms[i].x1, &ms[i].x2);
    }

    int ans = 0;
    for (int step = 0; step < 2; step++) {
      for (int rcnt = 0; rcnt <= n; rcnt++) {
        double vx = W;
        double vy = (rcnt % 2 == 0 ? yen : H - yen) + (H * rcnt) - yst;

        bool g = true;
        int cans = 0;
        int pr0 = -1, pr1 = -1;
        for (int lay = 0; lay < rcnt && g; lay++) {
          g = false;
          for (int i = 0; i < n; i++) if ((ms[i].t == 'F') == (lay % 2)) {
            double cx = ((1 + lay) * H - yst) * vx / vy;
            if (ms[i].x1 - EPS <= cx && cx <= ms[i].x2 + EPS) {
              if (lay % 2) g = i != pr1, pr1 = i;
              else g = i != pr0, pr0 = i;
              cans += ms[i].score;
              break;
            }
          }
        }
        if (g) ans = max(ans, cans);
      }

      for (int i = 0; i < n; i++)
        if (ms[i].t == 'F') ms[i].t = 'T';
        else ms[i].t = 'F';
      yst = H - yst;
      yen = H - yen;
    }
    printf("%d\n", ans);
  }
  return 0;
}