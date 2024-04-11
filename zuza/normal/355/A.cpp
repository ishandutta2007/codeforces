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
  int k, d; scanf("%d %d", &k, &d);

  if (d > 0) {
    printf("%d", d); REP(i, k-1) printf("0");
    printf("\n");
  } else {
    if (k == 1) printf("0\n");
    else puts("No solution");
  }
  
  return 0;
}