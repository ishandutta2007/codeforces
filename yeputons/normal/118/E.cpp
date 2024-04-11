#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>

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
vi stim; int ctim;

vector<pii> res;

int dfs(int v, int par = -1) {
  stim[v] = ctim++;

  int low = stim[v];
  for (int i = 0; i < sz(es[v]); i++) {
    int b = es[v][i];
    if (b == par) continue;

    if (stim[b] >= 0) {
      low = min(low, stim[b]);
      if (stim[b] < stim[v])
        res.pb(mp(v, b));
      continue;
    }

    res.pb(mp(v, b));
    low = min(low, dfs(b, v));
  }
  if (par >= 0 && low >= stim[v]) throw v;
  return low;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif
  
  int m;
  while (scanf("%d%d", &n, &m) >= 1) {
    es = vvi(n);
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b), a--, b--;
      es[a].pb(b);
      es[b].pb(a);
    }
    stim = vi(n, -1);
    ctim = 0;
    res.clear();

    try {
      dfs(0);
      assert(sz(res) == m);
      for (int i = 0; i < sz(res); i++)
        printf("%d %d\n", res[i].first + 1, res[i].second + 1);
    } catch (...) {
      printf("0\n");
    }
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}