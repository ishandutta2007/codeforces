#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define VAR(name, val) __typeof(val) name=(val)
#define FORC(it, V) for(VAR(it, (V).begin()); it != (V).end(); ++it)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

const int MAXN = 51;
const int MAXVAL = MAXN * (1e4) + 123;

int main(void)
{
  static char bio[MAXVAL] = {0};
  int n, d; scanf("%d %d", &n, &d);

  bio[0] = true;
  REP(i, n) {
    int x; scanf("%d", &x);
    for (int j = MAXVAL - 1; j >= 0; --j) {
      if (bio[j] && j+x < MAXVAL)
        bio[j+x] = true;
    }
  }

  int cost = 0, days = 0;
  for (int i = 1; i < MAXVAL; ) { // stop ?
    int last = -1;
    for (; i <= cost+d; ++i)
      if (bio[i])
        last = i;
    if (last != -1) {
      cost = last;
      ++days;
    } else {
      break;
    }
  }

  printf("%d %d\n", cost, days);
  return 0;
}