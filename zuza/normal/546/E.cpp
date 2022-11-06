#include <cassert>
#include <cstring>

#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <iostream>

#include <queue>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int inf = 1e9;

namespace maxflow {
  struct Edge {
    int a, b, cap;
    int nx;
  };
 
  const int MAXV = 500;
  const int MAXE = 10000;
 
  int ne = -1;
  Edge es[MAXE];
  int last_eidx[MAXV];
 
  void clear() { ne = 0; memset(last_eidx, -1, sizeof last_eidx); }
  void add_edge(int a, int b, int cap) {
    es[ne] = {a, b, cap, last_eidx[a]}; last_eidx[a] = ne; ++ne;
    es[ne] = {b, a, 0, last_eidx[b]}; last_eidx[b] = ne; ++ne; // pazi cap = 0
  }
 
  int solve(int source, int sink, int v) {
    assert(ne != -1);
    int ans = 0;
 
    while (true) {
      static int dad_eidx[MAXV]; REP(i, v) dad_eidx[i] = -1;
      static int acc[MAXV]; REP(i, v) acc[i] = 0;
      static queue<int> Q; while (!Q.empty()) Q.pop();
 
      for (Q.push(source), acc[source] = inf; !Q.empty(); Q.pop()) {
        int ex = Q.front();
 
        for (int eidx = last_eidx[ex]; eidx != -1; eidx = es[eidx].nx) {
          Edge& e = es[eidx];
          int val = min(acc[e.a], e.cap);
          if (val > 0 && acc[e.b] == 0) {
            acc[e.b] = val;
            dad_eidx[e.b] = eidx;
            Q.push(e.b);
          }
        }
      }
 
      if (acc[sink] == 0)  break;
      int f = acc[sink]; ans += f;
      // if (ans >= inf) ???
 
      for (int x = sink; x != source; ) {
        int eidx = dad_eidx[x];
        Edge& e = es[ eidx ];
        es[eidx].cap -= f;
        es[eidx^1].cap += f;
        x = e.a;
      }
    }
 
    return ans;
  }
 
  void output(int n) {
    static int graf[123][123];
    memset(graf, 0, sizeof graf);

    REP(i, ne) {
      int a = es[i].a, b = es[i].b, cap = es[i].cap;
      if (a%2 == 0 && b%2 == 1 && a < 2*n && b < 2*n) {
        graf[b/2][a/2] = cap;
      }
    }

    REP(i, n) REP(j, n) printf("%d%c", graf[i][j], j+1 == n ? '\n' : ' ');
  }
}


int main(void) {
  maxflow::clear();
  int n, e; scanf("%d %d", &n, &e);

  const int MAXN = 123;

  static int A[MAXN];
  static int B[MAXN];

  int a_sum = 0;
  int b_sum = 0;

  REP(i, n) scanf("%d", A+i), a_sum += A[i];
  REP(i, n) scanf("%d", B+i), b_sum += B[i];

  int source = 2*n, sink = source+1;
  int must_flow = 0;

  REP(i, n) {
    if (A[i] > B[i]) { // visak
      maxflow::add_edge(source, 2*i, A[i]-B[i]);
    } else if (A[i] < B[i]) { // manjak
      maxflow::add_edge(2*i, sink, B[i]-A[i]);
      must_flow += B[i] - A[i];
    }
    maxflow::add_edge(2*i, 2*i+1, A[i]);
  }

  REP(i, e) {
    int a, b; scanf("%d %d", &a, &b); --a, --b;
    maxflow::add_edge(2*a+1, 2*b, inf);
    maxflow::add_edge(2*b+1, 2*a, inf);
  }

  int ans = maxflow::solve(source, sink, 2*n+2);
  if (a_sum == b_sum && ans == must_flow) {
    puts("YES");
    maxflow::output(n);
  } else {
    puts("NO");
  }


  return 0;
}