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
  int n, b, d; scanf("%d %d %d", &n, &b, &d);

  int maxg = n;
  REP(i, d) maxg = (maxg + b-1) / b;

  if (maxg > 1) puts("-1");
  else {
    const int MAXN = 1e3 + 123;
    static int nd2b[MAXN][MAXN];

    REP(in, n) {
      int tmp = in;
      REP(id, d) {
        nd2b[in][id] = tmp%b;
        tmp = tmp/b;
      }
    }

    REP(id, d) {
      REP(in, n) printf("%d%c", nd2b[in][id]+1, in+1 == n ? '\n' : ' ');
    }
  }

  return 0;
}