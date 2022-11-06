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

const int inf = 1e9;
const int MAXN = 1e6 + 123;
int A[MAXN];

int main(void)
{
  int n; scanf("%d", &n);
  int frek[5] = {0};
  REP(i, n) {
    scanf("%d", A+i);
    ++frek[A[i]];
  }
  sort(A, A+n);

  int moved = 0;
  int best = inf;
  REP(nula, n) {
    int need = frek[0]*3 + frek[1]*2 + frek[2]*1;
    int space = frek[0]*4 + frek[1]*3 + frek[2]*2 + frek[3]*1;

    if (space < moved) {
      //
    } else if (need - moved <= 0) {
      best = min(best, moved);
    } else {
      if (need - moved - frek[4] <= 0) {
        best = min(best, need);
      }
    }

    //    printf("nula = %d best = %d\n", nula, best);

    /////////////////////////
    --frek[A[nula]];
    moved += A[nula];
  }
  
    printf("%d\n", best >= inf ? -1 : best);
  return 0;
}