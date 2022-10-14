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

vvi es;
vi cyc;
vi was;

int dfs(int v, int par = -1) {
  was[v] = 1;
  for (int i = 0; i < sz(es[v]); i++) {
    int b = es[v][i];
    if (b == par) continue;

    assert(was[b] < 2);
    if (was[b]) {
      cyc.pb(b);
      cyc.pb(v);
      return b;
    }
    int res = dfs(b, v);
    if (res >= 0) {
      if (res == v)
        return -1;
      cyc.pb(v);
      return res;
    }
  }
  was[v] = 2;
  return -1;
}

const int INF = 1e9;
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif
  
  int n;
  while (scanf("%d", &n) >= 1) {
    es = vvi(n);
    for (int i = 0; i < n; i++) {
      int a, b;
      scanf("%d%d", &a, &b), a--, b--;
      es[a].pb(b);
      es[b].pb(a);
    }

    cyc.clear();
    was = vi(n, 0);
    dfs(0);
    assert(sz(cyc));
//    for (int i = 0; i < sz(cyc); i++)
//      eprintf("%d%c", cyc[i], "\n "[i + 1 < sz(cyc)]);

    deque<int> q;
    vi ds(n, INF);
    for (int i = 0; i < sz(cyc); i++) {
      ds[cyc[i]] = 0;
      q.pb(cyc[i]);
    }

    while (!q.empty()) {
      int v = q.front(); q.pop_front();
      for (int i = 0; i < sz(es[v]); i++) {
        int b = es[v][i];
        if (ds[b] <= ds[v] + 1) continue;
        ds[b] = ds[v] + 1;
        q.pb(b);
      }
    }
    for (int i = 0; i < n; i++)
      printf("%d%c", ds[i], "\n "[i + 1 < n]);
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}