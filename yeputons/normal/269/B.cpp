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

const int INF = 1e9;

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, m;
  while (scanf("%d%d", &n, &m) >= 1) {
    vi tys(n);
    for (int i = 0; i < n; i++)
      scanf("%d%*f", &tys[i]), tys[i]--;

    vvi dyn(n + 1, vi(m, INF));
    dyn[0][0] = 0;

    for (int i = 0; i <= n; i++)
    for (int cty = 0; cty < m; cty++) if (dyn[i][cty] < INF) {
      if (cty + 1 < m) {
        dyn[i][cty + 1] = min(dyn[i][cty + 1], dyn[i][cty]);
      }
      if (i < n) {
        dyn[i + 1][cty] = min(dyn[i + 1][cty], dyn[i][cty] + (tys[i] != cty));
      }
    }
    printf("%d\n", dyn[n][m - 1]);
  }
  return 0;
}