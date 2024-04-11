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

int main(void)
{
  int n, e; scanf("%d %d", &n, &e);
  vector<int> A(n);
  REP(i, n) scanf("%d", &A[i]);

  int ans = 0;
  REP(i, e) {
    int a, b; scanf("%d %d", &a, &b); --a, --b;
    ans += min(A[a], A[b]);
  }
  printf("%d\n", ans);
  return 0;
}