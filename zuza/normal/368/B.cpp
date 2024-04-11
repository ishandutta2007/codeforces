#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

int main(void)
{
  int n_a, n_q; scanf("%d %d", &n_a, &n_q);
  const int MAXN = 1e5 + 123;
  static int A[MAXN];
  static int Res[MAXN];
  REP(i, n_a) scanf("%d", A+i);

  set<int> S;
  for (int i = n_a - 1; i >= 0; --i) {
    S.insert(A[i]);
    Res[i] = (int)S.size();
  }

  REP(i, n_q) {
    int x; scanf("%d", &x); --x;
    printf("%d\n", Res[x]);
  }
  
  return 0;
}