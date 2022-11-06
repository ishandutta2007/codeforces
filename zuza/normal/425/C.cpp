#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

#ifdef ONLINE_JUDGE
# define LLD "%I64d"
#else
# define LLD "%ll" "d"
#endif

typedef long long llint;

const int MAXN = 1e5 + 123;
const int MAXK = 500;
const int inf = 1e9;

int na, nb;
int A[MAXN], B[MAXN];
int minb[MAXK];
set<int> idxs[MAXN];

int main(void)
{
  int maxe, e; scanf("%d %d %d %d", &na, &nb, &maxe, &e);
  REP(a, na) { scanf("%d", A+a); }
  REP(b, nb) { scanf("%d", B+b); idxs[B[b]].insert(b); }
  assert(maxe / e < MAXK);

  REP(i, MAXK) minb[i] = inf;
  minb[0] = 0;

  int maxk = maxe / e;

  int ans = 0;
  REP(a, na) {
    for (int k = maxk; k >= 1; --k) {
      assert(k*e <= maxe);
      auto it = idxs[A[a]].lower_bound(minb[k-1]);
      if (it != idxs[A[a]].end()) {
        int bpos = *it+1;
        int cost = a+1+bpos;
        minb[k] = min(minb[k], bpos);
        if (k*e + cost <= maxe) ans = max(ans, k);
      }
    }
  }

  printf("%d\n", ans);
  return 0;
}