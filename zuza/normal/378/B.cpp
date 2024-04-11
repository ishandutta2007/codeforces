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
  struct S { int w, t, idx; };

  const int MAXN = 1e5 + 123;
  static S A[2*MAXN];

  int n; scanf("%d", &n); // !!!
  int cnt = 0;

  REP(i, n) {
    int a, b; scanf("%d %d", &a, &b);
    A[cnt++] = {0, a, i};
    A[cnt++] = {1, b, i};
  }
  sort(A, A+cnt, [](S a, S b) {
      return a.t < b.t;
    });

  static int res[2][MAXN] = {0};
  int pol = n / 2;
  REP(i, pol) res[0][i] = res[1][i] = true;
  REP(i, n) res[A[i].w][A[i].idx] = true;

  REP(i, 2) { REP(j, n) printf("%d", res[i][j]); putchar('\n'); }
  return 0;
}