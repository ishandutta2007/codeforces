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
  vector<int> cs;
  int n, x; scanf("%d %d", &n, &x);
  REP(i, n) {
    int c; scanf("%d", &c);
    cs.push_back(c);
  }

  sort(cs.begin(), cs.end());
  llint ans = 0;
  REP(i, n) {
    ans += max<llint>(1, x-i) * cs[i];
  }
  cout << ans << endl;

  return 0;
}