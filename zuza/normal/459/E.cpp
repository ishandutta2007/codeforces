#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

struct Edge {
  int a, b, w;
  int lp;
};

const int MAXW = 1e5 + 123;
vector<Edge> wes[MAXW];

int main(void) {
  int n, e; scanf("%d %d", &n, &e);

  REP(ie, e) {
    int a, b, w; scanf("%d %d %d", &a, &b, &w); --a, --b;
    wes[w].push_back({a, b, w, -123});
  }

  int ans = 0;
  vector<int> lp(n, 0);
  for (int w = MAXW-1; w >= 0; --w) {
    for (auto& e : wes[w]) {
      e.lp = lp[e.b] + 1;
    }
    for (auto& e : wes[w]) {
      lp[e.a] = max(lp[e.a], e.lp);
      ans = max(ans, lp[e.a]);
    }
  }
  printf("%d\n", ans);
  
  return 0;
}