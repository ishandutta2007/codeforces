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
  const int MAXN = 123;
  static int A[MAXN][MAXN];
  static int rsum[MAXN]; memset(rsum, 0, sizeof rsum);
  static int csum[MAXN]; memset(csum, 0, sizeof csum);
  static int rneg[MAXN]; memset(rneg, 0, sizeof rneg);
  static int cneg[MAXN]; memset(cneg, 0, sizeof cneg);

  auto neg = [](int a, int b) {
    int val = A[a][b];
    rsum[a] -= 2*val;
    csum[b] -= 2*val;
    A[a][b] = -val;
  };
  auto print_out = [](int a[], int n) {
    int sum = 0;
    REP(i, n) sum += a[i];
    printf("%d", sum);
    REP(i, n) if (a[i]) printf(" %d", i+1); 
    putchar('\n');
  };

  int r, s; scanf("%d %d", &r, &s);
  REP(i, r) REP(j, s) scanf("%d", A[i]+j);
  REP(i, r) REP(j, s) rsum[i] += A[i][j];
  REP(i, r) REP(j, s) csum[j] += A[i][j];

  bool ch = false;
  do {
    ch = false;
    REP(i, r) if (rsum[i] < 0) {
      REP(j, s) neg(i, j);
      rneg[i] ^= 1;
      ch = true;
    }
    REP(j, s) if (csum[j] < 0) {
      REP(i, r) neg(i, j);
      cneg[j] ^= 1;
      ch = true;
    }
  } while (ch);

  print_out(rneg, r);
  print_out(cneg, s);

  return 0;
}