#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <queue>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

typedef pair<int, int> point;
#define X first
#define Y second

int dp[21][21][1 << 8];

struct State {
  int X, Y;
  int state;

  int& ref() { return dp[X][Y][state]; }
};

const int MAXN = 123;;

int n_tres = 0;
int n_objs = 0;
int R, S;
char grid[MAXN][MAXN];
vector<point> objs;
vector<char> is_bomb;
vector<int> tres_index;
int tres_value[123];
point start(-1, -1);

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int main(void)
{
  scanf("%d %d", &R, &S);
  REP(i, R) scanf("%s", grid[i]);

  REP(i, R) REP(j, S) {
    if (isdigit(grid[i][j])) {
      ++n_tres;
      ++n_objs;

      objs.push_back(point(i, j));
      is_bomb.push_back(false);
      tres_index.push_back(grid[i][j] - '1');

    } else if (grid[i][j] == 'B') {
      ++n_objs;

      objs.push_back(point(i, j));
      is_bomb.push_back(true);
      tres_index.push_back(-1);

    } else if (grid[i][j] == 'S') {
      start = point(i, j);
      grid[i][j] = '.';
    }
  }

  REP(i, n_tres) scanf("%d", tres_value + i);

  int solution = 0;
  queue<State> Q;
  memset(dp, -1, sizeof dp);
  State source = {start.X, start.Y, 0};
  for (Q.push(source), source.ref() = 0; !Q.empty(); Q.pop()) {
    State ex = Q.front();

    if (ex.X == start.X && ex.Y == start.Y) {
      bool ok = true;
      int val = -ex.ref();

      REP(i, n_objs) {
        if (ex.state&(1<<i)) {
          if (is_bomb[i]) ok = false;
          else val += tres_value[ tres_index[i] ];
        }
      }

      if (ok) solution = max(solution, val);
    }

    REP(pc, 4) {
      State nov = ex;
      nov.X += dx[pc];
      nov.Y += dy[pc];
      if (nov.X < 0 || nov.Y < 0) continue;
      if (nov.X >= R || nov.Y >= S) continue;
      if (grid[nov.X][nov.Y] != '.') continue;

      // promijeni ref
      if (dx[pc] != 0) {
        int r = max(ex.X, nov.X);
        REP(i, n_objs) {
          if (objs[i].X == r && objs[i].Y < ex.Y) {
            nov.state ^= 1<<i;
          }
        }
      }

      if (nov.ref() != -1) continue;
      nov.ref() = ex.ref() + 1;
      Q.push(nov);      
    }
  }

  printf("%d\n", solution);
  return 0;
}