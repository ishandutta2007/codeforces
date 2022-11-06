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

int min_pers;
int n_boys, n_bic;
int P[MAXN];
int C[MAXN];
int a;

bool bs_cmpf(int mid) {
  llint need = 0;
  llint pers = 0;

  for (int a = 0, b = mid-1; a < mid; ++a, --b) {
    if (P[a] >= C[b]) {
      pers += C[b];
    } else {
      pers += P[a];
      need += C[b] - P[a];
    }
  }

  if (need <= a) {
    min_pers = max(pers - (a - need), 0ll);
    return true;
  }
  return false;
}

int main(void)
{
  scanf("%d %d %d", &n_boys, &n_bic, &a);
  REP(i, n_boys) scanf("%d", P+i);
  REP(i, n_bic) scanf("%d", C+i);
  sort(P, P+n_boys, greater<int>());
  sort(C, C+n_bic);

  int l = 0, r = min(n_boys, n_bic);
  while (l < r) {
    int mid = (l+r+1) / 2;
    if (bs_cmpf(mid))
      l = mid;
    else
      r = mid - 1;
  }
  bs_cmpf(l);
  printf("%d %d\n", l, min_pers);

  return 0;
}