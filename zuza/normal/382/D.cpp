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

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

const int MAXN = 2e3 + 123;

int r, s;
char grid[MAXN][MAXN];
int longest[MAXN][MAXN];


bool next(int x, int y, int& nx, int& ny) {
  nx = x; ny = y;
  if (grid[x][y] == 'v') { ++nx; return true; }
  if (grid[x][y] == '^') { --nx; return true; }
  if (grid[x][y] == '<') { --ny; return true; }
  if (grid[x][y] == '>') { ++ny; return true; }
  return false;
}

int solve(int x, int y) {
  int orig_x = x, orig_y = y;
  struct Pt { int x, y; };
  static vector<Pt> V; V.clear();

  for (; longest[x][y] == 0 && grid[x][y] != '#';) {
    longest[x][y] = -1;
    V.push_back({x, y});
    int nx, ny;
    next(x, y, nx, ny);
    x = nx;
    y = ny;
  }

  if (longest[x][y] == -1) return -1;
  int step = longest[x][y] + 1;

  for (int i = V.size() - 1; i >= 0; --i, ++step) {
    longest[ V[i].x ][ V[i].y ] = step;
  }

  return longest[orig_x][orig_y];
}

int simulate(int x1, int y1, int x2, int y2) {
  int step = 0;
  while (true) {
    int nx1, ny1; int move1 = next(x1, y1, nx1, ny1);
    int nx2, ny2; int move2 = next(x2, y2, nx2, ny2);
    if (grid[nx1][ny1] != '#' && nx1 == nx2 && ny1 == ny2) {
      assert(move1 && move2);
      --step;
      x1 = nx1;
      y1 = ny1;
    } else {
      step += move1 + move2;
      x1 = nx1;
      y1 = ny1;
      x2 = nx2;
      y2 = ny2;
    }
    if (move1 == 0 && move2 == 0) break;
  }    
  return step;
}

int main(void)
{
  scanf("%d %d", &r, &s);
  REP(i, r) scanf("%s", grid[i]);

  memset(longest, 0, sizeof longest);

  struct S { int x, y, c; };
  vector<S> V;

  REP(i, r) REP(j, s) {
    if (grid[i][j] != '#') {
      if (longest[i][j] == 0) {
        if (solve(i, j) == -1) {
          puts("-1");
          return 0;
        }
      }

      V.push_back({i, j, longest[i][j]});
    }
  }

  int best = 0;
  sort(V.begin(), V.end(), [](const S& a, const S& b) {
      return a.c > b.c;
    });
  if (V.size() > 4) V.resize(4);

  int vsz = V.size();
  for (int a = 0; a < vsz; ++a)
    for (int b = a+1; b < vsz; ++b) {
      best = max(best, simulate(V[a].x, V[a].y, V[b].x, V[b].y));
    }

  printf("%d\n", best);
  return 0;
}