#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

llint solve(vector<llint>& A, vector<llint>& B) {
  int na = A.size();
  int nb = B.size();

  const llint MAXN = 5e5 + 123;
  static llint prefixA[MAXN];
  static llint prefixB[MAXN];

  REP(i, na+1) prefixA[i] = i==0 ? 0 : prefixA[i-1] + A[i-1];
  REP(i, nb+1) prefixB[i] = i==0 ? 0 : prefixB[i-1] + B[i-1];

  llint ans = 0;
  if (na-1 >= 0) ans += prefixA[na-1];
  if (nb-1 >= 0) ans += prefixB[nb-1];
  
  llint add = 0;
  while (!A.empty() && !B.empty()) {
    if (A.back() > B.back()) {
      add += B.back();
      A.pop_back();
    } else {
      add += A.back();
      B.pop_back();
    }

    int szA = A.size(), szB = B.size();
    llint val = add + prefixA[szA-1] + prefixB[szB-1];
    ans = max(ans, val);
  }

  return ans;
}

int main(void)
{
  int n; scanf("%d", &n);

  vector<llint> stk;

  llint add = 0; // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ add
  llint maks = 0; // el

  REP(iter, n) {
    llint x; scanf("%lld", &x);

    while (!stk.empty() && maks > stk.back() && stk.back() < x) {
      assert(stk.size() >= 2);
      stk.pop_back();
      add += min(x, stk.back());
    }

    stk.push_back(x);
    maks = max(maks, x);
  }

  sort(stk.begin(), stk.end());
  for (int i = 0; i < (int)stk.size() - 2; ++i)
    add += stk[i];
  printf("%lld\n", add);
  return 0;
}