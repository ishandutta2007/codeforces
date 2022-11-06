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
  const int n = 5;
  int A[5][5];
  REP(i, n) REP(j, n) scanf("%d", A[i]+j);
  REP(i, n) REP(j, i) { A[i][j] += A[j][i]; A[j][i] = A[i][j]; }

  int ans = 0;
  vector<int> V; REP(i, n) V.push_back(i);
  do {
    int a = V[0], b = V[1], c = V[2], d = V[3], e = V[4];
    int val = A[a][b] + 2*A[c][d] + A[b][c] + 2*A[d][e];
    ans = max(val, ans);
  } while (next_permutation(V.begin(), V.end()));

  printf("%d\n", ans);
  return 0;
}