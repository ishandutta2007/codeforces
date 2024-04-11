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

int MOD;
void add(int &a, int b) {
  a = (a + b) % MOD;
}
int mul(int a, int b) { return ll(a) * b % MOD; }

vvi es;
vb was;

int dfs(int v) {
  if (was[v]) return 0;
  was[v] = true;
  int res = 1;
  for (int i = 0; i < sz(es[v]); i++)
    res += dfs(es[v][i]);
  return res;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, m;
  while (scanf("%d%d%d", &n, &m, &MOD) >= 1) {
    es = vvi(n);
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b), a--, b--;
      es[a].pb(b);
      es[b].pb(a);
    }
    if (MOD == 1) {
      printf("0\n");
      continue;
    }

    vi ws;
    was = vb(n, false);
    for (int i = 0; i < n; i++) if (!was[i])
      ws.pb(dfs(i));

    n = sz(ws);
    int res = 1;

    if (n != 1) {
      for (int i = 0; i < n; i++)
        res = mul(res, ws[i]);

      int k = 0;
      for (int i = 0; i < n; i++) add(k, ws[i]);
      for (int i = 0; i < n - 2; i++) res = mul(res, k);
    }
    printf("%d\n", res);
  }
  return 0;
}