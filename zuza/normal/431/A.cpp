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
  int a[4]; REP(i, 4) scanf("%d", a+i);
  int suma = 0;
  char buff[123123]; scanf("%s", buff);
  for (char* p = buff; *p; ++p) {
    suma += a[ *p-'1' ];
  }
  printf("%d\n", suma);
  return 0;
}