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

#ifdef ONLINE_JUDGE
# define LLD "%I64d"
#else
# define LLD "%ll" "d"
#endif

typedef long long llint;

const int MAXN = 1e5 + 123;
const int MAXLOG = 18;

llint X[MAXN];
llint Y[MAXN];
int rptr[MAXN];
int uplink[MAXLOG][MAXN];
int dep[MAXN];

inline bool ccw(llint x1, llint y1, llint x2, llint y2, llint x3, llint y3) {
  return (x3-x1)*(y2-y1) < (y3-y1)*(x2-x1);
}

int climb(int a, int kol) {
  for (int it = 0; kol; kol >>= 1, ++it) {
    if (kol&1) a = uplink[it][a];
    assert(a != -1);
  }
  return a;
}

int lca(int a, int b) {
  if (dep[a] < dep[b]) swap(a, b);
  a = climb(a, dep[a] - dep[b]);
  if (a == b) return a;

  for (int g = MAXLOG-1; g >= 0; --g) {
    if (uplink[g][a] != uplink[g][b]) {
      a = uplink[g][a];
      b = uplink[g][b];
    }
  }

  return uplink[0][a];
}

int main(void)
{
  int n; scanf("%d", &n);
  REP(i, n) {
    llint x, y; scanf(LLD " " LLD, &x, &y);
    X[i] = x;
    Y[i] = y;
  }

  rptr[n-1] = -1;
  memset(uplink, -1, sizeof uplink);

  for (int i = n-2; i >= 0; --i) { // pazi -1!!
    rptr[i] = i+1;

    while (true) {
      int j = rptr[i];
      if (j == -1) break;
      int k = rptr[j];
      if (k == -1) break;

      if (ccw(X[i], Y[i], X[j], Y[j], X[k], Y[k])) {
        rptr[i] = k;
      } else {
        break;
      }
    }

    uplink[0][i] = rptr[i];
  }

  dep[n-1] = 0;
  for (int i = n-2; i >= 0; --i) {
    assert(rptr[i] != -1);
    dep[i] = dep[rptr[i]] + 1;
  }

  //  REP(i, n) printf("uplink[0][%d] = %d\n", i, uplink[0][i]);

  for (int g = 1; g < MAXLOG; ++g) {
    REP(i, n) {
      int val = uplink[g-1][i];
      if (val != -1) val = uplink[g-1][val];
      uplink[g][i] = val;
    }
  }

  int n_q; scanf("%d", &n_q);
  REP(i_q, n_q) {
    int a, b; scanf("%d %d", &a, &b); --a, --b;
    printf("%d%c", lca(a, b) + 1, i_q+1 == n_q ? '\n' : ' ');
  }

  return 0;
}