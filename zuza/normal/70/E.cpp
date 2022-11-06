#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

const int MAXN = 180;
const int inf = 1e9;

int n;
int reg_cost;
int D_cost[MAXN];

struct Edge {
  int a, b, ind;
};
vector<Edge> E[MAXN];
vector<int> top_order;
int is_parent[MAXN][MAXN];

void dfs(int x, int dad) {
  for (Edge& e : E[x]) {
    if (e.b == dad) continue;
    is_parent[e.a][e.b] = true;
    dfs(e.b, x);
  }
  top_order.push_back(x);
}

int dist[MAXN][MAXN];

void dist_dfs(int orig, int x, int dad, int d) {
  dist[orig][x] = d;
  for (Edge& e : E[x]) {
    if (e.b == dad) continue;
    dist_dfs(orig, e.b, e.a, d+1);
  }
}

int main(void)
{
  scanf("%d %d", &n, &reg_cost);
  for (int i = 1; i <= n-1; ++i) scanf("%d", D_cost+i);
  REP(i, n-1) { 
    int a, b; scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back({a, b, i});
    E[b].push_back({b, a, i});
  }

  dfs(0, -1);
  REP(i, n) is_parent[i][i] = 1;
  REP(k, n) REP(i, n) REP(j, n) is_parent[i][j] |= is_parent[i][k] && is_parent[k][j];

  REP(i, n) dist_dfs(i, i, -1, 0);

  static int dp[MAXN][MAXN];
  static int recon_d[MAXN][MAXN];
  static int recon_l[MAXN][MAXN];

  static int bestsub[MAXN];
  static int best_recon[MAXN];

  for (int v : top_order) {
    REP(g, n) {
      if (g == v) {
        dp[v][g] = reg_cost;
      }
      else {
        dp[v][g] = D_cost[dist[v][g]];
      }
    }

    for (const Edge& e : E[v]) {
      if (!is_parent[e.a][e.b]) continue;

      static int tmpV[MAXN];
      static int tmp_recon_d[MAXN];
      static int tmp_recon_l[MAXN];

      REP(g, n) tmpV[g] = inf;

      REP(g, n) {
        if (dp[e.a][g] + dp[e.b][g] < tmpV[g]) {
          tmpV[g] = dp[e.a][g] + dp[e.b][g];
          tmp_recon_d[g] = g;
          tmp_recon_l[g] = g;
        }
        if (!is_parent[e.b][g]) {
          if (dp[e.a][g] + bestsub[e.b] < tmpV[g]) {
            tmpV[g] = dp[e.a][g] + bestsub[e.b];
            tmp_recon_d[g] = best_recon[e.b];
            tmp_recon_l[g] = g;
          }
        }
      }

      REP(g, n) {
        dp[e.a][g] = tmpV[g];
        recon_d[e.ind][g] = tmp_recon_d[g];
        recon_l[e.ind][g] = tmp_recon_l[g];
      }
    }

    bestsub[v] = inf;
    REP(g, n) if (is_parent[v][g]) {
      if (dp[v][g] < bestsub[v]) {
        best_recon[v] = g;
        bestsub[v] = dp[v][g];
      }
    }
  }

  static int sol[MAXN]; memset(sol, -1, sizeof sol);

  function<void (int, int)> build;
  build = [&build](int v, int g) {
    for (int e_it = (int)E[v].size() - 1; e_it >= 0; --e_it) {
      const Edge& e = E[v][e_it];
      if (!is_parent[e.a][e.b]) continue;     
      build(e.b, recon_d[e.ind][g]);
      g = recon_l[e.ind][g];
    }
    sol[v] = g;
  };

  printf("%d\n", bestsub[0]);

  build(0, best_recon[0]);
  REP(i, n) printf("%d%c", sol[i]+1, i+1 == n ? '\n' : ' ');
  return 0;
}