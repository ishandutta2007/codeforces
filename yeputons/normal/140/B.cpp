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

#define INF 1e9

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vvi ls(n + 1, vi(n, -1));
    for (int i = 0; i <= n; i++) {
      vi cur(n);
      for (int i2 = 0; i2 < n; i2++)
        scanf("%d", &cur[i2]), cur[i2]--;

      for (int i2 = 0; i2 < n; i2++)
        ls[i][cur[i2]] = i2;
    }

    vi ans(n, -1);
    for (int i = 0; i < n; i++) {
      int bans = INF, bi = -1;

      int curv = INF, curi = -1;
      for (int i2 = 0; i2 < n; i2++) if (i2 != i) {
        if (ls[n][i2] < curv) {
          curv = ls[n][i2];
          curi = i2;
        }
        assert(curi >= 0);
        if (ls[i][curi] < bans) {
          bans = ls[i][curi];
          bi = i2;
        }
      }
      ans[i] = bi;
    }

    for (int i = 0; i < n; i++)
      printf("%d%c", ans[i] + 1, "\n "[i + 1 < n]);
  }
  return 0;
}