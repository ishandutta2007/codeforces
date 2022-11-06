#include <cassert>
#include <cstring>

#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

struct Edge {
  int a, b, idx;
};

// #include <stack>

const int MAXV = 3e5; ////////// @@@@@@@@@@@@@@@
const int MAXCOMP = 3e5; ///////// @@@@@@@@@@@@@@@@@@

// Output:
int ncomp;
int v_to_comp[MAXV];
vector<int> comp_vs[MAXCOMP];
vector<int> comp_E[MAXCOMP];

namespace bi {
  int color[MAXV];
  int D[MAXV];
  int tt;
  stack<int> stk;

  enum { WHITE, GREY, BLACK };

  int bridge_dfs(int x, int dadidx, vector<Edge> Ev[]) { // no double edges
    color[x] = GREY;
    stk.push(x);
    int lw = D[x] = tt++;

    for (Edge e : Ev[x]) {
      int y = e.b;
      if (e.idx == dadidx) continue;
      if (color[y] == GREY)
        lw = min(lw, D[y]);
      else if (color[y] == WHITE) {
        lw = min(lw, bridge_dfs(y, e.idx, Ev));
      } else if (color[y] == BLACK) {
        continue;
      }
    }
    color[x] = BLACK;
    if (lw == D[x]) {
      while (true) {
        int top = stk.top(); stk.pop();
        comp_vs[ncomp].push_back(top);
        v_to_comp[top] = ncomp;
        if (top == x) break;
      }
      ++ncomp;
    }
    return lw;
  }

  void biconnected_bridge(int nv, vector<Edge> Ev[]) {
    ncomp = 0;
    tt = 0;
    memset(color, WHITE, sizeof color);
    REP(v, nv) {
      if (color[v] == WHITE)
        bridge_dfs(v, -1, Ev);
    }

    REP(v, nv) {
      for (auto e : Ev[v]) {
        int vc = v_to_comp[e.a];
        int wc = v_to_comp[e.b];
        if (vc != wc) {
          comp_E[vc].push_back(wc);
        }
      }
    }
  }
}

// int cnt = 0;
// int bio[MAXV];

const int MAXLOG = 19; // 2^(MAXLOG-1) >= n

// Output:

namespace lca { // start: lca::calc(n, E);
  int dep[MAXV];
  int jmp[MAXLOG][MAXV];

  void dfs(int x, int dad, vector<int> Ev[]) {
    if (dad == -1) dep[x] = 0;
    else dep[x] = dep[dad] + 1;
    jmp[0][x] = dad;

    for (int y : Ev[x]) {
      if (y != dad) {
        dfs(y, x, Ev);
      }
    }
  }

  int climb(int x, int cnt) {
    REP(j, MAXLOG) if (cnt&(1<<j)) x = jmp[j][x];
    return x;
  }

  int get_root(int a) { return climb(a, dep[a]); }

  int get_lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    a = climb(a, dep[a]-dep[b]);
    if (a == b) return a;
    for (int j = MAXLOG-1; j >= 0; --j)
      if (jmp[j][a] != jmp[j][b])
        a = jmp[j][a], b = jmp[j][b];
    return jmp[0][a];
  }

  void calc(int n, vector<int> Ev[]) {
    REP(v, n) dep[v] = -1;
    REP(v, n)
      if (dep[v] == -1)
        dfs(v, -1, Ev);

    REP(j, MAXLOG-1) {
      REP(v, n) {
        int x = jmp[j][v];
        if (x != -1) x = jmp[j][x];
        jmp[j+1][v] = x;
      }
    }
  }
}

bool ok;
int bio[MAXV];
int cum[MAXV][2];

pair<int, int> dfs(int x, int d) {
  int c[2] = {cum[x][0], cum[x][1]};
  bio[x] = true;
  for (int y : comp_E[x]) {
    if (y != d) {
      auto p = dfs(y, x);
      c[0] += p.first;
      c[1] += p.second;
    }
  }
  if (c[0] > 0 && c[1] > 0) ok = false;
  return make_pair(c[0], c[1]);
}

int main(void) {
  int n, e, q; scanf("%d %d %d", &n, &e, &q);
  static vector<Edge> E[MAXV];

  REP(i, e) {
    int a, b; scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back({a, b, i});
    E[b].push_back({b, a, i});
  }

  bi::biconnected_bridge(n, E);
  lca::calc(ncomp, comp_E);

  memset(bio, 0, sizeof bio);
  memset(cum, 0, sizeof cum);
  ok = true;
  REP(i, q) {
    int av, bv; scanf("%d %d", &av, &bv); --av, --bv;
    int ac = v_to_comp[av], bc = v_to_comp[bv];

    int ar = lca::get_root(ac), br = lca::get_root(bc);
    if (ar != br) { ok = false; break; }

    int lca = lca::get_lca(ac, bc);
    cum[ac][0] += 1;
    cum[lca][0] -= 1;
    cum[bc][1] += 1;
    cum[lca][1] -= 1;
  }

  REP(i, ncomp) if (!bio[i]) dfs(i, -1);    
  puts(ok ? "Yes" : "No");
  return 0;
}