#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <set>
#include <map>

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
int R, S;
set<int> blocked[MAXN];
map<int, set<int> > x_suma;
map<int, set<int> > x_diff;

bool is_blocked(int x, int y) {
  if (x < 0 || y < 0 || x >= R || y >= S) return true;
  return blocked[x].count(y);
}

void push_diag(int x, int y) {
  x_suma[x+y].insert(x);
  x_diff[x-y].insert(x);
}

struct State {
  int x, y;
  int dx, dy;

  friend bool operator < (State a, State b) {
    return make_tuple(a.x, a.y, a.dx, a.dy) < make_tuple(b.x, b.y, b.dx, b.dy);
  }
};

State one_step(State s, llint& steps) {
  int dx = s.dx, dy = s.dy, x = s.x, y = s.y;
  steps = 0;

  if (dx+dy == 0) {
    auto it = x_suma[x+y].lower_bound(x);
    if (dx == -1) { assert(it != x_suma[x+y].begin()); --it; }
    steps = abs(x - *it) - 1;
  } else if (dx-dy == 0) {
    auto it = x_diff[x-y].lower_bound(x);
    if (dx == -1) { assert(it != x_diff[x-y].begin()); --it; }
    steps = abs(x - *it) - 1;
  } else assert(false);

  int ndx = dx, ndy = dy;
  int nx = x + steps*dx, ny = y + steps*dy;

  assert(is_blocked(nx+dx, ny+dy));
  if (is_blocked(nx, ny+dy) && is_blocked(nx+dx, ny)) { ndx = -ndx; ndy = -ndy; }
  else if (is_blocked(nx, ny+dy)) { ndy = -ndy; nx += dx; }
  else if (is_blocked(nx+dx, ny)) { ndx = -ndx; ny += dy; }
  else { ndx = -ndx; ndy = -ndy; }

  ++steps;
  return { nx, ny, ndx, ndy };
}

bool solve_until_cycle(State start, llint& ans) {
  set<State> seen;
  ans = 0;

  State s = start; // ne koristi start!
  while (seen.insert(s).second) {
    llint val; State nov = one_step(s, val);
    ans += val;
    if (s.dx == -nov.dx && s.dy == -nov.dy) return false;
    s = nov;
  }

  return true;
}

int main(void)
{
  int nblocked; scanf("%d %d %d", &R, &S, &nblocked);
  REP(i, nblocked) {
    int x, y; scanf("%d %d", &x, &y); --x, --y;
    blocked[x].insert(y);
    push_diag(x, y);
  }
  REP(i, R) {
    push_diag(i, -1);
    push_diag(i, S);
  }
  FOR(j, -1, S+1) {
    push_diag(-1, j);
    push_diag(R, j);
  }

  int sx, sy; char tmp[123]; scanf("%d %d %s", &sx, &sy, tmp); --sx, --sy; string dir = tmp;
  int dx = -2, dy = -2;
  if (dir == "NE") { dx = -1; dy = +1; }
  if (dir == "SE") { dx = +1; dy = +1; }
  if (dir == "SW") { dx = +1; dy = -1; }
  if (dir == "NW") { dx = -1; dy = -1; }

  llint ign;
  State start = one_step({sx, sy, dx, dy}, ign);
  llint val;
  llint ans = 0;
  if (solve_until_cycle(start, val)) ans = val;
  else {
    ans = val;
    start = {start.x, start.y, -start.dx, -start.dy};
    solve_until_cycle(start, val);
    ans += val - 1;
  }

  printf(LLD "\n", ans);
  return 0;
}