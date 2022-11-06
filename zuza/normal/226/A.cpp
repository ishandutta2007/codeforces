#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

#ifdef ONLINE_JUDGE
# define LLD "%I64d"
#else
# define LLD "%ll" "d"
#endif

typedef long long llint;

int power_mod(int a, int e, int mod) {
  llint p2 = a;
  llint ans = 1;
  for (; e; e >>= 1) {
    if (e&1) ans = ans*p2%mod;
    p2 = p2*p2 % mod;
  }
  return ans;
}

int main(void)
{
  int n, mod; scanf("%d %d", &n, &mod);
  printf("%d\n", (power_mod(3, n, mod) - 1+mod) % mod);
  return 0;
}