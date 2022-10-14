#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())
#define TASKNAME "std"

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

vb was;
vvi es;
vi cst;

vi cols;
vvi cycs;

void dfs(int v, int par = -1) {
  was[v] = true;
  cst.pb(v);
  
  for (int i = 0; i < sz(es[v]); i++) {
    int b = es[v][i];
    if (b == par) continue;
    if (was[b]) {
      if (cols[v] >= 0) {
        assert(cols[v] == cols[b]);
      } else {
        int cid = sz(cycs);
        cycs.pb(vi());
        
        for (int i2 = sz(cst) - 1; i2 >= 0; i2--) {
          cycs[cid].pb(cst[i2]);
          assert(cols[cst[i2]] < 0);
          cols[cst[i2]] = cid;
          if (cst[i2] == b) break;
        }
      }
    } else
      dfs(b, v);
  }
  cst.pop_back();
}

int dfs2(int v, int par = -1) {
  int cid = cols[v];
  int res = sz(cycs[cid]) > 1;
  int sumcnt = 0;
  int nzcnt = 0;

  for (int i = 0; i < sz(cycs[cid]); i++) {
    int a = cycs[cid][i];
    int subcnt = 0;
    
    for (int i2 = 0; i2 < sz(es[a]); i2++) {
      int b = es[a][i2];
      if (cols[b] == cid) continue;

      int cres = -1;
      if (b != par) {
        cres = dfs2(b, a);
      } else {
         cres = 1;
      }
      
      res += cres; 
      subcnt++;
    }
//    if (v + 1 == 2)
//      eprintf("  res=%d, subcnt=%d\n", res, subcnt);
    res -= subcnt / 2;
    sumcnt += subcnt;
    if (subcnt) nzcnt++;
  }
//  eprintf("v=%d, par=%d, res=%d, sumcnt=%d\n", v + 1, par + 1, res, sumcnt);
  if (sz(cycs[cid]) > 1) {
    if (nzcnt >= 2) {
      res -= 1;
    }
  }
  return res;
}

int main() {
  #ifdef DEBUG
  freopen(TASKNAME ".in", "r", stdin);
  freopen(TASKNAME ".out", "w", stdout);
  #endif
  
  int n, m;
  while (scanf("%d%d", &n, &m) >= 1) {
    es = vvi(n);
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b), a--, b--;
      es[a].pb(b);
      es[b].pb(a);
    }
    
    was = vb(n, false);
    cst.clear();
    cols = vi(n, -1);
    cycs = vvi();
    dfs(0);
    
    for (int i = 0; i < n; i++) if (cols[i] < 0) {
      int cid = sz(cycs);
      cycs.pb(vi(1, i));
      cols[i] = cid;
    }
    
/*    for (int i = 0; i < sz(cycs); i++) {
      for (int i2 = 0; i2 < sz(cycs[i]); i2++)
        eprintf(" %d", cycs[i][i2] + 1);
      eprintf("\n");
    }*/
    
    int ans = dfs2(0);
    printf("%d %d\n", ans, m);
  }
  return 0;
}