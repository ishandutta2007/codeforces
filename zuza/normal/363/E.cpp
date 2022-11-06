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

inline int myrand() { return ((rand()&((1<<15)-1)) << 15) ^ (rand()&((1<<15)-1)); }
typedef long long llint;

const int MAXN = 519;

int R, S;
int grid[MAXN][MAXN];
int SQRT[MAXN*MAXN];

pair<int, int> get_interval(int cx, int cy, int rsq, int Y) {
  int dx2lim = rsq - (cy-Y)*(cy-Y);
  if (dx2lim < 0) return make_pair(0, 0);

  int dx = SQRT[dx2lim];
  return make_pair(max(0, cx - dx), min(cx + dx + 1, R));
}

int prefixY[MAXN][MAXN];
int center_val[MAXN][MAXN];

int best_cv_up[MAXN][MAXN];
int cnt_cv_up[MAXN][MAXN];

int best_cv_down[MAXN][MAXN];
int cnt_cv_down[MAXN][MAXN];

inline int sqr(int x) { return x*x; }

pair<int, int> get_intersecting(int cx, int cy, int rsq, int Y) {
  auto par = get_interval(cx, cy, 2*2*rsq, Y);

  auto test_it = [cx, cy, Y, rsq](int X) {
    bool ret = false;

    int dx = abs(cx-X);
    int dy = abs(cy-Y);

    if (dx < dy) swap(dx, dy);

    int dx1 = (dx+1)/2;
    int dx2 = dx - dx1;

    int aval_y1 = rsq - dx1*dx1 < 0 ? -1e9 : SQRT[rsq - dx1*dx1];
    int aval_y2 = rsq - dx2*dx2 < 0 ? -1e9 : SQRT[rsq - dx2*dx2];

    if (aval_y1 + aval_y2 >= dy)
      ret = true;
    return ret;
  };

  while (par.first < par.second && !test_it(par.first)) {
    ++par.first;
  }
  while (par.first < par.second && !test_it(par.second-1)) {
    --par.second;
  }

  return par;
}

int main(void)
{
  for (int r = 0; r <= MAXN*MAXN; ++r) {
    int tmp = SQRT[r] = int(sqrt(r) + 1e-8);
    assert(tmp*tmp <= r);
    assert((tmp+1)*(tmp+1) > r);
  }

  int r; scanf("%d %d %d", &R, &S, &r);
  r = min(r, min(R, S));

  REP(r, R) REP(s, S) scanf("%d", grid[r]+s);
  REP(s, S) {
    prefixY[0][s] = 0;
    REP(r, R) prefixY[r+1][s] = prefixY[r][s] + grid[r][s];
  }

  REP(r, R) REP(s, S) center_val[r][s] = -1e9;
  for (int x = r; x < R-r; ++x)
    for (int y = r; y < S-r; ++y) {

      int suma = 0;
      for (int s = 0; s < S; ++s) {
        auto par = get_interval(x, y, r*r, s);
        suma += prefixY[par.second][s] - prefixY[par.first][s];
      }

      center_val[x][y] = suma;
    }

  REP(s, S) {
    best_cv_up[0][s] = -1e9;
    cnt_cv_up[0][s] = 0;

    for (int x = 0; x < R; ++x) {
      int tmp = center_val[x][s];
      int& ref = best_cv_up[x+1][s];
      int& cnt = cnt_cv_up[x+1][s];
      
      ref = best_cv_up[x][s];
      cnt = cnt_cv_up[x][s];
      if (tmp > ref) {
        ref = tmp;
        cnt = 1;
      } else if (tmp == ref) {
        ++cnt;
      }
    }

    best_cv_down[R][s] = -1e9;
    cnt_cv_down[R][s] = 0;

    for (int x = R-1; x >= 0; --x) {
      int tmp = center_val[x][s];
      int& ref = best_cv_down[x][s];
      int& cnt = cnt_cv_down[x][s];

      ref = best_cv_down[x+1][s];
      cnt = cnt_cv_down[x+1][s];
      if (tmp > ref) {
        ref = tmp;
        cnt = 1;
      } else if (tmp == ref) {
        ++cnt;
      }
    }
  }

  int best_val = 0;
  llint cnt_best = 0;

  for (int cx1 = r; cx1 < R-r; ++cx1)
    for (int cy1 = r; cy1 < S-r; ++cy1) {
      for (int cy2 = r; cy2 < S-r; ++cy2) {
        auto par = get_intersecting(cx1, cy1, r*r, cy2);
        par.first = max(par.first, r);
        par.second = min(par.second, R-r+1);

        auto combine = [&best_val, &cnt_best](int val, int cnt) {
          if (val > best_val) {
            best_val = val;
            cnt_best = cnt;
          } else if (val == best_val) {
            cnt_best += cnt;
          }
        };

        combine(center_val[cx1][cy1] + best_cv_up[par.first][cy2], cnt_cv_up[par.first][cy2]);
        combine(center_val[cx1][cy1] + best_cv_down[par.second][cy2], cnt_cv_down[par.second][cy2]);

        // printf("center1 = (%d, %d) Y = %d -> par = [%d, %d> cnts = %d %d CNT = %lld\n", cx1, cy1, cy2, par.first, par.second,
        //        cnt_cv_up[par.first][cy2] * (best_cv_up[par.first][cy2] == 0), cnt_cv_down[par.second][cy2] * (best_cv_down[par.second][cy2] == 0),
        //        cnt_best);
      }
    }

  assert(cnt_best % 2 == 0);
  cout << best_val << " " << (cnt_best / 2) << endl;
  return 0;
}