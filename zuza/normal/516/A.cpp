#include <cassert>
#include <cstring>

#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

llint fakt(int x) {
  llint ans = 1;
  REP(i, x) ans *= i+1;
  return ans;
}

int main(void) {
  int n; scanf("%d", &n);
  char buff[123]; scanf("%s", buff);

  int frek[10] = {0};

  REP(i, n) {
    int d = buff[i] - '0';
    llint p = fakt(d);    

    for (int f = 2; f <= 7; ++f)
      while (p%f == 0) {
        ++frek[f];
        p /= f;
      }
  }

  for (int i = 9; i >= 2; --i) {
    while (frek[i] > 0) {
      printf("%d", i);
      llint p = fakt(i);

      for (int j = 2; j <= 9; ++j) {
        while (p%j == 0) {
          p /= j;
          --frek[j];
        }
      }

    }
  }
  putchar('\n');

  return 0;
}