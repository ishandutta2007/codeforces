#include <algorithm>

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
  int n_hook, d; scanf("%d %d", &n_hook, &d);
  static int A[123];
  REP(i, n_hook) scanf("%d", A+i);
  int n_guest; scanf("%d", &n_guest);
  sort(A, A+n_hook);
  int suma = 0;
  REP(i, n_guest) {
    if (i < n_hook) suma += A[i];
    else suma -= d;
  }
  printf("%d\n", suma);
  return 0;
}