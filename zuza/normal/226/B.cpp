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

int main(void)
{
  const int MAXN = 1e5 + 123;
  static llint A[MAXN];
  static llint pref[MAXN];
  static llint ans[MAXN];

  int n; scanf("%d", &n);
  REP(i, n) scanf(LLD, A+i);
  sort(A, A+n, greater<int>());
  pref[0] = 0; REP(i, n) pref[i+1] = pref[i] + A[i];

  for (int k = 1; k <= n; ++k) {
    llint kol = 1;
    llint dep = 0;
    llint suma = 0;

    for (llint pos = 0; pos < n; ) {
      suma += (pref[min<llint>(n, pos+kol)] - pref[pos]) * dep;
      pos += kol;
      kol *= k;
      ++dep;
    }

    ans[k] = suma;
  }

  int nq; scanf("%d", &nq);
  REP(iq, nq) { 
    int k; scanf("%d", &k); k = min(k, n);
    printf(LLD "\n", ans[k]);
  }

  return 0;
}