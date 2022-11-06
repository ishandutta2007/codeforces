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

int main(void)
{
  int n, m; scanf("%d %d", &n, &m);
  vector<llint> cost;
  REP(i, m) {
    int a, b; scanf("%d %d", &a, &b);
    cost.push_back(b);
  }
  sort(cost.begin(), cost.end(), [](int a, int b) { return a > b; });

  // ako je k neparan -> k*(k-1)/2
  // ako je k paran -> k*(k-1)/2 + (k/2) - 1

  int maks_k = 0;
  for (llint k = 1; k*(k-1)/2 + 1 <= n; k += 2) maks_k = max<llint>(maks_k, k);
  for (llint k = 2; k*(k-1)/2 + (k/2) <= n; k += 2) maks_k = max<llint>(maks_k, k);

  maks_k = min(maks_k, m);
  llint suma = 0; REP(i, maks_k) suma += cost[i];
  cout << suma << endl;
  
  return 0;
}