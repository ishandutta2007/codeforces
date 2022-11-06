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

inline int myrand() { return ((rand()&((1<<15)-1)) << 15) ^ (rand()&((1<<15)-1)); }
typedef long long llint;

const int MAXN = 1e5 + 123;

int idx[MAXN];
int last[MAXN];
char bitcnt[1 << 20];
bool bad[1 << 20];

int main(void)
{
  int n_n, n_s, d; scanf("%d %d %d", &n_n, &n_s, &d);
  REP(i, n_s) {
    int k; scanf("%d", &k);
    REP(j, k) { int x; scanf("%d", &x); --x; idx[x] = i; }
  }

  bitcnt[0] = 0;
  for (int i = 1, ub = 1<<n_s; i < ub; ++i)
    bitcnt[i] = bitcnt[i - (i&-i)] + 1;

  memset(last, -1, sizeof last);
  memset(bad, 0, sizeof bad);
  for (int i = 0; i <= n_n; ++i) {
    if (i >= d) {
      int mask = 0;
      REP(j, n_s) if (last[j] < i-d) mask |= 1<<j;
      bad[mask] = true;
    }
    if (i < n_n) last[idx[i]] = i;
  }

  int best = n_s;
  for (int i = (1<<n_s)-1; i >= 0; --i) {
    if (bad[i]) {
      REP(j, n_s) bad[i & ~(1<<j)] = true;
    } else {
      best = min<int>(best, bitcnt[i]);
    }
  }

  printf("%d\n", best);
  return 0;
}