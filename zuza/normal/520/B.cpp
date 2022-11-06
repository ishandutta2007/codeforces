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

int main(void) {
  int a, b; scanf("%d %d", &a, &b);
  int step = 0;
  while (a != b) {
    if (b < a) ++b, ++step;
    else if (b%2 == 0) b /= 2, ++step;
    else ++b, ++step;
  }
  printf("%d\n", step);
  return 0;
}