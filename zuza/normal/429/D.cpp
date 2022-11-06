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

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

#ifdef ONLINE_JUDGE
# define LLD "%I64d"
#else
# define LLD "%ll" "d"
#endif

typedef long long llint;

const int MAXN = 1e5 + 123;

struct Pt {
  llint x, y; 
};

vector<Pt> pts;
auto x_cmpf = [](Pt a, Pt b) { return a.x < b.x; };
auto y_cmpf = [](Pt a, Pt b) { return a.y < b.y; };
inline llint sq(llint x) { return x*x; }
inline llint dist(Pt a, Pt b) { llint dx = a.x-b.x, dy = a.y-b.y; return dx*dx + dy*dy; }

llint solve(int lo, int hi) {
  if (hi-lo <= 1) return 4e18;
  int mid = (lo + hi) / 2;
  llint x_mid = pts[mid].x;
  llint ans = min(solve(lo, mid), solve(mid, hi));
  inplace_merge(pts.begin()+lo, pts.begin()+mid, pts.begin()+hi, y_cmpf);

  static vector<Pt> pruga; pruga.clear();
  FOR(i, lo, hi) {
    if (sq(pts[i].x - x_mid) < ans) {
      for (int j = pruga.size() - 1; j >= 0; --j) {
        if (sq(pruga[j].y - pts[i].y) >= ans) break;
        ans = min(ans, dist(pruga[j], pts[i]));
        assert(j >= (int)pruga.size() - 30);
      }
      pruga.push_back(pts[i]);
    }
  }

  return ans;
}

int main(void)
{
  int n; scanf("%d", &n);
  int A[MAXN];
  int pref[MAXN];

  REP(i, n) scanf("%d", A+i);
  pref[0] = A[0]; FOR(i, 1, n) pref[i] = pref[i-1] + A[i];
  REP(i, n) pts.push_back({i, pref[i]});

  sort(pts.begin(), pts.end(), x_cmpf);
  llint ans = solve(0, n);
  printf(LLD "\n", ans);
  return 0;
}