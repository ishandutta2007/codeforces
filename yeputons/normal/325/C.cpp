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

class Solver1 {
  vvi es, rves;
  vb loop;
  vb was;
  vi ord, comp;
  vb cyc;

  void dfs(int v) {
    if (was[v]) return;
    was[v] = true;
    for (int i = 0; i < sz(es[v]); i++)
      dfs(es[v][i]);
    ord.pb(v);
  }
  void dfs2(int v) {
    if (was[v]) return;
    was[v] = true;
    for (int i = 0; i < sz(rves[v]); i++)
      dfs2(rves[v][i]);
    comp.pb(v);
  }

  public:
  Solver1(int n) : es(n), rves(n), loop(n, false) {}
  void adde(int a, int b) {
    es[a].pb(b);
    rves[b].pb(a);
    if (a == b) loop[a] = true;
  }
  vi getOrd() {
    const int n = sz(es);
    was = vb(n, false);
    ord = vi();
    for (int i = 0; i < n; i++)
      if (!was[i]) dfs(i);
    reverse(ord.begin(), ord.end());

    was = vb(n, false);
    cyc = vb(n, false);
    for (int _i = 0; _i < n; _i++) {
      int i = ord[_i];
      if (!was[i]) {
        comp = vi();
        dfs2(i);
        if (sz(comp) == 1 && !loop[comp[0]]) {
        } else {
          for (int i2 = 0; i2 < sz(comp); i2++)
            cyc[comp[i2]] = true;
        }
      }
    }

    was = vb(n, false);
    for (int i = 0; i < n; i++)
      if (!was[i] && cyc[i]) {
        dfs2(i);
      }
    cyc = was;
    was = vb(n, false);
    ord.clear();
    for (int i = 0; i < n; i++)
      if (!was[i] && !cyc[i]) {
        dfs(i);
      }
    return ord;
  }
};

const int MAXV = 314000000;

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int m, n;
  while (scanf("%d%d", &m, &n) >= 2) {
    vector<vvi> ts(n);

    for (int i = 0; i < m; i++) {
      int a, k;
      scanf("%d%d", &a, &k), a--;
      vi res(k);
      for (int i2 = 0; i2 < k; i2++) {
        scanf("%d", &res[i2]), res[i2]--;
      }
      ts[a].pb(res);
    }

    vb canFin(n, false);
    vi minFin(n, MAXV + 1);
    vector<vector<pii> > revRem(n);
    vvi remCnt(n);
    priority_queue<pii> q;
    for (int i = 0; i < n; i++) {
      remCnt[i].resize(sz(ts[i]));

      for (int i2 = 0; i2 < sz(ts[i]); i2++) {
        int cs = 0;
        for (int i3 = 0; i3 < sz(ts[i][i2]); i3++)
          if (ts[i][i2][i3] >= 0) {
            remCnt[i][i2]++;
            revRem[ts[i][i2][i3]].pb(mp(i, i2));
          } else {
            cs++;
          }
        if (remCnt[i][i2] == 0) {
          canFin[i] = true;
          if (cs < minFin[i]) {
            minFin[i] = cs;
            q.push(mp(-minFin[i], i));
          }
        }
      }
    }
    while (!q.empty()) {
      int cd = -q.top().first;
      int v = q.top().second;
      q.pop();
      if (minFin[v] != cd) continue;

      for (int i = 0; i < sz(revRem[v]); i++) {
        int a = revRem[v][i].first;
        int b = revRem[v][i].second;
        remCnt[a][b]--;
        assert(remCnt[a][b] >= 0);
        if (remCnt[a][b] == 0) {
          canFin[a] = true;
          int nd = 0;
          for (int i2 = 0; i2 < sz(ts[a][b]); i2++) {
            int x = ts[a][b][i2];
            if (x < 0) nd++;
            else nd += minFin[x];
            nd = min(nd, MAXV);
          }
          if (nd < minFin[a]) {
            minFin[a] = nd;
            q.push(mp(-nd, a));
          }
        }
      }
    }
    
    Solver1 s(n);
    for (int i = 0; i < sz(ts); i++) if (canFin[i]) {
      for (int i2 = 0; i2 < sz(ts[i]); i2++) {
        bool g = true;
        for (int i3 = 0; i3 < sz(ts[i][i2]); i3++) {
          int b = ts[i][i2][i3];
          if (b >= 0) g = g && canFin[b];
        }
        if (g) {
          for (int i3 = 0; i3 < sz(ts[i][i2]); i3++) {
            int b = ts[i][i2][i3];
            if (b >= 0) s.adde(i, b);
          }
        }
      }
    }

    vi ord = s.getOrd();
    vi amax(n, -2);
    for (int _i = 0; _i < sz(ord); _i++) {
      int v = ord[_i];
      if (!canFin[v]) continue;

//      eprintf("v=%d\n", v + 1);
      for (int i2 = 0; i2 < sz(ts[v]); i2++) {
        int cval = 0;
//        eprintf("  i2=%d\n", i2);
        for (int i3 = 0; i3 < sz(ts[v][i2]); i3++) {
          int b = ts[v][i2][i3];
          if (b >= 0 && !canFin[b]) {
            cval = -2;
            break;
          }
        }

        if (cval < 0) continue;
        for (int i3 = 0; i3 < sz(ts[v][i2]); i3++) {
          int b = ts[v][i2][i3];
//          eprintf("    b=%d\n", b + 1);
          if (b < 0) cval++;
          else {
            assert(amax[b] >= 0);
            cval += amax[b];
          }
          cval = min(cval, MAXV);
        }
//        eprintf("cval=%d\n", cval);
        amax[v] = max(amax[v], cval);
      }
      assert(amax[v] >= 0);
    }

    for (int i = 0; i < n; i++) {
      if (!canFin[i]) {
        printf("-1 -1\n");
        continue;
      }
      printf("%d %d\n", minFin[i], amax[i]);
    }
  }
  return 0;
}