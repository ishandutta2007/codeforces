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

const int MAXN = 45;

int R, S;
int A[MAXN][MAXN];
int q[MAXN][MAXN][MAXN][MAXN];

int main(void)
{
  int n_q; scanf("%d %d %d", &R, &S, &n_q);

  REP(r, R+1) REP(s, S+1) A[r][s] = 0;
  REP(r, R) REP(s, S) scanf("%1d", &A[r+1][s+1]);
  REP(r, R) {
    REP(s, S) A[r+1][s+1] += A[r+1][s];
    REP(s, S) A[r+1][s+1] += A[r][s+1];
  }

  memset(q, 0, sizeof q);
  for (int dx = 1; dx <= R; ++dx)
    for (int dy = 1; dy <= S; ++dy) {
      REP(x1, R-dx+1) REP(y1, S-dy+1) {
        int x2 = x1 + dx;
        int y2 = y1 + dy;
        q[x1][x2][y1][y2] =
          + (A[x2][y2] - A[x1][y2] - A[x2][y1] + A[x1][y1] == 0)
          + q[x1+1][x2][y1][y2] + q[x1][x2][y1+1][y2]
          + q[x1][x2-1][y1][y2] + q[x1][x2][y1][y2-1]
          - q[x1+1][x2-1][y1][y2] - q[x1+1][x2][y1+1][y2] - q[x1+1][x2][y1][y2-1]
          - q[x1][x2-1][y1+1][y2] - q[x1][x2-1][y1][y2-1] - q[x1][x2][y1+1][y2-1]
          + q[x1+1][x2-1][y1+1][y2] + q[x1+1][x2-1][y1][y2-1]
          + q[x1+1][x2][y1+1][y2-1] + q[x1][x2-1][y1+1][y2-1]
          - q[x1+1][x2-1][y1+1][y2-1];
      }
    }
  
  REP(cs, n_q) {
    int x1, y1, x2, y2; scanf("%d %d %d %d", &x1, &y1, &x2, &y2); --x1, --y1;
    printf("%d\n", q[x1][x2][y1][y2]);
  }

  return 0;
}