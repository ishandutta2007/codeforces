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
  int c1, c2, c3, c4; scanf("%d %d %d %d", &c1, &c2, &c3, &c4);
  int n, m; scanf("%d %d", &n, &m);

  int sum_a = 0;
  int sum_b = 0;

  REP(i, n) { 
    int x; scanf("%d", &x);
    int cost = min(x*c1, c2);
    sum_a += cost;
  }
  REP(i, m) {
    int x; scanf("%d", &x);
    int cost = min(x*c1, c2);
    sum_b += cost;
  }

  sum_a = min(sum_a, c3);
  sum_b = min(sum_b, c3);
  int sol = min(sum_a + sum_b, c4);

  printf("%d\n", sol);
  return 0;
}