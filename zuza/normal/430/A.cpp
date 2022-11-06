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
  struct Pt { int x, idx, color; };
  int n; scanf("%d %*d", &n);
  static Pt pts[123];
  REP(i, n) {
    int x; scanf("%d", &x); 
    pts[i] = {x, i, -1};
  }
  sort(pts, pts+n, [](Pt a, Pt b) { return a.x < b.x; });
  REP(i, n) pts[i].color = i%2;
  sort(pts, pts+n, [](Pt a, Pt b) { return a.idx < b.idx; });
  REP(i, n) printf("%d%c", pts[i].color, i+1 == n ? '\n' : ' ');
  return 0;
}