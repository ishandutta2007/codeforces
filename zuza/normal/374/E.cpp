#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

const int inf = 1e9;

struct Point { int x, y; };
vector<Point> X, Y;

bool bs_cmpf(int mid) {
  struct Segment { int x; int l, r; };
  vector<Segment> H, V;

  for (auto p : X) H.push_back({p.y, p.x-2*mid, p.x+2*mid});
  for (auto p : Y) V.push_back({p.x, p.y-2*mid, p.y+2*mid});

  auto merge = [](vector<Segment>& S) {
    sort(S.begin(), S.end(), [](Segment a, Segment b) {
        if (a.x != b.x) return a.x < b.x;
        return a.l < b.l;
      });
    vector<Segment> output; output.reserve(S.size());
    Segment tmp = {-inf, -inf, inf};
    for (auto s : S) {
      if (s.x == tmp.x && tmp.r >= s.l) {
        tmp.r = max(tmp.r, s.r);
      } else {
        if (tmp.x != -inf) output.push_back(tmp);
        tmp = s;
      }
    }
    if (tmp.x != -inf) output.push_back(tmp);
    S.swap(output);
  };

  merge(H);
  merge(V);

  const int MAXN = 2010;
  static int cnt[MAXN][MAXN];
  REP(v1, (int)V.size()) REP(v2, (int)V.size()) cnt[v1][v2] = 0;

  REP(h, (int)H.size()) {
    static vector<int> adj; adj.clear();
    REP(v, (int)V.size()) {
      if (V[v].l <= H[h].x && H[h].x <= V[v].r && H[h].l <= V[v].x && V[v].x <= H[h].r)
        adj.push_back(v);
    }
    for (int a = 0; a < (int)adj.size(); ++a)
      for (int b = a+1; b < (int)adj.size(); ++b)
        if (++cnt[adj[a]][adj[b]] == 2)
          return true;
  }

  return false;
}

int main(void)
{
  int n_x, n_y; scanf("%d %d", &n_x, &n_y);
  REP(i, n_x) { int x, y; scanf("%d %d", &x, &y); X.push_back({x-y, x+y}); }
  REP(i, n_y) { int x, y; scanf("%d %d", &x, &y); Y.push_back({x-y, x+y}); }

  int l = 1, r = 2e6 + 124;
  if (!bs_cmpf(r)) { puts("Poor Sereja!"); exit(0); }
  while (l < r) {
    int mid = (l + r) / 2;
    if (bs_cmpf(mid))
      r = mid;
    else
      l = mid + 1;
  }

  printf("%d\n", l);
  return 0;
}