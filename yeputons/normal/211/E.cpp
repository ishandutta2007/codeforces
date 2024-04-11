#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <bitset>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())
#define all(x) (all).begin(), (all).end()

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

vvi es;
int dfs(int v, int par = -1) {
  int res = 1;
  for (int i = 0; i < sz(es[v]); i++) {
    int b = es[v][i];
    if (b == par) continue;
    res += dfs(b, v);
  }
  return res;
}

int main(int argc, char* argv[]) {
  #ifdef DEBUG
  {
    string filename = "std";
    if (argc >= 2) {
      filename = argv[1];
      int l = sz(filename);
      if (l >= 3 && string(filename, l - 3, 3) == ".in")
        filename = string(filename, 0, l - 3);
    }
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
  }
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    es = vvi(n);
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      scanf("%d%d", &a, &b), a--, b--;
      es[a].pb(b);
      es[b].pb(a);
    }

    vb bcan(n + 1, false);
    for (int root = 0; root < n; root++) {
      vb can(n + 1, false);
      can[0] = true;
      for (int i = 0; i < sz(es[root]); i++) {
        int x = dfs(es[root][i], root);
        for (int i = n - x; i >= 0; i--) if (can[i])
          can[i + x] = true;
      }
      for (int i = 0; i <= n; i++)
        bcan[i] = bcan[i] || can[i];
    }
    int ans = 0;
    for (int i = 1; i < n - 1; i++)
      ans += bcan[i];
    printf("%d\n", ans);
    for (int i = 1; i < n - 1; i++)
      if (bcan[i])
        printf("%d %d\n", i, n - i - 1);
  }
  return 0;
}