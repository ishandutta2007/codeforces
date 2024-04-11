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

struct Pt { llint x, y; };

int ccw(Pt a, Pt b, Pt c) {
  llint sum = 0;
  sum += a.x * (b.y - c.y);
  sum += b.x * (c.y - a.y);
  sum += c.x * (a.y - b.y);
  return (sum > 0) - (sum < 0);
}

llint tri_area_2(Pt a, Pt b, Pt c) {
  llint sum = 0;
  sum += a.x * (b.y - c.y);
  sum += b.x * (c.y - a.y);
  sum += c.x * (a.y - b.y);
  return sum;
}

int n;
inline int nx(int x) { return x+1 == n ? 0 : x+1; }

int main(void)
{
  scanf("%d", &n);
  vector<Pt> pts(n);
  REP(i, n) {
    int x, y; scanf("%d %d", &x, &y);
    pts[i] = {x, y};
  }

  llint s_area = 0;
  REP(i, n) s_area += tri_area_2({0, 0}, pts[i], pts[nx(i)]);
  if (s_area < 0) reverse(pts.begin(), pts.end());

  const int MAXN = 200 + 123;
  const llint mod = 1e9 + 7;
  static llint dp[MAXN][MAXN];
  memset(dp, 0, sizeof dp);

  REP(i, n) dp[i][nx(i)] = 1;
  FOR(L, 2, n) {
    REP(i, n) {
      int j = (i+L)%n;
      dp[i][j] = 0;

      FOR(s, 1, L) {
        int k = (i+s) % n;

        if (ccw(pts[i], pts[k], pts[j]) > 0) {
          dp[i][j] += dp[i][k] * dp[k][j];
          dp[i][j] %= mod;
        }
      }
    }
  }

  int ans = dp[0][n-1] % mod;
  printf("%d\n", ans);

  return 0;
}