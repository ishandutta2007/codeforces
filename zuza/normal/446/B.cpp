#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <set>
#include <functional>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

vector<llint> calc(vector<llint>& val, llint delta, int nops) {
  vector<llint> ans; ans.push_back(0);
  multiset<llint, greater<llint> > pq(val.begin(), val.end());

  llint acc = 0;
  REP(iops, nops) {
    llint x = *pq.begin(); pq.erase(pq.begin());
    acc += x;
    ans.push_back(acc);
    pq.insert(x + delta);
  }

  return ans;
}

int main(void) {
  int R, C; scanf("%d %d", &R, &C);
  int nops; llint p; scanf("%d %lld", &nops, &p);

  vector<llint> rsum(R, 0), csum(C, 0);
  REP(i, R) REP(j, C) {
    llint x; scanf("%lld", &x);
    rsum[i] += x;
    csum[j] += x;
  }

  vector<llint> takeR = calc(rsum, -p*C, nops);
  vector<llint> takeC = calc(csum, -p*R, nops);

  const llint inf = 1e18;
  llint ans = -inf;
  for (int tr = 0; tr <= nops; ++tr) {
    llint val = takeR[tr] + takeC[nops - tr] - tr * (llint)(nops - tr) * p;
    ans = max(ans, val);
  }

  printf("%lld\n", ans);
  return 0;
}