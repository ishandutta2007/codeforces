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

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

vvi es, rves;
vi tim; vb was;
int cyclen;
void dfs(int v, int ctim) {
  if (was[v]) return;
  if (tim[v] > 0) {
    cyclen = gcd(cyclen, abs(ctim - tim[v]));
    return;
  }
  tim[v] = ctim;
  for (int i = 0; i < sz(es[v]); i++)
    dfs(es[v][i], ctim + 1);
  was[v] = true;
}

void dfs2(int v, int ctim) {
  if (was[v]) return;
  was[v] = true;
  tim[v] = ctim;
  for (int i = 0; i < sz(es[v]); i++) {
    dfs2(es[v][i], ctim + 1);
    cyclen = gcd(cyclen, abs(tim[es[v][i]] - 1 - ctim));
  }
  for (int i = 0; i < sz(rves[v]); i++) {
    dfs2(rves[v][i], ctim - 1);
    cyclen = gcd(cyclen, abs(tim[rves[v][i]] + 1 - ctim));
  }
}

int curans;
inline int modans(int x) {
  if (x < 0) x += curans;
  if (x >= curans) x -= curans;
  return x;
}

bool dfs3(int v, int ctim) {
  if (was[v]) return ctim == tim[v];
  was[v] = true;
  tim[v] = ctim;
  for (int i = 0; i < sz(es[v]); i++) {
    if (!dfs3(es[v][i], modans(ctim + 1)))
      return false;
  }
  for (int i = 0; i < sz(rves[v]); i++) {
    if (!dfs3(rves[v][i], modans(ctim - 1)))
      return false;
  }
  return true;
}

int n;
bool tryPaint(int _ans) {
  was = vb(n, false);
  tim = vi(n, 0);
  curans = _ans;
  for (int i = 0; i < n; i++) if (!was[i]) if (!dfs3(i, 0)) return false;
  return true;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int m;
  while (scanf("%d%d", &n, &m) >= 1) {
    es = vvi(n);
    rves = vvi(n);
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b), a--, b--;
      es[a].pb(b);
      rves[b].pb(a);
    }

    was = vb(n, false);
    tim = vi(n, 0);
    cyclen = 0;
    for (int i = 0; i < n; i++) 
      if (!was[i])
        dfs(i, 1);

    eprintf("cyclen=%d\n", cyclen);
    if (!cyclen) {
      tim = vi(n, 0);
      was = vb(n, false);

      for (int i = 0; i < n; i++)
        if (!sz(rves[i])) {
          dfs2(i, 1);
        }
    }
    eprintf("cyclen=%d\n", cyclen);

    if (!cyclen) printf("%d\n", n);
    else {
      for (int i = cyclen; i >= 1; i--)
        if (cyclen % i == 0) {
          if (tryPaint(i)) {
            printf("%d\n", i);
            goto end;
          }
        }
      assert(false);
      end:;
    }
  }
  return 0;
}