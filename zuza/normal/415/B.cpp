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
  int n; llint a, b; scanf("%d " LLD " " LLD, &n, &a, &b);
  REP(i, n) {
    llint x; scanf(LLD, &x);
    printf(LLD "%c", (x*a % b) / a, i+1 == n ? '\n' : ' ');
  }
  return 0;
}