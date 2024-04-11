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

const int MAXVAL = 1e6 + 123;

int main(void)
{
  int n, k; scanf("%d %d", &n, &k);
  int minA = 1e9;
  static int frek[2*MAXVAL]; memset(frek, 0, sizeof frek);
  static int prefix[2*MAXVAL]; memset(prefix, 0, sizeof prefix);

  REP(i, n) { int x; scanf("%d", &x); ++frek[x]; minA = min(minA, x); }
  prefix[0] = 0;
  REP(i, 2*MAXVAL-1) prefix[i+1] = prefix[i] + frek[i];

  if (minA <= k) {
    printf("%d\n", minA);
    exit(0);
  }

  int sol = k + 1;
  for (int M = k + 2; M <= minA; ++M) {
    int cnt = 0;
    for (int a = 0; a < MAXVAL; a += M) {
      cnt += prefix[a + k + 1] - prefix[a];
    }
    if (cnt == n) sol = M;
  }

  printf("%d\n", sol);
  return 0;
}