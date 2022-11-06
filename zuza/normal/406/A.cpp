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
  int par = 0;

  REP(i, n) REP(j, n) {
    int x; scanf("%d", &x);
    if (i == j) par ^= x;
  }

  int q; scanf("%d", &q);
  REP(i_q, q) {
    int type; scanf("%d", &type);
    if (type == 3) {
      putchar(par + '0');
    } else {
      scanf("%*d");
      par ^= 1;
    }
  }
  putchar('\n');

  return 0;
}