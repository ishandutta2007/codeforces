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
#define TRACE(x) cout << #x << " = " << x << endl
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define _ << " _ " <<

#ifdef ONLINE_JUDGE
# define LLD "%I64d"
#else
# define LLD "%ll" "d"
#endif

typedef long long llint;

int main(void)
{
  int n, k; scanf("%d %d", &n, &k);
  const int MAXN = 234;
  static int A[MAXN];
  REP(i, n) scanf("%d", A+i);

  const int inf = 1e9;
  int ans = -inf;

  FOR(lo, 0, n+1) FOR(hi, lo+1, n+1) {
    int suma = 0;    
    vector<int> mini, maks;

    FOR(i, 0, n) {
      if (lo <= i && i < hi) {
        mini.push_back(A[i]);
        suma += A[i];
      } else {
        maks.push_back(A[i]);
      }
    }

    sort(mini.begin(), mini.end());
    sort(maks.begin(), maks.end(), greater<int>());
    
    ans = max(ans, suma);
    for (int i = 0; i < (int)mini.size() && i < (int)maks.size() && i < k; ++i) {
      suma -= mini[i];
      suma += maks[i];
      ans = max(ans, suma);
    }
  }

  printf("%d\n", ans);
  return 0;
}