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

#ifdef ONLINE_JUDGE
# define LLD "%I64d"
#else
# define LLD "%ll" "d"
#endif

typedef long long llint;

int main(void)
{
  int n; scanf("%d", &n);
  const int MAXN = 123;
  static int red[MAXN] = {0};
  REP(i, n) {
    int x; scanf("%d", &x);
    for (int j = 1; j <= x; ++j) ++red[j];
  }

  REP(i, n) {
    int kol = 0; for (int j = 0; j < MAXN; ++j) kol += (red[j] >= n-i);
    printf("%d%c", kol, i+1 == n ? '\n' : ' ');
  }

  return 0;
}