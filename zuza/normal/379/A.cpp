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
  int A, B; scanf("%d %d", &A, &B);
  int left = 0;
  int suma = 0;

  while (true) {
    A += left / B;
    left %= B;
    if (A == 0) break;

    suma += A;    
    left += A;
    A = 0;
  }

  printf("%d\n", suma);
  return 0;
}