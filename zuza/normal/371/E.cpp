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

typedef long long llint;

int main(void)
{
  int n; scanf("%d", &n);

  struct Idx {
    llint x;
    int idx;
  };
  const int MAXN = 3e5 + 123;
  Idx idxs[MAXN]; // llint!!

  REP(i, n) { 
    int x; scanf("%d", &x);
    idxs[i] = {x, i};
  }
  sort(idxs, idxs+n, [](Idx a, Idx b) {
      return a.x < b.x;
    });

  llint prefix[MAXN]; prefix[0] = 0; REP(i, n) prefix[i+1] = prefix[i] + idxs[i].x;
  int k; scanf("%d", &k);

  int best = -1;
  llint sum = 0;
  llint min_sum = 5e18;

  REP(i, n) {
    if (i < k) sum += (2*i - k + 1) * idxs[i].x;
    if (i >= k) { 
      sum -= (-k+1) * idxs[i-k].x;
      sum += (k-1) * idxs[i].x;
      sum -= 2*(prefix[i] - prefix[i-k+1]);
    }
    if (i >= k-1) { 
      if (sum < min_sum) { min_sum = sum; best = i-k+1; }
    }
  }

  REP(i, k) printf("%d%c", idxs[best+i].idx+1, i+1 == k ? '\n' : ' ');
  return 0;
}