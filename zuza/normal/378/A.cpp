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
  int x, y; scanf("%d %d", &x, &y); --x, --y;
  int a[3] = { 0 };
  REP(i, 6) {
    int d1 = abs(i-x);
    int d2 = abs(i-y);
    a[0] += d1 < d2;
    a[1] += d1 == d2;
    a[2] += d1 > d2;
  }
  printf("%d %d %d\n", a[0], a[1], a[2]);
  return 0;
}