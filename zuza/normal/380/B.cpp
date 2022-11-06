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

struct Iv {
  int lv, lo, hi, x;
};

const int MAXL = 7010;

vector<Iv> E[MAXL];

int main(void)
{
  int n_lvs, n_ops; scanf("%d %d", &n_lvs, &n_ops);

  auto ild = [](int d, int pos) {
    int add = 0;
    for (int tmp = pos-1; tmp; tmp /= 2) ++add;
    return pos-1 + add + 1;
  };

  REP(i_ops, n_ops) {
    int tip; scanf("%d", &tip);
    if (tip == 1) {
      int lv, lo, hi, x; scanf("%d %d %d %d", &lv, &lo, &hi, &x);
      E[lv].push_back({lv, lo, hi, x});
    } else if (tip == 2) {
      int lv, pos; scanf("%d %d", &lv, &pos);
      int lo = pos, hi = pos+1;

      static vector<int> S; S.clear();

      for (int L = lv; L <= n_lvs; ++L) {
        for (auto iv : E[L]) { // [lo, hi>
          if (!(iv.hi < lo || hi <= iv.lo)) {
            S.push_back(iv.x);
          }
        }

        lo = ild(L, lo);
        hi = ild(L, hi);
      }

      sort(S.begin(), S.end());
      S.resize(unique(S.begin(), S.end()) - S.begin());
      printf("%d\n", (int)S.size());
    } else assert(false);
  }

  return 0;
}