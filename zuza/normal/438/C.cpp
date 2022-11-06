#include <cassert>
#include <cstring>

#include <algorithm>
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

struct Pt {
  llint x, y;
  Pt(llint x = 0, llint y = 0) : x(x), y(y) {}
  friend bool operator == (Pt a, Pt b) { return make_pair(a.x, a.y) == make_pair(b.x, b.y); }
};

int ccw(Pt a, Pt b, Pt c) { // 2D only!
  llint sum = 0;
  sum += a.x * (b.y - c.y);
  sum += b.x * (c.y - a.y);
  sum += c.x * (a.y - b.y);
  return (sum > 0) - (sum < -0);
}

llint tri_area(Pt a, Pt b, Pt c) {
  llint sum = 0;
  sum += a.x * (b.y - c.y);
  sum += b.x * (c.y - a.y);
  sum += c.x * (a.y - b.y);
  return sum;
}

// point STRICTLY inside a line segment (not on it's endpoints)
bool point_in_segment(Pt p, Pt a, Pt b) { // 2D !!!
  if (ccw(a, b, p) != 0) return false;

  if (min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x))
    if (min(a.y, b.y) < p.y && p.y < max(a.y, b.y))
      return true;
  if (min(a.x, b.x) < p.x && p.x < max(a.x, b.x))
    if (min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y))
      return true;

  return false;
}

// not on endpoints
bool intersects(Pt a, Pt b, Pt c, Pt d) {
  if (a == c || a == d || b == c || b == d) return false;
  if (ccw(a, b, c) * ccw(a, b, d) < 0)
    if (ccw(c, d, a) * ccw(c, d, b) < 0)
      return true;
  return false;
}

const llint mod = 1000000007;
const int MAXN = 210;

llint dp[MAXN][MAXN];
int good[MAXN][MAXN];

int n;
Pt pts[MAXN];

int main(void)
{
  scanf("%d", &n);
  REP(i, n) {
    int x, y; scanf("%d %d", &x, &y);
    pts[i] = Pt(x, y);
  }
  llint area = 0;
  Pt origin(0, 0);
  REP(i, n) {
    area += tri_area(origin, pts[i], pts[(i+1)%n]);
  }
  if (area < 0) reverse(pts, pts+n);

  REP(a, n) REP(b, n) {
    int& ref = good[a][b]; ref = true;
    if (a == b) { ref = false; continue; }

    REP(x, n) {
      int y = (x+1)%n;
      if (intersects(pts[a], pts[b], pts[x], pts[y])) ref = false;
      if (point_in_segment(pts[x], pts[a], pts[b])) ref = false;
      if (point_in_segment(pts[y], pts[a], pts[b])) ref = false;
    }
  }

  memset(dp, 0, sizeof dp);
  REP(i, n) dp[i][(i+1)%n] = 1;

  FOR(L, 2, n) {
    REP(a, n) {
      int b = (a+L)%n;
      dp[a][b] = 0;

      FOR(prvi, 1, L) {
        int c = (a + prvi) % n;
        if (ccw(pts[a], pts[c], pts[b]) <= 0) continue;
        if (good[a][c] && good[b][c]) {
          dp[a][b] += dp[a][c] * dp[c][b];
          dp[a][b] %= mod;
        }
      }
    }
  }

  llint ans = 0;
  int a = 0, b = 1;

  FOR(c, 2, n) {
    if (ccw(pts[a], pts[b], pts[c]) > 0) {
      if (good[a][c] && good[b][c]) {
        ans += dp[1][c] * dp[c][0];
        ans %= mod;
      }
    }
  }

  printf(LLD "\n", ans);
  return 0;
}