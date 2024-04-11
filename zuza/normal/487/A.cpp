#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  int hy, ay, dy; scanf("%d %d %d", &hy, &ay, &dy);
  int hm, am, dm; scanf("%d %d %d", &hm, &am, &dm);
  int ch, ca, cd; scanf("%d %d %d", &ch, &ca, &cd);

  int ans = 1e9;

  for (int add_ay = 0; add_ay <= 500; ++add_ay) {
    int dmg_y = ay + add_ay - dm;
    if (dmg_y <= 0) continue;

    int A = (hm + dmg_y-1) / dmg_y;
    int cost = add_ay * ca;
    int dmg = am - dy;

    REP(ih, 10000)
      if (hy + ih - A*(llint)(dmg) > 0) {
        ans = min(ans, cost + ih*ch);
      }

    REP(id, 10000) {
      if (hy - A*(llint)(dmg - id) > 0) {
        ans = min(ans, cost + id*cd);
      }
    }
  }

  printf("%d\n", ans);
  return 0;
}