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
  static int frek[123];
  int m; scanf("%d", &m);
  int sum_a = 0, sum_b = 0;
  REP(i, m) { scanf("%d", frek+i); sum_b += frek[i]; }
  int x, y; scanf("%d %d", &x, &y);
  REP(i, m) {
    if (x <= sum_a && sum_a <= y)
      if (x <= sum_b && sum_b <= y) {
        printf("%d\n", i+1); 
        exit(0);
      }
    sum_a += frek[i];
    sum_b -= frek[i];
  }
  puts("0");
  return 0;
}