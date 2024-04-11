#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

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

const int MAXN = 24;

int n;
int A[MAXN];

bool solve(int used, int build, int need, int nc, int bidx, int work) {
  if (need == -1) {
    REP(i, n) if (build&(1<<i)) {
      return solve(used, build^(1<<i), A[i]-1, 0, i, 0);
    }
    if (used == (1<<n)-1) return true; // sve iskoristili?
    return false;
  }

  if (work == n) {
    if (need != 0) return false;
    if (nc == 1) return false;
    return solve(used, build, -1, -1, -1, -1);
  }
  if (~used&(1<<work) && need-A[work] >= 0)  {
    if (solve(used|(1<<work), build|(1<<work), need-A[work], nc+1, bidx, work+1))
      return true;
    while (work+1 < n && A[work+1] == A[work]) ++work;
  }

  if (solve(used, build, need, nc, bidx, work+1))
    return true;
  return false;
}

int main(void)
{
  scanf("%d", &n); REP(i, n) scanf("%d", A+i); sort(A, A+n, greater<int>());

  if (A[0] == n && solve(1, 1, -1, -1, -1, -1))
    puts("YES");
  else
    puts("NO");
  return 0;
}