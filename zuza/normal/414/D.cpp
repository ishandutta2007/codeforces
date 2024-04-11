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

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

#ifdef ONLINE_JUDGE
# define LLD "%I64d"
#else
# define LLD "%ll" "d"
#endif

typedef long long llint;

const int MAXN = 1e5 + 123;

vector<int> E[MAXN];
int dep[MAXN];

void dfs(int x, int dad, int d) {
  ++dep[d];
  for (int b : E[x]) {
    if (b == dad) continue;
    dfs(b, x, d+1);
  }
}

int main(void)
{
  int n, k, p; scanf("%d %d %d", &n, &k, &p);
  REP(i, n-1) {
    int a, b; scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  dfs(0, -1, 0);

  static llint pref_a[MAXN]; pref_a[0] = 0;
  static llint pref_ai[MAXN]; pref_ai[0] = 0;

  REP(i, n) {
    pref_a[i+1] = pref_a[i] + dep[i];
    pref_ai[i+1] = pref_ai[i] + i*dep[i];
  }

  int best = 0;

  for (int hi = 1; hi < n; ++hi) {
    int bs_lo = 1, bs_hi = hi+1;

    auto get_cost = [hi](int lo) -> llint {
      llint a = hi * (pref_a[hi+1] - pref_a[lo]);
      llint b = pref_ai[hi+1] - pref_ai[lo];
      return a - b;
    };

    while (bs_lo < bs_hi) {
      int mid = (bs_lo + bs_hi) / 2;
      llint cost = get_cost(mid);
      if (cost > p)
        bs_lo = mid + 1;
      else
        bs_hi = mid;
    }

    int lo = bs_lo;

    //    printf("lo = %d hi = %d\n", lo, hi);

    llint cost = get_cost(lo);
    int used = pref_a[hi+1] - pref_a[lo];
    
    if (lo-1 > 0) {
      int unit = hi - (lo-1);
      int add = (p - cost) / unit;
      add = min(add, dep[lo-1]);

      used += add;
      cost += unit*add;
    }

    assert(cost <= p);
    best = min(k, max(best, used));
  }

  printf("%d\n", best);
  return 0;
}