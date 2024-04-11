#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " << 

typedef long long llint;
typedef pair<int, int> Pt;
#define x first
#define y second

namespace std {
template<>
struct hash<pair<int, int> > {
  size_t operator () (const pair<int, int>& p) const {
    return p.x ^ (p.y * 3137);
  }
};
}

int main(void)
{
  unordered_set<Pt> pt_s;
  int n; scanf("%d", &n);
  int rtn = 1; while (rtn*rtn <= n) ++rtn;

  const int MAXN = 1e5 + 123;
  static vector<Pt> xpts[MAXN]; REP(i, MAXN) xpts[i].clear();

  REP(i, n) {
    int x, y; scanf("%d %d", &x, &y);
    xpts[x].push_back({x, y});
    pt_s.insert({x, y});
  }
  static vector<int> bigx; bigx.clear();
  int ans = 0;

  REP(x, MAXN) {
    int sz = xpts[x].size();

    if (sz < rtn) {
      sort(xpts[x].begin(), xpts[x].end());
      FOR(i, 0, sz) FOR(j, i+1, sz) {
        Pt down = xpts[x][i], up = xpts[x][j];
        int d = up.y - down.y;
        if (pt_s.count({down.x+d, down.y}) && pt_s.count({up.x+d, up.y}))
          ++ans;
        if (pt_s.count({down.x-d, down.y}) && pt_s.count({up.x-d, up.y}))
          ++ans;
      }
      FOR(i, 0, sz) pt_s.erase(xpts[x][i]);
    } else bigx.push_back(x);    
  }

  int bsz = bigx.size();
  FOR(i1, 0, bsz) FOR(i2, i1+1, bsz) {
    int x1 = bigx[i1], x2 = bigx[i2];
    int d = x2 - x1;
    int x1sz = xpts[x1].size();
    REP(i, x1sz) {
      Pt down = xpts[x1][i];
      if (pt_s.count({down.x+d, down.y}) &&
          pt_s.count({down.x, down.y+d}) && 
          pt_s.count({down.x+d, down.y+d}))
        ++ans;
    }
  }

  printf("%d\n", ans);

  return 0;
}