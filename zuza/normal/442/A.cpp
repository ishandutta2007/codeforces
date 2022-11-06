#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void)
{
  int n; scanf("%d", &n);
  int cards[102][2];

  REP(i, n) {
    char ac, bc; scanf(" %c %c", &ac, &bc);
    int a = string("RGBYW").find(ac);
    int b = bc - '1';
    cards[i][0] = a; cards[i][1] = b;
  }

  auto check = [&](int a, int b, int s) {
    if (a == b) return false;
    if (((s>>a)&1) || ((s>>b)&1)) return true;
    return false;
  };

  int ans = 1e9;
  REP(s1, 1<<5) REP(s2, 1<<5) {
    bool ok = true;
    REP(i, n) FOR(j, i+1, n) if (cards[i][0] != cards[j][0] || cards[i][1] != cards[j][1]) {
      if (!check(cards[i][0], cards[j][0], s1) && !check(cards[i][1], cards[j][1], s2))
        ok = false;
    }
    if (ok) {
      ans = min<int>(ans, __builtin_popcount(s1) + __builtin_popcount(s2));
    }
  }

  printf("%d\n", ans);
  return 0;
}