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

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vvi g(n, vi(n));
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &g[i][j]);

    vi ord(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &ord[i]), ord[i]--;
    reverse(ord.begin(), ord.end());

    vector<ll> res(n);
    vb was(n, false);
    for (int _i = 0; _i < n; _i++) {
      int i = ord[_i];
      was[i] = true;

      for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        g[j][k] = min(g[j][k], g[j][i] + g[i][k]);

      for (int j = 0; j < n; j++) if (was[j])
      for (int k = 0; k < n; k++) if (was[k] && j != k)
        res[_i] += g[j][k];
    }
    reverse(res.begin(), res.end());
    for (int i = 0; i < sz(res); i++)
      printf("%I64d%c", res[i], "\n "[i + 1 < sz(res)]);
  }
  return 0;
}