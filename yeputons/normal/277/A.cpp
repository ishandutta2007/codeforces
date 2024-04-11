#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
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

int n, m;
vvb g;
vb was;

void dfs(int v) {
  if (was[v]) return;
  was[v] = true;
  for (int l = 0; l < m; l++) if (g[v][l])
  for (int i2 = 0; i2 < n; i2++) if (g[i2][l])
    dfs(i2);
}

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  while (scanf("%d%d", &n, &m) >= 1) {
    g = vvb(n, vb(m, false));
    bool isgood = false;
    for (int i = 0; i < n; i++) {
      int k;
      scanf("%d", &k);
      isgood = isgood || k > 0;
      for (int i2 = 0; i2 < k; i2++) {
        int x;
        scanf("%d", &x), x--;
        g[i][x] = true;
      }
    }

    was = vb(n, false);
    int ccnt = 0;
    for (int i = 0; i < n; i++) if (!was[i]) {
      dfs(i);
      ccnt++;
    }
    printf("%d\n", isgood ? max(0, ccnt - 1) : ccnt);
  }
  return 0;
}