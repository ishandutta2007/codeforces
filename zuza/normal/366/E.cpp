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

int main(void)
{
  const int MAXK = 9;

  int R, S; scanf("%d %d", &R, &S);
  int k, n_notes; scanf("%d %d", &k, &n_notes);

  const int inf = 1e9;
  static int msuma[MAXK][4]; REP(a, MAXK) REP(b, 4) msuma[a][b] = -inf;
  static bool adj[MAXK][MAXK] = {{0}};

  REP(r, R) REP(s, S) {
    int x; scanf("%d", &x); --x;
    REP(a, 4) {
      int val = 0;
      val += ((a&1) ? -1 : +1) * r;
      val += ((a&2) ? -1 : +1) * s;
      msuma[x][a] = max(msuma[x][a], val);
    }
  }
  int last = -1;
  REP(i, n_notes) {
    int x; scanf("%d", &x); --x;
    if (i > 0) adj[last][x] = true;
    last = x;
  }

  int maks = 0;
  REP(a, k) REP(b, k) if (adj[a][b]) {
    REP(state, 4) maks = max(maks, msuma[a][state] + msuma[b][(~state)&3]);
  }

  printf("%d\n", maks);
  return 0;
}