#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void)
{
  int n, m; scanf("%d %d", &n, &m);
  for (int x = 1; ; ++x) {
    if (n + x/m == x) {
      printf("%d\n", x);
      break;
    }
  }
  return 0;
}