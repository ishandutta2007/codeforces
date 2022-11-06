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

const int MAXN = 1e5 + 123;

int A[MAXN];
vector<int> E[MAXN];
llint cost[MAXN];

int main(void)
{
  // razlicito !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

  // ans racunaj na prvu

  int maks, n; scanf("%d %d", &maks, &n);
  llint ans = 0;
  memset(cost, 0, sizeof cost);
  
  REP(i, n) {
    scanf("%d", A+i); --A[i];
    if (i) { 
      int a = A[i-1], b = A[i];
      if (a != b) {
        E[a].push_back(b);
        E[b].push_back(a);
        ans += abs(a-b);
        cost[a] += abs(a-b);
        cost[b] += abs(a-b);
      }
    }
  }

  llint orig = ans;
  REP(i, maks) {
    sort(E[i].begin(), E[i].end());
    int sz = E[i].size();
    llint suma = 0; REP(j, sz) suma += E[i][j];
    llint left = 0;
    REP(j, sz) {
      llint val = orig - cost[i] + abs(j*(llint)E[i][j] - left) + abs((suma-left) - (sz-j)*(llint)E[i][j]);
      if (val < ans) ans = val;
      left += E[i][j];
    }
  }
  printf(LLD "\n", ans);  
  return 0;
}