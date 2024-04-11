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

int n;
vvi es;
vi ds;

void dfs(int v) {
  for (int i = 0; i < sz(es[v]); i++) {
    int b = es[v][i];
    if (ds[b] >= 0) {
      assert(ds[b] <= ds[v] + 1);
      continue;
    }
    ds[b] = ds[v] + 1;
    dfs(b);
  }
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #else
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int m;
  while (scanf("%d", &m) >= 1) {
    int ans = 0;

    for (int i = 0; i < m; i++) {
      scanf("%d", &n);
      es = vvi(n);
      for (int i2 = 0; i2 < n - 1; i2++) {
        int a, b;
        scanf("%d%d", &a, &b), a--, b--;
        es[a].pb(b); es[b].pb(a);
      }

      int cres = 0;
      for (int a = 0; a < n; a++) {
        ds = vi(n, -1);
        ds[a] = 0;
        dfs(a);

        for (int b = 0; b < n; b++)
          cres = max(cres, ds[b]);
      }
      ans += cres;
    }
    printf("%d\n", ans);
  }
  return 0;
}