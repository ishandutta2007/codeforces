#include <cassert>
#include <cstring>

#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  llint mod; scanf("%lld", &mod);

  llint h1, a1, x1, y1; 
  scanf("%lld %lld %lld %lld", &h1, &a1, &x1, &y1);

  llint h2, a2, x2, y2; 
  scanf("%lld %lld %lld %lld", &h2, &a2, &x2, &y2);

  int steps = 2*mod + 2;
  vector<llint> X(steps), Y(steps);
  vector<llint> goodA, goodB;

  X[0] = h1; Y[0] = h2;
  FOR(i, 1, steps) {
    X[i] = (x1*X[i-1] + y1) % mod;
    Y[i] = (x2*Y[i-1] + y2) % mod;
    if (X[i] == a1) goodA.push_back(i);
    if (Y[i] == a2) goodB.push_back(i);
  }

  const llint inf = 1e18;
  llint ans = inf;

  auto testit = [&](llint t) {
    if (X[t] == a1 && Y[t] == a2)
      ans = min(ans, t);
  };

  for (auto t : goodA) testit(t);
  for (auto t : goodB) testit(t);

  if (goodA.size() >= 2 && goodB.size() >= 2) {
    llint a = goodA[0], M = goodA[1] - goodA[0];
    llint b = goodB[0], N = goodB[1] - goodB[0];

    REP(k, 2*N+2) {
      if ((a + k*M - b) % N == 0)
        if (a + k*M >= b)
          ans = min(ans, a+k*M);
    }
  }

  if (ans >= inf) puts("-1");
  else printf("%lld\n", ans);

  return 0;
}