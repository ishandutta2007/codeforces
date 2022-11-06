#include <cassert>
#include <cstring>

#include <cstdio>
#include <cstdlib>

#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 2123;

char grid[MAXN][MAXN];
int deg[MAXN][MAXN];

int R, S;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

struct Pt { int x, y; };

inline int valid(int x, int y) {
  if (x >= 0 && y >= 0 && x < R && y < S) return true;
  return false;
}

inline bool is_free(int x, int y) {
  if (valid(x, y) && grid[x][y] == '.') return true;
  return false;
}

void bad() {
  puts("Not unique");
  exit(0);
}

queue<Pt> Q;

void remove(int x, int y) {
  REP(pc, 4) {
    int nx = x + dx[pc], ny = y + dy[pc];
    if (is_free(nx, ny)) {
      --deg[nx][ny];
      if (deg[nx][ny] <= 1) Q.push({nx, ny});
    }
  }
}

int main(void) {
  scanf("%d %d", &R, &S);
  REP(i, R) scanf("%s", grid[i]);

  int left = 0;

  REP(i, R) REP(j, S) if (grid[i][j] == '.') {
    deg[i][j] = 0;
    ++left;

    REP(pc, 4) {
      if (is_free(i+dx[pc], j+dy[pc]))
        ++deg[i][j];
    }

    if (deg[i][j] <= 1) {
      Q.push({i, j});
    }
  }

  for (; !Q.empty(); Q.pop()) {
    int ex = Q.front().x, ey = Q.front().y;
    if (grid[ex][ey] != '.') continue;
    if (deg[ex][ey] == 0) bad();
    assert(deg[ex][ey] == 1);

    int dir = -1;
    REP(pc, 4) if (is_free(ex+dx[pc], ey+dy[pc])) dir = pc;    
    if (dir == -1) bad();

    const string SS = "v^<>^v><";
    grid[ex][ey] = SS[2*dir];
    grid[ex+dx[dir]][ey+dy[dir]] = SS[2*dir+1];
    left -= 2;

    remove(ex, ey);
    remove(ex+dx[dir], ey+dy[dir]);
  }

  if (left > 0) bad();
  REP(i, R) puts(grid[i]);

  return 0;
}