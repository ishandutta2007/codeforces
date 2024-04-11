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

inline int myrand() { return ((rand()&((1<<15)-1)) << 15) ^ (rand()&((1<<15)-1)); }
typedef long long llint;

const int MAXN = 1e5 + 123;

int A[MAXN];

int main(void)
{
  int n, l, r, ql, qr; scanf("%d %d %d %d %d", &n, &l, &r, &ql, &qr);
  int sum = 0;
  REP(i, n) {
    scanf("%d", A+i);
    sum += A[i];
  }

  int mini = 2147483647;
  int sum_l = 0, sum_r = sum;

  for (int num_l = 0; num_l <= n; ++num_l) {
    int num_r = n - num_l;
    mini = min(mini, l*sum_l + r*sum_r + max(0, num_l-num_r-1)*ql + max(0, num_r-num_l-1)*qr);
    // kraj
    if (num_l < n) {
      sum_l += A[num_l];
      sum_r -= A[num_l];
    }
  }

  printf("%d\n", mini);
  return 0;
}