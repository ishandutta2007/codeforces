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

const int inf = 1e9;

struct Tour {
  int offset;
  vector<int> data;
  Tour(int n)  {
    offset = 1; while (offset < n) offset *= 2;
    data.resize(2*offset, inf);
  }

  int get_min(int a, int b) {
    int ans = inf;
    for (a += offset, b += offset; a < b; a >>=1, b >>= 1) {
      if (a&1) ans = min(ans, data[a++]);
      if (b&1) ans = min(ans, data[--b]);
    }
    return ans;
  }

  void update(int x, int val) {
    for (int ptr = x+offset; ptr; ptr /= 2) {
      data[ptr] = min(data[ptr], val);
    }
  }
};

int main(void) {
  int n, maxdiff, minl; scanf("%d %d %d", &n, &maxdiff, &minl);
  Tour maxT(n), minT(n);

  REP(i, n) {
    int x; scanf("%d", &x);
    minT.update(i, x);
    maxT.update(i, -x);
  }

  Tour dp(n+1); dp.update(0, 0);
  FOR(b, minl, n+1) {
    // [b-minl, b>
    if (-maxT.get_min(b-minl, b) - minT.get_min(b-minl, b) > maxdiff) {
      continue;
    }

    int lo = 0, hi = b - minl;
    while (lo < hi) {
      int mid = (lo + hi) / 2;
      if (-maxT.get_min(mid, b) - minT.get_min(mid, b) <= maxdiff)
        hi = mid;
      else
        lo = mid + 1;
    }

    dp.update(b, dp.get_min(lo, b-minl+1) + 1);
  }

  int ans = dp.get_min(n, n+1);

  if (ans >= inf) printf("-1\n");
  else printf("%d\n", ans);

  return 0;
}