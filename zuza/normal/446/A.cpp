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
  const int MAXN = 1e5 + 123;

  int n; scanf("%d", &n);
  static int A[MAXN];
  REP(i, n) scanf("%d", A+i);

  static int left[MAXN]; left[0] = 1;
  FOR(i, 1, n) {
    left[i] = 1;
    if (A[i-1] < A[i]) left[i] = left[i-1] + 1;
  }

  // -A[i] pazi
  static int right[MAXN];
  for (int i = n-1; i >= 0; --i) {
    right[i] = 1;
    if (A[i] < A[i+1]) right[i] = right[i+1] + 1;
  }

  int ans = 1;
  if (n > 1) ans = max(ans, 1+right[1]);
  if (n > 1) ans = max(ans, 1+left[n-2]);
  FOR(i, 1, n-1) {
    if (A[i+1] - A[i-1] >= 2) {
      ans = max(ans, left[i-1] + 1 + right[i+1]);
    }
    ans = max(ans, 1+right[i+1]);
    ans = max(ans, 1+left[i-1]);
  }
  
  printf("%d\n", ans);
  return 0;
}