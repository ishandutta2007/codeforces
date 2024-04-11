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
  int n, d; scanf("%d %d", &n, &d);
  int jokes = 2*n - 2;

  int suma = -10;
  REP(i, n) {
    int t; scanf("%d", &t);
    suma += t + 10;
  }
  if (suma > d) { puts("-1"); return 0; }
  jokes += (d - suma) / 5;

  printf("%d\n", jokes);
  return 0;
}