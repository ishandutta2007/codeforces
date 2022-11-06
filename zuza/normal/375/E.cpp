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

const int MAXN = 500;
const int MAXLOG = 9;

struct Edge { int a, b, w; };

int n, max_dist;
int uplink[MAXLOG][MAXN];
int color[MAXN];
int weight[MAXN];
int depth_01[MAXN];
llint depth_w[MAXN];

vector<Edge> E[MAXN];

void dfs(int x, int d, int dep, llint dep_w) {
  uplink[0][x] = d;
  depth_01[x] = dep;
  depth_w[x] = dep_w;
  weight[x] = 1;
  for (auto e : E[x]) {
    if (e.b == d) continue;
    dfs(e.b, x, dep+1, dep_w + e.w);
    weight[x] += weight[e.b];
  }
}

int lca(int a, int b) {
  if (depth_01[a] > depth_01[b]) swap(a, b);
  int delta = depth_01[b] - depth_01[a];
  REP(i, MAXLOG) if (delta&(1<<i)) b = uplink[i][b];
  if (a == b) return a;

  for (int i = MAXLOG-1; i >= 0; --i)
    if (uplink[i][a] != uplink[i][b]) {
      a = uplink[i][a];
      b = uplink[i][b];
    }
  return uplink[0][a];
}

int get_dist(int a, int b) {
  int g = lca(a, b);
  llint ret = depth_w[a] + depth_w[b] - 2*depth_w[g];
  if (ret > max_dist) return max_dist + 1;
  return (int)ret;
}
const int MAXR = 511;
const int MAXVAR = 511 + MAXR;
const double eps = 1e-8; // 1e-6?

#include <cmath>

struct Simplex {
  double A[MAXR][MAXVAR+1];
  double obj[MAXVAR+1];
  int ones[MAXR];

  double saved[MAXVAR+1];
  double sol[MAXVAR+1];

  int n_r, n_col;

  void mult_row(double* row, double k) {
    REP(j, n_col+1) row[j] *= k;
  }
  void add_row_mult(double* row_b, double* row_a, double mult) {
    REP(j, n_col+1) row_b[j] += row_a[j]*mult;
  }
  void pivot(int r, int c) {
    mult_row(A[r], 1.0 / A[r][c]);
    ones[r] = c;
    REP(i, n_r) {
      if (i != r && A[i][c] != 0)
        add_row_mult(A[i], A[r], -A[i][c]);
    }
    add_row_mult(obj, A[r], -obj[c]);
    add_row_mult(saved, A[r], -saved[c]);
  }
  void move_col(int c2, int c1) {
    REP(i, n_r) { A[i][c2] = A[i][c1]; A[i][c1] = 0; } // { ... }
    obj[c2] = obj[c1]; obj[c1] = 0;
    saved[c2] = saved[c1]; saved[c1] = 0;
  }

  void load() {
    scanf("%d %d", &n_r, &n_col);
    REP(j, n_col+1) scanf("%lf", obj + j);
    REP(i, n_r) {
      REP(j, n_col+1) scanf("%lf", A[i] + j);
      ones[i] = n_r + i;
      mult_row(A[i], 1 / A[i][ones[i]]);
    }
  }

  void debug() {
    printf("saved = "); REP(j, n_col+1) printf("%5.1lf ", saved[j]); putchar('\n');
    printf("obj   = "); REP(j, n_col+1) printf("%5.1lf ", obj[j]); putchar('\n');
    REP(i, n_r) {
      printf("        ");
      REP(j, n_col+1)
        printf("%5.1lf ", A[i][j]);
      putchar('\n');
    }
    printf("ones = "); REP(i, n_r) printf("%d ", ones[i]); putchar('\n');
    putchar('\n');
  }

  double solve_feasible() {
    while (true) {
      int new_one = -1;
      REP(j, n_col) if (obj[j] < -eps) { new_one = j; break; }
      if (new_one == -1) break;

      int row = -1;
      double lim = 1e100;
      REP(i, n_r) {
        if (A[i][new_one] > eps) {
          double val = A[i][n_col] / A[i][new_one];
          if (val < lim) {
            lim = val;
            row = i;
          }
        }
      }
      if (row == -1) return -1e100; // unbounded // !! promjena
      pivot(row, new_one);
    }
    memset(sol, 0, sizeof sol);
    REP(i, n_r) sol[ones[i]] = A[i][n_col];
    return obj[n_col];
  }

  bool get_feasibile() {
    int min_row = -1;
    REP(i, n_r) if (min_row == -1 || A[i][n_col] < A[min_row][n_col]) min_row = i;
    if (A[min_row][n_col] > eps) return true; // basic feasible

    ++n_col;
    REP(i, n_col) saved[i] = obj[i];
    move_col(n_col, n_col-1);

    memset(obj, 0, sizeof obj);
    obj[n_col - 1] = 1;
    REP(i, n_r) A[i][n_col - 1] = -1;

    pivot(min_row, n_col - 1);
    double val = solve_feasible();
    if (val < -eps) return false; // infeasible // !!!! promjena
    REP(i, n_r) {
      if (ones[i] == n_col - 1) {
        int maxj = -1;
        REP(j, n_col) if (maxj == -1 || fabs(A[i][j]) > fabs(A[i][maxj])) maxj = j;
        pivot(i, maxj);
      }
    }

    move_col(n_col-1, n_col);
    REP(i, n_col) obj[i] = saved[i];
    --n_col;
    return true;
  }

  double solve_all() {
    if (!get_feasibile()) return -1e100; // impossible
    return - solve_feasible(); // !!! promjena
  }
} simplex;

int main(void)
{
  scanf("%d %d", &n, &max_dist);
  int sum_c = 0;
  REP(i, n) { scanf("%d", color + i); sum_c += color[i]; }

  REP(i, n-1) {
    int a, b, w; scanf("%d %d %d", &a, &b, &w); --a, --b;
    E[a].push_back((Edge){a, b, w});
    E[b].push_back((Edge){b, a, w});
  }

  memset(uplink, -1, sizeof uplink);
  dfs(0, -1, 0, 0LL);
  for (int l = 1; l < MAXLOG; ++l)
    REP(i, n) {
      int val = uplink[l-1][i];
      if (val != -1) val = uplink[l-1][val];
      uplink[l][i] = val; 
    }

  static Simplex simplex;
  
  int n_r = n + 1;
  int n_var = n;
  int n_col =  n_var + n_r;
  simplex.n_r = n_r;
  simplex.n_col = n_col;

  REP(i, n) { 
    memset(simplex.A[i], 0, sizeof simplex.A[i]);
    REP(j, n) simplex.A[i][j] = - (get_dist(i, j) <= max_dist);
    simplex.A[i][n_var + i] = 1;
    simplex.ones[i] = n_var + i;
    simplex.A[i][n_col] = -1;
  }

  memset(simplex.A[n], 0, sizeof simplex.A[n]);
  REP(i, n) simplex.A[n][i] = 1;
  simplex.A[n][n_var + n] = 1;
  simplex.ones[n] = n_var + n;
  simplex.A[n][n_col] = sum_c;

  memset(simplex.obj, 0, sizeof simplex.obj);
  REP(i, n) simplex.obj[i] = 1 - color[i];

  double sol = simplex.solve_all();
  if (sol < -eps) puts("-1");
  else printf("%d\n", int(sol + 0.5));

  return 0;
}