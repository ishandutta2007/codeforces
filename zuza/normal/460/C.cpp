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

const int MAXN = 1e5 + 123;

int n, d, w;
int A[MAXN];

bool check(llint h) {
  llint sum = 0;
  llint left = d;
  static llint raise[MAXN];

  REP(i, n) {
    if (i-w >= 0) sum -= raise[i-w];
    llint x = max(0ll, h - A[i] - sum);
    left -= x;
    raise[i] = x;
    sum += x;
  }

  return left >= 0;
}

int main(void) {
  scanf("%d %d %d", &n, &d, &w);
  REP(i, n) scanf("%d", A+i);

  llint lo = 1, hi = 2e9;
  while (lo < hi) {
    llint mid = lo + (hi-lo+1) / 2;
    if (check(mid))
      lo = mid;
    else
      hi = mid - 1;
  }
  printf("%lld\n", lo);
  return 0;
}