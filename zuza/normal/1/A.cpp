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

int main(void) {
  int n, m, a; scanf("%d %d %d", &n, &m, &a);
  long long int x = (n + a - 1) / a, y = (m + a - 1) / a;  
  printf("%lld\n", x*y);
  return 0;
}