/***** 31. 12. 2013. Min-Cost Max-Flow --> tested CF 212 D2 #E *****///

#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

#include <set>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

const int MAXV = 51; // !!!
const int inf = 1e9;

struct Edge {
  int a, b, cap, cost;
  Edge* rev;
};

vector<Edge> E[MAXV]; // pazi na resize !!! pocisti na pocetku

int v;
int phi[MAXV];
Edge* recon_e[MAXV];

Edge augment(int source, int sink) {
  static int max_cap[MAXV]; REP(i, v) max_cap[i] = 0;
  static int min_cost[MAXV]; REP(i, v) min_cost[i] = +inf;
 
  auto v_cmpf = [](int a, int b) {
    if (min_cost[a] != min_cost[b]) return min_cost[a] < min_cost[b];
    return a < b;
  };
  set<int, decltype(v_cmpf)> pq(v_cmpf);

  max_cap[source] = inf;
  min_cost[source] = 0;
  pq.insert(source);

  while (!pq.empty()) {
    int expand = *pq.begin(); pq.erase(pq.begin());
    
    for (Edge& e : E[expand]) { // pazi na &
      if (e.cap == 0) continue;
      int cost = min_cost[e.a] + phi[e.a] + e.cost - phi[e.b];
      assert(cost >= min_cost[e.a]); // Johnson ispravan?

      if (cost < min_cost[e.b]) {
        if (min_cost[e.b] < inf) pq.erase(e.b);

        min_cost[e.b] = cost;
        max_cap[e.b] = min(max_cap[e.a], e.cap);
        recon_e[e.b] = &e;

        pq.insert(e.b);
      }
    }
  }

  REP(i, v) phi[i] += min_cost[i];
  return {source, sink, max_cap[sink], phi[sink] - phi[source]}; // cost per 1 capacity
}

int get_flow(int source, int sink, int k) { // najveci flow integer cijenom koja je <= k
  int flow = 0;
  memset(phi, 0, sizeof phi);

  while (true) {
    Edge ret = augment(source, sink); // first = flow, second = cost per 1
    int kol = min(ret.cap, ret.cost > 0 ? k/ret.cost : inf); // obicno if (ret.first == 0) break;
    if (kol == 0) break;

    flow += kol;
    k -= ret.cost * kol;
    for (int b = sink; b != source; b = recon_e[b]->a) {
      recon_e[b]->cap -= kol;
      recon_e[b]->rev->cap += kol;
    }
  }
  return flow;
}

int main(void)
{
  int k; scanf("%d %d", &v, &k);
  REP(i, v) E[i].reserve(4*v);

  REP(i, v) REP(j, v) {
    int cap; scanf("%d", &cap);
    if (cap > 0) {
      E[i].push_back({i, j, cap, 0});
      E[j].push_back({j, i, 0, 0});
      E[i].back().rev = &E[j].back();
      E[j].back().rev = &E[i].back();

      E[i].push_back({i, j, inf, 1});
      E[j].push_back({j, i, 0, -1});
      E[i].back().rev = &E[j].back();
      E[j].back().rev = &E[i].back();      
    }
  }
  REP(i, v) { assert((int)E[i].size() <= 4*v); }
  int flow = get_flow(0, v-1, k);
  printf("%d\n", flow);

  return 0;
}