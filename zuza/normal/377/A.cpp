#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

#define X first
#define Y second

int main(void)
{
  const int MAXN = 543;

  typedef pair<int, int> point;
  int R, S, K; scanf("%d %d %d", &R, &S, &K);
  static char grid[MAXN][MAXN];

  auto valid = [R, S](int r, int s) {
    if (r < 0 || s < 0) return false;
    if (r >= R || s >= S) return false;
    return true;
  };
  const int dx[4] = {-1, 0, 1, 0};
  const int dy[4] = {0, 1, 0, -1};

  REP(r, R) scanf("%s", grid[r]);
  if (K == 0) {
    REP(r, R) puts(grid[r]);
    exit(0);
  }

  point source(-1, -1);
  REP(r, R) REP(s, S) if (grid[r][s] == '.') source = point(r, s);

  static int dist[MAXN][MAXN]; memset(dist, -1, sizeof dist);
  queue<int> qX, qY;
  vector<point> V;

  for (qX.push(source.X), qY.push(source.Y), dist[source.X][source.Y] = 0; !qX.empty(); qX.pop(), qY.pop()) {
    int X = qX.front();
    int Y = qY.front();

    V.push_back(point(X, Y));
    REP(pc, 4) {
      int nX = X + dx[pc];
      int nY = Y + dy[pc];

      if (!valid(nX, nY)) continue;
      if (dist[nX][nY] != -1) continue;
      if (grid[nX][nY] != '.') continue;

      dist[nX][nY] = dist[X][Y] + 1;
      qX.push(nX);
      qY.push(nY);
    }
  }

  reverse(V.begin(), V.end());
  for (auto p : V) {
    if (K == 0) break;
    grid[p.X][p.Y] = 'X';
    --K;
  }

  assert(K == 0);
  REP(r, R) puts(grid[r]);

  return 0;
}