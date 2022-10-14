#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>

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

class Solver {
  int n;
  vvi fl, w;

  vb was;
  int curw;
  bool dfs(int v) {
    if (v == n - 1) return true;
    if (was[v]) return false;
    was[v] = true;
    for (int b = 0; b < n; b++) if (fl[v][b] + curw <= w[v][b] && dfs(b)) {
      fl[b][v] -= curw;
      fl[v][b] += curw;
      return true;
    }
    return false;
  }

  public:
  Solver(int _n) : n(_n), w(n, vi(n, 0)) {}
  void add(int a, int b, int _w) {
    w[a][b] += _w;
  }

  int solve() {
    int ans = 0;
    fl = vvi(n, vi(n, 0));
    for (curw = 1 << 30; curw >= 1; curw >>= 1)
      for (;; ans += curw) {
        was = vb(n, false);
        if (!dfs(0)) break;
      }
    return ans;
  }
};

int n;
vvi es;
vi p1, p2;
vb was;

bool dfs(int v) {
  if (was[v]) return false;
  was[v] = true;
  for (int i = 0; i < sz(es[v]); i++) {
    int b = es[v][i];
    if (b == p1[v]) continue;

    if (p2[b] < 0 || dfs(p2[b])) {
      p1[v] = b;
      p2[b] = v;
      return true;
    }
  }
  return false;
}

const int FINF = 1e9;
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%d", &n) >= 1) {
    es = vvi(n);
    for (int i = 0; i < n; i++) {
      int k;
      scanf("%d", &k);
      for (int i2 = 0; i2 < k; i2++) {
        int x;
        scanf("%d", &x), x--;
        es[i].pb(x);
      }
    }
    vi pr(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &pr[i]);

    p1 = vi(n, -1);
    p2 = vi(n, -1);
    for (int step = 0; step < n; step++) {
      was = vb(n, false);
      for (int i = 0; i < n; i++)
        if (p1[i] < 0)
          dfs(i);
    }

    Solver s(2 + n);
    for (int a = 0; a < n; a++) {
      if (pr[a] > 0) {
        s.add(1 + a, 1 + n, pr[a]);
      } else if (pr[a] < 0) {
        s.add(0, 1 + a, -pr[a]);
      }

      for (int i = 0; i < sz(es[a]); i++) {
        int b = p2[es[a][i]];
        s.add(1 + a, 1 + b, FINF);
      }
    }

    int cans = 0;
    for (int i = 0; i < n; i++) if (pr[i] < 0) cans += pr[i];
    cans += s.solve();
    printf("%d\n", cans);
  }
  return 0;
}