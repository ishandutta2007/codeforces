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
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " << 

#ifdef ONLINE_JUDGE
# define LLD "%I64d"
#else
# define LLD "%ll" "d"
#endif

typedef long long llint;

struct ED { 
  int a, b;
  llint w;
};

const int MAXN = 1e5 + 123;
const llint inf = 1e18 + 123;

int n;
vector<ED> E[MAXN];
int np; vector<int> ports;

bool has[MAXN];
llint dist[MAXN];
int recon[MAXN];

void dijkstraAll() {
  auto cmpf = [](int a, int b) {
    return make_tuple(dist[a], a) < make_tuple(dist[b], b);
  };
  set<int, decltype(cmpf)> pq(cmpf);

  REP(i, n) dist[i] = inf;
  REP(i, n) recon[i] = -1;
  REP(i, np) {
    int x = ports[i];
    dist[x] = 0;
    recon[x] = x;
    pq.insert(x);
  }

  for (; !pq.empty(); ) {
    int ex = *pq.begin(); pq.erase(pq.begin());

    for (ED e : E[ex]) {
      llint val = dist[e.a] + e.w;
      if (val < dist[e.b]) {
        if (dist[e.b] < inf) pq.erase(e.b);
        dist[e.b] = val;
        recon[e.b] = recon[e.a]; assert(recon[e.b] != -1);
        pq.insert(e.b);
      }
    }
  }

}

int dad[MAXN];
int find_dad(int x) {
  if (dad[x] == -1) return x;
  return dad[x] = find_dad(dad[x]);
};


int main(void)
{
  int  e; scanf("%d %d", &n, &e);
  REP(i, e) {
    int a, b, w; scanf("%d %d %d", &a, &b, &w); --a, --b;
    E[a].push_back({a, b, w});
    E[b].push_back({b, a, w});
  }

  memset(has, 0, sizeof has);
  scanf("%d", &np);
  REP(i, np) {
    int x; scanf("%d", &x); --x;
    has[x] = true;
    ports.push_back(x);
  }

  dijkstraAll();
  llint first = dist[0]; assert(dist[0] < inf);

  vector<ED> table;
  REP(x, n) {
    for (ED e : E[x]) {
      if (recon[e.a] != -1 && recon[e.a] != recon[e.b]) {
        assert(dist[e.a] < inf && dist[e.b] < inf);
        table.push_back({recon[e.a], recon[e.b], dist[e.a] + dist[e.b] + e.w});
      }
    }
  }

  memset(dad, -1, sizeof dad);
  sort(table.begin(), table.end(), [](ED a, ED b) { return a.w < b.w; });
  llint suma = first;
  for (ED e : table) {
    int A = find_dad(e.a), B = find_dad(e.b);
    if (A != B) {
      suma += e.w;
      dad[A] = B;
    }
  }

  cout << suma << endl;
  return 0;
}