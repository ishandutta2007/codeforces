#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;

typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

int main(void)
{
  int n, e; scanf("%d %d", &n, &e);

  const int MAXN = 512;
  static int vval[MAXN];
  REP(i, n) scanf("%d", vval+i);

  double ans = 0;
  REP(i, e) {
    int a, b, w; scanf("%d %d %d", &a, &b, &w); --a, --b;
    double val = (vval[a] + vval[b]) / 1. / w;
    ans = max(ans, val);
  }

  printf("%.12lf\n", ans);
  return 0;
}