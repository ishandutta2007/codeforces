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

int na, nb;
vector<int> A, B;
vector<llint> prefA, prefB;

llint solve(int val) {
  llint ans = 0;

  llint a_lo = lower_bound(A.begin(), A.end(), 1) - A.begin();
  llint a_hi = lower_bound(A.begin(), A.end(), val+1) - A.begin();

  ans += abs((a_hi - a_lo)*val - prefA[a_hi] + prefA[a_lo]);

  llint b_lo = lower_bound(B.begin(), B.end(), val+1) - B.begin();
  llint b_hi = lower_bound(B.begin(), B.end(), 1e9 + 123) - B.begin();
  
  ans += abs((b_hi - b_lo)*val - prefB[b_hi] + prefB[b_lo]);

  return ans;
}

int main(void)
{
  scanf("%d %d", &na, &nb);
  REP(i, na) { int x; scanf("%d", &x); A.push_back(x); }
  REP(i, nb) { int x; scanf("%d", &x); B.push_back(x); }
  sort(A.begin(), A.end()); sort(B.begin(), B.end());

  prefA.resize(na+1, 0); REP(i, na) prefA[i+1] = prefA[i] + A[i];
  prefB.resize(nb+1, 0); REP(i, nb) prefB[i+1] = prefB[i] + B[i];

  llint ans = 1e18;
  for (int x : A) ans = min(ans, solve(x));
  for (int x : B) ans = min(ans, solve(x));
  cout << ans << endl;

  return 0;
}