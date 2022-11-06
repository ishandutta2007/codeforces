#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

int main(void)
{
  int n; scanf("%d", &n);
  const int MAXN = 1e3 + 123;
  static int A[MAXN];
  REP(i, n) {
    scanf("%d", A+i);
  }
  int l = 0, r = n;
  int sum[2] = {0};
  int step = 0;
  while (l < r) {
    if (A[l] > A[r-1]) {
      sum[step&1] += A[l];
      ++l;
    } else {
      sum[step&1] += A[r-1];
      --r;
    }
    ++step;
  }
  printf("%d %d\n", sum[0], sum[1]);
  return 0;
}