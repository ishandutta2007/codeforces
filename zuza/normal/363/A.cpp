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
  int n; scanf("%d", &n);
  bool nula = (n == 0);

  for (; n || nula; n /= 10) {
    nula = false;
    int dig = n % 10;

    if (dig >= 5) printf("-O|"), dig -= 5;
    else printf("O-|");

    if (dig == 0) printf("-OOOO");
    if (dig == 1) printf("O-OOO");
    if (dig == 2) printf("OO-OO");
    if (dig == 3) printf("OOO-O");
    if (dig == 4) printf("OOOO-");
    putchar('\n');
  }



  return 0;
}