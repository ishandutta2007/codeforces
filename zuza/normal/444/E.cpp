#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

struct Edge {
  int a, b, w;
}; 
vector<Edge> es;

const int MAXN = 3000 + 123;
int dad[MAXN];
int find_dad(int x) { return (dad[x] == -1) ? x : dad[x] = find_dad(dad[x]); }

int main(void)
{
  int n; scanf("%d", &n);
  REP(i, n-1) {
    int a, b, w; scanf("%d %d %d", &a, &b, &w); --a, --b;
    es.push_back({a, b, w});
  }

  static int vals[MAXN];
  int rhs = 0;
  REP(i, n) {
    int v; scanf("%d", &v);
    vals[i] = v; rhs += v;
  }

  auto bs_cmpf = [&](int R) {
    if (n > rhs) return false;

    REP(i, n) dad[i] = -1;
    for (auto e : es) {
      if (e.w < R) {
        int aa = find_dad(e.a);
        int bb = find_dad(e.b);
        if (aa != bb) dad[e.a] = e.b;
      }
    }
    static map<int, int> counter; counter.clear();
    static map<int, int> r2sum; r2sum.clear();
    REP(i, n) {
      ++counter[ find_dad(i) ];
      r2sum[ find_dad(i) ] += vals[i];
    }
    for (auto p : counter) {
      if (p.second > rhs-r2sum[p.first])
        return false;
    }
    return true;
  };

  int lo = 0, hi = 1e5;
  while (lo < hi) {
    int mid = (lo + hi + 1) / 2;
    if (bs_cmpf(mid))
      lo = mid;
    else
      hi = mid - 1;
  }
  printf("%d\n", lo);

  return 0;
}